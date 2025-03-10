#include "stdafx.h"
#include "ChuWeiController.h"
#include "../../service/chuweidingyi/ChuWeiService.h"
#include "../ApiDeclarativeServicesHelper.h"
#include <oatpp/core/Types.hpp> 

//分页查询
ChuWeiPageJsonVO::Wrapper ChuWeiController::execQueryChuwei(const ChuWeiQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	ChuWeiService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = ChuWeiPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

//修改储位
StringJsonVO::Wrapper ChuWeiController::execModifyChuwei(const ChuWeiDTO::Wrapper& dto)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();

	// 参数校验：检查 id 是否为空
	if (!dto->id) {
		jvo->init("", RS_PARAMS_INVALID); // 错误时返回空字符串和错误码
		return jvo;
	}
		ChuWeiService service;
		if (service.updateData(dto)) {
			// 成功响应（携带ID）
			jvo->success(dto->id);
		}
		else {
			// 失败响应,返回错误提示信息
			jvo->fail(String{ "fail" });
		}
	return jvo;
}

//通过单个id删除储位
StringJsonVO::Wrapper ChuWeiController::execRemoveChuwei(const String& id)
{
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!id || id->empty())
	{
		jvo->init("", RS_PARAMS_INVALID); // 错误时返回空字符串和错误码
		return jvo;
	}
	// 定义一个Service
	ChuWeiService service;
	// 执行删除操作
	if (service.removeData(id)) {
		jvo->success(id); // 成功时返回 id
	}
	else {
		jvo->fail(String{ "fail" }); // 失败时返回 id 和错误码
	}
	// 响应结果
	return jvo;
}

//批量删除储位
StringJsonVO::Wrapper ChuWeiController::execBatchRemoveChuwei(const BatchDeleteDTO::Wrapper& dto) {
	auto jvo = StringJsonVO::createShared();
	if (!dto || !dto->ids || dto->ids->empty()) {
		jvo->init("", RS_PARAMS_INVALID);
		return jvo;
	}

	ChuWeiService service;
	std::vector<String> successIds;

	// 显式迭代器遍历
	auto& idList = dto->ids;
	for (auto it = idList->begin(); it != idList->end(); ++it) {
		const auto& id = *it;
		if (service.removeData(id)) {
			successIds.push_back(id);
		}
	}

	// 响应逻辑
	if (successIds.empty()) {
		jvo->fail(ZH_WORDS_GETTER("Chuwei.delete.fail"));
	}
	else if (successIds.size() == idList->size()) {
		jvo->success(ZH_WORDS_GETTER("Chuwei.delete.success"));
	}
	else {
		jvo->success(ZH_WORDS_GETTER("Chuwei.delete.partly_success"));
	}

	return jvo;
}