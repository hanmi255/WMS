#pragma once
#ifndef _HUO_QU_CANG_WEI_SHU_JU_VO_
#define _HUO_QU_CANG_WEI_SHU_JU_VO_

#include "../../GlobalInclude.h"
#include "../../dto/cangweitu/HuoQuCangWeiShuJuDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 仓位数据JsonVO，用于响应给客户端的Json对象
 */
class HuoQuCangWeiShuJuJsonVO : public JsonVO<HuoQuCangWeiShuJuDTO::Wrapper> {
	DTO_INIT(HuoQuCangWeiShuJuJsonVO, JsonVO<HuoQuCangWeiShuJuDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_HUO_QU_CANG_WEI_SHU_JU_VO_