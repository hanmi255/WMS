#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: JOHAN LIN
 @Date: 2025/02/21 03:51:00

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

#ifndef _COST_ATTRIBUTE_DTO_
#define _COST_ATTRIBUTE_DTO_

#include "domain/GlobalInclude.h"
#include "iomanip"
#include <id/SnowFlake.h>

#include OATPP_CODEGEN_BEGIN(DTO)
/*
	删除客户计费属性
*/
class DeleteCostAttributeDTO : public oatpp::DTO {
	DTO_INIT(DeleteCostAttributeDTO, DTO);

	// 要删除的客户属性编码
	API_DTO_FIELD_DEFAULT(String, costAttributeCode, ZH_WORDS_GETTER("cost.attribute.deleteCodes"));
	API_DTO_FIELD_DEFAULT(String, costAttributeName, ZH_WORDS_GETTER("cost.attribute.deleteName"));

};

/*
	导入客户计费属性
*/
class ImportCostAttributeDTO : public oatpp::DTO {
    DTO_INIT(ImportCostAttributeDTO, DTO);

	 //唯一编号,主键
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("cost.field.id"));

	 //创建人名称
	API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("cost.field.create_name"));

	 //创建人登录名称
	API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("cost.field.create_by"));

	 //创建日期(日期类型)
	API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("cost.field.create_date"));

	 //更新人名称
	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("cost.field.update_name"));

	 //更新人登录名称
	API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("cost.field.update_by"));

	 //更新日期(日期类型)
	API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("cost.field.update_date"));

	 //所属部门
	API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("cost.field.sys_org_code"));

	// 所属公司
	API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("cost.field.sys_company_code"));

	 //客户计费属性编码
	API_DTO_FIELD_DEFAULT(String, kehushuxing_code, ZH_WORDS_GETTER("cost.field.kehushuxing_code"));

	 //客户计费属性名称
	API_DTO_FIELD_DEFAULT(String, kehushuxing_name, ZH_WORDS_GETTER("cost.field.kehushuxing_name"));

public:
	void addExcel(string code, string name, string create_name = "admin", string create_by = "admin", string sys_org_code = "A05", string sys_company_code = "A05")
	{
		SnowFlake a(0, 0);
		string s = to_string(a.nextId());
		this->id = s;
		this->create_name = create_name;
		this->create_by = create_by;
		this->create_date = getCurrentTimeString();
		this->sys_org_code = sys_org_code;
		this->sys_company_code = sys_company_code;
		this->kehushuxing_code = code;
		this->kehushuxing_name = name;
	}

	std::string getCurrentTimeString() {
		auto now = std::chrono::system_clock::now();
		std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
		auto* localTime = std::localtime(&currentTime);

		std::stringstream ss;
		ss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
		return ss.str();
	}
};

/*
	客户计费属性
*/
class CostAttributeDTO : public oatpp::DTO {
	DTO_INIT(CostAttributeDTO, DTO);

	// 唯一编号,主键
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("cost.field.id"));

	// 创建人名称
	API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("cost.field.create_name"));

	// 创建人登录名称
	API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("cost.field.create_by"));

	// 创建日期(日期类型)
	API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("cost.field.create_date"));

	// 更新人名称
	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("cost.field.update_name"));

	// 更新人登录名称
	API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("cost.field.update_by"));

	// 更新日期(日期类型)
	API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("cost.field.update_date"));

	// 所属部门
	API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("cost.field.sys_org_code"));

	// 所属公司
	API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("cost.field.sys_company_code"));

	// 客户计费属性编码
	API_DTO_FIELD_DEFAULT(String, kehushuxing_code, ZH_WORDS_GETTER("cost.field.kehushuxing_code"));

	// 客户计费属性名称
	API_DTO_FIELD_DEFAULT(String, kehushuxing_name, ZH_WORDS_GETTER("cost.field.kehushuxing_name"));

public:
	void addExcel(vector<string> rowData)
	{
		this->id = rowData[0];
		this->create_name = rowData[1];
		this->create_by = rowData[2];
		this->create_date = rowData[3];
		this->update_name = rowData[4];
		this->update_by = rowData[5];
		this->update_date = rowData[6];
		this->sys_org_code = rowData[7];
		this->sys_company_code = rowData[8];
		this->kehushuxing_code = rowData[9];
		this->kehushuxing_name = rowData[10];
	}
};

// 传输数据对象
class CostPageDTO : public  PageDTO<CostAttributeDTO::Wrapper>
{
	DTO_INIT(CostPageDTO, PageDTO<CostAttributeDTO::Wrapper>);
};

/*
	客户计费属性列表
*/
class CostAttributesDTO : public oatpp::DTO {
	DTO_INIT(CostAttributesDTO, DTO);

	// 客户计费属性列表
	API_DTO_FIELD_DEFAULT(Vector <CostAttributeDTO::Wrapper>, costAttributes, ZH_WORDS_GETTER("cost.attribute.array"));
};

/*
	客户计费属性Excel文件
*/
class CostAttributeExcelFileDTO : public oatpp::DTO {
	DTO_INIT(CostAttributeExcelFileDTO, DTO);

	// Excel文件名
	API_DTO_FIELD_DEFAULT(String, fileName, ZH_WORDS_GETTER("excel.name.export"));

	// Excel文件URL
	API_DTO_FIELD_DEFAULT(String, fileURL, ZH_WORDS_GETTER("excel.url.export"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COST_ATTRIBUTE_DTO_