#pragma once

#ifndef _XIANGXIXINXICHAXUNQUERY_
#define _XIANGXIXINXICHAXUNQUERY_

#include "../../GlobalInclude.h"
#include "domain/query/PageQuery.h"


#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 详细信息查询对象-------这个好像用不到
 */
//class xaingxixinxichaxun : public PageQuery
//{
//	DTO_INIT(xaingxixinxichaxun,PageQuery);
//	// 仓库
//	DTO_FIELD(String, cangku);
//	DTO_FIELD_INFO(cangku) {
//		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.cangku");
//	}
//
//	// 库位编码
//	DTO_FIELD(String, bianma);
//	DTO_FIELD_INFO(bianma) {
//		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.bianma");
//	}
//	
//	// 库位条码
//	DTO_FIELD(String, tiaoma);
//	DTO_FIELD_INFO(tiaoma) {
//		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.tiaoma");
//	}
//
//
//	// 库位类型
//	DTO_FIELD(String, leixing);
//	DTO_FIELD_INFO(leixing) {
//		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.leixing");
//	}
//
//	// 库位属性
//	DTO_FIELD(String, shuxing);
//	DTO_FIELD_INFO(shuxing) {
//		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.shuxing");
//	}
//
//	//产品属性
//	DTO_FIELD(String, chanpinshuxing);
//	DTO_FIELD_INFO(chanpinshuxing) {
//		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.chanpinshuxing");
//	}
//
//	// 上架次序
//	DTO_FIELD(String, shangjiacixu);
//	DTO_FIELD_INFO(shangjiacixu) {
//		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.shangjiacixu");
//	}
//
//	// 取货次序
//	DTO_FIELD(String, quhuocixu);
//	DTO_FIELD_INFO(quhuocixu) {
//		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.xinxi.quhuocixu");
//	}
//
//};


//数据表唯一id
class xiangxixinxiQUERY :public oatpp::DTO
{
	DTO_INIT(xiangxixinxiQUERY, DTO);
	// 仓库
	DTO_FIELD(String, weiyiid);
	DTO_FIELD_INFO(weiyiid) {
		info->description = ZH_WORDS_GETTER("chuweixiangxixinxi.bs.id");
	}
};


#include OATPP_CODEGEN_END(DTO)
#endif // !__XIANGXIXINXICHAXUNQUERY_