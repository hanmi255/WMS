#include "stdafx.h"
#include "controller/bagoodstype/BaGoodsTypeController.h"
#include "../../service/bagoodstype/BaGoodsTypeService.h"
#include "../ApiDeclarativeServicesHelper.h"


BaGoodsTypeNamePageJsonVO::Wrapper BaGoodsTypeController::execQueryBaGoodsType(const BaGoodsTypeQuery::Wrapper& query, const PayloadDTO& payload) {
	BaGoodsTypeService service;
	auto result = service.listAll(query);
	auto jvo = BaGoodsTypeNamePageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}