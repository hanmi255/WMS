#pragma once

#ifndef _STT_ON_MOVE_VO_
#define _STT_ON_MOVE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/stt-on-move/SttOnMoveDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 动碰盘列表JsonVO，用于响应给客户端的Json对象
 */
class SttOnMoveListJsonVO : public JsonVO<SttOnMoveListDTO::Wrapper> {
	DTO_INIT(SttOnMoveListJsonVO, JsonVO<SttOnMoveListDTO::Wrapper>);
};

/*
* 动碰盘详情JsonVO
*/
class SttOnMoveDetailJsonVO : public JsonVO<SttOnMoveDetailDTO::Wrapper>
{
	DTO_INIT(SttOnMoveDetailJsonVO, JsonVO<SttOnMoveDetailDTO::Wrapper>);
};

/**
 * 动碰盘列表分页显示JsonVO，用于响应给客户端的Json对象
 */
class SttOnMovePageJsonVO : public JsonVO<SttOnMovePageDTO::Wrapper> {
	DTO_INIT(SttOnMovePageJsonVO, JsonVO<SttOnMovePageDTO::Wrapper>);
};

/*
* 批量生成盘点任务JsonVO
*/
class SttOnMoveInsertTaskJsonVO : public JsonVO<SttOnMoveInsertTaskDTO::Wrapper>
{
	DTO_INIT(SttOnMoveInsertTaskJsonVO, JsonVO<SttOnMoveInsertTaskDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_STT_ON_MOVE_VO_