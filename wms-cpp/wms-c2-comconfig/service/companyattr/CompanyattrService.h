#pragma once
/*
 @Author: laughter
*/
#ifndef _COMPANYATTR_SERVICE_
#define _COMPANYATTR_SERVICE_
#include <list>
#include"domain/query/companyattr/CompanyattrQuery.h"
#include"domain/vo/companyattr/CompanyattrVO.h"
#include"domain/dto/companyattr/CompanyattrDTO.h"
/*
* 企业属性分页查询，新增和修改服务实现
*/
class CompanyattrService
{
public:
	// 分页查询所有数据
	CompanyattrListPageDTO::Wrapper listAll(const CompanyattrQuery::Wrapper& query);
	// 保存数据
	uint64_t saveData(const CompanyattrListDTO::Wrapper& dto, const PayloadDTO& payload);
	//增添数据
	bool updateData(const CompanyattrIdListDTO::Wrapper& dto, const PayloadDTO& payload);
};


#endif // !_COMPANYATTR_SERVICE_
