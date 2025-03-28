#pragma once


#ifndef _BILLING_NAME_DTO_
#define _BILLING_NAME_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class BillingNameDTO : public oatpp::DTO
{
    DTO_INIT(BillingNameDTO, DTO);
    DTO_FIELD(String, id) = "123456"; // 主键

};
class BillingNameBatchDTO :public oatpp::DTO
{
    DTO_INIT(BillingNameBatchDTO, DTO);
        DTO_FIELD(Vector<BillingNameDTO::Wrapper>, dtoList);  ///< 批量修改的数据列表
};
class BillingNamefileDTO :public oatpp::DTO
{
    DTO_INIT(BillingNamefileDTO, DTO);
    DTO_FIELD(String, id) = "123456"; // 主键
    DTO_FIELD(String, cost_code) = "123456";
    DTO_FIELD(String, cost_name) = "123456";
    DTO_FIELD(String, cost_type_code) = "123456";
    //DTO_FIELD(Vector<BillingNamefileDTO::Wrapper>, filedto);
};
class BillingNameVectorDTO :public oatpp::DTO
{
    DTO_INIT(BillingNameVectorDTO, DTO);
    DTO_FIELD(Vector<BillingNamefileDTO::Wrapper>, filedto);
};
#include OATPP_CODEGEN_END(DTO)

#endif // !_COST_NAME_DTO_