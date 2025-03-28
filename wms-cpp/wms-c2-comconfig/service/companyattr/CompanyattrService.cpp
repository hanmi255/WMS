/*
 @Author: laughter
*/
#include "stdafx.h"
#include "CompanyattrService.h"
#include "../../dao/companyattr/CompanyattrDAO.h"
#include "../../../lib-common/include/SimpleDateTimeFormat.h"
#include <ctime>
#include "../lib-common/include/id/UuidFacade.h"
string Getdate()
{
	std::time_t now = std::time(nullptr);
	std::tm local_time{};

	// 跨平台线程安全处理
#if defined(_WIN32)
	localtime_s(&local_time, &now);
#else
	localtime_r(&now, &local_time);
#endif

	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &local_time);
	return buffer;
}

CompanyattrListPageDTO::Wrapper CompanyattrService::listAll(const CompanyattrQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = CompanyattrListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	CompanyattrDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<CompanyattrDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (CompanyattrDO sub : result)
	{
		auto dto = CompanyattrListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,com_type_code, com_type_Code, com_type_name, com_type_Name);
		pages->addData(dto);
	}
	return pages;
}

uint64_t CompanyattrService::saveData(const CompanyattrListDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 创建生成器
	UuidFacade uf(1);
	SimpleDateTimeFormat time;
	// 组装DO数据
	CompanyattrIdDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,com_type_Code, com_type_code, com_type_Name, com_type_name);
	data.setId(uf.genUuid());
	data.setcreate_Name(payload.getRealname());
	data.setcreate_By(payload.getUsername());
	data.setcreate_Date(time.format());
	data.setsys_org_Code(payload.getOrgcode());
	data.setsys_company_Code(payload.getCompanycode());
	// 执行数据添加
	CompanyattrDAO dao;
	return dao.insert(data);
}
bool CompanyattrService::updateData(const CompanyattrIdListDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	CompanyattrIdDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, com_type_Code, com_type_code, com_type_Name, com_type_name);
	data.setupdate_Name(payload.getRealname());
	data.setupdate_By(payload.getUsername());
	data.setupdate_Date(Getdate());
	data.setsys_org_Code(payload.getOrgcode());
	data.setsys_company_Code(payload.getCompanycode());
	// 执行数据修改
	CompanyattrDAO dao;
	return dao.update(data) == 1;
}
