#pragma once
/*
 @Author: tutu
 @Date: 2025/03/05 14:21:55
*/
#ifndef _PLC_MAPPER_
#define _PLC_MAPPER_

#include "Mapper.h"
#include "../../domain/do/plc-file/PlcFileDO.h"

class PlcBaseMapper : public Mapper<PlcBaseDO>
{
public:
	PlcBaseDO mapper(ResultSet* resultSet) const override
	{
		PlcBaseDO data;
		data.setid(resultSet->getString(1));
		data.setplc_ip(resultSet->getString(2));
		data.setplc_port(resultSet->getString(3));
		data.setplc_type(resultSet->getString(4));
		data.setremark1(resultSet->getString(5));
		data.setcom_no(resultSet->getString(6));
		return data;
	}
};
class PtrPlcBaseMapper : public Mapper<PtrPlcBaseDO>
{
public:
	PtrPlcBaseDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<PlcBaseDO>();
		data->setid(resultSet->getString(1));
		data->setplc_ip(resultSet->getString(2));
		data->setplc_port(resultSet->getString(3));
		data->setplc_type(resultSet->getString(4));
		data->setremark1(resultSet->getString(5));
		data->setcom_no(resultSet->getString(6));
		return data;
	}
};
class PlcMapper : public Mapper<PlcDO>
{
public:
	PlcDO mapper(ResultSet* resultSet) const override//将sql结果集转换为SampleDO对象
	{
		PlcDO data;
		data.setid(resultSet->getString(1));
		data.setplc_ip(resultSet->getString(11));
		data.setplc_port(resultSet->getString(12));
		data.setplc_type(resultSet->getString(13));
		data.setcom_remark(resultSet->getString(14));
		data.setcom_time(resultSet->getString(15));
		data.setcom_seq(resultSet->getString(16));
		data.setcom_cons(resultSet->getString(17));
		data.setremark1(resultSet->getString(18));
		data.setcom_no(resultSet->getString(19));
		data.setquery01(resultSet->getString(20));
		data.setquery02(resultSet->getString(21));
		data.setsetp_time(resultSet->getString(22));
		data.setsetp_num(resultSet->getString(23));
		return data;
	}
};

class PtrPlcMapper : public Mapper<PtrPlcDO>
{
public:
	PtrPlcDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<PlcDO>();
		data->setid(resultSet->getString(1));
		data->setplc_ip(resultSet->getString(2));
		data->setplc_port(resultSet->getString(3));
		data->setplc_type(resultSet->getString(4));
		data->setcom_remark(resultSet->getString(5));
		data->setcom_time(resultSet->getString(6));
		data->setcom_seq(resultSet->getString(7));
		data->setcom_cons(resultSet->getString(8));
		data->setremark1(resultSet->getString(9));
		data->setcom_no(resultSet->getString(10));
		data->setquery01(resultSet->getString(11));
		data->setquery02(resultSet->getString(12));
		data->setsetp_time(resultSet->getString(13));
		data->setsetp_num(resultSet->getString(14));
		return data;
	}
};

#endif 