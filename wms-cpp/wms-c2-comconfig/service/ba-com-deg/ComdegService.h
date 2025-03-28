#ifndef _COMDEG_SERVICE_
#define _COMDEG_SERVICE_
#include <list>
#include "domain/dto/comdeg/ComdegDTO.h"
#include "domain/vo/comdeg/ComdegVO.h"
#include "domain/query/comdeg/ComdegQuery.h"
#include "domain/GlobalInclude.h"
/**
 * 分页查找，添加服务实现
 */

class ComdegService {

public:
	// 分页查询所有数据
	ComdegPageDTO::Wrapper listAll(const ComdegQuery::Wrapper& query);
	// 通过ID查询单个数据
	ComdegPageDTO::Wrapper getById(uint64_t id);
	// 保存数据
	uint64_t saveData(const ComdegAddDTO::Wrapper& dto,const PayloadDTO& payload);
};
#endif