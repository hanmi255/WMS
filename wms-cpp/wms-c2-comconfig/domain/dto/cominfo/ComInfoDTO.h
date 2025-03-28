#pragma once
#ifndef _COMPANY_INFORMATION_DTO_
#define _COMPANY_INFORMATION_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 公司信息对象
 */
class ComInfoAddDTO : public oatpp::DTO
{
	DTO_INIT(ComInfoAddDTO, DTO);
	// 1.公司ID
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("comconfig.cominfo.id");
	}
	// 2.创建人名称
	DTO_FIELD(String, create_name);
	DTO_FIELD_INFO(create_name) {
		info->description = ZH_WORDS_GETTER("comconfig.cominfo.create_name");
	}
	// 3.创建人登录名称
	DTO_FIELD(String, create_by);
	DTO_FIELD_INFO(create_by) {
		info->description = ZH_WORDS_GETTER("comconfig.cominfo.create_by");
	}
	// 4.创建日期
	DTO_FIELD(String, create_date);
	DTO_FIELD_INFO(create_date) {
		info->description = ZH_WORDS_GETTER("comconfig.cominfo.create_date");
	}
	// 5.更新人名称
	DTO_FIELD(String, update_name);
	DTO_FIELD_INFO(update_name) {
		info->description = ZH_WORDS_GETTER("comconfig.cominfo.update_name");
	}
	// 6.更新人登录名称
	DTO_FIELD(String, update_by);
	DTO_FIELD_INFO(update_by) {
		info->description = ZH_WORDS_GETTER("comconfig.cominfo.update_by");
	}
	// 7.更新日期
	DTO_FIELD(String, update_date);
	DTO_FIELD_INFO(update_date) {
		info->description = ZH_WORDS_GETTER("comconfig.cominfo.update_date");
	}
	// 8.所属部门
	DTO_FIELD(String, sys_org_code);
	DTO_FIELD_INFO(sys_org_code) {
		info->description = ZH_WORDS_GETTER("comconfig.cominfo.sys_org_code");
	}
	// 9.所属公司
	DTO_FIELD(String, sys_company_code);
	DTO_FIELD_INFO(sys_company_code) {
		info->description = ZH_WORDS_GETTER("comconfig.cominfo.sys_company_code");
	}
	// 10.公司代码
	DTO_FIELD(String, com_code);
	DTO_FIELD_INFO(com_code) {
		info->description = ZH_WORDS_GETTER("comconfig.cominfo.com_code");
	}
	// 11.公司中文简称
	DTO_FIELD(String, com_zh_name);
	DTO_FIELD_INFO(com_zh_name) {
		info->description = ZH_WORDS_GETTER("comconfig.cominfo.com_zh_name");
	}
	// 12.公司中文全称
	DTO_FIELD(String, com_zh_aname);
	DTO_FIELD_INFO(com_zh_aname) {
		info->description = ZH_WORDS_GETTER("comconfig.cominfo.com_zh_aname");
	}
	// 13.公司中文地址
	DTO_FIELD(String, com_zh_addr);
	DTO_FIELD_INFO(com_zh_addr) {
		info->description = ZH_WORDS_GETTER("comconfig.cominfo.com_zh_addr");
	}
	// 14.公司英文简称
	DTO_FIELD(String, com_en_name);
	DTO_FIELD_INFO(com_en_name) {
		info->description = ZH_WORDS_GETTER("comconfig.cominfo.com_en_name");
	}
	// 15.公司英文全称
	DTO_FIELD(String, com_en_aname);
	DTO_FIELD_INFO(com_en_aname) {
		info->description = ZH_WORDS_GETTER("comconfig.cominfo.com_en_aname");
	}

};


/**
 * 公司信息传输对象
 */
class ComInfoDTO : public ComInfoAddDTO
{
	DTO_INIT(ComInfoDTO, ComInfoAddDTO);
};

/**
 * 公司信息分页传输对象
 */
class ComInfoPageDTO: public PageDTO<ComInfoDTO::Wrapper>
{
	DTO_INIT(ComInfoPageDTO, PageDTO<ComInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COMPANY_INFORMATION_DTO_

