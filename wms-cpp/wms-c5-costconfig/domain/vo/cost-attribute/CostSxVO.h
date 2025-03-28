#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: wrzljrj
 @Date: 2025/02/22 17:47:56

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
#ifndef _COSTSX_VO_
#define _COSTSX_VO_

#include "../../GlobalInclude.h"
#include "../../dto/cost-attribute/CostSxDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 客户计费属性名称显示JsonVO，用于响应给客户端的Json对象,就是下拉然后会显示名称
 */
class CostSxNameListPageJsonVO : public JsonVO<CostSxNameListPageDTO::Wrapper> {
	
	DTO_INIT(CostSxNameListPageJsonVO, JsonVO<CostSxNameListPageDTO::Wrapper>);
	
};
//
/**
 * 示例分页显示客户计费属性JsonVO，用于响应给客户端的Json对象
 */
class CostSxPageJsonVO : public JsonVO<CostSxPageDTO::Wrapper> {
	DTO_INIT(CostSxPageJsonVO, JsonVO<CostSxPageDTO::Wrapper>);
};
//
#include OATPP_CODEGEN_END(DTO)

#endif // !_COSTSX_VO_