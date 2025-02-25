#ifndef _BIN_TRANSFER_VO_
#define _BIN_TRANSFER_VO_

#include "../../GlobalInclude.h"
#include "../../dto/shengchengchuweizhuanyi/BinTransferDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示JsonVO，用于响应给客户端的Json对象
 */
class BinTransferJsonVO : public JsonVO<BinTransferDTO::Wrapper> {
	DTO_INIT(BinTransferJsonVO, JsonVO<BinTransferDTO::Wrapper>);
};

/**
 * 分页显示JsonVO，用于响应给客户端的Json对象
 */
class BinTransferPageJsonVO : public JsonVO<BinTransferPageDTO::Wrapper> {
	DTO_INIT(BinTransferPageJsonVO, JsonVO<BinTransferPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_BIN_TRANSFER_VO_