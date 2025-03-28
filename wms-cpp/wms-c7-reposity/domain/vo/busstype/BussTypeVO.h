#pragma once

#ifndef _BUSSTYPE_VO_
#define _BUSSTYPE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/busstype/BussTypeDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * ҵ�����ͷ����б�JsonVO��������Ӧ���ͻ��˵�Json����
 */
class BussTypePageJsonVO : public JsonVO<BussTypeListPageDTO::Wrapper> {
	DTO_INIT(BussTypePageJsonVO, JsonVO<BussTypeListPageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_BUSSTYPE_VO_