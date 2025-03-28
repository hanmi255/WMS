#ifndef _BaWorkSt_SERVICE_
#define _BaWorkSt_SERVICE_
#include <list>
#include "domain/vo/baworkst/BaWorkStVO.h"
#include "domain/query/baworkst/BaWorkStQuery.h"
#include "domain/dto/baworkst/BaWorkStDTO.h"

/**
 * 工作状态服务实现
 */
class BaWorkStService
{
public:
	// 分页查询所有数据
	BaWorkStPageDTO::Wrapper listAll(const BaWorkStQuery::Wrapper& query);
	// 保存数据
	string saveData(const BaWorkStAddDTO::Wrapper& dto,  const PayloadDTO& payload);
	// 修改数据
	string updateData(const BaWorkStChangeDTO::Wrapper& dto, const PayloadDTO& payload);
};

#endif // !_SAMPLE_SERVICE_