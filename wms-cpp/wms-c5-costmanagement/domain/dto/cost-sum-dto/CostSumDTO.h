#pragma once
#ifndef _COSTSUM_DTO__
#define _COSTSUM_DTO_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class CostSumBaseDTO : public oatpp::DTO
{
	DTO_INIT(CostSumBaseDTO, oatpp::DTO);
	
	DTO_FIELD(String, costdate);
	DTO_FIELD_INFO(costdate) {
		info->description = ZH_WORDS_GETTER("costdate.date");
	}

	DTO_FIELD(String, client);
	DTO_FIELD_INFO(client) {
		info->description = ZH_WORDS_GETTER("client");
	}

	DTO_FIELD(String, clientname);
	DTO_FIELD_INFO(clientname) {
		info->description = ZH_WORDS_GETTER("clientname");
	}
	
	DTO_FIELD(String, cost);
	DTO_FIELD_INFO(cost) {
		info->description = ZH_WORDS_GETTER("cost");
	}
	DTO_FIELD(String, costname);
	DTO_FIELD_INFO(costname) {
		info->description = ZH_WORDS_GETTER("costname");
	}
	DTO_FIELD(String, number);
	DTO_FIELD_INFO(number) {
		info->description = ZH_WORDS_GETTER("number");
	}
	DTO_FIELD(String, unit);
	DTO_FIELD_INFO(unit) {
		info->description = ZH_WORDS_GETTER("unit");
	}
	DTO_FIELD(String, orgprice);
	DTO_FIELD_INFO(orgprice) {
		info->description = ZH_WORDS_GETTER("orgprice");
	}
	DTO_FIELD(String, notax);
	DTO_FIELD_INFO(notax) {
		info->description = ZH_WORDS_GETTER("notax");
	}
	DTO_FIELD(String, tax);
	DTO_FIELD_INFO(tax) {
		info->description = ZH_WORDS_GETTER("tax");
	}
	DTO_FIELD(String, taxprice);
	DTO_FIELD_INFO(taxprice) {
		info->description = ZH_WORDS_GETTER("taxprice");
	}
};

/**
 * 示例分页传输对象
 */
class CostSumListDTO : public CostSumBaseDTO
{
	DTO_INIT(CostSumListDTO, CostSumBaseDTO);
	API_DTO_FIELD_DEFAULT(String, ID, ZH_WORDS_GETTER(" "))
};
class CostSumPageDTO : public PageDTO<CostSumBaseDTO::Wrapper>
{
	DTO_INIT(CostSumPageDTO, PageDTO<CostSumBaseDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // 