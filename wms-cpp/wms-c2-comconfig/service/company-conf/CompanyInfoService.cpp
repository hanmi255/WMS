/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/03/13 11:13:11

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
#include "CompanyInfoService.h"
#include "../../dao/company-conf/CompanyInfoDAO.h"

CompanyListPageDTO::Wrapper CompanyInfooService::listAll(const CompanyInfoQuery::Wrapper& query) {
	// 构建返回对象
	auto pages = CompanyListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	CompanyInfoDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<CompanyInfoDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (CompanyInfoDO sub : result)
	{
		auto dto = CompanyListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, code, Code, ChineseFullName, Zh_name, ChineseSampleName, Zh_aname);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, ChineseAddr, Zh_addr, EnglishSampleName, En_name, EnglishFullName, En_aname);
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id,Id);
		pages->addData(dto);
	}
	return pages;
}

CompanyBaseeDTO::Wrapper CompanyInfooService::getById(uint64_t id)
{
	// 查询数据
	CompanyInfoDAO dao;
	auto res = dao.selectDetail(id);

	// 没有查询到数据
	if (!res)
		return nullptr;

	// 查询到数据转换成DTO
	auto dto = CompanyBaseeDTO::createShared();
	//ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, code, Code, ChineseFullName, Zh_Name, ChineseSampleName, Zh_aname, ChineseAddr, Zh_addr, EnglishSampleName, En_name, EnglishFullName,En_aname);
	dto->code = res->getCode();
	dto->ChineseSampleName = res->getZh_name();
	dto->ChineseFullName = res->getZh_aname();
	dto->ChineseAddr = res->getZh_addr();
	dto->EnglishSampleName = res->getEn_name();
	dto->EnglishFullName = res->getEn_aname();
	return dto;
}
