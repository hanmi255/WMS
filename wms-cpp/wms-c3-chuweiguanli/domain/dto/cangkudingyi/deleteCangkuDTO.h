#pragma once

#ifndef _DELETECANGKUDTO_H_
#define _DELETECANGKUDTO_H_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

//	删除仓库接口的DTO
class DeleteCangkuDTO : public oatpp::DTO
{
	DTO_INIT(DeleteCangkuDTO, DTO);

	//	仓库ID
	DTO_FIELD(oatpp::List<oatpp::String>, id) = {"d31f1ece - aa77 - 48ea - a5fc - 6792bbd48dbe","402882729517cd6f019517cd6fb80000","402882729517cd6f019517cdf0830001"};
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("Cangku.EndPoint.delete_cangku.params.ids");
	}

};
//	导出仓库的DTO
class ExportCangkuDTO : public oatpp::DTO
{
	DTO_INIT(ExportCangkuDTO, DTO);

	//	仓库代码
	DTO_FIELD(List<String>, store_id) = { "01-FKD","68-FKD","02-FKD" };
	DTO_FIELD_INFO(store_id) {
		info->description = ZH_WORDS_GETTER("Cangku.EndPoint.down_load_cangku_excel.params.store_id");
	}

};

#include OATPP_CODEGEN_END(DTO)

#endif // !_DELETECANGKUDTO_H_

