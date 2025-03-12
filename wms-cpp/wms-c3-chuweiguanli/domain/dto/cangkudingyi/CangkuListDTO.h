#pragma once

#include"../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class StoreBaseDTO : public oatpp::DTO
{
	DTO_INIT(StoreBaseDTO, DTO);

	DTO_FIELD(String, store_code);
	DTO_FIELD_INFO(store_code) {
		info->description = ZH_WORDS_GETTER("store.store_code");
	}

	DTO_FIELD(String, store_name);
	DTO_FIELD_INFO(store_name) {
		info->description = ZH_WORDS_GETTER("store.store_name");
	}

	DTO_FIELD(String, store_text);
	DTO_FIELD_INFO(store_text) {
		info->description = ZH_WORDS_GETTER("store.store_text");
	}
};

class CangkuListDTO :public StoreBaseDTO
{
	DTO_INIT(CangkuListDTO, StoreBaseDTO);

	// 主键
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id)
	{
		info->description = ZH_WORDS_GETTER("store.id");
	}
};

//	获取仓库列表 数据传输对象
class CangkuListPageDTO : public PageDTO<CangkuListDTO::Wrapper>
{
	DTO_INIT(CangkuListPageDTO, PageDTO<CangkuListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

