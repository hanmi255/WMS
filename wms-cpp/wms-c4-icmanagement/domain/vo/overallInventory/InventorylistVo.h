#pragma once
#ifndef _INVENTORYLIST_VO_
#define _INVENTORYLIST_VO_


#include "../../GlobalInclude.h"
#include "../../dto/overallInventory/InventorylistDto.h"
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class InventorylistDetailVo : public JsonVO<InventorylistDto::Wrapper> {
	DTO_INIT(InventorylistDetailVo, JsonVO<InventorylistDto::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class InventoryJsonPageVO : public JsonVO<InventorylistDto::Wrapper> {
	DTO_INIT(InventoryJsonPageVO, JsonVO<InventorylistDto::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_INVENTORY_LISTVO_