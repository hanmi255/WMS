/*
 Copyright Zero One Star. All rights reserved.

 @Author: Jane
 @Date: 2025/03/08 11:13:11

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
#include "CostGoodsService.h"
#include "../../dao/cost-goods/CostGoodsDAO.h"

bool CostGoodsService::removeData(string code)
{
	CostGoodsDAO dao;
	return dao.deleteByCode(code) == 1;
}

uint64_t saveData(const BPCExcelUploadDTO::Wrapper& dto)
{
	// 组装DO数据
	GoodsClassDO data;

	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, GoodsClassCode, goods_class_code, GoodsClassName, goods_class_name, CreateName, create_name, CreateBy, create_by,
		CreateDate, create_date, UpdateName, update_name, UpdateBy, update_by, UpdateDate, update_date, SysOrgCode, sys_org_code
		, SysCompanyCode, sys_company_code);
	
	CostGoodsDAO dao;
	return dao.insert(data);
}

list<GoodsClassDO> CostGoodsService::listAll()
{
	auto pages = BPCDeleteDTO::createShared();
	CostGoodsDAO dao;
	list<GoodsClassDO> result = dao.select();
	return result;
}