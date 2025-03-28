/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: Ann
 @Date: 2025/3/2 20:14
 
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
#include "GoodsClassService.h"
#include "../../domain/do/public-do/GoodsClassDO.h"
#include "../../dao/goods-class/GoodsClassDAO.h"
#include "SimpleDateTimeFormat.h"


// 修改数据
bool GoodsClassService::update(const GoodsClassModifyDTO::Wrapper& dto) {
	// 组装DO数据
	GoodsClassDO data;
	// 生成时间
	string now = SimpleDateTimeFormat::format();
	dto->update_date = now;
	ZO_STAR_DOMAIN_DTO_TO_DO(
		data, dto,
		Id, id,
		GoodsClassCode, code,
		GoodsClassName, name,
		UpdateName, update_name,
		UpdateBy, update_by,
		UpdateDate, update_date,
		SysOrgCode, sys_org_code,
		SysCompanyCode, sys_company_code);
	// 执行数据更新
	GoodsClassDAO dao;
	return dao.update(data);

}
// 保存数据
string GoodsClassService::insert(const GoodsClassAddDTO::Wrapper& dto) {
	// 组装DO数据
	GoodsClassDO data;
	// 生成时间
	string now = SimpleDateTimeFormat::format();
	dto->update_date = now;
	dto->create_date = now;

	ZO_STAR_DOMAIN_DTO_TO_DO(
		data, dto,
		GoodsClassCode, code,
		GoodsClassName, name,
		CreateName, create_name,
		CreateBy, create_by,
		CreateDate, create_date,
		UpdateName, update_name,
		UpdateBy, update_by,
		UpdateDate, update_date,
		SysOrgCode, sys_org_code,
		SysCompanyCode, sys_company_code);
	// 执行数据插入
	GoodsClassDAO dao;
	return dao.insert(data);

}
// 分页查询所有名称
GoodsClassNameListPageDTO::Wrapper GoodsClassService::listName(const GoodClassQuery::Wrapper& query) {
	// 构建返回对象
	auto pages = GoodsClassNameListPageDTO::createShared();


	//pages->pageIndex = query->pageIndex;
	//pages->pageSize = query->pageSize;

	// 查询数据总条数
	GoodsClassDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	//// 分页查询数据
	//pages->total = count;
	//pages->calcPages();
	list<GoodsClassDO> result = dao.selectName(query);
	// 将DO转换成DTO
	for (GoodsClassDO sub : result)
	{
		auto dto = GoodsClassNameListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, name, GoodsClassName);
		pages->addData(dto);
	}
	return pages;





}
// 分页查询所有数据
GoodsClassPageDTO::Wrapper GoodsClassService::listAll(const GoodClassQuery::Wrapper& query) {

	// 构建返回对象
	auto pages = GoodsClassPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	GoodsClassDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<GoodsClassDO> result = dao.selectAllWithPage(query);
	// 将DO转换成DTO
	for (GoodsClassDO sub : result)
	{
		auto dto = GoodsClassDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
			id, Id,                   // 编号
			name, GoodsClassName,     // 计费商品类名称
			code, GoodsClassCode,     // 计费商品类编码
			create_name, CreateName,  // 创建人名称
			create_by, CreateBy,      // 创建人登录名称
			create_date, CreateDate,  // 创建日期
			update_name, UpdateName,  // 更新人名称
			update_by, UpdateBy,      // 更新人登录名称
			update_date, UpdateDate,  // 更新日期
			sys_org_code, SysOrgCode, // 所属部门
			sys_company_code, SysCompanyCode // 所属公司
		);
		pages->addData(dto);
	}
	return pages;

}


