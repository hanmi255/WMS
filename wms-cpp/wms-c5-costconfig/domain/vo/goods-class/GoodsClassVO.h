#pragma once
/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: Ann
 @Date: 2025/2/23 17:45
 
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

#ifndef _GOODCLASSVO_H_
#define _GOODCLASSVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/goods-class/GoodsClassDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 计费商品类名称显示JsonVO，用于响应给客户端的Json对象,就是下拉然后会显示名称
 */
class GoodsClassNameListPageJsonVO : public JsonVO<GoodsClassNameListPageDTO::Wrapper> {

	DTO_INIT(GoodsClassNameListPageJsonVO, JsonVO<GoodsClassNameListPageDTO::Wrapper>);

};
//
/**
 * 示例分页显示计费商品类JsonVO，用于响应给客户端的Json对象
 */
class GoodsClassPageJsonVO : public JsonVO<GoodsClassPageDTO::Wrapper> {
	DTO_INIT(GoodsClassPageJsonVO, JsonVO<GoodsClassPageDTO::Wrapper>);
};




#include OATPP_CODEGEN_END(DTO)
#endif // !_GOODCLASSVO_H_