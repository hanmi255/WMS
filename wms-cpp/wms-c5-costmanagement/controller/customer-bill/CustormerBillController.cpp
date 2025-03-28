

#include "stdafx.h"
#include "CustormerBillController.h"
#include <iostream>
#include "service/customer-bill/CustomerBillService.h"


//客户账单查询
CustomerBillPageJsonVO::Wrapper CustormerBillController::execQuerySample(const CustomerBillQuery::Wrapper& query, const PayloadDTO& payload)
{

	// 定义返回数据对象
	auto jvo = CustomerBillPageJsonVO::createShared();

	// 有效值校验
	if (query->pageIndex<0 || query->pageSize<0)
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	CustomerBillPageService service;
	// 查询数据
	auto result = service.listAll(query);


	jvo->success(result);
	return jvo;
}







//导出未清账单
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> CustormerBillController::execExportFile(const UnsettledQuery::Wrapper& file)
{



	// 定义一个Service
	ExportService service;
	String fstring = service.getById(file->customercode);


	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + file->customercode.getValue("")+".xlsx");

	// 影响成功结果
	return response;
}









//导出期间账单
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> CustormerBillController::execperiodFile(const PeriodQuery::Wrapper& file)
{



	// 定义一个Service
	periodService service;
	String fstring = service.getBydate(file);



	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + file->customercode.getValue("") + ".xlsx");

	// 影响成功结果
	return response;
}



