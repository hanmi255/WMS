#pragma once
#ifndef _CHUWEI_VO_
#define _CHUWEI_VO_

#include "../../GlobalInclude.h"
#include "../../dto/chuweidingyi/QueryCWDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)


/**
 * 示例分页显示JsonVO，用于响应给客户端的Json对象
 */
class ChuWeiPageJsonVO : public JsonVO<QueryCWPageDTO::Wrapper> {
	DTO_INIT(ChuWeiPageJsonVO, JsonVO<QueryCWPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CHUWEI_VO_