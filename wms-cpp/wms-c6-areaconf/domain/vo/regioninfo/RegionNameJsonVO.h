#pragma once
/*
 @Author: 002
 @Date: 2025.2.27
*/
#ifndef _REGION_NAME_JSONVO_
#define _REGION_NAME_JSONVO_

#include "../../GlobalInclude.h"
#include "../../dto/regioninfo/RegionNameDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 显示RegionNameJsonVO，用于响应给客户端的Json对象
 */
class RegionNameJsonVO : public JsonVO<oatpp::Vector<RegionNameDTO::Wrapper>> {
    DTO_INIT(RegionNameJsonVO, JsonVO<oatpp::Vector<RegionNameDTO::Wrapper>>);
};

/**
 * 分页显示RegionNamePageJsonVO，用于响应给客户端的Json对象
 */
class RegionNamePageJsonVO : public JsonVO<RegionNamePageDTO::Wrapper> {
	DTO_INIT(RegionNamePageJsonVO, JsonVO<RegionNamePageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif 