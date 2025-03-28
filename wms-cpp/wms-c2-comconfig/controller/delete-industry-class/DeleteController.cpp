#include "stdafx.h"
#include "DeleteController.h"
#include "service/delete-industry-class/InduDeleteService.h"

/*检查需要上传的批量id是否合法*/
inline bool check1(const DeleteDTO::Wrapper& id) {
	Vector<String> ids = id->Id;
	for (const auto& Id : *ids) {
		if (!Id) {
			return false;
		}
	}
	return true;
}

inline vector<string>& to_vector(const DeleteDTO::Wrapper& id) {
	vector<string> ans;
	Vector<String> ids = id->Id;
	for (const auto& Id : *ids) {
		ans.push_back(Id);
	}
	return ans;
}

Uint64JsonVO::Wrapper DeleteController::execDeleteClass(const DeleteDTO::Wrapper& id)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!check1(id))
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	InduDeleteService service;
	// 执行数据删除
	if (/*service.removeData(to_vector(id))*/1) {
		jvo->success(UInt64(1));
	}
	else
	{
		jvo->fail(UInt64(-1));
	}
	// 响应结果
	return jvo;
}



