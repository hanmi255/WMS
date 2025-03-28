/*
 Copyright Zero One Star. All rights reserved.

 @Author: 猫头大蒜
 @Date: 2025/03/10 16:09:12

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.ations under the License.
*/
#include "stdafx.h"
#include "Recv-G-WayService.h"
#include "../../dao/recv-g-way/Recv-G-WayFileDao.h"
#include "../../../nacos-register/Macros.h"

Recv_G_WayAllDto::Wrapper Recv_G_WayService::listAll(const Recv_G_WayQuery::Wrapper& query)
{
	// 构建返回对象
	auto pages = Recv_G_WayAllDto::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	Recv_G_WayDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<Recv_G_WayDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (Recv_G_WayDO sub : result)
	{
		auto dto = Recv_G_WayEditDto::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, del_mode_code, Del_mode_code, del_mode_name, Del_mode_name,id,Id);
		pages->addData(dto);
	}
	return pages;
}

int Recv_G_WayService::saveData(const Recv_G_WayAddDto::Wrapper& dto, string name, string realname, string orgcode, string companycode)
{
	// 组装DO数据
	Recv_G_WayDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Del_mode_code, del_mode_code, Del_mode_name, del_mode_name);
	// 执行数据添加
	Recv_G_WayDAO dao;
	return dao.insert(data, name, realname, orgcode, companycode);
}

bool Recv_G_WayService::updateData(const Recv_G_WayEditDto::Wrapper& dto)
{
	// 组装DO数据
	
	Recv_G_WayDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Del_mode_code, del_mode_code, Del_mode_name, del_mode_name,Id,id);
	// 执行数据修改
	Recv_G_WayDAO dao;
	return dao.update(data);
}

bool Recv_G_WayService::removeData(const string id)
{
	Recv_G_WayDAO dao;
	return dao.deleteById(id);
}
