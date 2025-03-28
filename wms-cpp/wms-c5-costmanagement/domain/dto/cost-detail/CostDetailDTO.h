#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: epiphany
 @Date: 2025/2/27 22:17

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef _COST_DETAIL_DTO_
#define _COST_DETAIL_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//用于新增的DTO,包含添加数据需要的属性
class CostAddDTO : public oatpp::DTO
{
	DTO_INIT(CostAddDTO, DTO);
	// 客户
	DTO_FIELD(String, client);
	DTO_FIELD_INFO(client) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.client");
	}
	// 费用(编码)
	DTO_FIELD(String, cost);
	DTO_FIELD_INFO(cost) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.cost");
	}
	// 费用日期
	DTO_FIELD(String, costdate);
	DTO_FIELD_INFO(costdate) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.costdate");
	}
	//原价
	DTO_FIELD(String, oldprice);
	DTO_FIELD_INFO(oldprice) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.oldprice");
	}
	//不含税价
	DTO_FIELD(String, notax);
	DTO_FIELD_INFO(notax) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.notax");
	}
	//税额
	DTO_FIELD(String, tax);
	DTO_FIELD_INFO(tax) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.tax");
	}
	//含税价
	DTO_FIELD(String, taxprice);
	DTO_FIELD_INFO(taxprice) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.taxprice");
	}
	//费用来源
	DTO_FIELD(String, source);
	DTO_FIELD_INFO(source) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.source");
	}
	//备注
	DTO_FIELD(String, remark);
	DTO_FIELD_INFO(remark) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.remark");
	}
	//状态
	DTO_FIELD(String, state);
	DTO_FIELD_INFO(state) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.state");
	}
	//计费数量
	DTO_FIELD(String, count);
	DTO_FIELD_INFO(count) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.count");
	}
	//数量单位
	DTO_FIELD(String, unit);
	DTO_FIELD_INFO(unit) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.unit");
	}
};
//用于导出的DTO,包含导出到excel需要的属性
class CostExportDTO :public CostAddDTO
{
	DTO_INIT(CostExportDTO, CostAddDTO);
	//创建人
	DTO_FIELD(String, creator);
	DTO_FIELD_INFO(creator) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.creator");
	}
	//创建日期
	DTO_FIELD(String, createdate);
	DTO_FIELD_INFO(createdate) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.createdate");
	}
	//更新人
	DTO_FIELD(String, updater);
	DTO_FIELD_INFO(updater) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.updater");
	}
	//更新日期
	DTO_FIELD(String, updatedate);
	DTO_FIELD_INFO(updatedate) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.updatedate");
	}
	//客户名称
	DTO_FIELD(String, clientname);
	DTO_FIELD_INFO(clientname) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.clientname");
	}
	//费用名称
	DTO_FIELD(String, costname);
	DTO_FIELD_INFO(costname) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.costname");
	}
	//结算状态
	DTO_FIELD(String, status);
	DTO_FIELD_INFO(status) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.status");
	}
	//创建人登录名称(从payload读取)
	DTO_FIELD(String, create_by);
	DTO_FIELD_INFO(create_by) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.create-by");
	}
	//所属部门(从payload读取)
	DTO_FIELD(String, org_code);
	DTO_FIELD_INFO(org_code) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.org-code");
	}
	//所属公司(从payload读取)
	DTO_FIELD(String, company_code);
	DTO_FIELD_INFO(company_code) {
		info->description = ZH_WORDS_GETTER("cost-detail.field.company-code");
	}
};
#include OATPP_CODEGEN_END(DTO)
#endif // !_COST_DETAIL_DTO_