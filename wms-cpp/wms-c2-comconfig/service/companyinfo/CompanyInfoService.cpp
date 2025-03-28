
/*
 Copyright Zero One Star. All rights reserved.

 @Author: greent
 @Date: 2025/3/5 22:14:14

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
#include <ctime>
#include <sstream>
#include <iomanip>
#include "id/UuidFacade.h"

inline string getUuid() {
	UuidFacade uf(1);

	return uf.genUuid();
}

inline string getCurrentTime() {
	stringstream ss;
	time_t now;
	tm* timeinfo;

	//获取当前时间
	time(&now);
	timeinfo = localtime(&now);

	//格式化时间
	ss << timeinfo->tm_year + 1900 << "-" << setw(2) << setfill('0') << timeinfo->tm_mon + 1 << "-" << setw(2) << setfill('0')<< timeinfo->tm_mday << " "  << setw(2) << setfill('0') << timeinfo->tm_hour << ":" << setw(2) << setfill('0') << timeinfo->tm_min << ":"  << setw(2) << setfill('0') << timeinfo->tm_sec;

	string ans = ss.str();

	return ans;
}

uint64_t CompanyInfoService::saveData(const CompanyAddInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 组装DO数据
	CompanyInfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CompanyId, companyId, ZhAbbr, zhabbr, ZhFul, zhful, ZhAddr, zhaddr, EnAbbr, enabbr, EnFul, enful);
	data.setDate(getCurrentTime());
	data.setUserName(payload.getRealname());
	data.setLoginName(payload.getUsername());
	data.setId(getUuid());
	data.setOrgDept(payload.getOrgcode());
	data.setOrgCompany(payload.getCompanycode());
	// 执行数据添加
	CompanyInfoDAO dao;
	return dao.insert(data);
}

bool CompanyInfoService::updateData(const CompanyUpdateInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 组装DO数据
	CompanyInfoDO data;
//	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CompanyId, companyId, ZhAbbr, zhabbr, ZhFul, zhful, ZhAddr, zhaddr, EnAbbr, enabbr, EnFul, enful, Id, id);
	data.setCompanyId(dto->companyId);
	data.setZhAbbr(dto->zhabbr);
	data.setZhAddr(dto->zhaddr);
	data.setZhFul(dto->zhful);
	data.setEnAbbr(dto->enabbr);
	data.setEnFul(dto->enful);
	data.setDate(getCurrentTime());
	data.setUserName(payload.getRealname());
	data.setLoginName(payload.getUsername());
	data.setId(dto->id);
	data.setOrgDept(payload.getOrgcode());
	data.setOrgCompany(payload.getCompanycode());
	// 执行数据修改
	CompanyInfoDAO dao;
	return dao.update(data) == 1;
}

bool CompanyInfoService::removeData(vector<string>&& id) {
	// 执行数据删除
	CompanyInfoDAO dao;
	return dao.deleteById(id) == 1;
}