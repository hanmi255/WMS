#pragma once
#ifndef _STT_ON_MOVE_CONTROLLER_
#define _STT_ON_MOVE_CONTROLLER_

#include "oatpp/web/server/api/ApiController.hpp"
#include <vector>
#include "domain/vo/BaseJsonVO.h"
#include "domain/query/stt-on-move/SttOnMoveQuery.h"
#include "domain/dto/stt-on-move/SttOnMoveDTO.h"
#include "domain/vo/stt-on-move/SttOnMoveVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 盘点管理-动碰盘信息管理
 */
class SttOnMoveController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	API_ACCESS_DECLARE(SttOnMoveController);
	
public:
	// 定义动碰盘列表分页查询接口描述
	ENDPOINT_INFO(queryAll)
	{
		//定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sttOnMove.summary.queryAll"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(SttOnMovePageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();

		// 定义其他查询参数描述
		// 最早移动日期
		API_DEF_ADD_QUERY_PARAMS(String, "last_move_start", ZH_WORDS_GETTER("sttOnMove.field.lastMoveStart"), "2001-01-01", false);
		// 最晚移动日期
		API_DEF_ADD_QUERY_PARAMS(String, "last_move_end", ZH_WORDS_GETTER("sttOnMove.field.lastMoveEnd"), "2001-01-01", false);
		// 库存类型
		API_DEF_ADD_QUERY_PARAMS(String, "cktype", ZH_WORDS_GETTER("sttOnMove.field.kuctype"), ZH_WORDS_GETTER("sttOnMove.exampleVal.kuc"), false);
		// 储位 or 库位编码
		API_DEF_ADD_QUERY_PARAMS(String, "bin_id", ZH_WORDS_GETTER("sttOnMove.field.kuWeiBianMa"), "1", false);
		// 托盘
		API_DEF_ADD_QUERY_PARAMS(String, "tin_id", ZH_WORDS_GETTER("sttOnMove.field.binId"), "A", false);
		// 货主
		API_DEF_ADD_QUERY_PARAMS(String, "cus_code", ZH_WORDS_GETTER("sttOnMove.field.cusCode"), "1250", false);
		// 货主名称
		API_DEF_ADD_QUERY_PARAMS(String, "cus_name", ZH_WORDS_GETTER("sttOnMove.field.zhongWenQch"), "xxxCompany", false);
		// 商品编码
		API_DEF_ADD_QUERY_PARAMS(String, "goods_id", ZH_WORDS_GETTER("sttOnMove.field.goodsId"), "123", false);
		// 最小商品数量
		API_DEF_ADD_QUERY_PARAMS(UInt64, "goods_qua_min", ZH_WORDS_GETTER("sttOnMove.field.goodsQuaMin"), 1, false);
		// 最大商品数量
		API_DEF_ADD_QUERY_PARAMS(UInt64, "goods_qua_max", ZH_WORDS_GETTER("sttOnMove.field.goodsQuaMax"), 1000, false);
		// 商品名称
		API_DEF_ADD_QUERY_PARAMS(String, "goods_name", ZH_WORDS_GETTER("sttOnMove.field.shpMingCheng"), "ThinkPad p14s", false);
		// 最早生产日期
		API_DEF_ADD_QUERY_PARAMS(String, "goods_pro_data_start", ZH_WORDS_GETTER("sttOnMove.field.goodsProDataStart"), "2001-01-01", false);
		//最晚生产日期
		API_DEF_ADD_QUERY_PARAMS(String, "goods_pro_data_end", ZH_WORDS_GETTER("sttOnMove.field.goodsProDataEnd"), "2001-01-01", false);
	}
	// 定义动碰盘列表分页查询接口处理
	ENDPOINT(API_M_GET,"/stt/stt-on-move",queryAll,QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_QUERY_PARAM(userQuery, SttOnMoveQuery, queryParams);
		API_HANDLER_RESP_VO(execQueryAll(userQuery));
	}

	// 定义动碰盘列表查看单个移动库存项详情信息接口描述
	ENDPOINT_INFO(queryOne)
	{
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sttOnMove.summary.queryOne"));
		// 定义默认授权参数
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(SttOnMoveDetailJsonVO);
		// 定义路径参数说明
		API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("sttOnMove.field.id"), "0000", true);
	}
	// 定义动碰盘列表查看单个移动库存项详情信息接口处理
	ENDPOINT(API_M_GET,"/stt/stt-on-move/{id}",queryOne, PATH(String, id), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_RESP_VO(execQueryOne(id));
	}

	// 定义盘点任务生成接口描述
	//ENDPOINT_INFO(insertSttTask)
	//{
	//	// 定义接口标题
	//	API_DEF_ADD_TITLE(ZH_WORDS_GETTER("sttOnMove.summary.genStt"));
	//	// 定义默认授权参数
	//	API_DEF_ADD_AUTH();
	//	// 定义响应参数格式
	//	API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	//	// 定义路径参数说明
	//	API_DEF_ADD_PATH_PARAMS(String, "id", ZH_WORDS_GETTER("sttOnMove.field.id"), "0000", true);
	//}
	//定义盘点任务生成接口处理
	//ENDPOINT(API_M_POST,"stt/stt-on-move/{id}", insertSttTask,PATH(String,id), API_HANDLER_AUTH_PARAME)
	//{
	//	API_HANDLER_RESP_VO(execInsertSttTask(id, authObject->getPayload()));
	//}
	
	// 定义盘点任务生成接口描述（支持批量）
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("sttOnMove.summary.insert_stt_task_multi"), insertSttTaskMulti, SttOnMoveInsertTaskJsonVO::Wrapper);

	//定义盘点任务生成接口处理（支持批量）
	ENDPOINT(API_M_POST, "stt/stt-on-move", insertSttTaskMulti, BODY_DTO(SttOnMoveInsertTaskDTO::Wrapper,dto), API_HANDLER_AUTH_PARAME)
	{
		API_HANDLER_RESP_VO(execInsertSttTaskMulti(dto, authObject->getPayload()));
	}

private:
	SttOnMovePageJsonVO::Wrapper execQueryAll(const SttOnMoveQuery::Wrapper& query);
	SttOnMoveDetailJsonVO::Wrapper execQueryOne(const String& id);
	//StringJsonVO::Wrapper execInsertSttTask(const String& id,const PayloadDTO& payload);
	SttOnMoveInsertTaskJsonVO::Wrapper execInsertSttTaskMulti(const SttOnMoveInsertTaskDTO::Wrapper& ids, const PayloadDTO& payload);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _STT_ON_MOVE_CONTROLLER_