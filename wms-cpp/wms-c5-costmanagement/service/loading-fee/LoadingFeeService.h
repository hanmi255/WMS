#pragma once

#ifndef _LOADINGFEE_SERVICE_
#define _LOADINGFEE_SERVICE_

#include "../../domain/vo/loading-fee/LoadingFeeVO.h"
#include "../../domain/do/LoadingFeeDO.h"
#include "../../domain/dto/loading-fee/LoadingFeeDTO.h"
#include "../../domain/query/loading-fee/LoadingFeeQuery.h"
#include <list>
/**
 * 外包装车费服务实现
 */
class LoadingFeeService
{
public:
	// 分页查询外包装车费
	LoadingFeePageDTO::Wrapper pageQueryLoadingFee(const LoadingFeeQuery::Wrapper& query);
	//导出外包装车费
	list<LoadingFeeDO> DownloadLoadingFee(const LoadingFeeQuery::Wrapper& query);
};

#endif // _LOADINGFEE_SERVICE_