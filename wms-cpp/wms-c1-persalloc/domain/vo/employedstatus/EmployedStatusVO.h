#pragma once

#include "../../GlobalInclude.h"
#include "../../dto/employedstatus/EmployedStatusDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */
class EmployedStatusJsonVO : public JsonVO<EmployedStatusDTO::Wrapper> {
	DTO_INIT(EmployedStatusJsonVO, JsonVO<EmployedStatusDTO::Wrapper>);
};

/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class EmployedStatusPageJsonVO : public JsonVO<EmployedStatusDTO::Wrapper> {
	DTO_INIT(EmployedStatusPageJsonVO, JsonVO<EmployedStatusDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
