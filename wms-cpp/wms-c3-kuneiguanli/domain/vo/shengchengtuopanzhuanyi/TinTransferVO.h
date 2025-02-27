#ifndef _TIN_TRANSFER_VO_
#define _TIN_TRANSFER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/shengchengtuopanzhuanyi/TinTransferDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示JsonVO，用于响应给客户端的Json对象
 */
class TinTransferJsonVO : public JsonVO<TinTransferDTO::Wrapper> {
	DTO_INIT(TinTransferJsonVO, JsonVO<TinTransferDTO::Wrapper>);
};

/**
 * 分页显示JsonVO，用于响应给客户端的Json对象
 */
class TinTransferPageJsonVO : public JsonVO<TinTransferPageDTO::Wrapper> {
	DTO_INIT(TinTransferPageJsonVO, JsonVO<TinTransferPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_TIN_TRANSFER_VO_