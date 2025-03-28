#pragma once
/*
 @Author: gutianxuan
*/
#ifndef _TEMPERATURE_DTO_
#define _TEMPERATURE_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 温度属性数据对象
 */
class TemperatureDTO : public oatpp::DTO
{
	DTO_INIT(TemperatureDTO, oatpp::DTO);
	//温层代码 温层名称
	API_DTO_FIELD_DEFAULT(String, deg_type_code, ZH_WORDS_GETTER("reposity.temperature.field.deg_type_code"));
	API_DTO_FIELD_DEFAULT(String, deg_type_name, ZH_WORDS_GETTER("reposity.temperature.field.deg_type_name"));

};

/**
 * 温度属性详细数据对象
 */

class TemperatureDetailDTO : public oatpp::DTO {
	DTO_INIT(TemperatureDetailDTO, oatpp::DTO);

	//唯一ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("reposity.temperature.field.id"));
	//创建人名称 创建人登陆名称 创建日期 更新人名称 更新人登录名称 更新日期 所属部门 所属公司
	API_DTO_FIELD_DEFAULT(String, create_name, ZH_WORDS_GETTER("reposity.temperature.field.create_name"));
	API_DTO_FIELD_DEFAULT(String, create_by, ZH_WORDS_GETTER("reposity.temperature.field.create_by"));
	API_DTO_FIELD_DEFAULT(String, create_date, ZH_WORDS_GETTER("reposity.temperature.field.create_date"));
	API_DTO_FIELD_DEFAULT(String, update_name, ZH_WORDS_GETTER("reposity.temperature.field.update_name"));
	API_DTO_FIELD_DEFAULT(String, update_by, ZH_WORDS_GETTER("reposity.temperature.field.update_by"));
	API_DTO_FIELD_DEFAULT(String, update_date, ZH_WORDS_GETTER("reposity.temperature.field.update_date"));
	API_DTO_FIELD_DEFAULT(String, sys_org_code, ZH_WORDS_GETTER("reposity.temperature.field.sys_org_code"));
	API_DTO_FIELD_DEFAULT(String, sys_company_code, ZH_WORDS_GETTER("reposity.temperature.field.sys_company_code"));
	//温层代码 温层名称
	API_DTO_FIELD_DEFAULT(String, deg_type_code, ZH_WORDS_GETTER("reposity.temperature.field.deg_type_code"));
	API_DTO_FIELD_DEFAULT(String, deg_type_name, ZH_WORDS_GETTER("reposity.temperature.field.deg_type_name"));
};

//新增 不提供id  由后端自己生成
class TemperatureAddDTO : public TemperatureDTO {
	DTO_INIT(TemperatureAddDTO, TemperatureDTO);

};

//修改 需要提供id 前端传递
class TemperatureModifyDTO : public oatpp::DTO {
	DTO_INIT(TemperatureModifyDTO, oatpp::DTO);

	//唯一ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("reposity.temperature.field.id"));

	//温层代码 温层名称
	API_DTO_FIELD_DEFAULT(String, deg_type_code, ZH_WORDS_GETTER("reposity.temperature.field.deg_type_code"));
	API_DTO_FIELD_DEFAULT(String, deg_type_name, ZH_WORDS_GETTER("reposity.temperature.field.deg_type_name"));


};




/**
 * 上传文件数据对象
 */
class DegFileAddDTO : public oatpp::DTO
{
	DTO_INIT(DegFileAddDTO, DTO);
	// 温层代码
	DTO_FIELD(String, deg_type_code);
	DTO_FIELD_INFO(deg_type_code) {
		info->description = ZH_WORDS_GETTER("reposity.temperature.field.deg_type_code");
	}
	// 温层名称
	DTO_FIELD(String, deg_type_name);
	DTO_FIELD_INFO(deg_type_name) {
		info->description = ZH_WORDS_GETTER("reposity.temperature.field.deg_type_name");
	}
};


/*
* 下载文件数据对象
*/
class DegFileDTO :public oatpp::DTO
{
	DTO_INIT(DegFileDTO, DTO);

	//订单类型代码
	API_DTO_FIELD_DEFAULT(String, deg_type_code, ZH_WORDS_GETTER("reposity.temperature.field.deg_type_code"));

	//订单类型名称
	API_DTO_FIELD_DEFAULT(String, deg_name_name, ZH_WORDS_GETTER("reposity.temperature.field.deg_type_name"));

};


/**
 * 温度属性列表数据对象
 */
class TemperatureListDTO : public TemperatureDTO
{
	DTO_INIT(TemperatureListDTO, TemperatureDTO);

	// 唯一ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("reposity.temperature.field.id"));
};


//温度属性名称对象: id + name
class TemperatureNameDTO : public oatpp::DTO
{
	DTO_INIT(TemperatureNameDTO, DTO);
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("reposity.temperature.field.id"));
	API_DTO_FIELD_DEFAULT(String, deg_type_name, ZH_WORDS_GETTER("reposity.temperature.field.deg_type_name"));
};

//温度属性名称分页对象
class TemperatureNamePageDTO : public PageDTO<TemperatureNameDTO::Wrapper>
{
	DTO_INIT(TemperatureNamePageDTO, PageDTO);
};





/**
 * 温度属性列表分页数据对象
 */
class TemperaturePageDTO : public PageDTO<TemperatureDTO::Wrapper>
{
	// 唯一ID
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("reposity.temperature.field.id"));
	DTO_INIT(TemperaturePageDTO, PageDTO<TemperatureListDTO::Wrapper>);
};





#include OATPP_CODEGEN_END(DTO)
#endif // !_TEMPERATURE_DTO_





