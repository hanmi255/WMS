#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: epiphany
 @Date: 2025/3/3 22:14

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
#ifndef _GOODS_CLASS_DO_
#define _GOODS_CLASS_DO_
#include "../DoInclude.h"

/**
 * 对应数据库表ba_goods_class的实体类
 */
class GoodsClassDO
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
	// 计费商品类代码
	CC_SYNTHESIZE(string, goods_class_code, GoodsClassCode);
	// 计费商品类名称
	CC_SYNTHESIZE(string, goods_class_name, GoodsClassName);
public:
	GoodsClassDO() {
		id = "唯一编号,主键";
		create_name = "创建人名称";
		create_by = "创建人登录名称";
		create_date = "创建日期(日期类型)";
		update_name = "更新人名称";
		update_by = "更新人登录名称";
		update_date = "更新日期(日期类型)";
		sys_org_code = "所属部门";
		sys_company_code = "所属公司";
		goods_class_code = "计费商品类代码";
		goods_class_name = "计费商品类名称";
	}
};
// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<GoodsClassDO> PtrGoodsClassDO;
#endif // !_GOODS_CLASS_DO_
