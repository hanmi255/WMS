#include "stdafx.h"
#include "CompanyInfoController.h"

inline void init(const CompanyAddInfoDTO::Wrapper& correct, const CompanyAddInfoDTO::Wrapper& wrong) {
	correct->companyId = "1";
	correct->zhabbr = ZH_WORDS_GETTER("companyinfo.zhabbr");
	correct->zhful = ZH_WORDS_GETTER("companyinfo.zhful");
	correct->zhaddr = ZH_WORDS_GETTER("companyinfo.zhaddr");
	correct->enabbr = "English Abbreviation";
	correct->enful = "English Full Name";

	wrong->companyId = "-1";
	wrong->zhabbr = "";
	wrong->zhful = "";
	wrong->zhaddr = "";
	wrong->enabbr = "";
	wrong->enful = "";
}

CompanyInfoJsonVO::Wrapper CompanyInfoController::execAddCompanyInfo(const CompanyAddInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto jvo = CompanyInfoJsonVO::createShared();

	auto correct = CompanyAddInfoDTO::createShared();
	auto wrong = CompanyAddInfoDTO::createShared();

	init(correct, wrong);

	if (!dto->companyId || !dto->zhabbr || !dto->zhful || !dto->zhaddr || !dto->enabbr || !dto->enful)
	{
		jvo->init(wrong, RS_PARAMS_INVALID);
		//jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->zhabbr->empty() || dto->zhful->empty() || dto->zhaddr->empty() || dto->enabbr->empty() || dto->enful->empty())
	{
		jvo->init(wrong, RS_PARAMS_INVALID);
		//jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	CompanyInfoService service;
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
CompanyInfoJsonVO::Wrapper CompanyInfoController::execModifyCompanyInfo(const CompanyUpdateInfoDTO::Wrapper& dto, const PayloadDTO& payload) {
	auto jvo = CompanyInfoJsonVO::createShared();

	auto correct = CompanyAddInfoDTO::createShared();
	auto wrong = CompanyAddInfoDTO::createShared();

	init(correct, wrong);

	// 参数校验
	if (!dto->companyId)
	{
		jvo->init(wrong, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	CompanyInfoService service;
	// 执行数据修改
	if (service.updateData(dto, payload)) {
		jvo->success(correct);
	}
	else
	{
		jvo->fail(wrong);
	}
	// 响应结果
	return jvo;
}

/*检查需要上传的批量公司id是否合法*/
inline bool check1(const CompanyRemoveInfoDTO::Wrapper& id) {
	Vector<String> ids = id->companyId;
	for (const auto& companyId : *ids) {
		if (!companyId) {
			return false;
		}
	}
	return true;
}

inline vector<string> to_vector(const CompanyRemoveInfoDTO::Wrapper& id) {
	vector<string> ans;
	Vector<String> ids = id->companyId;
	for (const auto& companyId : *ids) {
		ans.push_back(companyId);
	}
	return ans;
}

// 3.3 演示企业信息录删除数据
CompanyInfoJsonVO::Wrapper CompanyInfoController::execRemoveCompanyInfo(const CompanyRemoveInfoDTO::Wrapper& id) {
	auto jvo = CompanyInfoJsonVO::createShared();

	auto correct = CompanyAddInfoDTO::createShared();
	auto wrong = CompanyAddInfoDTO::createShared();

	init(correct, wrong);

	// 参数校验
	if (!check1(id))
	{
		jvo->init(wrong, RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	CompanyInfoService service;

	// 执行数据删除
	if (service.removeData(to_vector(id))) {
		jvo->success(correct);
	}
	else
	{
		jvo->fail(wrong);
	}

	return jvo;
}