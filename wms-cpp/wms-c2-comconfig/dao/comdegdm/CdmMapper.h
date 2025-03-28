#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: mzylq
 @Date: 2025/2/23 22:21:34

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
#ifndef _CDMMAPPER_
#define _CDMMAPPER_

#include "Mapper.h"
#include "../../domain/do/comdegdm/CdmDO.h"

/**
 * 示例表字段匹配映射
 */
class CdmMapper : public Mapper<CdmDO>
{
public:
	CdmDO mapper(ResultSet* resultSet) const override
	{
		CdmDO data;
		data.setId(resultSet->getString(1));
		data.setCname(resultSet->getString(2));
		data.setCby(resultSet->getString(3));
		data.setCdate(resultSet->getString(4));
		data.setUname(resultSet->getString(5));
		data.setUby(resultSet->getString(6));
		data.setUdate(resultSet->getString(7));
		data.setSoc(resultSet->getString(8));
		data.setScc(resultSet->getString(9));
		data.setCdn(resultSet->getString(10));
		data.setCdd(resultSet->getString(11));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
//class PtrCompanyInfoMapper : public Mapper<PtrCompanyInfoDO>
//{
//public:
//	PtrCompanyInfoDO mapper(ResultSet* resultSet) const override
//	{
//		auto data = std::make_shared<CompanyInfoDO>();
//		data->setId(resultSet->getString(1));
//		data->setZhAbbr(resultSet->getString(2));
//		data->setZhFul(resultSet->getString(3));
//		data->setZhAddr(resultSet->getString(4));
//		data->setEnAbbr(resultSet->getString(5));
//		data->setEnFul(resultSet->getString(6));
//		data->setCompanyId(resultSet->getString(7));
//		return data;
//	}
// };

#endif //_CDM_MAPPER_