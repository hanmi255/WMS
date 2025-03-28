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
#include "costtypeService.h"
#include "../../dao/costtype/costtypeDAO.h"

//costtypePageDTO::Wrapper costtypeService::listAll(const costtypeQuery::Wrapper& query)
//{
//	// 构建返回对象
//	auto pages = costtypePageDTO::createShared();
//	pages->pageIndex = query->pageIndex;
//	pages->pageSize = query->pageSize;
//
//	// 查询数据总条数
//	costtypeDAO dao;
//	uint64_t count = dao.count(query);
//	if (count <= 0)
//	{
//		return pages;
//	}
//
//	// 分页查询数据
//	pages->total = count;
//	pages->calcPages();
//	list<costtypeDO> result = dao.selectWithPage(query);
//	// 将DO转换成DTO
//	for (costtypeDO sub : result)
//	{
//		auto dto = costtypeDTO::createShared();
//		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, Name, sex, Sex, age, Age);
//		pages->addData(dto);
//	}
//	return pages;
//}
//
//costtypeDTO::Wrapper costtypeService::getById(uint64_t id)
//{
//	// 查询数据
//	costtypeDAO dao;
//	auto res = dao.selectById(id);
//	
//	// 没有查询到数据
//	if (!res)
//		return nullptr;
//
//	// 查询到数据转换成DTO
//	auto dto = costtypeDTO::createShared();
//	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, id, Id, name, Name, sex, Sex, age, Age);
//	return dto;
//}
//
//uint64_t costtypeService::saveData(const costtypeAddDTO::Wrapper& dto)
//{
//	// 组装DO数据
//	costtypeDO data;
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age);
//	// 执行数据添加
//	costtypeDAO dao;
//	return dao.insert(data);
//}
//
//bool costtypeService::updateData(const costtypeDTO::Wrapper& dto)
//{
//	// 组装DO数据
//	costtypeDO data;
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Name, name, Sex, sex, Age, age, Id, id);
//	// 执行数据修改
//	costtypeDAO dao;
//	return dao.update(data) == 1;
//}

//bool costtypeService::removeData(uint64_t id)
//{
//	costtypeDAO dao;
//	return dao.deleteById(id) == 1;
//}
bool costtypeService::removeData(string id)
{
	costtypeDAO dao;
	return dao.deleteById(id) == 1;
}


bool costtypeService::removeData_more(const std::vector<std::string>& ids)
{
	costtypeDAO dao;
	return dao.deleteByIds(ids) == ids.size();
}