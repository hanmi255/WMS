#pragma once

#ifndef _DELETECANGKUDTO_H_
#define _DELETECANGKUDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class DeleteCangkuDTO : public oatpp::DTO
{
	DTO_INIT(DeleteCangkuDTO, DTO);

	//	≤÷ø‚ID
	DTO_FIELD(List<String>, id) = {"d31f1ece - aa77 - 48ea - a5fc - 6792bbd48dbe","402882729517cd6f019517cd6fb80000","402882729517cd6f019517cdf0830001"};
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("Cangku.EndPoint.delete_cangku.params.ids");
	}

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DELETECANGKUDTO_H_

