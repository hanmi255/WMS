#include "stdafx.h"
#include "CostDetailController.h"
#include "../../service/cost-detail-ahead/CostDetailService.h"

CostDetailListPageJsonVO::Wrapper CostDetialController::execQueryPageAll(const CostDetailQuery::Wrapper& query) {
	
	// 定义一个Service
	CostDetailService service;

	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = CostDetailListPageJsonVO::createShared();
	jvo->success(result);

	return jvo;
}


Uint64JsonVO::Wrapper CostDetialController::execAddCost(const CostDetailAddDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();

	// 定义一个Service
	CostDetailService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}


// 3.3 演示修改数据
StringJsonVO::Wrapper CostDetialController::execeditCost(const CostDetailEditDTO::Wrapper& dto, const PayloadDTO& payload) {
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();

	// 定义一个Service
	CostDetailService service;
	// 执行数据修改
	if (service.updateData(dto, payload)) {
		jvo->success(dto->id);
	}
	else
	{
		jvo->fail(dto->id);
	}
	// 响应结果
	return jvo;
}

// 3.3 演示删除数据
StringJsonVO::Wrapper CostDetialController::execRemoveCost(const String& id) {

	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 防御性检查：空字符串或非法字符
	if (!id) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	CostDetailService service;
	// 执行数据删除
	if (service.removeData(id)) {
		jvo->success(id);
	}
	else
	{
		jvo->fail(id);
	}
	// 响应结果
	return jvo;
}


StringJsonVO::Wrapper CostDetialController::execRemoveAllCost(const List<String>& ids) {
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 防御性检查：空字符串或非法字符
	if (!ids) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	CostDetailService service;
	int count = 0;
	// 执行数据删除
	for (int i = 0; i < ids->size(); i++) {
		if (service.removeData(ids[i])) {
			count++;
		}
		else
		{
			jvo->fail(ids[i]);
			break;
		}
	}
	if(count == ids->size())
		jvo->success("delete batch success");
	// 响应结果
	return jvo;
	/*

	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();

	if (!ids) {
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	vector<string> stringIds;
	for (int i=0; i < ids->size(); i++) {
		stringIds.push_back(ids[i]);
	}

	CostDetailService service;
	if (service.removeBatchData(stringIds)) {
		jvo->success("Batch delete success");
	}
	else {
		jvo->fail("Batch delete failed");
	}

	return jvo;
	*/
}