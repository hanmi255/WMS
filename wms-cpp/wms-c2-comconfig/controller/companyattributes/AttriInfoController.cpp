/*
 Copyright Zero One Star. All rights reserved.

 @Author: killerqueen
 @Date: 2025/03/9 17:48:10

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "AttriInfoController.h"
#include "service/companyattributes/AttriService.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include"ExcelComponent.h"

// 工具函数需要导入的库
#include <filesystem> //删除本地文件
#include <regex> // 正则表达式


// 转换成vector
vector<string> castTovector(Vector<String> vec) {
	vector<string> object_idv;
	for (const auto& index : *vec) {
		object_idv.push_back(index);
	}
	return object_idv;
}

// 根据jvo枚举类型初始化删除jvo
void initJvo_delete(const AttriDeleteInfoDTO::Wrapper& dto, JvoType jvotype) {
	switch (jvotype)
	{
	case success:
		dto->ids = { "1"};
		break;
	case error:
		dto->ids = { ""};
		break;
	default:
		break;
	}
}

// 动态获取上传服务Execl的标题
vector<std::string> getSheetTitle(const string& ExcelPath) {
	xlnt::workbook wb;
	wb.load(ExcelPath);
	vector<std::string> sheetTitle = wb.sheet_titles();
	return sheetTitle;
}


// 检验当前上传的execl文档数据量规模是否符合合法
bool checkExeclDataIsVaild(const string& ExcelPath) {
	xlnt::workbook wb;
	wb.load(ExcelPath);
	auto wsList = getSheetTitle(ExcelPath);

	// 避免数据量过大，照成插入负担
	const int maxRows = 100000; // 最大允许行数 
	
	int rowCount = 0;
	for (auto wsIndex : wsList) {
		xlnt::worksheet ws = wb.sheet_by_title(wsIndex);//根据title获取工作表
		for (const auto& row : ws.rows()) {
			rowCount++;
			if (rowCount > maxRows) {
				std::cerr << "The amount of data exceeds the limit!" << std::endl;
				return false;
			}
		}
	}
	return true;
}

// 删除本地临时文件
void deleteTempExecl(const string& ExecPath) {
	if (std::filesystem::exists(ExecPath)) {
		if (std::filesystem::remove(ExecPath)) {
			std::cout << "The file was deleted successfully" << endl;
		}
		else {
			std::cout <<"File deletion failed!"<<std::endl;
		}
	}
	else{
		std::cout <<"the path does not exist!"<< std::endl;
	}
}


// 脏数据校验
bool regexCheck(const string& typecodes,const string& typenames) {

	// 正则表达式：校验 typecodes（只允许数字）
	std::regex codeRegex(R"(^\d+$)"); // 只允许数字

	// 正则表达式：校验 typenames（允许字母、数字、中文字符、下划线，禁止空格和特殊符号）
	std::regex nameRegex(R"(^[a-zA-Z0-9_\p{Han}]+$)"); // \p{Han} 匹配中文字符，_ 匹配下划线

	// 校验 typecodes
	if (!std::regex_match(typecodes, codeRegex)) {
		std::cout << "typecodes check error" << std::endl;
		return false;
	}

	// 校验 typenames
	if (!std::regex_match(typenames, nameRegex)) {
		std::cout << "typenames check error" << std::endl;
		return false;
	}

	return true; // 如果两个字段都校验通过
}

/*读取数据，组装成vector<AttriInfoJsonDTO::Wrapper>*/
vector<AttriInfoJsonDTO::Wrapper> getDataFromExcelAttriInfo(const string& ExcelPath, const PayloadDTO& pdto) {
	int colNum = 2;//两个字段
	vector<AttriInfoJsonDTO::Wrapper> dtoList;
	ExcelComponent excel;

	//唯一值，避免重复 typecode typename 相同的不能出现两次，如果出现了两次要进行去重
	std::unordered_map<std::string, std::string> uniqueValues;  //如果提取数据时发现了重复的数据不保存进容器内

	// 动态获取当前execl拥有的页签
	auto sheet = getSheetTitle(ExcelPath);
	// 有多少页签数，保存多少页签的数据
	for (auto sheetTitle : sheet) {
		vector<vector<string>> dataList = excel.readIntoVector(ExcelPath, sheetTitle);//读取页签
		for (auto index : dataList) {
			auto dto = AttriInfoJsonDTO::createShared();
			// 字段数校验
			if (index.size() != colNum) {//列数不对,导入企业属性只包含两列数据 属性代码typecodes & 属性名称typenames
				return dtoList;
			}
			else {
				// 唯一性校验
				if (uniqueValues.find(index[0]) != uniqueValues.end()) {
					// 出现了重复
					continue; // 去找下一行的数据
				}
				// 脏数据校验
				else if (!regexCheck(index[0],index[1])) {
					// 出现了脏数据
					continue; // 去找下一行的数据
				}
				// 提取字段数据
				else {
					dto->sysorgcode = pdto.getOrgcode();
					dto->syscompanycode = pdto.getCompanycode();
					dto->creadename = pdto.getRealname();
					dto->createby = pdto.getUsername();
					dto->typecodes = index[0];
					dto->typenames = index[1];
					uniqueValues[index[0]] = index[1]; //保存唯一值
				}
			}
			dtoList.push_back(dto);
		}
	}
	return dtoList;
}

