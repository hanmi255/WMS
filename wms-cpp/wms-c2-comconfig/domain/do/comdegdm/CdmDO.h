#pragma
#ifndef CDMDO
#define CDMDO
#include"../DoInclude.h"

class CdmDO
{
	CC_SYNTHESIZE(string, id, Id);//Ö÷¼ü
	CC_SYNTHESIZE(string, cname, Cname);
	CC_SYNTHESIZE(string, cby, Cby);
	CC_SYNTHESIZE(string, cdate, Cdate);
	CC_SYNTHESIZE(string, uname, Uname);
	CC_SYNTHESIZE(string, uby, Uby);
	CC_SYNTHESIZE(string, udate, Udate);
	CC_SYNTHESIZE(string, soc, Soc);
	CC_SYNTHESIZE(string, scc, Scc);
	CC_SYNTHESIZE(string, cdn, Cdn);
	CC_SYNTHESIZE(string, cdd, Cdd);
public:
	CdmDO() {
		id = "";
		cname = "";
		cby = "";
		cdate = "";
		uname = "";
		uby = "";
		udate = "";
		soc = "";
		scc = "";
		cdn = "";
		cdd = "";
	}
};
#endif 