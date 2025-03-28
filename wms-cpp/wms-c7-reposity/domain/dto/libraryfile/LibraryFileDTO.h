#pragma once
/*
 @Author: nanbowan
*/

#include"../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 新增数据传输对象
 */
class LibraryFileAddDTO : public oatpp::DTO
{
	DTO_INIT(LibraryFileAddDTO, DTO);
	// 库位编码
	DTO_FIELD(String, bin_type_code);
	DTO_FIELD_INFO(bin_type_code) {
		info->description = ZH_WORDS_GETTER("dictionary.library.code.summary");
	}
	// 库位名称
	DTO_FIELD(String, bin_type_name);
	DTO_FIELD_INFO(bin_type_name) {
		info->description = ZH_WORDS_GETTER("dictionary.library.type.summary");
	}
};

/*
* 文件类型对象
*/
class LibraryFileDTO :public oatpp::DTO
{
	DTO_INIT(LibraryFileDTO, DTO);

	//订单类型代码
	API_DTO_FIELD_DEFAULT(String, bin_type_code, ZH_WORDS_GETTER("dictionary.library.code.summary"));

	//订单类型名称
	API_DTO_FIELD_DEFAULT(String, bin_type_name, ZH_WORDS_GETTER("dictionary.library.type.summary"));

};


#include OATPP_CODEGEN_END(DTO)
