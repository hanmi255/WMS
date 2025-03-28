#include "stdafx.h"
#include "CDMservice.h"
#include "dao/CDMDAO.h"
#include "domain/GlobalInclude.h"

string CDMService::modifyCDM(const CDMListDTO::Wrapper dto, const PayloadDTO& payload)
{
   CdmDO data;
	//ZO_STAR_DOMAIN_DTO_TO_DO(data, dto,
	//	Id, id,
	//	CDMName, name,
//);
	//data.setUpdateName(payload.getUsername());
	//data.setUpdateBy(payload.getId());
	
	CdmDAO dao;
	return dao.modify(data);
	//return {};
}


