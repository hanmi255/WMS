#pragma once
#ifndef _COST_DTO_
#define _COST_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


//费用类型
class CostBaseDto : public oatpp::DTO
{
	DTO_INIT(CostBaseDto, DTO);
	DTO_FIELD(UInt64, id)= 1;//主键
};
class GetCostDTO : public CostBaseDto
{
	DTO_INIT(GetCostDTO, CostBaseDto);
	DTO_FIELD(String, cost_code);//费用代码
	DTO_FIELD(String, cost_name);//费用名称
	DTO_FIELD(String, cost_type);//费用类型
	DTO_FIELD(String, create_name);//创建者名称
	DTO_FIELD(String, create_date);//创建时间
};
class CostListDTO : public CostBaseDto
{
	
	DTO_INIT(CostListDTO, CostBaseDto);
	DTO_FIELD(String, cost_code)= "12345";//费用代码
	DTO_FIELD(String, cost_name)= "other";//费用名称
	DTO_FIELD(String, cost_type) = "othercost";//费用类型
	DTO_FIELD(String, create_name) = "Li";//创建者名称
	DTO_FIELD(String, create_date) = "2024-9-13-09-13-45";//创建时间
	DTO_FIELD(String, update_name) = "Li";//修改名称
	DTO_FIELD(String, update_date) = "2024-9-14-09-13-45";//修改时间
};
//录取费用类型

//修改费用类型
class ModifyCostDTO : public CostBaseDto
{
	
	DTO_INIT(ModifyCostDTO, CostBaseDto);
	DTO_FIELD(String, cost_code) = "12345";//费用代码
	DTO_FIELD(String, cost_name) = "other";//费用名称
	DTO_FIELD(String, cost_type) = "othercost";//费用类型
	DTO_FIELD(String, update_name) = "Li";//修改名称
	DTO_FIELD(String, update_date) = "2024-9-13-09-13-45";//修改时间
};

//分页数据对象
class CostListPageDTO : public PageDTO<CostListDTO::Wrapper>
{
	DTO_INIT(CostListPageDTO, PageDTO<CostListDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_COST_DTO_