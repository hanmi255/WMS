#pragma once

#ifndef _STT_TASK_DAO_
#define _STT_TASK_DAO_
#include "BaseDAO.h"
#include "../../domain/do/goods-manage/wm_stt_in_goodsDO.h"

class SttTaskDAO : public BaseDAO
{
public:
	uint64_t insert(const Wm_Stt_In_GoodsDO& iObj);

	// 用于“删除”盘点任务，本质是修改stt_sta字段值并修改更新相关信息
	uint64_t modifySttSta(const Wm_Stt_In_GoodsDO& iObj);
};

#endif