#pragma once

#ifndef _TUOPAN_DTO_
#define _TUOPAN_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 托盘列表传输对象
 */

class TuopanDTO : public oatpp::DTO
{
	DTO_INIT(TuopanDTO, DTO);
	// 托盘号
	DTO_FIELD(String, tin_id);
	DTO_FIELD_INFO(tin_id) {
		info->description = ZH_WORDS_GETTER("tuopan.field.id");
	}
	// 托盘顺序
	DTO_FIELD(String, tin_sort);
	DTO_FIELD_INFO(tin_sort) {
		info->description = ZH_WORDS_GETTER("tuopan.field.order");
	}
	// 储位
	DTO_FIELD(String, bin_id);
	DTO_FIELD_INFO(bin_id) {
		info->description = ZH_WORDS_GETTER("tuopan.field.place");
	}
	// 托盘状态
	DTO_FIELD(String, tin_status);
	DTO_FIELD_INFO(tin_status) {
		info->description = ZH_WORDS_GETTER("tuopan.field.status");
	}
};


/*
* 托盘分页传输对象
*/
class TuopanPageDTO : public PageDTO<TuopanDTO::Wrapper>
{
	DTO_INIT(TuopanPageDTO, PageDTO<TuopanDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_TUOPAN_DTO_