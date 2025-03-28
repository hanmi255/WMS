#pragma once
#ifndef _CITYTYPE_H_
#define _CITYTYPE_H_

#include "../../GlobalInclude.h"
#include "domain/dto/citytype/CityTypeDTO.h"
#include "../../dto/citytype/CityTypeDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)

class CityTypeNameListJsonVO : public JsonVO<oatpp::List<CityTypeNameDTO::Wrapper>> {
	DTO_INIT(CityTypeNameListJsonVO, JsonVO<oatpp::List<CityTypeNameDTO::Wrapper>>);
};

class CityTypeJsonVO : public JsonVO<CityTypeDTO::Wrapper> {
	DTO_INIT(CityTypeJsonVO, JsonVO<CityTypeDTO::Wrapper>);
};

/**
 * 用于响应给客户端的Json对象,删除用
 */
class CityTypeVO : public JsonVO<CitytypeDeleteDTO::Wrapper> {
	DTO_INIT(CityTypeVO, JsonVO<CitytypeDeleteDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class PageJsonVO : public JsonVO<CityTypePageDTO::Wrapper> {
	DTO_INIT(CityTypePageDTO, JsonVO<CityTypePageDTO::Wrapper>);
};

class CityTypePageJsonVO : public JsonVO<CityTypePageDTO::Wrapper> {
	DTO_INIT(CityTypePageJsonVO, JsonVO<CityTypePageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif 