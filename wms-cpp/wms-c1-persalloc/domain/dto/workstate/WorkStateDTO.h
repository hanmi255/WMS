#pragma once
// 王也 2025/2/24
#ifndef _WORKSTATE_DTO_
#define _WORKSTATE_DTO_

#include "../../GlobalInclude.h"
#include "ApiHelper.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class WorkStateDTO : public oatpp::DTO
{
	DTO_INIT(WorkStateDTO, DTO);
	// ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("ba_work_st.field.id"));
	// 创建人名称
	API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("ba_work_st.field.create_name"));
	// 创建人登录名称
	API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("ba_work_st.field.create_by"));
	// 创建日期
	API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("ba_work_st.field.create_date"));
	// 更新人名称
	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("ba_work_st.field.update_name"));
	// 更新人登录名称
	API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("ba_work_st.field.update_by"));
	// 更新日期
	API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("ba_work_st.field.update_date"));
	// 所属部门
	API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("ba_work_st.field.sys_org_code"));
	// 所属公司
	API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("ba_work_st.field.sys_company_code"));
	// 工作状态代码
	API_DTO_FIELD_DEFAULT(String, work_sta_code, ZH_WORDS_GETTER("ba_work_st.field.work_sta_code"));
	// 工作状态名称
	API_DTO_FIELD_DEFAULT(String, work_sta_name, ZH_WORDS_GETTER("ba_work_st.field.work_sta_name"));


};

#include OATPP_CODEGEN_END(DTO)

#endif // !_WORKSTATE_DTO_