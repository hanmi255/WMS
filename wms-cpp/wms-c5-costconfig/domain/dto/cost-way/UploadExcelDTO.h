#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: tudou
 @Date: 2023/09/18 15:01:29

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
#ifndef _UPLOADEXCEL_DTO_
#define _UPLOADEXCEL_DTO_

#include "../../GlobalInclude.h"
#include OATPP_CODEGEN_BEGIN(DTO)
#include "../lib-common/include/id/SnowFlake.h"
#include <chrono>
#include <iomanip>
/**
 * excel文件上传对象
 */
class UploadExcelDTO : public oatpp::DTO
{
	DTO_INIT(UploadExcelDTO, DTO);
	// 计费方式
	
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("Costconfig.way.id"));
	API_DTO_FIELD_DEFAULT(String, pronut_name, ZH_WORDS_GETTER("Costconfig.way.name"));

	API_DTO_FIELD_DEFAULT(String, pronut_code, ZH_WORDS_GETTER("Costconfig.way.code"));
	API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("Costconfig.way.create_name"));

	API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("Costconfig.way.create_by"));


	API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("Costconfig.way.create_date"));

	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("Costconfig.way.update_name"));

	API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("Costconfig.way.update_by"));

	
	API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("Costconfig.way.update_date"));

	
	API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("Costconfig.way.sys_org_code"));


	
	API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("Costconfig.way.sys_company_code"));

	


	
public:
	UploadExcelDTO() {}
	UploadExcelDTO(String pronut_code, String pronut_name, String create_name=oatpp::String("管理员"), 
		String create_by = oatpp::String("admin"),string create_date=NULL,string update_name=NULL,string update_by=NULL,
		string update_date=NULL, String sys_org_code=oatpp::String("A05"),string sys_company_code=oatpp::String("A05"))
	{
		
		this->pronut_name = pronut_name;
		this->pronut_code = pronut_code;
	}
	std::string getCurrentTimeString() {
		auto now = std::chrono::system_clock::now();
		std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
		auto* localTime = std::localtime(&currentTime);

		std::stringstream ss;
		ss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
		return ss.str();
	}
	void addExcel(string n,string m,string create_name = ZH_WORDS_GETTER("Costconfig.way.create_name1"),string create_by = "admin", string sys_org_code = "A05",string sys_company_code = "A05")
	{
		SnowFlake a(0, 0);
		string s = to_string(a.nextId());
		this->id = s;
		this->pronut_code = n;
		this->pronut_name = m;
		this->create_name =create_name;
		this->create_by = create_by;
		this->create_date = getCurrentTimeString();
		this->sys_org_code = sys_org_code;
		this->sys_company_code = sys_company_code;

	}
};

#include OATPP_CODEGEN_END(DTO)

#endif // _UPLOADEXCEL_DTO_