#ifndef _AREAINFO_DTO_
#define _AREAINFO_DTO_
#include "../../GlobalInclude.h"
#include "tree/TreeNode.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AreaInfoUpdDTO : public oatpp::DTO
{
	DTO_INIT(AreaInfoUpdDTO, DTO);

	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("AreaInfo.id");
	}

	DTO_FIELD(String, city_code);
	DTO_FIELD_INFO(city_code) {
		info->description = ZH_WORDS_GETTER("AreaInfo.city_code");
	}

	DTO_FIELD(String, city_name);
	DTO_FIELD_INFO(city_name) {
		info->description = ZH_WORDS_GETTER("AreaInfo.city_name");
	}

	DTO_FIELD(String, city_serc);
	DTO_FIELD_INFO(city_serc) {
		info->description = ZH_WORDS_GETTER("AreaInfo.city_serc");
	}

	DTO_FIELD(String, city_del);
	DTO_FIELD_INFO(city_del) {
		info->description = ZH_WORDS_GETTER("AreaInfo.city_del");
	}

	DTO_FIELD(String, city_type_name);
	DTO_FIELD_INFO(city_type_name) {
		info->description = ZH_WORDS_GETTER("AreaInfo.city_type_name");
	}

	DTO_FIELD(String, barea_name);
	DTO_FIELD_INFO(barea_name) {
		info->description = ZH_WORDS_GETTER("AreaInfo.barea_name");
	}

	DTO_FIELD(String, area_name);
	DTO_FIELD_INFO(area_name) {
		info->description = ZH_WORDS_GETTER("AreaInfo.area_name");
	}
};

class AreaNameTreeDTO : public oatpp::DTO, public TreeNode
{
	DTO_INIT(AreaNameTreeDTO, DTO);
	// id
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("AreaInfo.id"));
	// 名称
	API_DTO_FIELD_DEFAULT(String, name, ZH_WORDS_GETTER("AreaInfo.name"));
	// 子地区名称
	API_DTO_FIELD(List<AreaNameTreeDTO::Wrapper>, children, ZH_WORDS_GETTER("AreaInfo.namesub"), false, {});
public:
	void addChild(shared_ptr<TreeNode> child) override
	{
		children->push_back(Wrapper(dynamic_pointer_cast<AreaNameTreeDTO>(child), Wrapper::Class::getType()));
	}
};

class AreaInfoDTO : public oatpp::DTO
{
	DTO_INIT(AreaInfoDTO, DTO);

	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("AreaInfo.id"));
	API_DTO_FIELD_DEFAULT(String, city_name, ZH_WORDS_GETTER("AreaInfo.city_name"));
	API_DTO_FIELD_DEFAULT(String, city_code, ZH_WORDS_GETTER("AreaInfo.city_code"));
	API_DTO_FIELD_DEFAULT(String, city_serc, ZH_WORDS_GETTER("AreaInfo.city_serc"));
	API_DTO_FIELD_DEFAULT(String, city_type_name, ZH_WORDS_GETTER("AreaInfo.city_type_name"));
	API_DTO_FIELD_DEFAULT(String, barea_name, ZH_WORDS_GETTER("AreaInfo.barea_name"));
	API_DTO_FIELD_DEFAULT(String, area_name, ZH_WORDS_GETTER("AreaInfo.area_name"));
	API_DTO_FIELD_DEFAULT(String, city_del, ZH_WORDS_GETTER("AreaInfo.city_del"));
};

class AreaInfoPageDTO : public PageDTO<AreaInfoDTO::Wrapper>
{
	DTO_INIT(AreaInfoPageDTO, PageDTO<AreaInfoDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_AREAINFO_DTO_
