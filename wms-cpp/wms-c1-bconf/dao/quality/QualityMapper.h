#pragma once
/*
 @Author: S4turday
 @Date: 2025年3月8日15:53:46

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
#ifndef _QUALITY_MAPPER_
#define _QUALITY_MAPPER_

#include "Mapper.h"
#include "domain/do/quality/QualityDO.h"

/*
 @Author: S4turday
 @Date: 2025年3月8日19:24:15

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

/**
 * 品质代码字段匹配映射
 */
class QualityMapper : public Mapper<QualityDO>
{
public:
	QualityDO mapper(ResultSet* resultSet) const override
	{
		QualityDO data;
		data.setId(resultSet->getString("id"));
		data.setName(resultSet->getString("qm_qa_name"));
		data.setCode(resultSet->getString("qm_qa_code"));
		return data;
	}
};

/**
 * 品质代码字段匹配映射-创建智能指针对象
 */
class PtrQualityMapper : public Mapper<PtrQualityDO>
{
public:
	PtrQualityDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<QualityDO>();
		data->setId(resultSet->getString("id"));
		data->setName(resultSet->getString("qm_qa_name"));
		data->setCode(resultSet->getString("qm_qa_code"));
		return data;
	}
};

#endif // !_QUALITY_MAPPER_