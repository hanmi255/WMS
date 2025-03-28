#include "stdafx.h"
#include "CostConfigController.h"

inline vector<string> to_vector(const CddDTO::Wrapper& id) {
	vector<string> ans;
	Vector<String> ids = id->companyId;
	for (const auto& companyId : *ids) {
		ans.push_back(companyId);
	}
	return ans;
}

StringJsonVO::Wrapper CostConfigController::execwaydelete(const CddDTO::Wrapper& id)
{

	auto jvo = StringJsonVO::createShared();
		CdmService service;
		vector<string> ids = to_vector(id);

		// Ö´ÐÐÊý¾ÝÉ¾³ý
		if (service.removeData(ids)) {
			jvo->success("success");
		}
		else
		{
			jvo->fail("fail");
		}

		return jvo;
	
}
