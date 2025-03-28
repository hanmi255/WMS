#include "stdafx.h"
#include "BillingNameController.h"
//#include "../../service/billing-configuration/CostNameService.h"
#include "../../service/billing-name/BillingNameService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include "../../lib-common/include/ExcelComponent.h"
#include "ApiHelper.h"
#include "../../domain/vo/file/FileVO.h"
#include <oatpp/web/protocol/http/Http.hpp>
StringJsonVO::Wrapper BillingNameController::execbatchdeleteBillingName(const BillingNameBatchDTO::Wrapper& bathdto)
{
	auto jvo = StringJsonVO::createShared();
	string resultfail = string("fail");
	string resultsuccess = string("success");
	BillingNameService  service;
	//service.batchdeleteData(bathdto);
	if (service.batchdeleteData(bathdto))
	{
		jvo->success(resultsuccess);
		return jvo;
	}
	else
	{
		jvo->fail(resultfail);
		return jvo;
	}

}
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> BillingNameController::execExportName(const BillingNameQuery::Wrapper& query)
{

	BillingNameService service;
	auto result = service.exportData(query);
	std::vector<BillingNameDO> datas(result.begin(), result.end());

	// 创建表头数据
	std::vector<std::string> headers = {
		ZH_WORDS_GETTER("billing-name.field.cost_code"),
		ZH_WORDS_GETTER("billing-name.field.cost_name"),
		ZH_WORDS_GETTER("billing-name.field.cost_type_code"),
	};
	std::vector<std::vector<std::string>> data;
	data.push_back(headers);

	for (int i = 0; i < datas.size(); ++i)
	{
		std::vector<std::string> row;

		row.push_back(datas[i].getCost_code());
		row.push_back(datas[i].getCost_name());
		row.push_back(datas[i].getCost_type_code());
		data.push_back(row);
	}

	// 定义保存数据位置和页签名称
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要从配置文件中获取
	std::string sheetName = ZH_WORDS_GETTER("billing-name.excelname.s1");
	//文件名
	std::string filename = ZH_WORDS_GETTER("billing-name.filename.s2") + ".xlsx";
	// 保存到文件
	ExcelComponent excel;
	auto buff = excel.writeVectorToBuff(sheetName, data);//把数据写进哪个数据表中，最终转换成二进制数据
	const char* tsData = reinterpret_cast<const char*>(buff.data());//把二进制数据转换成char类型
	auto fstring = String(tsData, buff.size());//再把char类型的数据转换成Oat++中的String
	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=billingname.xlsx");
	//"Content-Disposition"：指定内容的呈现方式（告诉浏览器如何处理这个文件）。
	//attachment：表示这个文件是一个附件，浏览器应该弹出下载对话框（而不是直接在浏览器中打开）。
	//filename = OffRackAdjustment.xlsx：指定下载时的默认文件名。
	return response;
}
StringJsonVO::Wrapper BillingNameController::execuploadName(std::shared_ptr<IncomingRequest> request)
{
	//// 1 初始化
	
	auto jvo = StringJsonVO::createShared();
	API_MULTIPART_INIT(container, reader);
	////// 2 配置读取器
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	////// 3 读取数据
	request->transferBody(&reader);
	////// 4 解析数据
	/////* todo: 解析的数据具体逻辑，需要根据你的业务需求来，下面是使用示例而已。 */
	/////* 获取文件数据 */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	auto vectordto = BillingNameVectorDTO::createShared();
	
	auto fileData="";
	auto fileSize=0;
	std::string filename = "";
	std::string sheetName = ZH_WORDS_GETTER("billing-name.excelname.s1");
	BillingNameService  service;
	if (file)
	{
		ExcelComponent excel;
	//	// 5. 读取文件内容
		 fileData = file->data();  // 获取二进制数据
		 fileSize = file->size();
		filename = partfile->getFilename().getValue(""); // 获取原始文件名
		
		 std::vector<std::vector<std::string>> result= excel.readIntoVector(fileData,fileSize,sheetName);
		 for (int i = 1; i < result.size(); i++)
		 {
			
				 auto dto = BillingNamefileDTO::createShared();  // 创建对象
				 dto->id = oatpp::String(result[i][0]);
				 dto->cost_code= oatpp::String(result[i][1]);
				 dto->cost_name = oatpp::String(result[i][2]);
				 dto->cost_type_code = oatpp::String(result[i][3]);
				 if (!service.batchinsertData(dto))
				 {
					 jvo->fail("No file uploaded");
					 return jvo;
				}
		 }
		

	}
	else
	{
		jvo->fail("No file uploaded");
		return jvo;
	}
	////这样就得到了一个dto现在要做的就是把dto转换成do
	
		jvo->success("uploaded file success");
	return jvo;
}