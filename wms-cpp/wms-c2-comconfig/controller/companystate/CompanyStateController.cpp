#include "stdafx.h"
#include "CompanyStateController.h"

inline void init(const CompanyAddStateDTO::Wrapper& correct, const CompanyAddStateDTO::Wrapper& wrong) {
	correct->clientid = "1";
	correct->clientname = ZH_WORDS_GETTER("companystate.name");
	correct->state = ZH_WORDS_GETTER("companystate.state");


	wrong->clientid = "-1";
	wrong->clientname = "";
	wrong->state = "";
}

CompanyStateJsonVO::Wrapper CompanyStateController::execAddCompanyInfo(const CompanyAddStateDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto jvo = CompanyStateJsonVO::createShared();

	auto correct = CompanyAddStateDTO::createShared();
	auto wrong = CompanyAddStateDTO::createShared();

	init(correct, wrong);

	if (!dto->clientid || !dto->clientname || !dto->state)
	{
		jvo->init(wrong, RS_PARAMS_INVALID);
		//jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (!dto->clientid || !dto->clientname || !dto->state)
	{
		jvo->init(wrong, RS_PARAMS_INVALID);
		//jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	//// 定义一个Service
	CompanyStateService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto, payload);
	if (id > 0) {
		jvo->success(correct);
		//jvo->success(nullptr);
	}
	else
	{
		jvo->fail(wrong);
		//jvo->fail(nullptr);
	}
	return jvo;
}
// 3.3 演示企业信息录修改数据
CompanyStateJsonVO::Wrapper CompanyStateController::execModifyCompanyInfo(const CompanyUpdateStateDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto jvo = CompanyStateJsonVO::createShared();

	auto correct = CompanyAddStateDTO::createShared();
	auto wrong = CompanyAddStateDTO::createShared();

	init(correct, wrong);

	// 参数校验
	if (!dto->clientid)
	{
		jvo->init(wrong, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	CompanyStateService service;
	 //执行数据修改
	if (service.updateData(dto, payload)) {
		jvo->success(correct);
	}
	else
	{
		jvo->fail(wrong);
	}
	//// 响应结果
	return jvo;
}

/*检查需要上传的批量公司id是否合法*/
inline bool check1(const CompanyRemoveStateDTO::Wrapper& id) {
	Vector<String> ids = id->companyId;
	for (const auto& companyId : *ids) {
		if (!companyId) {
			return false;
		}
	}
	return true;
}


//不可以传引用vector<string>&！！！返回的引用会指向一个已经销毁的对象
//不可以传引用vector<string>&！！！返回的引用会指向一个已经销毁的对象
//不可以传引用vector<string>&！！！返回的引用会指向一个已经销毁的对象
inline std::vector<std::string> to_vector(const CompanyRemoveStateDTO::Wrapper& id) {
	vector<string> ans;
	Vector<String> ids = id->companyId;
	for (const auto& companyId : *ids) {
		ans.push_back(companyId);
	}
	return ans;
}


// 3.3 演示企业信息录删除数据
CompanyStateJsonVO::Wrapper CompanyStateController::execRemoveCompanyInfo(const CompanyRemoveStateDTO::Wrapper& id) {
	auto jvo = CompanyStateJsonVO::createShared();

	auto correct = CompanyAddStateDTO::createShared();
	auto wrong = CompanyAddStateDTO::createShared();

	init(correct, wrong);

	//// 参数校验
	if (!check1(id))
	{
		jvo->init(wrong, RS_PARAMS_INVALID);
		return jvo;
	}
	//// 定义一个Service
	CompanyStateService service;
	service.removeData1(to_vector(id));
	//// 执行数据删除
	if (service.removeData1(to_vector(id))) {
		jvo->success(correct);
	}
	else
	{
		jvo->fail(wrong);
	}

	return jvo;
}
