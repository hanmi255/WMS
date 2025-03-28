#include "stdafx.h"
#include "MyController.h"

StringJsonVO::Wrapper MyController::excuteTest(const PageQuery::Wrapper& query) 
{
	auto vo = StringJsonVO::createShared();
	vo->success(String(ZH_WORDS_GETTER("test")));
	return vo;
}