#pragma once
#ifndef _EduCode_Service_
#define _EduCode_Service_
#include <list>
#include <string>
#include<domain/dto/education/EducationalDTO.h>
class DelRoleService
{
public:

	// 通过ID删除数据
	bool removeData(std::string id);

	uint64_t setEduCode(const EducationalDTO::Wrapper& dto, const PayloadDTO& auth);

	// 修改数据
	bool updateData(const EducationalDTO::Wrapper& dto, const PayloadDTO& payload);
};

#endif // !_EduCode_Service_
