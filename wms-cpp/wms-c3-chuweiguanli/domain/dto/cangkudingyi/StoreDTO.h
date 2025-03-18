#pragma once
#ifndef _STOREDTO_
#define _STOREDTO_
#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class BaseDTO : public oatpp::DTO
{
	DTO_INIT(BaseDTO, DTO);
	
	DTO_FIELD(String, store_code);
	DTO_FIELD_INFO(store_code) {
		info->description = ZH_WORDS_GETTER("store.store_code");
	}

	DTO_FIELD(String, store_name);
	DTO_FIELD_INFO(store_name) {
		info->description = ZH_WORDS_GETTER("store.store_name");
	}

	DTO_FIELD(String, store_text);
	DTO_FIELD_INFO(store_text) {
		info->description = ZH_WORDS_GETTER("store.store_text");
	}
};

class StoreAddDTO : public BaseDTO
{
	DTO_INIT(StoreAddDTO, BaseDTO);

	/*DTO_FIELD(String, sys_org_code);
	DTO_FIELD_INFO(sys_org_code) {
		info->description = ZH_WORDS_GETTER("store.sys_org_code");
	}

	DTO_FIELD(String, sys_company_code);
	DTO_FIELD_INFO(sys_company_code) {
		info->description = ZH_WORDS_GETTER("store.sys_company_code");
	}*/
};

class StoreModifyDTO : public BaseDTO
{
	DTO_INIT(StoreModifyDTO, BaseDTO);

	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("store.id");
	}
};

class StoreDTO : /*public StoreAddDTO, public StoreModifyDTO*/ public BaseDTO
{
	DTO_INIT(StoreDTO, BaseDTO);

	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("store.id");
	}

	DTO_FIELD(String, sys_org_code);
	DTO_FIELD_INFO(sys_org_code) {
		info->description = ZH_WORDS_GETTER("store.sys_org_code");
	}

	DTO_FIELD(String, sys_company_code);
	DTO_FIELD_INFO(sys_company_code) {
		info->description = ZH_WORDS_GETTER("store.sys_company_code");
	}

	DTO_FIELD(String, create_name);
	DTO_FIELD_INFO(create_name) {
		info->description = ZH_WORDS_GETTER("store.create_name");
	}

	DTO_FIELD(String, create_by);
	DTO_FIELD_INFO(create_by) {
		info->description = ZH_WORDS_GETTER("store.create_by");
	}

	DTO_FIELD(String, create_date);
	DTO_FIELD_INFO(create_date) {
		info->description = ZH_WORDS_GETTER("store.create_date");
	}

	DTO_FIELD(String, update_name);
	DTO_FIELD_INFO(update_name) {
		info->description = ZH_WORDS_GETTER("store.update_name");
	}

	DTO_FIELD(String, update_by);
	DTO_FIELD_INFO(update_by) {
		info->description = ZH_WORDS_GETTER("store.update_by");
	}

	DTO_FIELD(String, update_date);
	DTO_FIELD_INFO(update_date) {
		info->description = ZH_WORDS_GETTER("store.update_date");
	}
};

#include OATPP_CODEGEN_BEGIN(DTO)
#endif // !_STOREDTO_