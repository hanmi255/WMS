#pragma once
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
#ifndef _DOWNGOODS_VO_
#define _DOWNGOODS_VO_

#include "../../GlobalInclude.h"
#include "../../dto/batch-modify-goods/DownGoodsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 批量修改下架货物模块数据显示JsonVO，用于响应给客户端的Json对象
 */
class DownGoodsJsonVO : public JsonVO<DownGoodsDTO::Wrapper> {
	DTO_INIT(DownGoodsJsonVO, JsonVO<DownGoodsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DOWNGOODS_VO_