#pragma once

#ifndef _INVENTORY_PVO_
#define _INVENTORY_PVO_

#include "../../GlobalInclude.h"
#include "../../dto/inentorydifference/InventoryPDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 盘点人详情JsonVO，用于响应给客户端的Json对象
 */
class InventoryPJsonVO : public JsonVO<InventoryPDtailDTO::Wrapper> {
	DTO_INIT(InventoryPJsonVO, JsonVO<InventoryPDtailDTO::Wrapper>);
};

/**
 * 盘点人详情列表JsonVO，用于响应给客户端的Json对象
 */
class InventoryPPageJsonVO : public JsonVO<InventoryPPageDTO::Wrapper> {
	DTO_INIT(InventoryPPageJsonVO, JsonVO<InventoryPPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_INVENTORY_PVO_