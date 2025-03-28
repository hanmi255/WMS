#pragma once

#ifndef _COST_DTO_
#define _COST_DTO_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 费用明细基础响应对象   dto这里相当于响应字段
 */
class CostDetailBaseDTO : public oatpp::DTO
{
	DTO_INIT(CostDetailListPageDTO, DTO);

	// 唯一ID
	API_DTO_FIELD_DEFAULT(String, id , ZH_WORDS_GETTER("cost.field.id"));

	// 客户编码
	API_DTO_FIELD_DEFAULT(String, cus_code, ZH_WORDS_GETTER("cost.field.cus_code"));

	// 客户名称
	API_DTO_FIELD_DEFAULT(String, cus_name, ZH_WORDS_GETTER("cost.field.cus_name"));

	// 费用编码
	API_DTO_FIELD_DEFAULT(String, cost_code, ZH_WORDS_GETTER("cost.field.cost_code"));

	// 费用名称
	API_DTO_FIELD_DEFAULT(String, cost_name, ZH_WORDS_GETTER("cost.field.cost_name"));

	// 费用日期
	API_DTO_FIELD_DEFAULT(String, cost_data, ZH_WORDS_GETTER("cost.field.cost_data"));

	// 费用来源
	API_DTO_FIELD_DEFAULT(String, cost_ori, ZH_WORDS_GETTER("cost.field.cost_ori"));

	// 备注
	API_DTO_FIELD_DEFAULT(String, beizhu, ZH_WORDS_GETTER("cost.field.beizhu"));

	// 状态
	API_DTO_FIELD_DEFAULT(String, cost_sta, ZH_WORDS_GETTER("cost.field.cost_sta"));

	// 创建人名
	API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("cost.field.create_name"));

	//创建日期
	API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("cost.field.create_date"));

	// 更新人名
	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("cost.field.update_name"));

	// 原价
	API_DTO_FIELD_DEFAULT(String, cost_yj, ZH_WORDS_GETTER("cost.field.cost_yj"));

	// 不含税价
	API_DTO_FIELD_DEFAULT(String, cost_bhs, ZH_WORDS_GETTER("cost.field.cost_bhs"));

	// 税额
	API_DTO_FIELD_DEFAULT(String, cost_se, ZH_WORDS_GETTER("cost.field.cost_se"));

	// 含税价
	API_DTO_FIELD_DEFAULT(String, cost_hsj, ZH_WORDS_GETTER("cost.field.cost_hsj"));

	// 计费数量
	API_DTO_FIELD_DEFAULT(String, cost_sl, ZH_WORDS_GETTER("cost.field.cost_sl"));

	// 数量单位
	API_DTO_FIELD_DEFAULT(String, cost_unit, ZH_WORDS_GETTER("cost.field.cost_unit"));

	// 是否结算
	API_DTO_FIELD_DEFAULT(String, cost_js, ZH_WORDS_GETTER("cost.field.cost_js"));


};


/**
 * 费用明细录入响应对象   dto这里相当于响应字段
 */
class CostDetailAddDTO : public CostDetailBaseDTO
{
	DTO_INIT(CostDetailAddDTO, CostDetailBaseDTO);

	// ..............

};


/**
 * 费用明细列表分页传输对象
 */
class CostDetailListPageDTO : public PageDTO<CostDetailBaseDTO::Wrapper>
{
	DTO_INIT(CostDetailListPageDTO, PageDTO<CostDetailBaseDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)
#endif // !_COST_DTO_

