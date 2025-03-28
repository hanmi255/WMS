

#include "stdafx.h"
#include"DelEduCodeService.h"
#include"../../dao/DelEduCode/DelEduCodeDAO.h"
#include"domain/dto/education/EducationalDTO.h"
#include"domain/do/education/EduCodeDO.h"
#include "SimpleDateTimeFormat.h"
bool DelRoleService::removeData(std::string id)
{
	EducationalDAO dao;
	return dao.deleteById(id) == 1;
}

bool DelRoleService::updateData(const EducationalDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	EduCodeDO data;
	data.setId(dto->id);
	data.setUpdate_name(payload.getUsername());
	data.setUpdate_by(payload.getRealname());
	data.setUpdate_date(SimpleDateTimeFormat::format());
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Edu_sta_code, code, Edu_sta_name, name);
	// 执行数据修改
	EducationalDAO dao;
	return dao.update(data) == 1;
}

uint64_t DelRoleService::setEduCode(const EducationalDTO::Wrapper& dto, const PayloadDTO& auth)
{
	EducationalDAO dao;
	auto res = dao.insertEduCode(dto, auth);
	return res;
}