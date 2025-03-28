#pragma once
#ifndef _ADDITION_CONTROLLER_
#define _ADDITION_CONTROLLER_

#include "../../../lib-oatpp/include/domain/vo/BaseJsonVO.h"

#include "../../domain/vo/addition-adjustment/AdditionVO.h"
//#include "../../domain/query/removal-adjustment/RemovalQuery.h"
#include "../../domain/dto/addition-adjustment/AdditionDTO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class AdditionController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(AdditionController);
	// 3 定义接口
public:
	
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("addition-adjustment.post.batchmodify_goods"), batchmodifyAddition, StringJsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/addition-adjustment/batchmodify",batchmodifyAddition,BODY_DTO(AdditionBatchDTO::Wrapper,bathdto),execbatchAddition(bathdto));
private:
	StringJsonVO::Wrapper execbatchAddition(const AdditionBatchDTO::Wrapper& batchdto);
};
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // 