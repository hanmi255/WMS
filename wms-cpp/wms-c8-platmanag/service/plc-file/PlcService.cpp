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
#include "PlcService.h"
#include "../../dao/plc-file/PlcDAO.h"

bool PlcService::saveData(const PlcAddDTO::Wrapper& dto, string name, string realname, string orgcode, string companycode)
{
	// 组装DO数据
	PlcDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, plc_ip, plc_ip, plc_port, plc_port, plc_type, plc_type, com_remark, com_remark, com_time, com_time, com_seq, com_seq, com_cons, com_cons, remark1, remark1, com_no, com_no, query01, query01, query02, query02, setp_time, setp_time, setp_num, setp_num);
	// 执行数据添加
	PlcDAO dao;
	return dao.insert(data, name, realname, orgcode, companycode);
}
PlcListPageDTO::Wrapper PlcService::listAll(const PlcFileQuery::Wrapper& query)
{
	auto pages = PlcListPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;
	//查询总条数
	PlcDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}
	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<PlcBaseDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (PlcBaseDO sub : result)
	{
		auto dto = PlcListDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id , id, plc_ip, plc_ip, plc_port, plc_port, plc_type, plc_type, com_remark, remark1, com_no, com_no);
		pages->addData(dto);
	}
	return pages;
}
PlcdetailDTO::Wrapper PlcService::getById(string id)
{
	// 查询数据
	PlcDAO dao;
	auto res = dao.selectById(id);
	// 没有查询到数据     
	if (!res)
		return nullptr;
	// 查询到数据转换成DTO
	auto dto = PlcdetailDTO::createShared();
	ZO_STAR_DOMAIN_DO_TO_DTO_1(dto, res, id, id, plc_ip, plc_ip, plc_port, plc_port, plc_type, plc_type, com_remark, com_remark, com_time, com_time, com_seq, com_seq, com_cons, com_cons, remark1, remark1, com_no, com_no, query01, query01, query02, query02, setp_time, setp_time, setp_num, setp_num);
	return dto;
}
bool PlcService::updateData(const PlcdetailDTO::Wrapper& dto)
{
	PlcDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, id ,id, plc_ip, plc_ip, plc_port, plc_port, plc_type, plc_type, com_remark, com_remark, com_time, com_time, com_seq, com_seq, com_cons, com_cons, remark1, remark1, com_no, com_no, query01, query01, query02, query02, setp_time, setp_time, setp_num, setp_num);
	// 执行数据修改
	PlcDAO dao;
	return dao.update(data);
}
bool PlcService::removeData(string id)
{
	PlcDAO dao;
	return dao.deleteById(id);
}