#pragma once
#ifndef _EDUCATIONAL_H_

#include "../../GlobalInclude.h"
#include"domain/dto/education/EducationalDTO.h"
#include OATPP_CODEGEN_BEGIN(DTO)


//class EducationalVO : public oatpp::DTO {
//	DTO_INIT(EducationalVO, DTO);
//	//学历代码
//	API_DTO_FIELD(String, education_code, ZH_WORDS_GETTER("educational_background.field.Education_code"), true, "john");
//	//学历名称
//	API_DTO_FIELD(String, education_name, ZH_WORDS_GETTER("educational_background.field.Education_name"), true, "1");
//	//操作
//	API_DTO_FIELD(String, education_operation, ZH_WORDS_GETTER("educational_background.field.Education_operation"), true, "1");
//};

/**
 * 示例显示JsonVO，用于响应给客户端的Json对象
 */


class EduCodeVO : public oatpp::DTO
{
	DTO_INIT(EduCodeVO, DTO);
	//员工昵称
	API_DTO_FIELD(String, code, ZH_WORDS_GETTER("educational_background.field.Education_code"), true, "");
	//员工工号
	API_DTO_FIELD(String, nama, ZH_WORDS_GETTER("educational_background.field.Education_name"), true, "");


};

class EducationalJsonVO : public JsonVO<EducationalDTO::Wrapper> {
	DTO_INIT(EducationalJsonVO, JsonVO<EducationalDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_EDUCATIONAL_H_


