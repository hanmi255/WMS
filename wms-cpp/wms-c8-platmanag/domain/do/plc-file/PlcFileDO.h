#pragma once
/*
 @Author: tutu
 @Date: 2025/03/05 11:15:32
*/
#ifndef _PLC_DO_
#define _PLC_DO_
#include "../DoInclude.h"

/**
 * 数据库wms_plc实体类
 */
class PlcBaseDO
{
	CC_SYNTHESIZE(string, id, id);
	CC_SYNTHESIZE(string, plc_ip, plc_ip);
	CC_SYNTHESIZE(string, plc_port, plc_port);
	CC_SYNTHESIZE(string, plc_type, plc_type);
	CC_SYNTHESIZE(string, remark1, remark1);
	CC_SYNTHESIZE(string, com_no, com_no);
public:
	PlcBaseDO() {
		id = "";
		plc_ip = "";
		plc_port = "";
		plc_type = "";
		remark1 = "";
		com_no = "";
	}
};
class PlcDO
{
	CC_SYNTHESIZE(string, id, id);//protected变量id，ID用于生成生成getID和setID
	CC_SYNTHESIZE(string, plc_ip, plc_ip);
	CC_SYNTHESIZE(string, plc_port, plc_port);
	CC_SYNTHESIZE(string, plc_type, plc_type);
	CC_SYNTHESIZE(string, com_remark, com_remark);
	CC_SYNTHESIZE(string, com_time, com_time);
	CC_SYNTHESIZE(string, com_seq, com_seq);
	CC_SYNTHESIZE(string, com_cons, com_cons);
	CC_SYNTHESIZE(string, remark1, remark1);
	CC_SYNTHESIZE(string, com_no, com_no);
	CC_SYNTHESIZE(string, query01, query01);
	CC_SYNTHESIZE(string, query02, query02);
	CC_SYNTHESIZE(string, setp_time, setp_time);
	CC_SYNTHESIZE(string, setp_num, setp_num);
public:
	PlcDO() {
		id = "";
		plc_ip = "";
		plc_port = "";
		plc_type = "";
		com_remark = "";
		com_time = "";
		com_seq = "";
		com_cons = "";
		remark1 = "";
		com_no = "";
		query01 = "";
		query02 = "";
		setp_time = "";
		setp_num = "";
	}
};

//只能指针别名
typedef std::shared_ptr<PlcDO> PtrPlcDO;
typedef std::shared_ptr<PlcBaseDO> PtrPlcBaseDO;
#endif 
