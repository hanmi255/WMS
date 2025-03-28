//#include "stdafx.h"
//#include <iostream>
//
//// FastDFS需要导入的头
//#include "ServerInfo.h"
//#include "NacosClient.h"
//#include "FastDfsClient.h"
//#include "SimpleDateTimeFormat.h"
//#include "CostGoodsController.h"
//#include <ExcelComponent.h>
//
//StringJsonVO::Wrapper CostGoodsController::execwaydelete(const String& code)
//{
//	// 定义返回数据对象
//	auto jvo = StringJsonVO::createShared();
//	if (code == "")
//	{
//		jvo->init(String(""), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// 定义一个Service
//	CostGoodsService service;
//	// 执行数据删除
//	if (service.removeData(code.getValue(""))) {
//		jvo->success(code);
//	}
//	else
//	{
//		jvo->fail(code);
//	}
//	// 响应结果
//	return jvo;
//}
//
//std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> CostGoodsController::execDownloadFile(const String& filename)
//{
//	BillingProductCategoryQuery::Wrapper query;
//	CostGoodsService service;
//	list<GoodsClassDO> result = service.listAll();
//	std::vector<std::vector<std::string>> data;
//	stringstream ss;
//	std::vector<std::string> r1;
//	ss.clear();
//	std::string info = ZH_WORDS_GETTER("CostGoodsQuery.way.code");
//	ss << info;
//	r1.push_back(ss.str());
//	ss.str("");
//	ss.clear();
//	info = ZH_WORDS_GETTER("CostGoodsQuery.way.name");
//	ss << info;
//	r1.push_back(ss.str());
//	ss.str("");
//	data.push_back(r1);
//	for (auto r : result)
//	{
//		std::vector<std::string> row;
//		string n = r.getGoodsClassCode();
//		string m = r.getGoodsClassName();
//		ss.clear();
//		ss << n;
//		row.push_back(ss.str());
//		ss.str("");
//		ss.clear();
//		ss << m;
//		row.push_back(ss.str());
//		ss.str("");
//		data.push_back(row);
//	}
//	std::string fileName = "./public/excel/1.xlsx";
//	std::string sheetName = ZH_WORDS_GETTER("CostGoodsQuery.file.sheetname");
//	
//	
//	// 将Excel数据导出到String中
//	ExcelComponent excel;
//	auto buff = excel.writeVectorToBuff(sheetName, data);
//	const char* tsData = reinterpret_cast<const char*>(buff.data());
//	auto fstring = String(tsData, buff.size());
//	 
//	 
//	// 判断是否读取成功
//	if (!fstring)
//	{
//		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
//		return createResponse(Status::CODE_404, "File Not Found");
//	}
//
//	// 创建响应头
//	auto response = createResponse(Status::CODE_200, fstring);
//
//	// 设置响应头信息
//	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));
//
//	// 影响成功结果
//	return response;
//}
//
//StringJsonVO::Wrapper CostGoodsController::execUploadOne(std::shared_ptr<IncomingRequest> request)
//{
//	// 1 初始化容器和读取器
//	API_MULTIPART_INIT(container, reader);
//
//	// 2 配置读取器
//	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);//可上传多个参数,但是后续只解析"file"参数
//
//	// 3 读取数据
//	request->transferBody(&reader);
//	/* 打印上传总部分数 */
//	OATPP_LOGD("Multipart", "parts_count=%d", container->count());
//
//	// 4 解析数据
//	/* 获取文件数据 */
//	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
//	if (file)
//	{
//		/* 打印文件名称 */
//		string filename = partfile->getFilename().getValue("");
//		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());
//		/* 测试将文件保存到磁盘上面 */
//		//string fullPath = "public/static/file/" + filename;
//		//file.saveToFile(fullPath.c_str());
//
//		if (false)//是否上传到FastDFS,可选
//		{
//			/* 测试上传到FastDFS */
//			ZO_CREATE_DFS_CLIENT_URL(dfs, urlPrefix);
//			// 获取文件后缀名
//			string suffix = "";
//			size_t pos = filename.rfind(".");
//			if (pos != string::npos)
//			{
//				suffix = filename.substr(pos + 1);
//			}
//			// 上传文件
//			string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
//			downloadUrl = urlPrefix + downloadUrl;
//			OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());
//		}
//	}
//	// 5 响应结果:文件上传到String的file,要将file解析并传入数据库
//	auto jvo = StringJsonVO::createShared();
//	ExcelComponent excel;
//	const char* data = file->data();
//	vector<vector<string>> matrix = excel.readIntoVector(data, file->size(), ZH_WORDS_GETTER("CostGoodsQuery.file.sheetname"));
//	//将每行数据组装成DTO传输给service层插入
//	int lines = matrix.size();
//	for (int i = 1; i < lines; ++i)
//	{
//		auto dto = BPCExcelUploadDTO::createShared();
//		dto->addExcel(matrix[i][0], matrix[i][1]);
//		//从负载读取信息
//		CostGoodsService service;
//		uint64_t id = service.saveData(dto);
//		if (id <= 0)
//		{
//			jvo->fail("fail");
//			return jvo;
//		}
//	}
//	jvo->success("OK");
//	return jvo;
//}