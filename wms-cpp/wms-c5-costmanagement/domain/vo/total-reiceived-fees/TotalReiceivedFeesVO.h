#pragma once

#ifndef _TOTAL_RECEIVED_FEES_VO_
#define _TOTAL_RECEIVED_FEES_VO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


class TotalReiceivedFeesVO : public oatpp::DTO {
	DTO_INIT(TotalReiceivedFeesVO, DTO);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("TRF.id"));
	//API_DTO_FIELD_DEFAULT(String, creatorname, ZH_WORDS_GETTER("TRF.creatorname"));
	//API_DTO_FIELD_DEFAULT(String, createdate, ZH_WORDS_GETTER("TRF.createdate"));
	//API_DTO_FIELD_DEFAULT(String, updatename, ZH_WORDS_GETTER("TRF.updatename"));
	//API_DTO_FIELD_DEFAULT(String, updatedate, ZH_WORDS_GETTER("TRF.updatedate"));
	API_DTO_FIELD_DEFAULT(String, tax_exclusiveprice, ZH_WORDS_GETTER("TRF.taxexclusiveprice"));
	API_DTO_FIELD_DEFAULT(String, taxamount, ZH_WORDS_GETTER("TRF.taxamount"));
	
	API_DTO_FIELD_DEFAULT(String, taxinclusiveprice, ZH_WORDS_GETTER("TRF.taxinclusiveprice"));
	API_DTO_FIELD_DEFAULT(String, billingquantity, ZH_WORDS_GETTER("TRF.billingquantity"));
	API_DTO_FIELD_DEFAULT(String, unityofquantity, ZH_WORDS_GETTER("TRF.unityofquantity"));
	API_DTO_FIELD_DEFAULT(Boolean, issettleaccounts, ZH_WORDS_GETTER("TRF.issettleaccounts"));

	API_DTO_FIELD_DEFAULT(String, originalprice, ZH_WORDS_GETTER("TRF.originalprice"));
	API_DTO_FIELD_DEFAULT(String, feedate, ZH_WORDS_GETTER("TRF.feedate"));
	API_DTO_FIELD_DEFAULT(String, customers, ZH_WORDS_GETTER("TRF.customers"));
	API_DTO_FIELD_DEFAULT(String, customersname, ZH_WORDS_GETTER("TRF.customersname"));
	API_DTO_FIELD_DEFAULT(String, fees, ZH_WORDS_GETTER("TRF.fees"));
	API_DTO_FIELD_DEFAULT(String, feesname, ZH_WORDS_GETTER("TRF.feesname"));
};

//class TotalReiceivedFeesJsonVO :public JsonVO<TotalReiceivedFeesVO::Wrapper> {
//	DTO_INIT(TotalReiceivedFeesJsonVO, JsonVO<TotalReiceivedFeesVO::Wrapper>);
//};

class TotalReiceivedFeesPageVO :public PageDTO<TotalReiceivedFeesVO::Wrapper> {
	DTO_INIT(TotalReiceivedFeesPageVO, PageDTO<TotalReiceivedFeesVO::Wrapper>);
};


class TotalReiceivedFeesPageJsonVO :public JsonVO<TotalReiceivedFeesPageVO::Wrapper> {
	DTO_INIT(TotalReiceivedFeesPageJsonVO, JsonVO<TotalReiceivedFeesPageVO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_TOTAL_RECEIVED_FEES_VO_








