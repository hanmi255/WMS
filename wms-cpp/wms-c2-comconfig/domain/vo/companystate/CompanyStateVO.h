#pragma once
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: fycc
 @Date: 2025/2/22 20:45:06

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
#ifndef _COMPANYSTATE_VO_
#define _COMPANYSTATE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/companystate/CompanyStateDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 企业录入信息后的JsonVO，用于在主页面显示新录入的公司信息
 */
class CompanyStateJsonVO : public JsonVO<CompanyStateDTO::Wrapper> {
	DTO_INIT(CompanyStateJsonVO, JsonVO<CompanyStateDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif