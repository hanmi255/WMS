#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 圣少游
 @Date: 2025/2/22 11:36:29

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
#ifndef _MOVINGBIN_VO_
#define _MOVINGBIN_VO_

#include "../../GlobalInclude.h"
#include "../../dto/moving-bin/MovingBinDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 动仓盘点数据显示JsonVO，用于响应给客户端的Json对象
 */
class MovingBinJsonVO : public JsonVO<MovingBinListDTO::Wrapper> {
	DTO_INIT(MovingBinJsonVO, JsonVO<MovingBinListDTO::Wrapper>);
};

/**
 * 动仓盘点分页显示JsonVO，用于响应给客户端的Json对象
 */
class MovingBinPageJsonVO : public JsonVO<MovingBinPageDTO::Wrapper> {
	DTO_INIT(MovingBinPageJsonVO, JsonVO<MovingBinPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_MOVINGBIN_VO_