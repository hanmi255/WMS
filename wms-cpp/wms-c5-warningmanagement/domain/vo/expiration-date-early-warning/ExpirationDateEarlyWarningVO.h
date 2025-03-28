#pragma once
#ifndef _EXPIRATION_DATE_EARLY_WARNING_VO_
#define _EXPIRATION_DATE_EARLY_WARNING_VO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例分页查询对象
 */
class ExpirationDateEarlyWarningVO : public oatpp::DTO
{
	DTO_INIT(ExpirationDateEarlyWarningVO, DTO);
	// 姓名
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("EWM.id"));
	API_DTO_FIELD_DEFAULT(String, productcode, ZH_WORDS_GETTER("EWM.productcode"));
	API_DTO_FIELD_DEFAULT(String, customerproductcode, ZH_WORDS_GETTER("EWM.customerproductcode"));
	API_DTO_FIELD_DEFAULT(String, productname, ZH_WORDS_GETTER("EWM.productname"));
	API_DTO_FIELD_DEFAULT(String, customercode, ZH_WORDS_GETTER("EWM.customercode"));
	API_DTO_FIELD_DEFAULT(String, customername, ZH_WORDS_GETTER("EWM.customername"));
	API_DTO_FIELD_DEFAULT(String, productiondate, ZH_WORDS_GETTER("EWM.productiondate"));
	API_DTO_FIELD_DEFAULT(String, expirationdate, ZH_WORDS_GETTER("EWM.expirationdate"));
	//API_DTO_FIELD_DEFAULT(String, Thelowervalueoftheremainingratio, ZH_WORDS_GETTER("EWM.The lower value of the remaining ratio"));
	//API_DTO_FIELD_DEFAULT(String, Theuppervalueoftheremainingratio, ZH_WORDS_GETTER("EWM.The upper value of the remaining ratio"));
	API_DTO_FIELD_DEFAULT(String, theremainingratio, ZH_WORDS_GETTER("EWM.theremainingratio"));
	API_DTO_FIELD_DEFAULT(String, bzhi_qi, ZH_WORDS_GETTER("EWM.bzhi_qi"));
	API_DTO_FIELD_DEFAULT(Float64, res_date, ZH_WORDS_GETTER("EWM.res_date"));

	API_DTO_FIELD_DEFAULT(String, inventorytype, ZH_WORDS_GETTER("EWM.inventorytype"));
	API_DTO_FIELD_DEFAULT(UInt64, basicquantity, ZH_WORDS_GETTER("EWM.basicquantity"));
	API_DTO_FIELD_DEFAULT(String, basicunit, ZH_WORDS_GETTER("EWM.basicunit"));
};

class ExpirationDateEarlyWarningPageVO :public PageDTO<ExpirationDateEarlyWarningVO::Wrapper> {
	DTO_INIT(ExpirationDateEarlyWarningPageVO, PageDTO<ExpirationDateEarlyWarningVO::Wrapper>);
};


class ExpirationDateEarlyWarningPageJsonVO :public JsonVO<ExpirationDateEarlyWarningPageVO::Wrapper> {
	DTO_INIT(ExpirationDateEarlyWarningPageJsonVO, JsonVO<ExpirationDateEarlyWarningPageVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EXPIRATION_DATE_EARLY_WARNING_VO_