#pragma once
#ifndef _MODIFY_DTO_
#define _MODIFY_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
* 修改行业分类对象
*/
class ModifyDTO :public oatpp::DTO
{
	DTO_INIT(ModifyDTO, DTO);

	//行业分类唯一id
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("chengfeng.id");
	}

	//行业分类代码
	DTO_FIELD(String, classfl_code);
	DTO_FIELD_INFO(classfl_code) {
		info->description = ZH_WORDS_GETTER("chengfeng.code");
	}
	//行业分类名称
	DTO_FIELD(String, classfl_name);
	DTO_FIELD_INFO(classfl_name) {
		info->description = ZH_WORDS_GETTER("chengfeng.name");
	}
	//停用
	DTO_FIELD(String, classfl_del);
	DTO_FIELD_INFO(classfl_del) {
		info->description = ZH_WORDS_GETTER("chengfeng.del");
	}
};
 

#include OATPP_CODEGEN_END(DTO)
#endif // !_MODIFY_DTO_