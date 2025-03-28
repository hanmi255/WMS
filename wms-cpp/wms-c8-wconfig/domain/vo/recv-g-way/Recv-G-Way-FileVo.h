
#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 猫头大蒜
 @Date: 2025/03/10 16:09:12

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.ations under the License.
*/
#ifndef _Recv_G_Way_VO_
#define _Recv_G_Way_VO_

#include "../../GlobalInclude.h"
#include "../../dto/recv-g-way/Recv-G-WayFileDto.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class Recv_G_WayEditJsonVO : public JsonVO<Recv_G_WayEditDto::Wrapper> {
	DTO_INIT(Recv_G_WayEditJsonVO, JsonVO<Recv_G_WayEditDto::Wrapper>);
};
//**
/**
 * 接货查询详情JsonVO，用于响应给客户端的Json对象
 */
class Recv_G_WayAllJsonVO : public JsonVO<Recv_G_WayAllDto::Wrapper> {
	DTO_INIT(Recv_G_WayAllJsonVO, JsonVO<Recv_G_WayAllDto::Wrapper>);
};

//class EditorImageVO : public JsonVO<EditorImageDTO::Wrapper>
//{
//	DTO_INIT(EditorImageVO, JsonVO<EditorImageDTO::Wrapper>);
//};
//
class EditorImageVO : public JsonVO<EditorImageDTO::Wrapper>
{
	DTO_INIT(EditorImageVO, JsonVO<EditorImageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif //!_Recv_G_Way_V