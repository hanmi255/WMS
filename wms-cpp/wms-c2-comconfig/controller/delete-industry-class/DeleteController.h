#pragma once
#ifndef _DELETE_CONTROLLER_
#define _DELETE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "domain/dto/delete-industry-class/DeleteDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class DeleteController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(DeleteController);
	// 3 定义接口
public:
	// 3.1 定义删除接口描述
	ENDPOINT_INFO(DeleteClass) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("chengfeng.delete"), Uint64JsonVO::Wrapper);
		// 定义其他路径参数说明
		//API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("chengfeng.id"), 1, true);
	}
	// 3.2 定义删除接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/indclas/delete-indclas", DeleteClass, BODY_DTO(DeleteDTO::Wrapper, id), execDeleteClass(id));

	

private:	
	// 3.3 演示删除数据
	Uint64JsonVO::Wrapper execDeleteClass(const DeleteDTO::Wrapper& id);

	
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _DELETE_CONTROLLER_