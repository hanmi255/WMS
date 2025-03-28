#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: JOHAN LIN
 @Date: 2025/02/21 03:51:00

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

#ifndef _COST_ATTRIBUTE_QUERY_
#define _COST_ATTRIBUTE_QUERY_
#include "domain/query/PageQuery.h"

#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/*
    导出客户计费属性
*/
class ExportCostAttributeQuery : public PageQuery {
    DTO_INIT(ExportCostAttributeQuery, PageQuery);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_COST_ATTRIBUTE_QUERY_