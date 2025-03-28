#pragma once
#ifndef _QUALITYVO_H_
#define _QUALITYVO_H_

#include "../../GlobalInclude.h"
#include "../../dto/qcd/QualityDTO2.h"
#include "oatpp/web/protocol/http/Http.hpp"
#include OATPP_CODEGEN_BEGIN(DTO)

class QualityVO : public JsonVO<QualityDTO::Wrapper> {
	DTO_INIT(QualityVO, JsonVO<QualityDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_QUALITYVO_H_