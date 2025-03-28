#pragma
#ifndef CDMDO
#define CDMDO
#include"DoInclude.h"

class CdmDO
{
	CC_SYNTHESIZE(string, id, Id);//主键
	CC_SYNTHESIZE(string, name, CDMName); // 企业名称
public:
	CdmDO() {
		id = "";
		name = "";
	}
};
#endif 