
#include "stdafx.h"
#include "BusstyService.h"
#include "../wms-c7-reposity/dao/BusstyDAO.h"
#include "../wms-c7-reposity/domain/do/ba_buss_typeDO.h"
#include "../wms-c7-reposity/domain/dto/BusstyDTO.h"

bool BusstyService::removeData(uint64_t id)
{
	BusstyDAO dao;
	return dao.deleteById(id) == 1;
}
bool BusstyService::removedata(const uint64_t ID)
{
	BusstyDAO dao;
	return dao.deleteByID(ID) == 1;
}
bool BusstyService::leadin(std::vector<std::string> v)
{
	ba_buss_typeDO data; 
	data.setDesc(v.back()); v.pop_back();
	data.setName(v.back()); v.pop_back();
	data.setNum(v.back());  v.pop_back();

	BusstyDAO dao;
	return dao.leadin(data);
}
std::list<ba_buss_typeDO> BusstyService::leadout()
{
	BusstyDAO dao;
	return dao.leadout();
}