#pragma once

#ifndef _STT_TASK_CONTROLLER_
#define _STT_TASK_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/stt-task/SttTaskVO.h"
//#include "domain/dto/stt-task/SttTaskDTO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 盘点管理-动碰盘信息管理
 */
class SttTaskController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	API_ACCESS_DECLARE(SttTaskController);

public:
	// 定义删除盘点任务接口描述
	ENDPOINT_INFO(delTask)
	{
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sttTask.summary.del"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		// 定义查询参数描述
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("sttTask.field.id"), "0000", true);
	}

	// 定义删除盘点任务接口处理
	ENDPOINT(API_M_DEL, "/stt/stt-task/{id}", delTask,PATH(String, id), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_RESP_VO(execDelTask((id),authObject->getPayload()));
	}

private:
	
	StringJsonVO::Wrapper execDelTask(const String& id,const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // !_STT_TASK_CONTROLLER_