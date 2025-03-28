#include "stdafx.h"
#include <iostream>
#include "getLevelNameController.h"


EnterpriseLevelNameJseonVO::Wrapper LevelNameController::execGetLevelName()
{
	auto jvo = EnterpriseLevelNameJseonVO::createShared();
	EnterpriseLevelService service;
	auto  res = EnterpriseLevelNameDTO::createShared();
	try {
		res = service.getEnterpriseLevelName();
		jvo->success(res);
	}
	catch (const exception ep)
	{
		std::cout << "Exception : " << ep.what() << endl;
		jvo->fail(res);
	}
	return jvo;

}

