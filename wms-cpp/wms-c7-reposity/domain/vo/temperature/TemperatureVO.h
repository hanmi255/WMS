#pragma once
/*
 用于前端做显示
 @Author: gutianxuan
 @Date: 2025/02/23

*/
#ifndef _TEMPERATURE_VO_
#define _TEMPERATURE_VO_

#include "../../GlobalInclude.h"
#include "../../dto/temperature/TemperatureDTO.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 温度属性显示JsonVO，用于响应给客户端的Json对象
 * TemperatureDTO:  name code
 */
class TemperatureJsonVO : public JsonVO<TemperatureDTO::Wrapper> {
	DTO_INIT(TemperatureJsonVO, JsonVO<TemperatureDTO::Wrapper>);
};

/**
 * 温度属性分页列表JsonVO，用于响应给客户端的Json对象
 * TemperatureDTO:  id name code
 */
class TemperaturePageJsonVO : public JsonVO<TemperaturePageDTO::Wrapper> {
	DTO_INIT(TemperaturePageJsonVO, JsonVO<TemperaturePageDTO::Wrapper>);
};

/**
 * 温度属性名称分页列表JsonVO，用于响应给客户端的Json对象
 * TemperatureNameDTO:  id name
 *
 */

class TemperatureNamePageJsonVO : public JsonVO<TemperatureNamePageDTO::Wrapper> {
	DTO_INIT(TemperatureNamePageJsonVO, JsonVO<TemperatureNamePageDTO::Wrapper>);
};


#include OATPP_CODEGEN_END(DTO)

#endif // !_TEMPERATURE_VO_