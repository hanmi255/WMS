#ifndef _DISTRICTINFO_DO_
#define _DISTRICTINFO_DO_
#include "../DoInclude.h"

class BareaNameDO
{
	CC_SYNTHESIZE(string, id, Id);
	CC_SYNTHESIZE(string, barea_name, Barea_name);
public:
	BareaNameDO()
	{
		id = "id";
		barea_name = "name";
	}
};

class BareaInfoDO : public BareaNameDO
{
	CC_SYNTHESIZE(string, barea_code, Barea_code);
	CC_SYNTHESIZE(double, barea_rdata, Barea_rdata);
public:
	BareaInfoDO()
	{
		id = "id";
		barea_code = "barea_code";
		barea_name = "barea_name";
		barea_rdata = 10;
	}
};

#endif