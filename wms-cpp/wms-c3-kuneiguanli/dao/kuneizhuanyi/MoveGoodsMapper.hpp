#include "Mapper.h"
#include "domain/do/kuneizhuanyi/MoveGoodsDO.h"

template <typename T>
class GenericMapper : public Mapper<T> {
public:
	T mapper(ResultSet* resultSet) const override
	{
		T data;
		data.setId(resultSet->getString("id"));
		data.setCreateName(resultSet->getString("create_name"));
		data.setCreateBy(resultSet->getString("create_by"));
		data.setCreateDate(resultSet->getString("create_date"));
		data.setUpdateName(resultSet->getString("update_name"));
		data.setUpdateBy(resultSet->getString("update_by"));
		data.setUpdateDate(resultSet->getString("update_date"));
		data.setSysOrgCode(resultSet->getString("sys_org_code"));
		data.setSysCompanyCode(resultSet->getString("sys_company_code"));
		data.setOrderTypeCode(resultSet->getString("order_type_code"));
		data.setOrderId(resultSet->getString("order_id"));
		data.setOrderIdI(resultSet->getString("order_id_i"));
		data.setGoodsId(resultSet->getString("goods_id"));
		data.setGoodsName(resultSet->getString("goods_name"));
		data.setGoodsQua(resultSet->getString("goods_qua"));
		data.setGoodsProData(resultSet->getString("goods_pro_data"));
		data.setGoodsUnit(resultSet->getString("goods_unit"));
		data.setCusCode(resultSet->getString("cus_code"));
		data.setCusName(resultSet->getString("cus_name"));
		data.setTinFrom(resultSet->getString("tin_from"));
		data.setTinId(resultSet->getString("tin_id"));
		data.setBinFrom(resultSet->getString("bin_from"));
		data.setBinTo(resultSet->getString("bin_to"));
		data.setMoveSta(resultSet->getString("move_sta"));
		data.setToCusCode(resultSet->getString("to_cus_code"));
		data.setToCusName(resultSet->getString("to_cus_name"));
		data.setBaseUnit(resultSet->getString("base_unit"));
		data.setBaseGoodscount(resultSet->getString("base_goodscount"));
		data.setToGoodsProData(resultSet->getString("to_goods_pro_data"));
		data.setRunSta(resultSet->getString("run_sta"));

		return data;
	}
};

using MoveGoodsMapper = GenericMapper<MoveGoodsDO>;
using PtrMoveGoodsMapper = GenericMapper<PtrMoveGoodsDO>;