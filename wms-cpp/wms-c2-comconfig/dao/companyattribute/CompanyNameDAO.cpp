/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/03/08 14:41:52

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "CompanyNameDAO.h"
#include <sstream>
#include "CompanyNameMapper.h"

//获取企业属性名称数据
std::list<CompanyNameDO> CompanyNameDAO::getCompanyName()
{
	CompanyNameMapper map;
	/*添加redis*/
	string sql = "SELECT `id`, `com_type_code`, `com_type_name` FROM `ba_com_type`";
	return sqlSession->executeQuery<CompanyNameDO>(sql, map);
}

