/*
 @Author: nanbowan
*/
#include "stdafx.h"
#include <iostream>
#include "FileController.h"
#include"../wms-c7-reposity/service/file/FileService.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include <iterator>
#include <fstream>

StringJsonVO::Wrapper FileController::execUploadOne(std::shared_ptr<IncomingRequest> request)
{
	// 1 初始化
	API_MULTIPART_INIT(container, reader);

	// 2 配置读取器
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);

	// 3 读取数据
	request->transferBody(&reader);

	/* 打印上传总部分数 */
	OATPP_LOGD("Multipart", "parts_count=%d", container->count());

	// 4 解析数据
	/* TODO: 解析的数据具体逻辑，需要根据你的业务需求来，下面是使用示例而已。 */
	/* 获取表单数据 */
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, ZH_WORDS_GETTER("dictionary.order.id.summary"), id);
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, ZH_WORDS_GETTER("dictionary.order.code.summary"), code);
	API_MULTIPART_PARSE_FORM_FIELD_STR(container, ZH_WORDS_GETTER("dictionary.order.name.summary"), name);
	/* 打印表单数据 */
	if (id) OATPP_LOGD("Multipart", "id=%s", name.getValue({}).c_str());
	if (code) OATPP_LOGD("Multipart", "code='%s'", code.getValue({}).c_str());
	if (name) OATPP_LOGD("Multipart", "name=%s", name.getValue({}).c_str());
	/* 获取文件数据 */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	if (file)
	{
		/* 打印文件名称 */
		string filename = partfile->getFilename().getValue("");
		OATPP_LOGD("Multipart", "file='%s'", filename.c_str());

		/* 上传到FastDFS */
		ZO_CREATE_DFS_CLIENT(dfs);
		// 获取文件后缀名
		string suffix = "";
		size_t pos = filename.rfind(".");
		if (pos != string::npos)
		{
			suffix = filename.substr(pos + 1);
		}

		//检查文件类型是不是excel表格式
		if (suffix != "xls" && suffix != "xlsx")
		{
			//直接返回文件读取失败
			auto jvo = StringJsonVO::createShared();
			jvo->fail("Failed To Read File");
			return jvo;
		}

		// 上传文件
		string downloadUrl = dfs.uploadFile(file->data(), file->size(), suffix);
		OATPP_LOGD("Multipart", "download url='%s'", downloadUrl.c_str());

		FileService fs;
		if (!fs.insertData(downloadUrl))
		{
			//直接返回数据插入失败
			auto jvo = StringJsonVO::createShared();
			jvo->fail("Failed To Insert Data");
			return jvo;
		}
	}

	// 5 响应结果
	/* TODO: 具体响应什么结果，需要根据你的业务需求来，下面是使用示例而已。 */
	auto jvo = StringJsonVO::createShared();
	jvo->success("OK");
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> FileController::execDownloadFile(const String& filename)
{
	FileService fs;

	string path = fs.queryData();

	ZO_CREATE_DFS_CLIENT(dfs);

	string savePath = "./public/fastdfs";

	string filePath=dfs.downloadFile(path,&savePath);

	ifstream file(filePath, std::ios::binary);

	string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();

	// 判断是否读取成功
	if (content.empty())
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, content);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));

	dfs.deleteFile(filePath);

	// 影响成功结果
	return response;

}


