#pragma once
#ifndef _HUO_QU_CANG_WEI_SHU_JU_VO_
#define _HUO_QU_CANG_WEI_SHU_JU_VO_

#include "../../GlobalInclude.h"
#include "../../dto/cangweitu/HuoQuCangWeiShuJuDTO.h"
#include "../lib-oatpp/include/domain/vo/BaseJsonVO.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 仓位数据JsonVO，用于响应给客户端的Json对象
 */
class HuoQuCangWeiShuJuJsonVO : public JsonVO<List<HuoQuCangWeiShuJuDTO::Wrapper>> {
	DTO_INIT(HuoQuCangWeiShuJuJsonVO, JsonVO<HuoQuCangWeiShuJuDTO::Wrapper>);
};

class HuoQuCangWeiShuJuPageJsonVO : public JsonVO<HuoQuCangWeiShuJuPageDTO::Wrapper> {
	DTO_INIT(HuoQuCangWeiShuJuPageJsonVO, JsonVO<HuoQuCangWeiShuJuPageDTO::Wrapper>);
};



#include OATPP_CODEGEN_END(DTO)

#endif // !_HUO_QU_CANG_WEI_SHU_JU_VO_