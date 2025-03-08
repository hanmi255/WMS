#pragma once
#ifndef _HUO_QU_CANG_WEI_SHU_JU_DTO_
#define _HUO_QU_CANG_WEI_SHU_JU_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 仓位数据查询对象
 */
class HuoQuCangWeiShuJuDTO : public oatpp::DTO
{
	DTO_INIT(HuoQuCangWeiShuJuDTO, DTO);
	// 仓库
	API_DTO_FIELD_DEFAULT(String, bin_store, ZH_WORDS_GETTER("store.field.bin_store"));
	//储位
	API_DTO_FIELD_DEFAULT(String, bin_id, ZH_WORDS_GETTER("store.field.bin_id"));
	//层数
	API_DTO_FIELD_DEFAULT(String, znode, ZH_WORDS_GETTER("store.field.znode"));
	//行数
	API_DTO_FIELD_DEFAULT(String, xnode, ZH_WORDS_GETTER("store.field.xnode"));
	//列数
	API_DTO_FIELD_DEFAULT(String, ynode, ZH_WORDS_GETTER("store.field.ynode"));
	//颜色
	API_DTO_FIELD_DEFAULT(String, colour, ZH_WORDS_GETTER("store.field.colour"));
	//tincount
	API_DTO_FIELD_DEFAULT(String, tincount, "tincount");
};

class HuoQuCangWeiShuJuPageDTO : public PageDTO<HuoQuCangWeiShuJuDTO::Wrapper>
{
	DTO_INIT(HuoQuCangWeiShuJuPageDTO, PageDTO<HuoQuCangWeiShuJuDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_HUO_QU_CANG_WEI_SHU_JU_DTO_