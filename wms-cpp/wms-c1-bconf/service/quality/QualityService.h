#pragma once

/*
 @Author: S4turday
 @Date: 2025年3月8日16:13:57

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

#ifndef _QUALITY_SERVICE_
#define _QUALITY_SERVICE_
#include <list>
#include "domain/vo/quality/QualityVO.h"
#include "domain/query/quality/QualityQuery.h"
#include "domain/dto/quality/QualityDTO.h"



class QualityService {
public:
	// 分页 + 条件查询数据
	QualityPageDTO::Wrapper getData(const QualityQuery::Wrapper& query);
	QualityDetailDTO::Wrapper getByCode(const string& code);
	QualityDetailDTO::Wrapper getByName(const string& name);
	bool InsertData(const QualityAddDTO::Wrapper& dto, const PayloadDTO& payload);
	bool updateData(const QualityListDTO::Wrapper& dto, const PayloadDTO& payload);
	// 
};

#endif // !_QUALITY_SERVICE_