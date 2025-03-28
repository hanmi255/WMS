#include "BusinessLinkController.h"

BusinessLinkNameListJsonVO::Wrapper BusinessLinkController::execQueryBusinessLinkNameList()
{
	return BusinessLinkNameListJsonVO::createShared();
}

BusinessLinkPageJsonVO::Wrapper BusinessLinkController::execQueryBusinessLink(const BusinessLinkPageDTO::Wrapper& query, const PayloadDTO& payload)
{
	return BusinessLinkPageJsonVO::createShared();
}

Uint64JsonVO::Wrapper BusinessLinkController::execAddBusinessLink(const BusinessLinkAddDTO::Wrapper& dto)
{
	return Uint64JsonVO::createShared();
}