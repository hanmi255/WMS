#pragma once

#ifndef _UNLOADINGFEE_SERVICE_
#define _UNLOADINGFEE_SERVICE_

#include "../../domain/vo/unloading-fee/UnloadingFeeVO.h"
#include "../../domain/do/UnloadingFeeDO.h"
#include "../../domain/dto/unloading-fee/UnloadingFeeDTO.h"
#include "../../domain/query/unloading-fee/UnloadingFeeQuery.h"
#include <list>
/**
 * 外包卸货费服务实现
 */
class UnloadingFeeService
{
public:
	// 分页查询外包卸货费
	UnloadingFeePageDTO::Wrapper pageQueryUnloadingFee(const UnloadingFeeQuery::Wrapper& query);
	//导出外包卸货费
	list<UnloadingFeeDO> DownloadUnloadingFee(const UnloadingFeeQuery::Wrapper& query);
};

#endif // _UNLOADINGFEE_SERVICE_