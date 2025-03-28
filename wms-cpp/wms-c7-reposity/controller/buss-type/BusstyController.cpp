
#include "stdafx.h"
#include "BusstyController.h"
#include "../wms-c7-reposity/service/BusstyService.h"

Uint64JsonVO::Wrapper BusstyController::execDelOne(const UInt64& id)
{
	auto jvo = Uint64JsonVO::createShared();
	if (!id || id <= 0)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	BusstyService service;
	if (service.removeData(id.getValue(0))) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	return jvo;
}
Uint64JsonVO::Wrapper BusstyController::execDelPart(Vector<UInt64> ID)
{
	// 定义返回数据对象

	auto jvo = Uint64JsonVO::Wrapper::createShared();
	// 参数校验
	int i = 0;
	while(i<ID->size())
	{
		// 定义一个Service
		BusstyService service;
		if (!ID[i] || ID[i] <= 0)
		{
			jvo->init(UInt64(-1), RS_PARAMS_INVALID);

			return jvo;
		}
		if (service.removedata((ID->at(i).getValue(0)))) {
			jvo->success(ID[i]);
		}
		else
		{
			jvo->fail(ID[i]);
			return jvo;
		}
		i++;
	}
	// 响应结果
	return jvo;
}

StringJsonVO::Wrapper BusstyController::execLeadIn(std::shared_ptr<IncomingRequest> request)
{
	auto jvo = StringJsonVO::createShared();
	
	API_MULTIPART_INIT(container, reader);
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	request->transferBody(&reader);
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	
	string filename = partfile->getFilename().getValue("");
	string fullPath = "public/static/file/" + filename;
	std::vector<std::vector<std::string>> data = ExcelComponent::readIntoVector(fullPath, ZH_WORDS_GETTER("excel.sheet.s1"));

	BusstyService service;
	while(data.size()>1)
	{
		std::vector<std::string> v = data.back();
		service.leadin(v);
		data.pop_back();
	}
	jvo->success("OK");
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> BusstyController::execLeadOut(String filename)
{
	BusstyService service;
	std::list l=service.leadout();
	l.reverse();

	ExcelComponent excel;
	std::string info = ZH_WORDS_GETTER("excel.content.info");

	std::vector<std::vector<std::string>> data;
	data.insert(data.begin(), {
		ZH_WORDS_GETTER("tylead.num") ,
		ZH_WORDS_GETTER("tylead.name") ,
		ZH_WORDS_GETTER("tylead.desc") ,
		});
	while(l.size()>0)
	{
		std::vector<std::string> row;
		row.push_back(l.back().getNum());
		row.push_back(l.back().getName());
		row.push_back(l.back().getDesc());
		data.push_back(row);
		l.pop_back();
	}
	
	std::string fullPath = "public/static/" + URIUtil::urlDecode(filename.getValue(""));
	excel.writeVectorToFile(fullPath, ZH_WORDS_GETTER("excel.sheet.s1"), data);
	auto fstring = String::loadFromFile(fullPath.c_str());
	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);
	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=" + filename.getValue(""));
	// 影响成功结果
	return response;
}