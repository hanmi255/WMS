#pragma once


#ifndef _STT_TASK_SERVICE_
#define _STT_TASK_SERVICE_

#include "domain/dto/stt-on-move/SttOnMoveDTO.h"

/**
 * 盘点任务服务实现
 */
class SttTaskService
{
public:
	// 将动碰盘项添加到盘点任务中，新增盘点任务
	uint64_t insert(const SttOnMoveDetailDTO::Wrapper& sttOnMoveDetailDTO,const PayloadDTO& payload);

	//bool insert(const SttOnMoveInsertTaskDTO::Wrapper& dto, const PayloadDTO& payload);
	
	// 删除盘点任务（修改stt_sta为已删除
	uint64_t delData(const string& id, const PayloadDTO& payload);
};


#endif