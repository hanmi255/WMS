#include "stdafx.h"
#include "SttTaskDAO.h"
#include "domain/do/goods-manage/wm_stt_in_goodsDO.h"
#include "id/UuidFacade.h"
#include <sstream>
#include <ctime>



uint64_t SttTaskDAO::insert(const Wm_Stt_In_GoodsDO& iObj)
{
	// 未获取批次goods_batch
	string sql = "INSERT INTO `wm_stt_in_goods` (`id`,create_name,create_by,create_date,sys_org_code,sys_company_code,bin_id,tin_id,goods_id,goods_name,goods_qua,base_unit,goods_pro_data,goods_batch,cus_name,cus_code,stt_sta,stt_id,stt_type) VALUES( ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? , ? )";

	UuidFacade uf(1);

	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", uf.genUuid(), iObj.getCreateName(), iObj.getCreateBy(), iObj.getCreateDate(), iObj.getSysOrgCode(), iObj.getSysCompanyCode(), iObj.getBinId(), iObj.getTinId(), iObj.getGoodsId(), iObj.getGoodsName(), iObj.getGoodsQua(), iObj.getBaseUnit(), iObj.getGoodsProDate(), iObj.getGoodsBatch(), iObj.getCusName(), iObj.getCusCode(), iObj.getSttSta(), iObj.getSttId(), iObj.getSttType());
}

uint64_t SttTaskDAO::modifySttSta(const Wm_Stt_In_GoodsDO& iObj)
{
	string sql = "UPDATE `wm_stt_in_goods` SET update_name = ? , update_by = ? , update_date = ? , stt_sta = ? WHERE `id` = ?";

	return sqlSession->executeUpdate(sql,"%s%s%s%s%s", iObj.getUpdateName(), iObj.getUpdateBy(), iObj.getUpdateDate(), iObj.getSttSta(),iObj.getId());
}

