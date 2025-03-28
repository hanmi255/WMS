#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: Jane
 @Date: 2025/03/08 11:36:29

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
#ifndef _COSTGOODS_DTO_
#define _COSTGOODS_DTO_


#include "../../GlobalInclude.h"
#include <id/SnowFlake.h>
#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 计费商品类查询对象
 */
class BPCDeleteDTO : public oatpp::DTO
{
	DTO_INIT(BPCDeleteDTO, oatpp::DTO);
	// 计费商品类代码
	API_DTO_FIELD_DEFAULT(String, bpcid, ZH_WORDS_GETTER("CostGoodsQuery.way.id"));
	// 计费商品类编码
	API_DTO_FIELD_DEFAULT(String, bpcname, ZH_WORDS_GETTER("CostGoodsQuery.way.name"));
};

/**
 * excel文件传输数据对象
 */
class BPCExcelDownloadDTO : public oatpp::DTO
{
	DTO_INIT(BPCExcelDownloadDTO, DTO);
	// excel文件名
	API_DTO_FIELD_DEFAULT(String, filename, ZH_WORDS_GETTER("file.field.excel-filename"));
	// excel文字描述
	API_DTO_FIELD_DEFAULT(String, alt, ZH_WORDS_GETTER("file.field.excel-alt"));
	// excel地址
	API_DTO_FIELD_DEFAULT(String, href, ZH_WORDS_GETTER("file.field.excel-href"));
public:
	BPCExcelDownloadDTO() {}
	BPCExcelDownloadDTO(String filename, String alt = "", String href = "")
	{
		this->filename = filename;
		this->alt = alt;
		this->href = href;
	}
};

/**
 * excel文件传输数据对象
 */
class BPCExcelUploadDTO : public oatpp::DTO
{
	DTO_INIT(BPCExcelUploadDTO, DTO);

	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("CostGoodsQuery.way.id"));
	
	API_DTO_FIELD_DEFAULT(String, goods_class_name, ZH_WORDS_GETTER("CostGoodsQuery.way.name"));

	API_DTO_FIELD_DEFAULT(String, goods_class_code, ZH_WORDS_GETTER("CostGoodsQuery.way.code"));
	
	API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("CostGoodsQuery.way.create_name"));

	API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("CostGoodsQuery.way.create_by"));

	API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("CostGoodsQuery.way.create_date"));

	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("CostGoodsQuery.way.update_name"));

	API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("CostGoodsQuery.way.update_by"));

	API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("CostGoodsQuery.way.update_date"));

	API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("CostGoodsQuery.way.sys_org_code"));

	API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("CostGoodsQuery.way.sys_company_code"));

public:
	BPCExcelUploadDTO() {}
	BPCExcelUploadDTO(String goods_class_code, String goods_class_name, String create_name = oatpp::String("管理员"),
		String create_by = oatpp::String("admin"), string create_date = NULL, string update_name = NULL, string update_by = NULL,
		string update_date = NULL, String sys_org_code = oatpp::String("A05"), string sys_company_code = oatpp::String("A05"))
	{

		this->goods_class_name = goods_class_name;
		this->goods_class_code = goods_class_code;
	}
	std::string getCurrentTimeString() {
		auto now = std::chrono::system_clock::now();
		std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
		auto* localTime = std::localtime(&currentTime);

		std::stringstream ss;
		ss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
		return ss.str();
	}
	void addExcel(string code, string name, string create_name = "admin", string create_by = "admin", string sys_org_code = "A05", string sys_company_code = "A05")
	{
		SnowFlake a(0, 0);
		string s = to_string(a.nextId());
		this->id = s;
		this->goods_class_code = code;
		this->goods_class_name = name;
		this->create_name = create_name;
		this->create_by = create_by;
		this->create_date = getCurrentTimeString();
		this->sys_org_code = sys_org_code;
		this->sys_company_code = sys_company_code;
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COSTGOODS_DTO