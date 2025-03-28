#pragma once
#ifndef _QUALITY_DTO_
#define _QUALITY_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 品质代码基础数据对象 
 */
class QualityBaseDTO : public oatpp::DTO
{
	DTO_INIT(QualityBaseDTO, DTO);
	// 品质代码 
	API_DTO_FIELD_DEFAULT(String, qm_qa_code, ZH_WORDS_GETTER("quality.qm_qa_code"));

	// 品质代码名称
	API_DTO_FIELD_DEFAULT(String, qm_qa_name, ZH_WORDS_GETTER("quality.qm_qa_name"));
};

/**
 * 新增品质代码数据对象
 */
class QualityAddDTO : public QualityBaseDTO
{
	DTO_INIT(QualityAddDTO, QualityBaseDTO);

	//// 品质代码 
	//API_DTO_FIELD_DEFAULT(String, qm_qa_code, ZH_WORDS_GETTER("quality.qm_qa_code"));

	//// 品质代码名称
	//API_DTO_FIELD_DEFAULT(String, qm_qa_name, ZH_WORDS_GETTER("quality.qm_qa_name"));
}; 

/**
 * 品质代码详细数据对象
 */
class QualityDetailDTO : public QualityAddDTO
{
	DTO_INIT(QualityDetailDTO, QualityAddDTO);
	//// 品质代码 
	//API_DTO_FIELD_DEFAULT(String, qacode, ZH_WORDS_GETTER("quality.qm_qa_code"));

	//// 品质代码名称
	//API_DTO_FIELD_DEFAULT(String, qacodename, ZH_WORDS_GETTER("quality.qm_qa_name"));
};

/**
 * 品质代码列表数据对象
 */
class QualityListDTO : public QualityBaseDTO
{
	DTO_INIT(QualityListDTO, QualityBaseDTO);

	// 唯一标识
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("quality.qm_qa_id"));
};

/**
 * 品质代码分页传输对象
 */
class QualityPageDTO : public PageDTO<QualityListDTO::Wrapper>
{
	DTO_INIT(QualityPageDTO, PageDTO<QualityListDTO::Wrapper>);
};




#include OATPP_CODEGEN_END(DTO)
#endif // !QUALITY_DTO