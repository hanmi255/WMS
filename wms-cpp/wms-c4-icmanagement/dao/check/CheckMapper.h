#pragma once

#ifndef _CHECK_MAPPER_
#define _CHECK_MAPPER_

#include "Mapper.h"
#include "../../domain/do/check/CheckDO.h"

/**
 * 盘点数据映射器
 */
class CheckMapper : public Mapper<CheckDO>
{
public:
    CheckDO mapper(ResultSet* resultSet) const override
    {
        CheckDO data;
        data.setId(resultSet->getString(1));
        data.setCreate_name(resultSet->getString(2));
        data.setCreate_by(resultSet->getString(3));
        data.setCreate_date(resultSet->getString(4));
        data.setUpdate_name(resultSet->getString(5));
        data.setUpdate_by(resultSet->getString(6));
        data.setUpdate_date(resultSet->getString(7));
        data.setSys_org_code(resultSet->getString(8));
        data.setSys_company_code(resultSet->getString(9));
        data.setBin_id(resultSet->getString(10));
        data.setTin_id(resultSet->getString(11));
        data.setGoods_id(resultSet->getString(12));
        data.setGoods_name(resultSet->getString(13));
        data.setGoods_qua(resultSet->getString(14));
        data.setGoods_unit(resultSet->getString(15));
        data.setGoods_pro_data(resultSet->getString(16));
        data.setGoods_batch(resultSet->getString(17));
        data.setStt_qua(resultSet->getString(18));
        data.setCus_name(resultSet->getString(19));
        data.setCus_code(resultSet->getString(20));
        data.setStt_sta(resultSet->getString(21));
        data.setBase_unit(resultSet->getString(22));
        data.setBase_goodscount(resultSet->getString(23));
        data.setStt_id(resultSet->getString(24));
        data.setGoods_code(resultSet->getString(25));
        data.setStt_type(resultSet->getString(26));
        data.setDong_xian(resultSet->getString(27));
        return data;
    }
};

/**
 * 盘点数据映射器（共享指针版本）
 */
class PtrCheckMapper : public Mapper<PtrCheckDO>
{
public:
    PtrCheckDO mapper(ResultSet* resultSet) const override
    {
        auto data = std::make_shared<CheckDO>();
        data->setId(resultSet->getString(1));
        data->setCreate_name(resultSet->getString(2));
        data->setCreate_by(resultSet->getString(3));
        data->setCreate_date(resultSet->getString(4));
        data->setUpdate_name(resultSet->getString(5));
        data->setUpdate_by(resultSet->getString(6));
        data->setUpdate_date(resultSet->getString(7));
        data->setSys_org_code(resultSet->getString(8));
        data->setSys_company_code(resultSet->getString(9));
        data->setBin_id(resultSet->getString(10));
        data->setTin_id(resultSet->getString(11));
        data->setGoods_id(resultSet->getString(12));
        data->setGoods_name(resultSet->getString(13));
        data->setGoods_qua(resultSet->getString(14));
        data->setGoods_unit(resultSet->getString(15));
        data->setGoods_pro_data(resultSet->getString(16));
        data->setGoods_batch(resultSet->getString(17));
        data->setStt_qua(resultSet->getString(18));
        data->setCus_name(resultSet->getString(19));
        data->setCus_code(resultSet->getString(20));
        data->setStt_sta(resultSet->getString(21));
        data->setBase_unit(resultSet->getString(22));
        data->setBase_goodscount(resultSet->getString(23));
        data->setStt_id(resultSet->getString(24));
        data->setGoods_code(resultSet->getString(25));
        data->setStt_type(resultSet->getString(26));
        data->setDong_xian(resultSet->getString(27));
        return data;
    }
};

#endif // !_CHECK_MAPPER_