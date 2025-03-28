#ifndef _BAWORKST_DTO_
#define _BAWORKST_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 新增工作状态对象
 */
class BaWorkStAddDTO : public oatpp::DTO
{
	DTO_INIT(BaWorkStAddDTO, DTO);
	//工作状态代码
	DTO_FIELD(String, work_sta_code);
	DTO_FIELD_INFO(work_sta_code) {
		info->description = ZH_WORDS_GETTER("ba_work_st.field.work_sta_code");
	}
	//工作状态名称
	DTO_FIELD(String, work_sta_name);
	DTO_FIELD_INFO(work_sta_name) {
		info->description = ZH_WORDS_GETTER("ba_work_st.field.work_sta_name");
	}
};

/**
 * 工作状态对象
 */
class BaWorkStDTO : public BaWorkStAddDTO
{
	DTO_INIT(BaWorkStDTO, BaWorkStAddDTO);
	// 编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("ba_work_st.field.id");
	}
	// 创建人名称
	DTO_FIELD(String, create_name);
	DTO_FIELD_INFO(create_name) {
		info->description = ZH_WORDS_GETTER("ba_work_st.field.create_name");
	}
	//创建人登录名
	DTO_FIELD(String, create_by);
	DTO_FIELD_INFO(create_by) {
		info->description = ZH_WORDS_GETTER("ba_work_st.field.create_by");
	}
	// 所属部门
	DTO_FIELD(String, sys_org_code);
	DTO_FIELD_INFO(sys_org_code) {
		info->description = ZH_WORDS_GETTER("ba_work_st.field.sys_org_code");
	}
	// 所属公司
	DTO_FIELD(String, sys_company_code);
	DTO_FIELD_INFO(sys_company_code) {
		info->description = ZH_WORDS_GETTER("ba_work_st.field.sys_company_code");
	}
	// 创建日期
	DTO_FIELD(String, create_date);
	DTO_FIELD_INFO(create_date) {
		info->description = ZH_WORDS_GETTER("ba_work_st.field.create_date");
	}
	//更新人名称
	DTO_FIELD(String, update_name);
	DTO_FIELD_INFO(update_name) {
		info->description = ZH_WORDS_GETTER("ba_work_st.field.update_name");
	}
	//更新人登录名称
	DTO_FIELD(String, update_by);
	DTO_FIELD_INFO(update_by) {
		info->description = ZH_WORDS_GETTER("ba_work_st.field.update_by");
	}
	//更新日期
	DTO_FIELD(String, update_date);
	DTO_FIELD_INFO(update_date) {
		info->description = ZH_WORDS_GETTER("ba_work_st.field.update_date");
	}
};


/**
 * 修改工作状态对象
 */
class BaWorkStChangeDTO : public oatpp::DTO
{
	DTO_INIT(BaWorkStChangeDTO, oatpp::DTO);
	// 编号
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("ba_work_st.field.id");
	}
	//工作状态代码
	DTO_FIELD(String, work_sta_code);
	DTO_FIELD_INFO(work_sta_code) {
		info->description = ZH_WORDS_GETTER("ba_work_st.field.work_sta_code");
	}
	//工作状态名称
	DTO_FIELD(String, work_sta_name);
	DTO_FIELD_INFO(work_sta_name) {
		info->description = ZH_WORDS_GETTER("ba_work_st.field.work_sta_name");
	}
};

/**
 * 工作状态分页传输对象
 */
class BaWorkStPageDTO : public PageDTO<BaWorkStDTO::Wrapper>
{
	DTO_INIT(BaWorkStPageDTO, PageDTO<BaWorkStDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 