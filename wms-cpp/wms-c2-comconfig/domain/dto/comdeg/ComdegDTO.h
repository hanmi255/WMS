#pragma once
#ifndef _COMDEG_DTO_
#define _COMDEG_DTO_

#include "../../GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 公司等级基础列表对象
 */
class ComdegBaseDTO : public oatpp::DTO
{
	DTO_INIT(ComdegBaseDTO, DTO);

	//企业等级名称
	API_DTO_FIELD_DEFAULT(String, degname, ZH_WORDS_GETTER("com.field.degname"));

	//企业等级代码
	API_DTO_FIELD_DEFAULT(String, degcode, ZH_WORDS_GETTER("com.field.degcode"));

	//企业等级停用
	API_DTO_FIELD_DEFAULT(String, degdel, ZH_WORDS_GETTER("com.field.degdel"));
};

/**
 * 新增公司等级数据对象
 */
class ComdegAddDTO : public ComdegBaseDTO
{
	DTO_INIT(ComdegAddDTO, ComdegBaseDTO);

};

/**
 * 公司等级详情数据对象
 */
class ComdegDetailDTO : public ComdegAddDTO
{
	DTO_INIT(ComdegDetailDTO, ComdegAddDTO);

	//唯一标识
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("com.field.degid"));
};

/**
 * 公司等级列表对象
 */
class ComdegListDTO : public ComdegBaseDTO
{
	DTO_INIT(ComdegListDTO, ComdegBaseDTO);

	//唯一标识
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("com.field.degid"));
};

/**
 * 公司等级列表分页数据对象
 */
class ComdegPageDTO : public PageDTO<ComdegListDTO::Wrapper>
{
	DTO_INIT(ComdegPageDTO, PageDTO<ComdegListDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_COMDEG_DTO_