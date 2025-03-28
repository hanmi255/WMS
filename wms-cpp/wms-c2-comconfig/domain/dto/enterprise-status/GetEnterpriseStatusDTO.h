#pragma once
#ifndef _GETENTERPRISESTATUS_DTO_
#define _GETENTERPRISESTATUS_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例新增数据传输对象
 */
class EnterpriseStatusDTO : public oatpp::DTO
{
	DTO_INIT(EnterpriseStatusDTO, DTO);
	// 企业等级名称列表
	DTO_FIELD(String, name);
	DTO_FIELD_INFO(name) {
		info->description = ZH_WORDS_GETTER("enterprise.file.statusname");
	}
	DTO_FIELD(String, code);
	DTO_FIELD_INFO(code) {
		info->description = ZH_WORDS_GETTER("enterprise.file.statusid");
	}
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("enterprise.file.only");
	}
	DTO_FIELD(String, ban);
	DTO_FIELD_INFO(ban) {
		info->description = ZH_WORDS_GETTER("enterprise.file.stop");
	}


};
/**
 * 示例分页传输对象
 */
class EnterpriseStatusPageDTO : public PageDTO<EnterpriseStatusDTO::Wrapper>
{
	DTO_INIT(EnterpriseStatusPageDTO, PageDTO<EnterpriseStatusDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_GETENTERPRISESTATUS_DTO_