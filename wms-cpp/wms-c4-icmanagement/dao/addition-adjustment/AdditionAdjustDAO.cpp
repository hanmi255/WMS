#include "stdafx.h"
//#include "SampleDAO.h"
#include "AdditionAdjustDAO.h"
//#include "SampleMapper.h"
#include "AdditionAdjustMapper.h"
#include <sstream>


int AdditionDAO::update(const AdditionDO& uObj)
{
	string sql = "UPDATE `wm_to_up_goods` SET `order_id`=?, `goods_id`=?, `goods_name`=? WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s%s%s%s", uObj.getOrder_id(), uObj.getGoods_id(), uObj.getGoods_name(), uObj.getId());
}