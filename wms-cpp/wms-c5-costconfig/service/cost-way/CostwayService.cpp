/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 11:13:11

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
#include "CostwayService.h"
#include "../../dao/cost-way/CostwayDAO.h"


bool CostwayService::removeDataById(string id)
{
	CostwayDAO dao;
	return dao.deleteById(id) == 1;
}
uint64_t CostwayService::saveData(const UploadExcelDTO::Wrapper& dto)
{
	CostwayDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,  Id,id,Pronut_code, pronut_code, Pronut_name, pronut_name, Create_by, create_by, 
		Create_date, create_date, Update_name, update_name,Update_by, update_by, Update_date, update_date, Sys_org_code, sys_org_code
		,Sys_company_code, sys_company_code);
	CostwayDAO dao;
	return dao.insert(data);
}

list<CostwayDO> CostwayService::listAll()
{
	auto pages = DeleteDTO::createShared();
	CostwayDAO dao;
	list<CostwayDO> result = dao.select();
	return result;
}