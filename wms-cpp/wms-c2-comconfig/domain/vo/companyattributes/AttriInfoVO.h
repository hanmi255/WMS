#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: killerqueen
 @Date: 2025/2/24 11:00:14

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
#ifndef _ATTRIINFO_VO_
#define _ATTRIINFO_VO_

#include "../../GlobalInclude.h"
#include "../../dto/companyattributes/AttriInfoDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * AttriInfoJsonVO，用于企业属性代码和企业属性名字传给客户端的Json对象
 */
class AttriInfoJsonVO : public JsonVO<AttriInfoJsonDTO::Wrapper> {
	DTO_INIT(AttriInfoJsonVO, JsonVO<AttriInfoJsonDTO::Wrapper>);
};

class AttriDeleteJsonVO : public JsonVO<AttriDeleteInfoDTO::Wrapper> {
	DTO_INIT(AttriDeleteJsonVO, JsonVO<AttriDeleteInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_SAMPLE