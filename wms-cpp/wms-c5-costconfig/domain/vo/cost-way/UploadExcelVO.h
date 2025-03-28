#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: tudou
 @Date: 2023/09/18 14:46:10

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
#ifndef _UPLOADEXCEL_VO
#define _UPLOADEXCEL_VO

#include "../../GlobalInclude.h"
#include "../../dto/cost-way/UploadExcelDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * excel文件上传结果数据
 */
class UploadExcelJsonVO : public JsonVO<UploadExcelDTO::Wrapper>
{
	DTO_INIT(UploadExcelJsonVO, JsonVO<UploadExcelDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_UPLOADEXCEL_VO_