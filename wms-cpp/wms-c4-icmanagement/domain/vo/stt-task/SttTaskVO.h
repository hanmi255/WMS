#pragma once

#ifndef _STT_TASK_VO_
#define _STT_TASK_VO_

#include "../../GlobalInclude.h"
#include "domain/dto/stt-task/SttTaskDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 任务列表分页显示JsonVO，用于响应给客户端的Json对象
 */
class SttTaskPageJsonVO : public JsonVO<SttTaskListDTO::Wrapper> {
	DTO_INIT(SttTaskPageJsonVO, JsonVO<SttTaskListDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_STT_TASK_VO_