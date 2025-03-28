#pragma once
#ifndef _COSTSUM_QUERY_
#define _COSTSUM_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class CostSumQuery : public PageQuery
{
	DTO_INIT(CostSumQuery, PageQuery);
	// 姓名
	DTO_FIELD(String, datebegin);
	DTO_FIELD_INFO(datebegin) {
		info->description = ZH_WORDS_GETTER("costdate.begin");
	}
	//验收日期起
	DTO_FIELD(String,dateend);
	DTO_FIELD_INFO(dateend){
		info->description = ZH_WORDS_GETTER("costdate.end");
		}
	DTO_FIELD(String, client);
	DTO_FIELD_INFO(client){
		info->description = ZH_WORDS_GETTER("costdate.client");
		}
	DTO_FIELD(String, clientname);
	DTO_FIELD_INFO(clientname){
		info->description = ZH_WORDS_GETTER("clientname");
		}
	DTO_FIELD(String, cost);
	DTO_FIELD_INFO(cost){
		info->description = ZH_WORDS_GETTER("cost");
		}
	DTO_FIELD(String, costname);
	DTO_FIELD_INFO(costname){
		info->description = ZH_WORDS_GETTER("costname");
		}
};

#include OATPP_CODEGEN_END(DTO)
#endif // 
