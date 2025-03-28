#pragma once

#ifndef _COST_NAME_DTO_
#define _COST_NAME_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class CostBaseDto : public oatpp::DTO
{
    DTO_INIT(CostBaseDto, DTO);
    DTO_FIELD(String, id)="4028804072df34cc0174a95c083d0016"; // 主键

    
};

class CostNameDTO : public CostBaseDto
{
    DTO_INIT(CostNameDTO, CostBaseDto);
    DTO_FIELD(String, cost_code)="2001";         // 费用代码
    
    DTO_FIELD(String, cost_name) = ZH_WORDS_GETTER("cost.cost_name.Billed_per_pallet");    // 费用名称
    DTO_FIELD(String, cost_type_code)="01";    // 费用类型代码
    DTO_FIELD(String, create_name)="admin";       // 创建人名称
    DTO_FIELD(String, create_by)="admin";         // 创建人登录名称
    DTO_FIELD(String, create_date)="2017-10-18 06:49:08";     // 创建日期
    DTO_FIELD(String, update_name)="admin";       // 更新人名称
    DTO_FIELD(String, update_by)="admin";         // 更新人登录名称
    DTO_FIELD(String, update_date)="2017-10-18 06:49:27";     // 更新日期
    DTO_FIELD(String, sys_org_code)="A04";      // 所属部门
    DTO_FIELD(String, sys_company_code)="A04";  // 所属公司
};



class CostListDTO : public oatpp::DTO
{
    DTO_INIT(CostListDTO, DTO);
    DTO_FIELD(List<CostNameDTO::Wrapper>, rows) = {};
public:
    void addData(CostNameDTO::Wrapper one)
    {
        this->rows->push_back(one);
    }

};




class CostListPageDTO : public PageDTO<CostNameDTO::Wrapper>
{
    DTO_INIT(CostListPageDTO, PageDTO<CostNameDTO::Wrapper>);
};

class CostAddDTO : public oatpp::DTO
{
    DTO_INIT(CostAddDTO, DTO);
    DTO_FIELD(String, cost_code) = "2001";           // 费用代码
    DTO_FIELD(String, cost_name) = ZH_WORDS_GETTER("cost.cost_name.Billed_per_pallet");       // 费用名称
    DTO_FIELD(String, cost_type_code) = "01";    // 费用类型代码
    //DTO_FIELD(String, create_name) = "admin";       // 创建人名称
    //DTO_FIELD(String, create_by) = "admin";         // 创建人登录名称
    //DTO_FIELD(String, create_date) = "2017-10-18 06:49:08";     // 创建日期
    //DTO_FIELD(String, sys_org_code) = "A04";      // 所属部门
    //DTO_FIELD(String, sys_company_code) = "A04";  // 所属公司
};

class CostModifyDTO : public CostBaseDto
{
    DTO_INIT(CostModifyDTO, CostBaseDto);
    DTO_FIELD(String, cost_code) = "2001";           // 费用代码
    DTO_FIELD(String, cost_name) = ZH_WORDS_GETTER("cost.cost_name.Billed_per_pallet");;         // 费用名称
    DTO_FIELD(String, cost_type_code) = "01";    // 费用类型代码
    //DTO_FIELD(String, update_name) = "admin";       // 更新人名称
    //DTO_FIELD(String, update_by) = "admin";         // 更新人登录名称
    //DTO_FIELD(String, update_date) = "2017-10-18 06:49:27";     // 更新日期
    //DTO_FIELD(String, sys_org_code) = "A04";      // 所属部门
    //DTO_FIELD(String, sys_company_code) = "A04";  // 所属公司
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_COST_NAME_DTO_