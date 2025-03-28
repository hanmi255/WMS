#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei

 @Date: 2025/3/10 14:33

*/
#ifndef _REVIEW_STT_VO_H_
#define _REVIEW_STT_VO_H_

#include "../../GlobalInclude.h"
#include "../../dto/review-stt/ReviewSttDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个复盘显示JsonVO对象，用于响应给客户端
 */
class ReviewSttJsonVO : public JsonVO<ReviewSttDetailDTO::Wrapper>
{
	DTO_INIT(ReviewSttDetailDTO, JsonVO<ReviewSttDetailDTO::Wrapper>);
};

/**
 * 定义一个复盘分页显示JsonVO对象，用于响应给客户端
 */
class ReviewSttPageJsonVO : public JsonVO<ReviewSttPageDTO::Wrapper>
{
	DTO_INIT(ReviewSttPageJsonVO, JsonVO<ReviewSttPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // _REVIEW_STT_VO_H_