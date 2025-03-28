#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: tutu
 @Date: 2025/02/23 12:36:48

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
#ifndef _PLC_DTO_
#define _PLC_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * PLC基础数据对象，包含要显示基本数据
 */
class PlcBaseDto : public oatpp::DTO
{
	DTO_INIT(PlcBaseDto, DTO);
	// PLCIP
	API_DTO_FIELD_DEFAULT(String, plc_ip, "PLCIP");
	// PLC端口
	API_DTO_FIELD_DEFAULT(String, plc_port, ZH_WORDS_GETTER("plc.file.plcport"));
	// PLC型号
	API_DTO_FIELD_DEFAULT(String, plc_type, ZH_WORDS_GETTER("plc.file.plctype"));
	//指令备注
	API_DTO_FIELD_DEFAULT(String, com_remark, ZH_WORDS_GETTER("plc.file.remark"));
	// 指令编号
	API_DTO_FIELD_DEFAULT(String, com_no, ZH_WORDS_GETTER("plc.file.number"));
};

/**
 * PLC详情数据对象，用于add
 */
class PlcAddDTO : public PlcBaseDto
{
	DTO_INIT(PlcAddDTO, PlcBaseDto);
	//执行时间
	API_DTO_FIELD_DEFAULT(String, com_time, ZH_WORDS_GETTER("plc.file.time"));
	//执行顺序
	API_DTO_FIELD_DEFAULT(String, com_seq, ZH_WORDS_GETTER("plc.file.seq"));
	//指令集
	API_DTO_FIELD_DEFAULT(String, com_cons, ZH_WORDS_GETTER("plc.file.insset"));
	//备用1
	API_DTO_FIELD_DEFAULT(String, remark1, ZH_WORDS_GETTER("plc.file.standby"));
	//单步参数1
	API_DTO_FIELD_DEFAULT(String, query01, ZH_WORDS_GETTER("plc.file.sys1"));
	//单步参数2
	API_DTO_FIELD_DEFAULT(String, query02, ZH_WORDS_GETTER("plc.file.sys2"));
	//单步时间
	API_DTO_FIELD_DEFAULT(String, setp_time, ZH_WORDS_GETTER("plc.file.steptime"));
	//步数
	API_DTO_FIELD_DEFAULT(String, setp_num, ZH_WORDS_GETTER("plc.file.step"));
};

/**
 * 基础信息带ID，用于分页查询
 */
class PlcListDTO : public PlcBaseDto
{
	DTO_INIT(PlcListDTO, PlcBaseDto);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("plc.file.id"));
};

/**
 * PLC列表分页数据对象
 */
class PlcListPageDTO : public PageDTO<PlcListDTO::Wrapper>
{
	DTO_INIT(PlcListPageDTO, PageDTO<PlcListDTO::Wrapper>);
};
//完整数据带ID，用于修改数据
class PlcdetailDTO : public PlcAddDTO
{
	DTO_INIT(PlcdetailDTO, PlcAddDTO);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("plc.file.id"));
};
#include OATPP_CODEGEN_END(DTO)
#endif 