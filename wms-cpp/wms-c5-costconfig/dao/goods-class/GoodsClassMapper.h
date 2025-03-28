#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: Ann
 @Date: 2025/3/5 15:56
 
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
#ifndef _GOODSCLASS_MAPPER_
#define _GOODSCLASS_MAPPER_

#include "Mapper.h"
#include "../../domain/do/public-do/GoodsClassDO.h"

/**
 * 表字段匹配映射
 */
class GoodsClassMapperName : public Mapper<GoodsClassDO>
{
public:
	GoodsClassDO mapper(ResultSet* resultSet) const override
	{
		GoodsClassDO data;
		data.setId(resultSet->getString(1));
		data.setGoodsClassName(resultSet->getString(2));


		return data;
	}
};


class GoodsClassMapperAll : public Mapper<GoodsClassDO>
{
public:
	GoodsClassDO mapper(ResultSet* resultSet) const override
	{
		GoodsClassDO data;
		data.setId(resultSet->getString(1));
		data.setGoodsClassName(resultSet->getString(2));
		data.setGoodsClassCode(resultSet->getString(3));
		data.setCreateName(resultSet->getString(4)); // 创建人名称
		data.setCreateBy(resultSet->getString(5)); // 创建人登录名称
		data.setUpdateName(resultSet->getString(6)); // 更新人名称
		data.setUpdateBy(resultSet->getString(7)); // 更新人登录名称
		data.setSysOrgCode(resultSet->getString(8)); // 所属部门 
		data.setSysCompanyCode(resultSet->getString(9)); // 所属公司
		data.setCreateDate(resultSet->getString(10)); // 创建日期
		data.setUpdateDate(resultSet->getString(11)); // 更新日期

		return data;
	}
};


#endif // !_GOODSCLASS_MAPPER_