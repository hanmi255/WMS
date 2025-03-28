#pragma once
#ifndef _LISTGOODS_VO_
#define _LISTGOODS_VO_

/*****************************************************************************
    *  @COPYRIGHT NOTICE
    *  @Copyright (c) 2013, kato1
    *  @All rights reserved
    *  @file	 : ListgoodsController.cpp
    *  @version  : ver 1.0
    *  @author   : kato1
    *  @date     : 2025/2/26 17:04
    *  @brief    : brief
*****************************************************************************/


#include "../../dto/adjust-list/ListgoodsDTO.h"
#include "domain/query/PageQuery.h"
#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 修改上架货物JsonVO，用于响应给客户端的Json对象
 */
class  ListgoodsadjustJsonVO : public JsonVO<ListgoodsadjustDTO::Wrapper> {
	DTO_INIT(ListgoodsadjustJsonVO, JsonVO<ListgoodsadjustDTO::Wrapper>);
};


/**
 * 上架货物详情JsonVO，用于响应给客户端的Json对象
 */
class ListgoodsdetailJsonVO : public JsonVO<ListgoodsDetailDTO::Wrapper> {
	DTO_INIT(ListgoodsdetailJsonVO, JsonVO<ListgoodsDetailDTO::Wrapper>);
};

/**
 * 上架货物分页列表显示JsonVO，用于响应给客户端的Json对象
 */
class ListgoodsPageJsonVO : public JsonVO<ListgoodsPageDTO::Wrapper> {
	DTO_INIT(ListgoodsPageJsonVO, JsonVO<ListgoodsPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_LISTGOODS_VO_#pragma once
