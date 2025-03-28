#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "GoodsDiffPostController.h"
#include "Macros.h"
#include "../../service/goods-manage/GoodsManageService.h"
#include "FastDfsClient.h"



GoodsDiffPostPageJsonVO::Wrapper GoodsDiffPostController::execQueryAll(const GoodsDiffPostQuery::Wrapper& query)
{
	// 定义一个Service
	GoodsManageService service;
	// 查询数据
	auto result = service.listAll(query);
	
	// 响应结果
	auto jvo = GoodsDiffPostPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

Uint64JsonVO::Wrapper GoodsDiffPostController::execDiffPost(const GoodsDiffPostDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义一个Service
	GoodsManageService service;
	// 查询数据

	auto result = service.updateData(dto,payload);
	// 响应结果
	auto jvo = Uint64JsonVO::createShared();
	if (result)
	{
		jvo->success(result);
	}
	else
	{
		jvo->fail(result);
	}
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> GoodsDiffPostController::execExportDiffPost(const ExportGoodsDiffPostQuery::Wrapper& query)
{
	GoodsManageService service;
		
	auto result = service.exportData(query);
	//// 响应结果
	//auto jvo = Uint64JsonVO::createShared();
	//if (result)
	//{
	//	jvo->success(result);
	//}
	//else
	//{
	//	jvo->fail(result);
	//}
	//return jvo;

	// 构建文件全路径
	//std::string fullPath = result + URIUtil::urlDecode(filename.getValue(""));
	std::string fullPath = result/* + URIUtil::urlDecode("test.xlsx")*/;
	// 读取文件
	auto fstring = String::loadFromFile(fullPath.c_str());

	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	//response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));
	response->putHeader("Content-Disposition", "attachment; filename=test.xlsx" /*ZH_WORDS_GETTER("diff-post.excel.name")*/);

	// 影响成功结果
	return response;
}