/*删除企业属性 -- 支持批量删除*/
AttriDeleteJsonVO::Wrapper AttriController::execRemoveAttri(const AttriDeleteInfoDTO::Wrapper& id) {
	// 定义返回数据对象
	auto jvo = AttriDeleteJsonVO::createShared();
	auto jvo_error = AttriDeleteInfoDTO::createShared();
	auto jvo_success = AttriDeleteInfoDTO::createShared();
	initJvo_delete(jvo_error,error);
	initJvo_delete(jvo_success, success);

	// 参数校验
	Vector<String> vec_id = id->ids;
	for (const auto& count : *vec_id) {
		if (!count) {
			jvo->init(jvo_error, RS_PARAMS_INVALID);
			return jvo;
		}
	}
	
	// 执行删除
	AttriService service;

	if (service.removeData(castTovector(id->ids))) {
		jvo->success(jvo_success);
	}
	else {
		jvo->fail(jvo_error);
	}

	return jvo;
}



/*导出企业数据，生成Execl文件*/

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> AttriController::execDownloadArrtibutes(const String& filename) {
	// 构建文件全路径
	std::string fullPath = "public/downloadentattr/" + URIUtil::urlDecode(filename.getValue(""));

	// 读取文件
	auto fstring = String::loadFromFile(fullPath.c_str());

	//导出数据到客户端
	AttriService service;
	std::vector<std::vector<std::string>> data = service.getData();//调用service获取服务数据

	//添加标头信息
	data.insert(data.begin(), {
	ZH_WORDS_GETTER("attrikq.download-arrti.header.h1") ,
	ZH_WORDS_GETTER("attrikq.download-arrti.header.h2") ,
	ZH_WORDS_GETTER("attrikq.download-arrti.header.h3") ,
	ZH_WORDS_GETTER("attrikq.download-arrti.header.h4") ,
	ZH_WORDS_GETTER("attrikq.download-arrti.header.h5") ,
	ZH_WORDS_GETTER("attrikq.download-arrti.header.h6") ,
	ZH_WORDS_GETTER("attrikq.download-arrti.header.h7") ,
	ZH_WORDS_GETTER("attrikq.download-arrti.header.h8") ,
		});

	ExcelComponent excel;
	//将数据导出到String中
	auto buff = excel.writeVectorToBuff(ZH_WORDS_GETTER("attrikq.download-arrti.sheet"), data);
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	auto tsfstring = String(tsData, buff.size());

	// 创建响应头
	auto response = createResponse(Status::CODE_200, tsfstring);

	if (!tsfstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}
	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	// 影响成功结果
	return response;
}


