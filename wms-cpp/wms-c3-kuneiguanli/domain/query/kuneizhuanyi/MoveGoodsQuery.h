#pragma once

#include "domain/GlobalInclude.h"
#include "domain/query/PageQuery.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* ��ҳ��ѯת�������б�
*/
class MoveGoodsQuery : public PageQuery {
	DTO_INIT(MoveGoodsQuery, PageQuery);
	// ת������ID
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("movegoods.field.id");
	}
	// ��Ʒ����
	DTO_FIELD(String, goods_id);
	DTO_FIELD_INFO(goods_id) {
		info->description = ZH_WORDS_GETTER("movegoods.field.goods_id");
	}
	// ��Ʒ����
	DTO_FIELD(String, goods_name);
	DTO_FIELD_INFO(goods_name) {
		info->description = ZH_WORDS_GETTER("movegoods.field.goods_name");
	}
	// �ͻ�����
	DTO_FIELD(String, cus_code);
	DTO_FIELD_INFO(cus_code) {
		info->description = ZH_WORDS_GETTER("movegoods.field.cus_code");
	}
	// �ͻ�����
	DTO_FIELD(String, cus_name);
	DTO_FIELD_INFO(cus_name) {
		info->description = ZH_WORDS_GETTER("movegoods.field.cus_name");
	}
	// ת�ƿͻ�
	DTO_FIELD(String, to_cus_code);
	DTO_FIELD_INFO(to_cus_code) {
		info->description = ZH_WORDS_GETTER("movegoods.field.to_cus_code");
	}
	// ת�ƿͻ�����
	DTO_FIELD(String, to_cus_name);
	DTO_FIELD_INFO(to_cus_name) {
		info->description = ZH_WORDS_GETTER("movegoods.field.to_cus_name");
	}
	// Դ����
	DTO_FIELD(String, tin_from);
	DTO_FIELD_INFO(tin_from) {
		info->description = ZH_WORDS_GETTER("movegoods.field.tin_from");
	}
	// ������
	DTO_FIELD(String, tin_id);
	DTO_FIELD_INFO(tin_id) {
		info->description = ZH_WORDS_GETTER("movegoods.field.tin_id");
	}
	// Դ��λ
	DTO_FIELD(String, bin_from);
	DTO_FIELD_INFO(bin_from) {
		info->description = ZH_WORDS_GETTER("movegoods.field.bin_from");
	}
	// ����λ
	DTO_FIELD(String, bin_to);
	DTO_FIELD_INFO(bin_to) {
		info->description = ZH_WORDS_GETTER("movegoods.field.bin_to");
	}
	// ״̬
	DTO_FIELD(String, move_sta);
	DTO_FIELD_INFO(move_sta) {
		info->description = ZH_WORDS_GETTER("movegoods.field.move_sta");
	}
	// ִ��״̬
	DTO_FIELD(String, run_sta);
	DTO_FIELD_INFO(run_sta) {
		info->description = ZH_WORDS_GETTER("movegoods.field.run_sta");
	}
};

/**
* ��ѯת�����������Ϣ
*/
class MoveGoodsBaseQuery : public PageQuery {
	DTO_INIT(MoveGoodsBaseQuery, PageQuery);
	// ת������ID
<<<<<<< HEAD
	DTO_FIELD(String, id);
	DTO_FIELD_INFO(id) {
		info->description = ZH_WORDS_GETTER("movegoods.field.id");
=======
	DTO_FIELD(oatpp::List<oatpp::String>, items);
	DTO_FIELD_INFO(items) {
		info->description = ZH_WORDS_GETTER("move-goods.field.items");
	}
};

// ��ѯ����ת������
class MoveGoodsExcelQuery : public oatpp::DTO
{
	DTO_INIT(MoveGoodsExcelQuery, DTO);

	DTO_FIELD(String, file_path);
	DTO_FIELD_INFO(file_path) {
		info->description = ZH_WORDS_GETTER("move-goods.field.file_path");
	}

	DTO_FIELD(String, ids);
	DTO_FIELD_INFO(ids) {
		info->description = ZH_WORDS_GETTER("move-goods.field.id");
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0
	}
};

#include OATPP_CODEGEN_END(DTO)
