#pragma once


#ifndef _STUCODE_SERVICE_
#define _STUCODE_SERVICE_
#include <list>
#include "domain/vo/stucode/StuCodeVO.h"
#include "domain/query/stucode/StuCodeQuery.h"
#include "domain/dto/stucode/StuCodeDTO.h"
#include "domain/dto/stucode/StuCodeDelDTO.h"
#include "ApiHelper.h"
#include "oatpp-swagger/Types.hpp"
#include "dao/StuCodeDAO.h"	



/**
 * 示例服务实现，演示基础的示例服务实现
 */
class StuCodeService
{
public:
	// 分页查询数据
	StuCodePageDTO::Wrapper listAll(const StuCodeQuery::Wrapper& query);

	uint64_t updateStuCode(const StuCodeDTO::Wrapper& dto, const PayloadDTO& auth);

	uint64_t setStuCode(const StuCodeDTO::Wrapper& dto, const PayloadDTO& auth);
	
	uint64_t setDelCode(const StuCodeDelDTO::Wrapper& dto);

	uint64_t importStuCode();
};

#endif // !_SAMPLE_SERVICE_