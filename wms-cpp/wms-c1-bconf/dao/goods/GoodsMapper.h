#ifndef _GOODSMAPPER_H_
#define _GOODSMAPPER_H_


 #include "../../domain/do/goods/GoodsDo.h"
 #include "Mapper.h"
 
 class GoodsMapper : public Mapper<GoodsDo>
 {
 public:
 	GoodsDo mapper(ResultSet* resultSet) const override 
 	{
 		GoodsDo data;
 		data.setID(resultSet->getInt(1));
 		data.setCategory_code(resultSet->getString(2));
 		data.setCategory_name(resultSet->getString(3));
 		data.setCategory_level(resultSet->getInt(4));
 		data.setPID(resultSet->getInt(5));
 		data.setTop_node(resultSet->getString(6));
 		return data;
 	}
 };

 
#endif 
