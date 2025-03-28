#pragma once
#ifndef _EXPORT_DTO_
#define _EXPORT_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)
/**
* 修改行业分类对象
*/
class ExportAddDTO :public oatpp::DTO
{
	DTO_INIT(ExportDTO, DTO);

	//行业分类唯一id
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("chengfeng.id"));


	//行业分类代码
	API_DTO_FIELD_DEFAULT(String, classfl_code, ZH_WORDS_GETTER("chengfeng.code"));

	//行业分类名称
	API_DTO_FIELD_DEFAULT(String, classfl_name, ZH_WORDS_GETTER("chengfeng.name"));

	//停用
	API_DTO_FIELD_DEFAULT(String, classfl_del, ZH_WORDS_GETTER("chengfeng.del"));
};

/**
 * 公司信息传输对象
 */
class ExportDTO : public ExportAddDTO
{
	DTO_INIT(ExportDTO, ExportAddDTO);
};

/**
 * 公司信息分页传输对象
 */
class ExportPageDTO : public PageDTO<ExportDTO::Wrapper>
{
	DTO_INIT(ExportPageDTO, PageDTO<ExportDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPORT_DTO_