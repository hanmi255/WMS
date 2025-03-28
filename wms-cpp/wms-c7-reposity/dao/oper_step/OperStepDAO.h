/*
/*@File Name         : OperStepDAO.h                                                     
/*@Author            : 智商局局长
/*@Description       :
*/
#ifndef _OperStep_DAO_
#define _OperStep_DAO_
#include "BaseDAO.h"
#include "domain/do/oper_step/OperStepDO.h"

class OperStepDAO : public BaseDAO {
public:
	bool del(const OperStepDO& dObj);
	bool update(const OperStepDO& uObj);
	std::list<OperStepDO> selectAll();
	bool insertFromExcel(const std::list<OperStepDO>& iObj);

};
#endif // !_OperStep_DAO_

