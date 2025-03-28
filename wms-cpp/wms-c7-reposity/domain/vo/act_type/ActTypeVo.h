#pragma once

#ifndef _ACTTYPEVO_H_
#define _ACTTYPEVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/act_type/ActTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 定义一个作业类型的基础类型显示JsonVO对象，用于响应给客户端，或用于录入作业类型
 */
class ActTypeBaseJsonVO : public JsonVO<ActTypeBaseDTO::Wrapper>
{
	DTO_INIT(ActTypeBaseJsonVO, JsonVO<ActTypeBaseDTO::Wrapper>);
};

/**
 * 分页显示JsonVO对象，用于响应给客户端
 */

class ActTypePageJsonVO : public JsonVO<ActTypePageDTO::Wrapper>
{
	DTO_INIT(ActTypePageJsonVO, JsonVO<ActTypePageDTO::Wrapper>);
};

/**
 * 定义一个作业类型详细信息分页显示JsonVO对象，用于响应给客户端
 */
//class ActTypeListJsonVO : public JsonVO<ActTypePageDTO::Wrapper>
//{
//	DTO_INIT(ActTypeListJsonVO, JsonVO<ActTypePageDTO::Wrapper>);
//};

#include OATPP_CODEGEN_END(DTO)
#endif // _ACTTYPEVO_H_