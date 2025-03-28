#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: tudou
 @Date: 2022/10/25 11:36:29

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
#ifndef _DELETE_DTO_
#define _DELETE_DTO_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 计费方式查询对象
 */
class DeleteDTO : public oatpp::DTO
{
	DTO_INIT(DeleteDTO, oatpp::DTO);
	// 计费方式id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("coway.id");
	}
	// 计费方式编码
	DTO_FIELD(String, pronut_code);
	DTO_FIELD_INFO(pronut_code) {
		info->description = ZH_WORDS_GETTER("Costconfig.way.code");
	}
	// 编号
	DTO_FIELD(String, pronut_name);
	DTO_FIELD_INFO(pronut_name) {
		info->description = ZH_WORDS_GETTER("Costconfig.way.name");
	}
	
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_DeleteDTO_QUERY_