#include "stdafx.h"
#include "LoadingFeeController.h"
#include "../../service/loading-fee/LoadingFeeService.h"
#include "../ApiDeclarativeServicesHelper.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"

//分页查询外包装车费
LoadingFeePageJsonVO::Wrapper LoadingFeeController::execPageQueryLoadingFee(const LoadingFeeQuery::Wrapper& query, const PayloadDTO& payload)
{
	//定义一个Service
	LoadingFeeService service;
	//执行数据查询
	auto res = service.pageQueryLoadingFee(query);
	// 响应结果
	auto jvo = LoadingFeePageJsonVO::createShared();
	jvo->success(res);
	return jvo;
}

// 执行文件下载处理
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> LoadingFeeController::execDownloadLoadingFee(const LoadingFeeQuery::Wrapper& query)
{
	//定义一个Service
	LoadingFeeService service;
	//执行数据查询,获取查询数据
	list<LoadingFeeDO> res = service.DownloadLoadingFee(query);

	//将查询数据转换成导出数据
	std::vector<std::vector<std::string>> data;
	//初始化表项
	std::vector<std::string> title;
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.fee"));
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.operator"));
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.operateDate"));
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.orderNo"));
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.goods"));
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.goodsName"));
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.goodsNum"));
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.goodsWeight"));
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.feeRMB"));
	title.push_back(ZH_WORDS_GETTER("loadingfee.field.price"));
	data.push_back(title);

	//添加数据
	for (auto a : res)
	{
		std::vector<std::string> row;
		row.push_back(a.getFee());
		row.push_back(a.getXOperator());
		row.push_back(a.getOperateDate());
		row.push_back(a.getOrderNo());
		row.push_back(a.getGoods());
		row.push_back(a.getGoodsName());
		row.push_back(to_string(a.getGoodsNum()));
		row.push_back(to_string(a.getGoodsWeight()));
		row.push_back(to_string(a.getFeeRMB()));
		row.push_back(to_string(a.getPrice()));
		data.push_back(row);
	}

	// 将Excel数据导出到String中
	ExcelComponent excel;
	auto buff = excel.writeVectorToBuff(ZH_WORDS_GETTER("file.field.filename"), data);
	const char* resData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(resData, buff.size());

	// 判断是否获取数据
	if (!fstring)
	{
		std::cerr << "Failed to load data: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "Data Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 获取当前时间点
	auto now = std::chrono::system_clock::now();

	// 将时间点转换为时间戳
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

	// 使用 stringstream 进行时间格式化
	std::ostringstream oss;
	oss << std::put_time(std::localtime(&currentTime), "%Y-%m-%d %H:%M:%S");

	//设置文件名
	string filename = "loading_fee_" + oss.str() + ".xlsx";

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	return response;
}