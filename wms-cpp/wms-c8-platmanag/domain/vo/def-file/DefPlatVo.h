#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: maomao
 @Date: 2025/2/24 10:38:50

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
#ifndef _DEFDEL_VO_
#define _DEFDEL_VO_

#include "../../GlobalInclude.h"

#include "../../dto/def-file/DefPlatDto.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 月台定义-月台删除功能JsonVO，用于响应给客户端的Json对象
 */
class DefDelJsonVO : public JsonVO<DefDelDto::Wrapper> {
	DTO_INIT(DefDelJsonVO, JsonVO<DefDelDto::Wrapper>);
};
/**
 * 月台定义-月台修改功能JsonVO，用于响应给客户端的Json对象
 */
class DefEditJsonVO : public JsonVO<DefEditDto::Wrapper> {
	DTO_INIT(DefEditJsonVO, JsonVO<DefEditJsonVO::Wrapper>);
};/**
 * 月台定义-月台导出功能JsonVO，用于响应给客户端的Json对象
 */
class DefPutJsonVO : public JsonVO<DefPutDto::Wrapper> {
	DTO_INIT(DefPutJsonVO, JsonVO<DefPutDto::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif // _DEFDEL_VO_