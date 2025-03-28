/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/02/24 11:37:57

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
#include <iostream>
#include "UploadFileController.h"
#include "ExcelComponent.h"
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "service/tradeclassifi/UploadFileService.h"
#include <filesystem> //删除本地文件
#include <regex> // 正则表达式
#include "domain/dto/tradeclassifi/UploadFileDTO.h"
#include <fstream>

// 动态获取上传服务Execl的标题
vector<std::string> GetSheetTitle(const string& ExcelPath) {
	xlnt::workbook wb;
	wb.load(ExcelPath);
	vector<std::string> sheetTitle = wb.sheet_titles();
	return sheetTitle;
}

bool CheckExeclDataIsVaild(const std::string& ExcelPath) {
	try {
		// 1. 检查文件是否存在
		std::ifstream file(ExcelPath);
		if (!file.good()) {
			std::cerr << "错误: 文件不存在或不可读 - " << ExcelPath << std::endl;
			return false;
		}

		// 2. 检查文件格式
		if (ExcelPath.find(".xlsx") == std::string::npos) {
			std::cerr << "错误: 仅支持 .xlsx 格式文件" << std::endl;
			return false;
		}

		// 3. 加载工作簿
		xlnt::workbook wb;
		wb.load(ExcelPath);

		// 4. 获取所有工作表名
		const auto wsList = wb.sheet_titles();

		// 5. 检查行数限制
		const int maxRows = 100000;
		int rowCount = 0;
		for (const auto& sheetName : wsList) {
			auto ws = wb.sheet_by_title(sheetName);
			for (const auto& row : ws.rows()) {
				if (++rowCount > maxRows) {
					std::cerr << "错误: 数据量超过限制 (" << maxRows << " 行)" << std::endl;
					return false;
				}
			}
		}
		return true;
	}
	catch (const xlnt::exception& e) {
		std::cerr << "xlnt 异常: " << e.what() << std::endl;
		return false;
	}
	catch (const std::exception& e) {
		std::cerr << "标准异常: " << e.what() << std::endl;
		return false;
	}
}

// 脏数据校验
bool RegexCheck(const string& typecodes, const string& typenames) {

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

// 删除本地临时文件
void DeleteTempExecl(const string& ExecPath) {
	if (std::filesystem::exists(ExecPath)) {
		if (std::filesystem::remove(ExecPath)) {
			std::cout << "The file was deleted successfully" << endl;
		}
		else {
			std::cout << "File deletion failed!" << std::endl;
		}
	}
	else {
		std::cout << "the path does not exist!" << std::endl;
	}
}

/*读取数据，组装成vector<AttriInfoJsonDTO::Wrapper>*/
vector<UploadFileDTO::Wrapper> getDataFromExcelUploadFile(const string& ExcelPath, const PayloadDTO& pdto) {
	int colNum = 2;//两个字段
	vector<UploadFileDTO::Wrapper> dtoList;
	ExcelComponent excel;

	//唯一值，避免重复 typecode typename 相同的不能出现两次，如果出现了两次要进行去重
	std::unordered_map<std::string, std::string> uniqueValues;  //如果提取数据时发现了重复的数据不保存进容器内

	// 动态获取当前execl拥有的页签
	auto sheet = GetSheetTitle(ExcelPath);
	// 有多少页签数，保存多少页签的数据
	for (auto sheetTitle : sheet) {
		vector<vector<string>> dataList = excel.readIntoVector(ExcelPath, sheetTitle);//读取页签
		for (auto index : dataList) {
			auto dto = UploadFileDTO::createShared();
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
				else if (!RegexCheck(index[0], index[1])) {
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

StringJsonVO::Wrapper UploadFileController::execUploadTrade(std::shared_ptr<IncomingRequest> request, const PayloadDTO& dto)
{
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

		///* 测试上传到FastDFS */
		//ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
		//// 获取文件后缀名
		//string suffix = "";
		//size_t pos = filename.rfind(".");
		//if (pos != string::npos)
		//{
		//	suffix = filename.substr(pos + 1);
		//}
		// 上传文件
		//string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		//downloadUrl = urlPrefix + downloadUrl;
		//OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
		//std::cout << downloadUrl << std::endl;


		// 初步的文件数据量校验，如果这一流程不通过将会被直接返回 
		// 【注：空Execl在这一流程不会被视为无效】
		//  数据量过大会被视作无效 -- 超出容量限制

		if (!CheckExeclDataIsVaild(fullPath)) {
			std::cerr << "file data invaild!!!" << std::endl;
			jvo->fail("file data invaild");
			//删除本地临时文件
			DeleteTempExecl(fullPath);
			//删除远端文件
			//dfs.deleteFile(downloadUrl);
			return jvo;
		}

		// 导入数据库
		UploadFileService service;

		vector<UploadFileDTO::Wrapper> object_data = getDataFromExcelUploadFile(fullPath, dto);

		if (object_data.size() == 0) {// 如果数据为空
			jvo->fail("empty");
		}
		for (auto dto : object_data) {
			if (!service.saveData(dto)) { //service执行插入
				jvo->fail("false");
			}
		}

		//删除本地临时文件
		DeleteTempExecl(fullPath);
		//删除远端文件
		//dfs.deleteFile(downloadUrl);

		//所有工作都成功 设置ok
		jvo->success("ok");
	}

	return jvo;
}
