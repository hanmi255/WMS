#include "stdafx.h"
#include "ModifyController.h"
#include "service/modify-industry-class/ModifyService.h"

Uint64JsonVO::Wrapper ModifyController::execModifyClass(const ModifyDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	std::string yes = ZH_WORDS_GETTER("chengfeng.yes");
	std::string no = ZH_WORDS_GETTER("chengfeng.no");

	std::string del = dto->classfl_del;

	// 参数校验
	if (!dto->id || !(del==yes||del==no))
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	ModifyService service;
	// 执行数据修改
	if (service.updateData(dto)) {
		jvo->success(UInt64(1));
	}
	else
	{
		jvo->fail(UInt64(-1));
	}

	// 响应结果
	return jvo;
}