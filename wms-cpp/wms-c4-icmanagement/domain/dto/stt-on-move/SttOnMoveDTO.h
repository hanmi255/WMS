#pragma once

#ifndef _STT_ON_MOVE_DTO_
#define _STT_ON_MOVE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/*
*	动碰盘点基础数据对象，列表显示内容
*/
class SttOnMoveBaseDTO : public oatpp::DTO 
{
	DTO_INIT(SttOnMoveBaseDTO, oatpp::DTO);

	// 移动日期
	API_DTO_FIELD_DEFAULT(String, last_move, ZH_WORDS_GETTER("sttOnMove.field.lastMove"));
	// 库存类型
	API_DTO_FIELD_DEFAULT(String, cktype, ZH_WORDS_GETTER("sttOnMove.field.kuctype"));
	// 储位 or 库位编码
	API_DTO_FIELD_DEFAULT(String, bin_id, ZH_WORDS_GETTER("sttOnMove.field.kuWeiBianMa"));
	// 托盘
	API_DTO_FIELD_DEFAULT(String, tin_id, ZH_WORDS_GETTER("sttOnMove.field.binId"));
	// 货主
	API_DTO_FIELD_DEFAULT(String, cus_code, ZH_WORDS_GETTER("sttOnMove.field.cusCode"));
	// 货主名称
	API_DTO_FIELD_DEFAULT(String, cus_name, ZH_WORDS_GETTER("sttOnMove.field.zhongWenQch"));
	// 商品编码
	API_DTO_FIELD_DEFAULT(String, goods_id, ZH_WORDS_GETTER("sttOnMove.field.goodsId"));
	// 商品数量
	API_DTO_FIELD_DEFAULT(String, goods_qua, ZH_WORDS_GETTER("sttOnMove.field.goodsQua"));
	// 商品名称
	API_DTO_FIELD_DEFAULT(String, goods_name, ZH_WORDS_GETTER("sttOnMove.field.shpMingCheng"));
	// 生产日期
	API_DTO_FIELD_DEFAULT(String, goods_pro_data, ZH_WORDS_GETTER("sttOnMove.field.goodsProData"));
	// 保质期
	API_DTO_FIELD_DEFAULT(String, goods_save_date, ZH_WORDS_GETTER("sttOnMove.field.bzhiQi"));
	// 单位
	API_DTO_FIELD_DEFAULT(String, goods_unit, ZH_WORDS_GETTER("sttOnMove.field.goodsUnit"));
	// 基本单位
	API_DTO_FIELD_DEFAULT(String, base_unit, ZH_WORDS_GETTER("sttOnMove.field.baseUnit"));
	// 盘点状态
	API_DTO_FIELD_DEFAULT(String, stt_sta, ZH_WORDS_GETTER("sttOnMove.field.sttSta"));
};


/*
* 动碰盘点列表对象，带唯一标识
*/
class SttOnMoveListDTO : public SttOnMoveBaseDTO
{
	DTO_INIT(SttOnMoveListDTO, SttOnMoveBaseDTO);

	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("sttOnMove.field.id"));
};

/*
* 动碰盘详情数据对象
*/
class SttOnMoveDetailDTO : public SttOnMoveListDTO
{
	DTO_INIT(SttOnMoveDetailDTO, SttOnMoveListDTO);
	// 移动状态
	API_DTO_FIELD_DEFAULT(String,move_sta,ZH_WORDS_GETTER("sttOnMove.field.move_sta"));
	// 部门
	API_DTO_FIELD_DEFAULT(String, sys_org_code,ZH_WORDS_GETTER("sttOnMove.field.sys_org_code"));
	// 公司
	API_DTO_FIELD_DEFAULT(String, sys_company_code,ZH_WORDS_GETTER("sttOnMove.field.sys_company_code"));
};

/*
* 动碰盘点分页查询结果对象
*/
class SttOnMovePageDTO : public PageDTO<SttOnMoveListDTO::Wrapper>
{
	DTO_INIT(SttOnMovePageDTO, PageDTO<SttOnMoveListDTO::Wrapper>);
};

/*
* 由动碰盘生成盘点任务DTO，对象包含查询id数组,也用于返回查询成功的id
*/
class SttOnMoveInsertTaskDTO : public oatpp::DTO
{
	DTO_INIT(SttOnMoveInsertTaskDTO,DTO);

	API_DTO_FIELD_DEFAULT(Vector<String>,ids,ZH_WORDS_GETTER("sttOnMove.field.ids"));
};

#include OATPP_CODEGEN_END(DTO)

#endif