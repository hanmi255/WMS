#include "stdafx.h"
#include "controller/bagoodstype/BaGoodsTypeController.h"
#include "../../service/bagoodstype/BaGoodsTypeService.h"
#include "../ApiDeclarativeServicesHelper.h"


BaGoodsTypePageJsonVO::Wrapper BaGoodsTypeController::execQueryBaGoodsType(const BaGoodsTypeQuery::Wrapper& query, const PayloadDTO& payload) {
	BaGoodsTypeService service;
	auto result = service.listAll(query);
	auto jvo = BaGoodsTypePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}