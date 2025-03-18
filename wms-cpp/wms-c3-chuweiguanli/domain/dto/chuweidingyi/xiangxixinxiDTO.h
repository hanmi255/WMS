#pragma once

#ifndef _XIANGXIXINXI_
#define _XIANGXIXINXI_
#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)


//唯一标识
class daochuchuweiDTO :public oatpp::DTO
{
	DTO_INIT(daochuchuweiDTO, DTO);
	//标识
	DTO_FIELD(List<String>, biaoshi);
	DTO_FIELD_INFO(biaoshi)
	{
		info->description= ZH_WORDS_GETTER("chuweixiangxixinxi.bs.bioashi");
	}
};


//详细信息
class xiangxixinxiDTO : public oatpp::DTO
{
	DTO_INIT(xiangxixinxiDTO, DTO);
	// 仓库
	DTO_FIELD(String, cangku);
	DTO_FIELD_INFO(cangku) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.cangku");
	}

	// 库位编码
	DTO_FIELD(String, bianma);
	DTO_FIELD_INFO(bianma) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.bianma");
	}


	// 库位条码
	DTO_FIELD(String, tiaoma);
	DTO_FIELD_INFO(tiaoma) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.tiaoma");
	}

	// 库位类型
	DTO_FIELD(String, leixing);
	DTO_FIELD_INFO(leixing) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.leixing");
	}

	// 库位属性5
	DTO_FIELD(String, shuxing);
	DTO_FIELD_INFO(shuxing) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.shuxing");
	}

	//产品属性6
	DTO_FIELD(String, chanpinshuxing);
	DTO_FIELD_INFO(chanpinshuxing) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.chanpinshuxing");
	}

	// 上架次序
	DTO_FIELD(String, shangjiacixu);
	DTO_FIELD_INFO(shangjiacixu) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.shangjiacixu");
	}

	// 取货次序 8
	DTO_FIELD(String, quhuocixu);
	DTO_FIELD_INFO(quhuocixu) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.quhuocixu");
	}

	//所属客户
	DTO_FIELD(String, kehu);
	DTO_FIELD_INFO(kehu) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.kehu");
	}

	//最大面积
	DTO_FIELD(String, zuidamianji);
	DTO_FIELD_INFO(zuidamianji) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidamianji");
	}

	// 体积单位
	DTO_FIELD(String, tiji);
	DTO_FIELD_INFO(tiji) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.tiji");
	}


	// 重量单位
	DTO_FIELD(String, zhongliang);
	DTO_FIELD_INFO(zhongliang) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zhongliang");
	}

	// 面积单位
	DTO_FIELD(String, mianji);
	DTO_FIELD_INFO(mianji) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.minaji");
	}

	// 最大体积14
	DTO_FIELD(String, zuidatiji);
	DTO_FIELD_INFO(zuidatiji) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidatiji");
	}

	// 最大重量
	DTO_FIELD(String, zuidazhongliang);
	DTO_FIELD_INFO(zuidazhongliang) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidazhongliang");
	}

	// 最大托盘
	DTO_FIELD(String, zuidatuopan);
	DTO_FIELD_INFO(zuidatuopan) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.zuidatupan");
	}

	// 长17
	DTO_FIELD(String, chang);
	DTO_FIELD_INFO(chang) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.chang");
	}

	// 宽
	DTO_FIELD(String, kuan);
	DTO_FIELD_INFO(kuan) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.kuan");
	}

	// 高
	DTO_FIELD(String, gao);
	DTO_FIELD_INFO(gao) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.gao");
	}

	// 停用
	DTO_FIELD(String, tingyong);
	DTO_FIELD_INFO(tingyong) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.tingyong");
	}



	// 备注
	DTO_FIELD(String, beizhu);
	DTO_FIELD_INFO(beizhu) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.beizhu");
	}

	// 备注1
	DTO_FIELD(String, beizhu1);
	DTO_FIELD_INFO(beizhu1) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.beizhu1");
	}

	// 备注2
	DTO_FIELD(String, beizhu2);
	DTO_FIELD_INFO(beizhu2) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.beizhu2");
	}

	// 动线
	DTO_FIELD(String, dongxian);
	DTO_FIELD_INFO(dongxian) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.dongxian");
	}

	// 电子标签ID
	DTO_FIELD(String, ID);
	DTO_FIELD_INFO(ID) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.ID");
	}


	//x坐标
	DTO_FIELD(String, x);
	DTO_FIELD_INFO(x) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.x");
	}

	//y坐标
	DTO_FIELD(String, y);
	DTO_FIELD_INFO(y) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.y");
	}

	//z坐标
	DTO_FIELD(String, z);
	DTO_FIELD_INFO(z) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.z");
	}
};




#include OATPP_CODEGEN_END(DTO)
#endif // !_XIANGXIXINXI_