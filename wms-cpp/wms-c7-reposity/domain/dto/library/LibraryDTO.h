#pragma once
/*
 @Author: nanbowan
*/
#include"../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
* 修改温度属性对象
*/
class ModifyLibraryDTO :public oatpp::DTO
{
	DTO_INIT(ModifyLibraryDTO, DTO);

	//要修改的库位类型的唯一id
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("dictionary.library.id.summary"));

	//新库位类型代码
	API_DTO_FIELD_DEFAULT(String, bin_type_code, ZH_WORDS_GETTER("dictionary.library.code.summary"));

	//新库位类型名称
	API_DTO_FIELD_DEFAULT(String, bin_type_name, ZH_WORDS_GETTER("dictionary.library.type.summary"));

};


#include OATPP_CODEGEN_END(DTO)
