#pragma once
#ifndef _CITY_TYPE_SERVICE_
#define _CITY_TYPE_SERVICE_
#include <list>
#include "domain/vo/citytype/CityTypeVO.h"
#include "domain/dto/citytype/CityTypeDTO.h"
#include "domain/do/citytype/CityTypeDO.h"
#include "domain/query/citytype/CityTypeQuery.h"

class CityTypeService
{
public:
	bool removeData(std::string id);
	void import(const std::vector<std::vector<std::string>>& rowData, const PayloadDTO& payload);
	oatpp::List<CityTypeNameDTO::Wrapper> nameList();
	CityTypePageDTO::Wrapper listAll(const CityTypeQuery::Wrapper& query);
	std::vector<std::vector<std::string>> listAll();
	std::string Add(const CitytypeBaseDTO::Wrapper& dto, const PayloadDTO& payload);
	bool Udp(const CityTypeDTO::Wrapper& dto, const PayloadDTO& payload);
};

#endif 

