#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: tutu
 @Date: 2025/02/22 19:47:41

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
#ifndef _PLCFILE_QUERY_
#define _PLCFILE_QUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * PLC分页查询对象
 */
class PlcFileQuery : public PageQuery
{
	DTO_INIT(PlcFileQuery, PageQuery);

	//PLC型号1
	API_DTO_FIELD_DEFAULT(String, plc_type1, ZH_WORDS_GETTER("plc.query.type1"));
	//PLC型号2
	API_DTO_FIELD_DEFAULT(String, plc_type2, ZH_WORDS_GETTER("plc.query.type2"));
	//指令备注1
	API_DTO_FIELD_DEFAULT(String, com_remark1, ZH_WORDS_GETTER("plc.query.remark1"));
	//指令备注2
	API_DTO_FIELD_DEFAULT(String, com_remark2, ZH_WORDS_GETTER("plc.query.remark2"));
	//指令编号
	API_DTO_FIELD_DEFAULT(String, com_no, ZH_WORDS_GETTER("plc.query.com_no"));
};

#include OATPP_CODEGEN_END(DTO)
#endif 