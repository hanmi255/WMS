#pragma once

#include "domain/GlobalInclude.h"
#include "domain/dto/kuneizhuanyi/MoveGoodsDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 显示JsonVO
*/
class MoveGoodsJsonVO : public JsonVO<MoveGoodsDTO::Wrapper> {
	DTO_INIT(MoveGoodsJsonVO, JsonVO<MoveGoodsDTO::Wrapper>);
};

/**
* 分页显示JsonVO
*/
class MoveGoodsPageJsonVO : public JsonVO<MoveGoodsPageDTO::Wrapper> {
	DTO_INIT(MoveGoodsPageJsonVO, JsonVO<MoveGoodsPageDTO::Wrapper>);
};

/**
* 详细显示JsonVO
*/
class MoveGoodsDetailedJsonVO : public JsonVO<MoveGoodsDetailedDTO::Wrapper> {
	DTO_INIT(MoveGoodsDetailedJsonVO, JsonVO<MoveGoodsDetailedDTO::Wrapper>);
};

/**
* 导出JsonVO
*/
class MoveGoodsDownLoadJsonVO : public JsonVO<MoveGoodsDownLoadDTO::Wrapper> {
	DTO_INIT(MoveGoodsDownLoadJsonVO, JsonVO<MoveGoodsDownLoadDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
