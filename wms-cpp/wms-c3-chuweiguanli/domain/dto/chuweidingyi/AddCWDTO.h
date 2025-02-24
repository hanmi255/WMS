#pragma once

#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddCWDTO : public oatpp::DTO {
	DTO_INIT(AddCWDTO, DTO);

	//	�ֿ�����
	DTO_FIELD(String, store_name);
	DTO_FIELD_INFO(store_name)
	{
		info->description = ZH_WORDS_GETTER("Cangku.info.store_name");
	}

	//�����ͻ�
	DTO_FIELD(String, kuhu_name);
	DTO_FIELD_INFO(kuhu_name)
	{
		info->description = ZH_WORDS_GETTER("chuwei.add.kehu");
	}
	// ��λ����
	DTO_FIELD(String, kuwei_bianma);
	DTO_FIELD_INFO(kuwei_bianma) {
		info->description = ZH_WORDS_GETTER("chuwei.add.kuweibianma");
	}
	// ��λ����
	DTO_FIELD(String, kuwei_tiaoma);
	DTO_FIELD_INFO(kuwei_tiaoma) {
		info->description = ZH_WORDS_GETTER("chuwei.add.kuweitiaoma");
	}
	// ��λ����
	DTO_FIELD(String, kuwei_leixing);
	DTO_FIELD_INFO(kuwei_leixing) {
		info->description = ZH_WORDS_GETTER("chuwei.add.kuweileixing");
	}
	// ��λ����
	DTO_FIELD(String, kuwei_shuxing);
	DTO_FIELD_INFO(kuwei_shuxing) {
		info->description = ZH_WORDS_GETTER("chuwei.add.kuweishuxing");
	}
	// ��Ʒ����
	DTO_FIELD(String, chanqin_shuxing);
	DTO_FIELD_INFO(chanqin_shuxing)
	{
		info->description = ZH_WORDS_GETTER("chuwei.add.chanqinshuxing");
	}
	//	�ϼܴ���
	DTO_FIELD(Int64, shangjia_cixv);
	DTO_FIELD_INFO(shangjia_cixv)
	{
		info->description = ZH_WORDS_GETTER("chuwei.add.shangjiacixv");
	}
	//	ȡ������
	DTO_FIELD(Int64, quhuo_cixv);
	DTO_FIELD_INFO(quhuo_cixv)
	{
		info->description = ZH_WORDS_GETTER("chuwei.add.quhuocixv");
	}
	//	�������
	DTO_FIELD(Int64, zuida_zhongliang);
	DTO_FIELD_INFO(zuida_zhongliang)
	{
		info->description = ZH_WORDS_GETTER("chuwei.add.zuidazhongliang");
	}
	//	�������
	DTO_FIELD(Int64, zuida_tuopan);
	DTO_FIELD_INFO(zuida_tuopan)
	{
		info->description = ZH_WORDS_GETTER("zuida_tuopan");
	}
	//	��
	DTO_FIELD(Int64, chang);
	DTO_FIELD_INFO(chang)
	{
		info->description = ZH_WORDS_GETTER("chuwei.add.chang");
	}
	//	��
	DTO_FIELD(Int64, kuan);
	DTO_FIELD_INFO(kuan)
	{
		info->description = ZH_WORDS_GETTER("chuwei.add.kuan");
	}
	//	��
	DTO_FIELD(Int64, gao);
	DTO_FIELD_INFO(gao)
	{
		info->description = ZH_WORDS_GETTER("chuwei.add.gao");
	}
	//	������
	DTO_FIELD(Int64, zuida_tiji);
	DTO_FIELD_INFO(zuida_tiji)
	{
		info->description = ZH_WORDS_GETTER("chuwei.add.zuida_tiji");
	}
	//	ͣ��
	DTO_FIELD(String, tingyong);
	DTO_FIELD_INFO(tingyong) {
		info->description = ZH_WORDS_GETTER("chuwei.add.tingyong");
	}
	//	��ע
	DTO_FIELD(String, beizhu);
	DTO_FIELD_INFO(beizhu) {
		info->description = ZH_WORDS_GETTER("chuwei.add.beizhu");
	}
	//	��ע1
	DTO_FIELD(String, beizhu1);
	DTO_FIELD_INFO(beizhu1) {
		info->description = ZH_WORDS_GETTER("chuwei.add.beizhu1");
	}
	//	��ע2
	DTO_FIELD(String, beizhu2);
	DTO_FIELD_INFO(beizhu2) {
		info->description = ZH_WORDS_GETTER("chuwei.add.beizhu2");
	}
	//	����
	DTO_FIELD(String, dongxian);
	DTO_FIELD_INFO(dongxian) {
		info->description = ZH_WORDS_GETTER("chuwei.add.dongxian");
	}
	//	���ӱ�ǩID
	DTO_FIELD(String, diancibiaoqianID);
	DTO_FIELD_INFO(diancibiaoqianID) {
		info->description = ZH_WORDS_GETTER("chuwei.add.diancibiaoqianID");
	}
	//	�����λ
	DTO_FIELD(String, tijidanwei);
	DTO_FIELD_INFO(tijidanwei) {
		info->description = ZH_WORDS_GETTER("chuwei.add.tijidanwei");
	}
	//	������λ
	DTO_FIELD(String, zhonglaingdanwei);
	DTO_FIELD_INFO(zhonglaingdanwei) {
		info->description = ZH_WORDS_GETTER("chuwei.add.zhonglaingdanwei");
	}
	//	�����λ
	DTO_FIELD(String, mianjidanwei);
	DTO_FIELD_INFO(mianjidanwei) {
		info->description = ZH_WORDS_GETTER("chuwei.add.mianjidanwei");
	}
	//	������
	DTO_FIELD(String, zuidamianji);
	DTO_FIELD_INFO(zuidamianji) {
		info->description = ZH_WORDS_GETTER("chuwei.add.zuidamianji");
	}
	//	x����
	DTO_FIELD(String, x_node);
	DTO_FIELD_INFO(x_node) {
		info->description = ZH_WORDS_GETTER("chuwei.add.x_node");
	}
	//	y����
	DTO_FIELD(String, y_node);
	DTO_FIELD_INFO(y_node) {
		info->description = ZH_WORDS_GETTER("chuwei.add.y_node");
	}
	//	z����
	DTO_FIELD(String, z_node);
	DTO_FIELD_INFO(z_node) {
		info->description = ZH_WORDS_GETTER("chuwei.add.z_node");
	}
};

#include OATPP_CODEGEN_END(DTO)
