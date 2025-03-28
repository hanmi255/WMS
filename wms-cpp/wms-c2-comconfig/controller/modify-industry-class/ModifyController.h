#pragma once
#ifndef _MODIFY_CONTROLLER_
#define _MODIFY_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/modify-industry-class/ModifyDTO.h"


// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

class ModifyController : public oatpp::web::server::api::ApiController // 1 继承控制器
{
	// 2 定义控制器访问入口
	API_ACCESS_DECLARE(ModifyController);
public:
	// 3.1 定义修改接口描述
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("chengfeng.modify"), modifyClass, Uint64JsonVO::Wrapper);
	// 3.2 定义修改接口处理
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/indclas/modify-indclas", modifyClass, BODY_DTO(ModifyDTO::Wrapper, dto), execModifyClass(dto));

private:
	// 3.3 演示修改数据
	Uint64JsonVO::Wrapper execModifyClass(const ModifyDTO::Wrapper& dto);


};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_