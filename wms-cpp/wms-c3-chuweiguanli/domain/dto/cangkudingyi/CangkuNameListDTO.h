#pragma once

#ifndef _CANGKUNAMELISTDTO_H_
#define _CANGKUNAMELLISTDTO_H_

#include"../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//	获取仓库名称列表 数据传输对象
class CangkuNameListDTO : public oatpp::DTO
{
	DTO_INIT(CangkuNameListDTO, DTO);

	//	仓库ID
	DTO_FIELD(String, id);
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
};

#include OATPP_CODEGEN_END(DTO)

#endif // _CANGKUNAMELLISTDTO_H_
