#pragma once

#ifndef _CANGKU_VO_
#define _CANGKU_VO_

#include "../../GlobalInclude.h"
#include "../../dto/cangkudingyi/CangkuNameListDTO.h"
#include "../../dto/cangkudingyi/CangkuListDTO.h"
#include "../../dto/cangkudingyi/deleteCangkuDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

// 获取仓库名称列表的显示JsonVO
class CangkuNameListJsonVO : public JsonVO<oatpp::List<CangkuNameListDTO::Wrapper>> {
	DTO_INIT(CangkuNameListJsonVO, JsonVO<oatpp::List<CangkuNameListDTO::Wrapper>>);
};

//	删除仓库的请求体JsonVO，没有用到...
class DeleteCangkuJsonVO : public JsonVO<oatpp::List<DeleteCangkuDTO::Wrapper>> {
	DTO_INIT(DeleteCangkuJsonVO, JsonVO<oatpp::List<DeleteCangkuDTO::Wrapper>>);
};

// 获取仓库列表的显示JsonVO
class CangkuListPageJsonVO : public JsonVO<CangkuListPageDTO::Wrapper> {
	DTO_INIT(CangkuListPageJsonVO, JsonVO<CangkuListPageDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_CANGKU_VO_
