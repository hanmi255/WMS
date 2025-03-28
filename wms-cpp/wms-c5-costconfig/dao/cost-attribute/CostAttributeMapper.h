#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: wrzljrj
 @Date: 2025/02/26 18:56:54

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
#ifndef _COST_ATTRIBUTE_MAPPER_
#define _COST_ATTRIBUTE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/cost-attribute/CostAttributeDO.h"

/**
 * 部分字段匹配映射
 */
class CostAttributeMapperName : public Mapper<CostSxDO>
{
public:
	CostSxDO mapper(ResultSet* resultSet) const override
	{
		CostSxDO data;
		data.setId(resultSet->getString(1));
		data.setName(resultSet->getString(2));
		return data;
	}
};


class CostAttributeMapperAll : public Mapper<CostSxDO>
{
public:
	CostSxDO mapper(ResultSet* resultSet) const override
	{
		CostSxDO data;
		data.setId(resultSet->getString(1));
		data.setCode(resultSet->getString(2));
		data.setName(resultSet->getString(3));
		data.setCreateName(resultSet->getString(4));
		data.setCreateBy(resultSet->getString(5));
		data.setUpdateName(resultSet->getString(6));
		data.setUpdateBy(resultSet->getString(7));
		data.setSysOrgCode(resultSet->getString(8));
		data.setSysCompanyCode(resultSet->getString(9));
		data.setCreateDate(resultSet->getString(10));
		data.setUpdateDate(resultSet->getString(11));
		return data;
	}
};


///**
// * 示例部分字段匹配映射-返回指针类型
// */
//class PtrSampleMapper : public Mapper<PtrSampleDO>
//{
//public:
//	PtrSampleDO mapper(ResultSet* resultSet) const override
//	{
//		auto data = std::make_shared<SampleDO>();
//		data->setId(resultSet->getUInt64(1));
//		data->setName(resultSet->getString(2));
//		data->setSex(resultSet->getString(3));
//		data->setAge(resultSet->getInt(4));
//		return data;
//	}
//};
class ExportCostAttributeMapper : public Mapper<CostAttributeDO>
{
public:
	CostAttributeDO mapper(ResultSet* resultSet) const override
	{
		CostAttributeDO data;
		data.setKeHuShuXingCode(resultSet->getString(1));
		data.setKeHuShuXingName(resultSet->getString(2));
		return data;
	}
};

#endif // !_COST_ATTRIBUTE_MAPPER_