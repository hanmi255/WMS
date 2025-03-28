#pragma once
#ifndef CDMDAO
#define CDMDAO
#include "domain/do/comdegdm/CdmDO.h"
#include "BaseDAO.h"

class CdmDAO : public BaseDAO
{
public:
	// 修改数据
   int  update(const CdmDO& uObj);
   //通过id批量删除数据
   int deleteById(vector<string>& ids);
   // 查询所有的com_type_code 和 com_type_name数据：企业属性
   std::list<CdmDO> getAllattri();
};
#endif 