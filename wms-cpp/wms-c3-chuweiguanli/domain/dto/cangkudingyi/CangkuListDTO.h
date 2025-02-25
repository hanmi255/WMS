#pragma once

#include"../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//	获取仓库列表 数据传输对象
class CangkuListDTO : public oatpp::DTO
{
	DTO_INIT(CangkuListDTO, DTO);

	//	仓库ID
	DTO_FIELD(Int64, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("Cangku.info.id");
	}

	//	仓库名称
	DTO_FIELD(String, store_name);
	DTO_FIELD_INFO(store_name) {
		info->description = ZH_WORDS_GETTER("Cangku.info.store_name");
	}

	//	仓库代码
	DTO_FIELD(String, store_code);
	DTO_FIELD_INFO(store_code) {
		info->description = ZH_WORDS_GETTER("Cangku.info.store_code");
	}

	//	仓库属性
	DTO_FIELD(String, store_text);
	DTO_FIELD_INFO(store_text) {
		info->description = ZH_WORDS_GETTER("Cangku.info.store_text");
	}
};

#include OATPP_CODEGEN_END(DTO)

