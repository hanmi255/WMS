#pragma once
/*
 @Author: gutianxuan
*/
#ifndef _TEMPERATURE_QUERY_
#define _TEMPERATURE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 温度属性分页查询对象
 */
class TemperatureQuery : public PageQuery
{
	DTO_INIT(TemperatureQuery, PageQuery);

	// 温层代码
	API_DTO_FIELD_DEFAULT(String, deg_type_code, ZH_WORDS_GETTER("reposity.temperature.field.deg_type_code"));

	// 温层名称
	API_DTO_FIELD_DEFAULT(String, deg_type_name, ZH_WORDS_GETTER("reposity.temperature.field.deg_type_name"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TEMPERATURE_QUERY_