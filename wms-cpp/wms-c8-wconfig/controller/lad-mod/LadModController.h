#pragma once


#ifndef _LADMOD_CONTROLLER_
#define _LADMOD_CONTROLLER_


#include "domain/vo/BaseJsonVO.h"

#include "domain/query/lad-mod/LadModQuery.h"
#include "domain/dto/lad-mod/LadModDTO.h"
#include "domain/vo/lad-mod/LadModVO.h"
#include "domain/dto/lad-mod/BatchDeleteRequestDto.h"
#include "oatpp/core/data/stream/FileStream.hpp"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
*提货方式-信息管理
*/
class LadModController : public oatpp::web::server::api::ApiController {
	//注册入口
	API_ACCESS_DECLARE(LadModController);
public:
	
	// 查询接口描述信息
	ENDPOINT_INFO(queryAll) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("lad.query-all.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(LadModPageJsonVO);
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("lad.field.code"), "SELF", false);
		API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("lad.field.name"), "test", false);
	}
	//查询接口
	ENDPOINT(API_M_GET, "/wconfig/ladmod", queryAll, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型 解析为LadModQuery格式的数据,即我们在query里定义的查询模型,并存到ladQuery这个变量中
		API_HANDLER_QUERY_PARAM(ladQuery, LadModQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execQueryAll(ladQuery));
		
	}
	// 添加数据接口描述信息
	ENDPOINT_INFO(addLad) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("lad.add.summary"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	
	//添加数据接口 添加的数据格式为AddDTO，即我们在DTO里定义的数据格式,接口的名字叫addLad
	ENDPOINT(API_M_POST, "/wconfig/ladmod", addLad, BODY_DTO(LadModAddDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAddLad(dto));
	}

	//修改数据接口描述信息
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("lad.modify.summary"), modifyLadMod, Uint64JsonVO::Wrapper);
	//定义修改数据接口
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/wconfig/ladmod", modifyLadMod, BODY_DTO(LadModDTO::Wrapper, dto), execModifyLadMod(dto));

	// 删除单个接口描述信息
	ENDPOINT_INFO(deleteLad) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("lad.delete.summary"), Uint64JsonVO::Wrapper);
		// 定义参数说明
		API_DEF_ADD_QUERY_PARAMS(UInt64, "id", ZH_WORDS_GETTER("lad.field.id"), 1, true);
	}
	// 定义删除单个接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/wconfig/ladmod/delete", deleteLad, QUERY(UInt64, id), execDeleteLad(id));

	// 批量删除接口描述信息
	ENDPOINT_INFO(batchDelete) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("lad.batchDelete.summary"), Uint64JsonVO::Wrapper);
	}
	// 定义批量删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/wconfig/ladmod/batch-delete", batchDelete, BODY_DTO(BatchDeleteRequestDto::Wrapper, dto), execBatchDeleteLad(dto));

	// 导入提货方式接口描述信息
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("lad.import.summary"), importLad, StringJsonVO::Wrapper);
	// 导入提货方式端点定义
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/wconfig/ladmod/import", importLad, REQUEST(std::shared_ptr<IncomingRequest>, request), execImportLad(request));

	// 导出提货方式接口
	// 定义描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("lad.export.summary"), exportLad, StringJsonVO::Wrapper);
	// 定义端点
	API_HANDLER_ENDPOINT_NOPARAM_AUTH(API_M_GET, "/wconfig/ladmod/export", exportLad, execExportLad());
private:
	//查询结果为VO层中我们定义的PageJsonVo,即分页对象,传入参数为query层中的LadModQuery
	LadModPageJsonVO::Wrapper execQueryAll(const LadModQuery::Wrapper& query);
	//添加结果为VO层中的普通JsonVo,即普通显示对象,传入参数为DTO层中的AddDTO
	Uint64JsonVO::Wrapper execAddLad(const LadModAddDTO::Wrapper& dto);
	//修改结果为VO层中的普通JsonVo,即普通显示对象,传入参数为DTO层中的AddDTO(修改和添加都用的是AddDTO)
	Uint64JsonVO::Wrapper execModifyLadMod(const LadModDTO::Wrapper& dto);
	//删除单个提货方式
	Uint64JsonVO::Wrapper execDeleteLad(const oatpp::UInt64& id);
	//批量删除
	Uint64JsonVO::Wrapper execBatchDeleteLad(const BatchDeleteRequestDto::Wrapper& dto);
	//导入提货方式
	StringJsonVO::Wrapper execImportLad(std::shared_ptr<IncomingRequest> request);
	//导出提货方式
	StringJsonVO::Wrapper execExportLad();
};


// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen

#endif // _LadMod_CONTROLLER_