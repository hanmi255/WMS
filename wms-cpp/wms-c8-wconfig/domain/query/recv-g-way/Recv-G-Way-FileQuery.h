#pragma once
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
#ifndef _MAKE_CARGO_FILE_QUERY_
#define _MAKE_CARGO_FILE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 接货方式查询对象
 */
class Recv_G_WayQuery : public PageQuery
{
	DTO_INIT(Recv_G_WayQuery, PageQuery);
	// 接货方式代码
	DTO_FIELD(String, del_mode_code);
	DTO_FIELD_INFO(del_mode_code) {
		info->description = ZH_WORDS_GETTER("recv-g-way.get.del_mode_code");
	}
	// 接货方式名称
	DTO_FIELD(String, del_mode_name);
	DTO_FIELD_INFO(del_mode_name) {
		info->description = ZH_WORDS_GETTER("recv-g-way.get.del_mode_name");
	}

};

#include OATPP_CODEGEN_END(DTO)
#endif 
