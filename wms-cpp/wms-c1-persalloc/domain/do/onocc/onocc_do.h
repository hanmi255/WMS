#ifndef _ONOCC_DO_
#define _ONOCC_DO_
#include "../DoInclude.h"

class EsDO
{
	CC_SYNTHESIZE(string, id, Id);

	CC_SYNTHESIZE(string, create_name, Create_Name);

	CC_SYNTHESIZE(string, create_by, Create_By);

	CC_SYNTHESIZE(string, create_date, Create_Date);

	CC_SYNTHESIZE(string, update_name, Update_Name);

	CC_SYNTHESIZE(string, update_by, Update_By);

	CC_SYNTHESIZE(string, update_date, Update_Date);

	CC_SYNTHESIZE(string, sys_org_code, Sys_Org_Code);

	CC_SYNTHESIZE(string, sys_company_code, Sys_Company_Code);

	CC_SYNTHESIZE(string, pos_sta_code, Pos_Sta_Code);

	CC_SYNTHESIZE(string, pos_sta_name, Pos_Sta_Name);
public:
	EsDO()
	{

	}
};


typedef std::shared_ptr<EsDO> PtrEsDO;

#endif