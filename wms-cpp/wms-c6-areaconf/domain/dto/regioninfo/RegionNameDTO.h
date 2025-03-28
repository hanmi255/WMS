#pragma once
/*
 @Author: 002
 @Date: 2025.2.27
*/
#ifndef _REGION_NAME_DTO_
#define _REGION_NAME_DTO_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 大区信息名称列表数据传输对象
 */
class RegionNameDTO : public oatpp::DTO
{
	DTO_INIT(RegionNameDTO, DTO);
	// ID
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("region.info.uniq_id");
	}
	// 名称
	DTO_FIELD(String, area_name);
	DTO_FIELD_INFO(area_name) {
		info->description = ZH_WORDS_GETTER("region.info.name");
	}

};


class RegionNamePageDTO : public PageDTO<RegionNameDTO::Wrapper>
{
	DTO_INIT(RegionNamePageDTO, PageDTO<RegionNameDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif 
