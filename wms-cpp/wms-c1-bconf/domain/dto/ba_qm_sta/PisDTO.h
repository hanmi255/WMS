#pragma once

#ifndef _PIS_DTO_
#define _PIS_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例新增品检状态数据传输对象
 */
class PisAddDTO : public oatpp::DTO
{
	DTO_INIT(PisAddDTO, DTO);
	// 品检状态代码
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("pis.field.qm_sta_code");
	}
	// 品检状态名称
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("pis.field.qm_sta_name");
	}
	// 编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("pis.field.id");
	}
};

/**
 * 示例传输对象
 */
class PisDTO : public PisAddDTO
{
	DTO_INIT(PisDTO, PisAddDTO);
	//// 编号
	//DTO_FIELD(String, id);
	//DTO_FIELD_INFO(id) {
	//	info->description = ZH_WORDS_GETTER("pis.field.id");
	//}
	//API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("qis.field.id"));
};

/**
 * 示例分页传输对象
 */
class PisPageDTO : public PageDTO<PisDTO::Wrapper>
{
	DTO_INIT(PisPageDTO, PageDTO<PisDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_SAMPLE_DTO_
