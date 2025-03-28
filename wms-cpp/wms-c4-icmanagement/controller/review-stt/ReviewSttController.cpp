#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "ReviewSttController.h"
#include "../../service/review-stt/ReviewSttService.h"
#include "FastDfsClient.h"



ReviewSttPageJsonVO::Wrapper ReviewSttController::execQueryAll(const ReviewSttQuery::Wrapper& query)
{
	// 定义一个Service
	ReviewSttService service;
	// 查询数据
	auto result = service.listAll(query);

	// 响应结果
	auto jvo = ReviewSttPageJsonVO::createShared();
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

Uint64JsonVO::Wrapper ReviewSttController::execReviewStt(const ReviewSttDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义一个Service
	ReviewSttService service;
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

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> ReviewSttController::execExportReviewStt(const ExportReviewSttQuery::Wrapper& query)
{
	ReviewSttService service;

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


