#include "stdafx.h"
#include "SexCodeController.h"

#include <iostream>
#include "SqlSession.h"
#include "list"
#include "domain/do/sex/SexDO.h"
#include "dao/SexMapper.h"
#include "ExcelComponent.h"
#include "SimpleDateTimeFormat.h"


namespace fs = std::filesystem;

StuCodePageJsonVO::Wrapper SexCodeController::execQueryStucode(StuCodeQuery::Wrapper& stucodeQuery)
{
	StuCodeService service;
	auto result = service.listAll(stucodeQuery);
	auto jvo = StuCodePageJsonVO::createShared();
	jvo->success(result);
	return jvo;

}

StringJsonVO::Wrapper SexCodeController::execModifyStucode(const StuCodeDTO::Wrapper& stucodeDto, const PayloadDTO& payload)
{
	StuCodeService service;
	auto jvo = StringJsonVO::createShared();
	if (!stucodeDto->name || stucodeDto->name->empty() || !stucodeDto->code || stucodeDto->code->empty())
	{
		jvo->fail("");
		return jvo;
	}
	auto result = service.updateStuCode(stucodeDto, payload);

	if (result)
	{
		jvo->success("success");
	}
	else
	{
		jvo->fail("failed");
	}
	return jvo;
}

StringJsonVO::Wrapper SexCodeController::execSetStucode(const StuCodeDTO::Wrapper& stucodeDto, const PayloadDTO& payload)
{
	StuCodeService service;
	auto jvo = StringJsonVO::createShared();
	if (!stucodeDto->name || stucodeDto->name->empty() || !stucodeDto->code || stucodeDto->code->empty())
	{
		jvo->fail("");
		return jvo;
	}
	auto result = service.setStuCode(stucodeDto, payload);

	if (result)
	{
		jvo->success("success");
	}
	else
	{
		jvo->fail("failed");
	}
	return jvo;
}

StringJsonVO::Wrapper SexCodeController::execDelStucode(const StuCodeDelDTO::Wrapper& stucodeDto)
{
	StuCodeService service;
	auto jvo = StringJsonVO::createShared();
	if (!stucodeDto->delList || stucodeDto->delList->empty())
	{
		jvo->fail("");
		return jvo;
	}

	auto result = service.setDelCode(stucodeDto);

	if (result)
	{
		jvo->success("success");
	}
	else
	{
		jvo->fail("failed");
	}
	return jvo;
}

StringJsonVO::Wrapper SexCodeController::execUploadOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload)
{

	//1 初始化
	API_MULTIPART_INIT(container, reader);

	// 2 配置读取器
	API_MULTIPART_CONFIG_MEMO_DEFAULT(reader, -1);
	// 3 读取数据
	request->transferBody(&reader);
	/* 获取文件数据 */
	API_MULTIPART_PARSE_FILE_FIELD(container, "file", file);
	// 从文件中读取
	auto jvo = StringJsonVO::createShared();
	if (file)
	{
		auto readData = ExcelComponent::readIntoVector(file->data(), file->size(), "Sheet1");
		auto time = SimpleDateTimeFormat::format();
		auto name = payload.getUsername();
		auto by = payload.getRealname();
		auto org = payload.getOrgcode();
		auto company = payload.getCompanycode();
		SqlSession sqlsession;
		for (auto row : readData)
		{
			std::vector<string> temp(3, "");
			int i = 0;
			for (auto cellVal : row)
			{
				temp[i] = cellVal;
				i++;
			}
			string sql = "INSERT INTO `ba_sex_sta` (`id`, `create_name`,`create_by`,`create_date`,`update_name`,`update_by`,`update_date`,`sys_org_code`,`sys_company_code`,`sex_sta_code`, `sex_sta_name`) VALUES(?, ?, ?,?,?,?,?,?,?,?,?)";
			auto ch = sqlsession.executeInsert(sql, "%s%s%s%s%s%s%s%s%s%s%s", temp[0], name, by, time, name, by, time, org, company, temp[1], temp[2]);
			if (ch < 0)
			{
				jvo->success("fail");
				return jvo;
			}
		}
	}

	jvo->success("OK");
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> SexCodeController::execDownloadFile()
{
	// 构建文件全路径
	std::string fullPath = "public/static/file/xlsx";
	//获取数据库数据
	SqlSession sqlsession;
	// 查询数据
	SqlParams params;
	string sql = "SELECT id,sex_sta_code,sex_sta_name FROM ba_sex_sta ";
	SexMapper mapper;
	list<SexDO> lres = sqlsession.executeQuery<SexDO>(sql, mapper);
	//数据库数据存入二维数组
	std::vector<std::vector<std::string>> chvec;
	for (auto chl : lres)
	{
		std::vector<string> vec;
		vec.push_back(chl.getId());
		vec.push_back(chl.getSexCode());
		vec.push_back(chl.getSexName());
		chvec.push_back(vec);
	}

	//将Excle数据导入到String中
	ExcelComponent excel;
	auto buff = excel.writeVectorToBuff(ZH_WORDS_GETTER("test"), chvec);
	const char* data = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(data, buff.size());

	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=sex.xlsx");

	// 影响成功结果
	return response;
}