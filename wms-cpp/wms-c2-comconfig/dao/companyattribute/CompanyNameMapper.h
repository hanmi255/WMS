#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/03/08 14:44:55

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
#ifndef _COMPANYNAMEMAPPER_
#define _COMPANYNAMEMAPPER_

#include "Mapper.h"
#include "../../domain/do/companyattribute/CompanyNameDO.h"

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class CompanyNameMapper : public Mapper<CompanyNameDO>
{
public:
	CompanyNameDO mapper(ResultSet* resultSet) const override
	{
		CompanyNameDO data;
		data.setId(resultSet->getString(1));
		data.setCode(resultSet->getString(2));
		data.setName(resultSet->getString(3));
		return data;
	}
};

#endif // !_COMPANYNAME_MAPPER_
