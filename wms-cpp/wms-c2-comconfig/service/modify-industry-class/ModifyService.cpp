#include "stdafx.h"
#include "ModifyService.h"
#include "../../dao/modify-industry-class/ModifyDAO.h"

bool ModifyService::updateData(const ModifyDTO::Wrapper& dto)
{
	// 组装DO数据
	ModifyDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Classfl_code, classfl_code, Classfl_name, classfl_name, Classfl_del, classfl_del, Id, id);
	// 执行数据修改
	ModifyDAO dao;
	return dao.update(data) == 1;
}

