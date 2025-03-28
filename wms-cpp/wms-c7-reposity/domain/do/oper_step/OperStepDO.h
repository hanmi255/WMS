#ifndef _OperStep_DO_
#define _OperStep_DO_
#include "../DoInclude.h"

class OperStepDO {

    CC_SYNTHESIZE(string, ID, Id);
    CC_SYNTHESIZE(string, create_name, Create_name);
    CC_SYNTHESIZE(string, create_by, Create_by);
    CC_SYNTHESIZE(string, create_date, Create_date);
    CC_SYNTHESIZE(string, oper_step_code, Oper_step_code);
    CC_SYNTHESIZE(string, oper_step_name, Oper_step_name);
    CC_SYNTHESIZE(string, update_name, Update_name);
    CC_SYNTHESIZE(string, update_by, Update_by);
    CC_SYNTHESIZE(string, update_date, Update_date);
    CC_SYNTHESIZE(string, sys_org_code, Sys_org_code);
    CC_SYNTHESIZE(string, sys_company_code, Sys_company_code);

public:
    OperStepDO() {
        ID = "admin";
        create_name = "admin";
        create_by = "admin";
        create_date = "2019-01-01 00:00:00";
        oper_step_code = "0";
        oper_step_name = "xxx";
        update_name = "admin";
        update_by = "admin";
        update_date = "2019-01-01 00:00:00";
        sys_org_code = "0";
        sys_company_code = "0";

    }
};




#endif // !_OperStep_DO_

