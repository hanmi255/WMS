#include "stdafx.h"
#include "UnloadingFeeController.h"
#include "../../service/unloading-fee/UnloadingFeeService.h"
#include "../ApiDeclarativeServicesHelper.h"


// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include "ExcelComponent.h"

//分页查询外包卸货费
UnloadingFeePageJsonVO::Wrapper UnloadingFeeController::execPageQueryUnloadingFee(const UnloadingFeeQuery::Wrapper& query, const PayloadDTO& payload)
{
	//定义一个Service
	UnloadingFeeService service;
	//执行数据查询
	auto res = service.pageQueryUnloadingFee(query);
	// 响应结果
	auto jvo = UnloadingFeePageJsonVO::createShared();
	jvo->success(res);
	return jvo;
}


//下载外包卸货费
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> UnloadingFeeController::execDownloadUnLoadingFee(const UnloadingFeeQuery::Wrapper& query)
{
	//定义一个Service
	UnloadingFeeService service;
	//执行数据查询,获取查询数据
	list<UnloadingFeeDO> res = service.DownloadUnloadingFee(query);

	//将查询数据转换成导出数据
	std::vector<std::vector<std::string>> data;
	//初始化表项
	std::vector<std::string> title;

	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.fee"));
	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.acceptor"));
	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.acceptDate"));
	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.orderNo"));
	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.goods"));
	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.goodsName"));
	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.unloadingNum"));
	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.unloadingWeight"));
	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.feeRMB"));
	title.push_back(ZH_WORDS_GETTER("unloadingfee.field.price"));
	data.push_back(title);

	//添加数据
	for (auto a : res)
	{
		std::vector<std::string> row;
		row.push_back(a.getFee());
		row.push_back(a.getAcceptor());
		row.push_back(a.getAcceptDate());
		row.push_back(a.getOrderNo());
		row.push_back(a.getGoods());
		row.push_back(a.getGoodsName());
		row.push_back(to_string(a.getUnloadingNum()));
		row.push_back(to_string(a.getUnloadingWeight()));
		row.push_back(to_string(a.getFeeRMB()));
		row.push_back(to_string(a.getPrice()));
		data.push_back(row);
	}

	// 将Excel数据导出到String中
	ExcelComponent excel;
	auto buff = excel.writeVectorToBuff(ZH_WORDS_GETTER("file.field.filename"), data);
	const char* resData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(resData, buff.size());

	// 判断是否读取成功
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
	string filename = "unloading_fee_" + oss.str() + ".xlsx";

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + filename);
	return response;
}