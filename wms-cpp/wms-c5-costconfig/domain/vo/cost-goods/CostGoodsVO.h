#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Jane
 @Date: 2025/03/08 11:34:14

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
#ifndef _COSTGOODSVO_H_
#define _COSTGOODSVO_H_

#include "domain/GlobalInclude.h"
#include "../../../domain/dto/cost-goods/CostGoodsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 计费商品类删除显示JsonVO，用于响应给客户端的Json对象
 */
class BPCDeleteJsonVO : public JsonVO<BPCDeleteDTO::Wrapper> {
	DTO_INIT(BPCDeleteJsonVO, JsonVO<BPCDeleteDTO::Wrapper>);
};

/**
 * excel文件上传结果数据
 */
class BPCExcelDownloadJsonVO : public JsonVO<BPCExcelDownloadDTO::Wrapper>
{
	DTO_INIT(BPCExcelDownloadJsonVO, JsonVO<BPCExcelDownloadDTO::Wrapper>);
};

/**
 * excel文件上传结果数据
 */
class BPCExcelUploadJsonVO : public JsonVO<BPCExcelUploadDTO::Wrapper>
{
	DTO_INIT(BPCExcelUploadJsonVO, JsonVO<BPCExcelUploadDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_COSTGOODSVO_H_