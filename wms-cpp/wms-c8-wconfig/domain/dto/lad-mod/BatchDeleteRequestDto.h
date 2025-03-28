#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: surpass
 @Date: 2025/02/24 23:34:36

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

#ifndef _BATCH_DELETE_REQUEST_DTO_
#define _BATCH_DELETE_REQUEST_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
// 批量删除提货方式dto
class BatchDeleteRequestDto : public oatpp::DTO {
	DTO_INIT(BatchDeleteRequestDto, DTO);
	// id列表
	API_DTO_FIELD_DEFAULT(List<oatpp::UInt64>, ids, ZH_WORDS_GETTER("lad.field.ids"));
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_BATCH_DELETE_REQUEST_DTO_