/*导入Execl文件*/
StringJsonVO::Wrapper AttriController::execUploadAttri(std::shared_ptr<IncomingRequest> request, const PayloadDTO& dto) {

	/*导入逻辑*/
	// 1 初始化
	API_MULTIPART_INIT(container, reader);

	// 2 配置读取器
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);

	// 3 读取数据
	request->transferBody(&reader);

	/* 打印上传总部分数 */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());

	// 4 解析数据
	/* 获取表单数据 */
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "typecode", typecode);
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, "typenames", typenames);

	/* 打印表单数据 */
	if (typecode) OATPP_LOGD("Multipart", "age=%d", typecode.getValue({}).c_str());
	if (typenames) OATPP_LOGD("Multipart", "nickname='%s'", typenames.getValue({}).c_str());

	/* 获取文件数据 */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	auto jvo = StringJsonVO::createShared();
	if (file)
	{
		/* 打印文件名称 */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());

		//将文件保存到本地
		string fullPath = "public/static/file/" + filename;
		//string fullPath = "E:\\temp\\" + filename;
		file.saveToFile(fullPath.c_str());
		std::cout << "The fullPath is : " << fullPath << std::endl;

		/* 测试上传到FastDFS */
		ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		// 获取文件后缀名
		string suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}
		// 上传文件
		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		downloadUrl = urlPrefix + downloadUrl;
		OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
		std::cout << downloadUrl << std::endl;


		// 初步的文件数据量校验，如果这一流程不通过将会被直接返回 
		// 【注：空Execl在这一流程不会被视为无效】
		//  数据量过大会被视作无效 -- 超出容量限制

		if (!checkExeclDataIsVaild(fullPath)) {
			std::cerr << "file data invaild!!!" << std::endl;
			jvo->fail("file data invaild");
			//删除本地临时文件
			deleteTempExecl(fullPath);
			//删除远端文件
			//dfs.deleteFile(downloadUrl);
			return jvo;
		}

		// 导入数据库
		AttriService service;

		// 获取Data流程细节说明 -- 这里会进行进一步的校验工作，并提取数据
		// 字段数校验
		//		企业属性上传：Execl包含两个字段：企业属性代码com_type_code 与 企业属性名称com_type_name对应两列数据
		//		和页面显示的查询数据一致
		//		其他信息由PayloadDTO获取，不会在Execl中获取
		// 数据去重（不会提取重复数据） 
		//		主要针对com_type_code 与 com_type_name 是否在Execl中唯一
		// 数据校验（不会提取脏数据）
		//		在com_type_code出现除数字以外的数据将被视为脏数据 ；
		//		在com_type_name出现&^%$#@*()~`,.';:[]{}【】()=+-/等无意义符号的将被视为脏数据，只允许字母、数字、中文字符和下划线，但不允许出现空格和特殊符号
		//		所有脏数据都不会被提取
		// 最后合格的数据都会被提取到我们的Object_data目标数据容器中，等待service执行数据库插入服务
		// 注：
		// `id` 通过代码自主生成
		//  `create_name` ,`create_by`, `sys_company_code`  `sys_org_code`  
		// 等其他数据【主要是创建信息之类的字段】由PayloadDTO获取并和提取出的数据一同插入到数据库中，不在这一步的效验和提取范围内

		vector<AttriInfoJsonDTO::Wrapper> object_data = getDataFromExcelAttriInfo(fullPath,dto);
		
		if (object_data.size() == 0) {// 如果数据为空
			jvo->fail("empty");
		}
		for (auto dto : object_data) {
			if (!service.saveData(dto)) { //service执行插入
				jvo->fail("false");
			}
		}

		//删除本地临时文件
		deleteTempExecl(fullPath);
		//删除远端文件
		//dfs.deleteFile(downloadUrl);
		
		//所有工作都成功 设置ok
		jvo->success("ok");
	}

	return jvo;
}