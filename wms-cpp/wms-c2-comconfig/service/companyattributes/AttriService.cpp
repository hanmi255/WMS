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

#include "AttriService.h"
#include "dao/companyattributes/AttriInfoDAO.h"
#include "domain/dto/companyattributes/AttriInfoDTO.h"


// 删除
bool AttriService::removeData(vector<string> id) {
	AttriInfoDAO dao;
	for (const auto & i : id) {
		if (dao.deleteById(i) != 1) {
			return false;
		}
	}
	return true;
}


// 返回企业属性的查询结果，准备下一步导入到execl文档中
vector<std::vector<std::string>> AttriService::getData() {
	AttriInfoDAO dao;
	std::list<AttriInfoDO> AttriList = dao.getAllAttri();//查询获取数据
	vector<std::vector<std::string>> resault_data;
	stringstream ss;

	for (auto index : AttriList)
	{
		std::vector<std::string> row;
		vector<string> tmpList = { index.getID() ,index.getCreateName() ,index.getCreateBy() ,index.getCreateDate(),
								   index.getSysorgCode(),index.getSysCompanyCode(),index.getTypeCode(),index.getTypeNames()};
		for (auto count : tmpList) {
			ss.clear();
			ss << count;
			row.push_back(ss.str());
			ss.str("");
		}
		
		resault_data.push_back(row);
	}
	return resault_data;
}

// 将上传的企业属性保存到数据库
uint64_t AttriService::saveData(const AttriInfoJsonDTO::Wrapper& dto) {
	// 组装DO数据
	AttriInfoDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,CreateName,creadename,CreateBy,createby,SysorgCode,sysorgcode,SysCompanyCode,syscompanycode,TypeCode, typecodes, TypeNames, typenames);
	AttriInfoDAO dao;
	// 执行数据添加
	return dao.insert(data);
}
