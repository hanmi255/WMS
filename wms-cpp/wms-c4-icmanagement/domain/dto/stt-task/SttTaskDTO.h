#pragma once

#ifndef _STT_TASKDTO_
#define _STT_TASKDTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
*	盘点任务基础数据对象
*/
class SttTaskBaseDTO : public oatpp::DTO
{
	DTO_INIT(SttTaskBaseDTO, oatpp::DTO);
	// 获取盘点任务列表的内容，交由负责获取列表的同学负责
};

class SttTaskDetailDTO : public SttTaskBaseDTO
{
	DTO_INIT(SttTaskDetailDTO, SttTaskBaseDTO);
};

class SttTaskListDTO : public SttTaskDetailDTO
{
	DTO_INIT(SttTaskListDTO, SttTaskDetailDTO);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("sttTask.field.id"));
};

class SttTaskPageDTO : public PageDTO<SttTaskListDTO::Wrapper>
{
	DTO_INIT(SttTaskPageDTO, PageDTO<SttTaskListDTO::Wrapper>);
};
#include OATPP_CODEGEN_END(DTO)

#endif