#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 14:21:55

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
#ifndef _COMPANYINFOMAPPER_
#define _COMPANYINFOMAPPER_

#include "Mapper.h"
#include "../../domain/do/company-conf/CompanyInfoDO.h"

/**
 * 示例表字段匹配映射
 */
class CompanyInfoMapper : public Mapper<CompanyInfoDO>
{
public:
	CompanyInfoDO mapper(ResultSet* resultSet) const override
	{
		CompanyInfoDO data;
		data.setCode(resultSet->getString(1));
		data.setZh_name(resultSet->getString(2));
		data.setZh_aname(resultSet->getString(3));
		data.setZh_addr(resultSet->getString(4));
		data.setEn_name(resultSet->getString(5));
		data.setEn_aname(resultSet->getString(6));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrCompanyInfoMapper : public Mapper<PtrCompanyInfoDO>
{
public:
	PtrCompanyInfoDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<CompanyInfoDO>();
		data->setCode(resultSet->getString(1));
		data->setZh_name(resultSet->getString(2));
		data->setZh_aname(resultSet->getString(3));
		data->setZh_addr(resultSet->getString(4));
		data->setEn_name(resultSet->getString(5));
		data->setEn_aname(resultSet->getString(6));
		return data;
	}
};

#endif // !_SAMPLE_MAPPER_