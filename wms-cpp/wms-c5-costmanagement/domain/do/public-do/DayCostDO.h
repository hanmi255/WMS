#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: epiphany
 @Date: 2025/3/3 20:53

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
#ifndef _DAY_COST_DO_
#define _DAY_COST_DO_
#include "../DoInclude.h"

/**
 * 对应数据库表wm_day_cost的实体类
 */
class DayCostDO
{
	// 唯一编号,主键
	CC_SYNTHESIZE(string, id, Id);
	// 创建人名称
	CC_SYNTHESIZE(string, create_name, CreateName);
	// 创建人登录名称
	CC_SYNTHESIZE(string, create_by, CreateBy);
	// 创建日期(日期类型)
	CC_SYNTHESIZE(string, create_date, CreateDate);
	// 更新人名称
	CC_SYNTHESIZE(string, update_name, UpdateName);
	// 更新人登录名称
	CC_SYNTHESIZE(string, update_by, UpdateBy);
	// 更新日期(日期类型)
	CC_SYNTHESIZE(string, update_date, UpdateDate);
	// 所属部门
	CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
	// 所属公司
	CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);
	// 客户编码
	CC_SYNTHESIZE(string, cus_code, CusCode);
	// 客户名称
	CC_SYNTHESIZE(string, cus_name, CusName);
	// 费用编码
	CC_SYNTHESIZE(string, cost_code, CostCode);
	// 费用名称
	CC_SYNTHESIZE(string, cost_name, CostName);
	// 费用日期(日期类型)
	CC_SYNTHESIZE(string, cost_date, CostDate);
	// 每日费用(原价)
	CC_SYNTHESIZE(string, day_cost_yj, DayCostYj);
	// 不含税价
	CC_SYNTHESIZE(string, day_cost_bhs, DayCostBhs);
	// 税额
	CC_SYNTHESIZE(string, day_cost_se, DayCostSe);
	// 含税价
	CC_SYNTHESIZE(string, day_cost_hsj, DayCostHsj);
	// 费用来源
	CC_SYNTHESIZE(string, cost_ori, CostOri);
	// 备注
	CC_SYNTHESIZE(string, beizhu, BeiZhu);
	// 状态
	CC_SYNTHESIZE(string, cost_sta, CostSta);
	// 计费数量
	CC_SYNTHESIZE(string, cost_sl, CostSl);
	// 数量单位
	CC_SYNTHESIZE(string, cost_unit, CostUnit);
	// 是否已结算
	CC_SYNTHESIZE(string, cost_js, CostJs);
public:
	DayCostDO() {
		id = "唯一编号,主键";
		create_name = "创建人名称";
		create_by = "创建人登录名称";
		create_date = "创建日期(日期类型)";
		update_name = "更新人名称";
		update_by = "更新人登录名称";
		update_date = "更新日期(日期类型)";
		sys_org_code = "所属部门";
		sys_company_code = "所属公司";
		cus_code = "客户编码";
		cus_name = "客户名称";
		cost_code = "费用编码";
		cost_name = "费用名称";
		cost_date = "费用日期(日期类型)";
		day_cost_yj = "每日费用";
		day_cost_bhs = "不含税价";
		day_cost_se = "税额";
		day_cost_hsj = "含税价";
		cost_ori = "费用来源";
		beizhu = "备注";
		cost_sta = "状态";
		cost_sl = "计费数量";
		cost_unit = "数量单位";
		cost_js = "是否已结算";
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<DayCostDO> PtrDayCostDO;

#endif // !_DAY_COST_DO_
