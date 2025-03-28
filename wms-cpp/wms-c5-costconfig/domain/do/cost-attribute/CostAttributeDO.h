#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: wrzljrj
 @Date: 2025/02/26 17:48:12

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef  _COST_ATTRIBUTE_DO_
#define  _COST_ATTRIBUTE_DO_

#include "../DoInclude.h"

// DO
class CostSxDO {
    // 主键
    CC_SYNTHESIZE(std::string, id, Id);
    CC_SYNTHESIZE(string, code, Code);
    CC_SYNTHESIZE(string, name, Name);
    CC_SYNTHESIZE(std::string, create_name, CreateName);
    CC_SYNTHESIZE(std::string, create_by, CreateBy);
    CC_SYNTHESIZE(std::string, update_name, UpdateName);
    CC_SYNTHESIZE(std::string, update_by, UpdateBy);
    CC_SYNTHESIZE(std::string, sys_org_code, SysOrgCode);
    CC_SYNTHESIZE(std::string, sys_company_code, SysCompanyCode);
    CC_SYNTHESIZE(std::string, create_date, CreateDate);
    CC_SYNTHESIZE(std::string, update_date, UpdateDate);

public:
    CostSxDO() {
        id = "";
        code = "";
        name = "";
        create_name = "";
        create_by = "";
        update_name = "";
        update_by = "";
        create_date = "";
        update_date = "";
        sys_org_code = "";
        sys_company_code = "";
    }

};
class CostAttributeDO {
    //// 主键
    //CC_SYNTHESIZE(std::string, id, Id);
    //CC_SYNTHESIZE(string, code, Code);
    //CC_SYNTHESIZE(string, name, Name);
    //CC_SYNTHESIZE(std::string, create_name, CreateName);
    //CC_SYNTHESIZE(std::string, create_by, CreateBy);
    //CC_SYNTHESIZE(std::string, update_name, UpdateName);
    //CC_SYNTHESIZE(std::string, update_by, UpdateBy);
    //CC_SYNTHESIZE(std::string, sys_org_code, SysOrgCode);
    //CC_SYNTHESIZE(std::string, sys_company_code, SysCompanyCode);
    //CC_SYNTHESIZE(std::string, create_date, CreateDate);
    //CC_SYNTHESIZE(std::string, update_date, UpdateDate);


    // 唯一编号,主键
    CC_SYNTHESIZE(string, id, Id);
    // 创建人名称
    CC_SYNTHESIZE(string, create_name, CreateName);
    // 创建人登录名称
    CC_SYNTHESIZE(string, create_by, CreateBy);
    // 创建日期(日期类型)
    CC_SYNTHESIZE(string, create_date, CreateDate);
    // 更新人名称
    CC_SYNTHESIZE(string, update_name, UpdateName);
    // 更新人登录名称
    CC_SYNTHESIZE(string, update_by, UpdateBy);
    // 更新日期(日期类型)
    CC_SYNTHESIZE(string, update_date, UpdateDate);
    // 所属部门
    CC_SYNTHESIZE(string, sys_org_code, SysOrgCode);
    // 所属公司
    CC_SYNTHESIZE(string, sys_company_code, SysCompanyCode);
    // 客户计费属性编码
    CC_SYNTHESIZE(string, kehushuxing_code, KeHuShuXingCode);
    // 客户计费属性名称
    CC_SYNTHESIZE(string, kehushuxing_name, KeHuShuXingName);
public:
    CostAttributeDO() {
        /*    id = "";
            code = "";
            name = "";
            create_name = "";
            create_by = "";
            update_name = "";
            update_by = "";
            create_date = "";
            update_date = "";
            sys_org_code = "";
            sys_company_code = "";*/

        id = "唯一编号,主键";
        create_name = "创建人名称";
        create_by = "创建人登录名称";
        create_date = "创建日期(日期类型)";
        update_name = "更新人名称";
        update_by = "更新人登录名称";
        update_date = "更新日期(日期类型)";
        sys_org_code = "所属部门";
        sys_company_code = "所属公司";
        kehushuxing_code = "客户计费属性编码";
        kehushuxing_name = "客户计费属性名称";
    }

};

#endif //  _COST_ATTRIBUTE_DO_
