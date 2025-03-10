#pragma once
#ifndef _CHUWEI_DTO_
#define _CHUWEI_DTO_

#include "../../GlobalInclude.h"
#include <oatpp/core/Types.hpp> 

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 储位列表基础数据
 */
class ChuWeiBaseDTO : public oatpp::DTO
{
	DTO_INIT(ChuWeiBaseDTO, DTO);
	// 仓库
	DTO_FIELD(String, bin_store);
	DTO_FIELD_INFO(bin_store) {
		info->description = ZH_WORDS_GETTER("Chuwei.field.store");
	}
	//上用原方式，下用宏
	//库位编码
	API_DTO_FIELD_DEFAULT(String, ku_wei_bian_ma, ZH_WORDS_GETTER("Chuwei.field.ku_wei_bian_ma"));
	//库位条码
	API_DTO_FIELD_DEFAULT(String, ku_wei_tiao_ma, ZH_WORDS_GETTER("Chuwei.field.ku_wei_tiao_ma"));
	//库位类型
	API_DTO_FIELD_DEFAULT(String, ku_wei_lei_xing, ZH_WORDS_GETTER("Chuwei.field.ku_wei_lei_xing"));
	//库位属性
	API_DTO_FIELD_DEFAULT(String, ku_wei_shu_xing, ZH_WORDS_GETTER("Chuwei.field.ku_wei_shu_xing"));
	//产品属性
	API_DTO_FIELD_DEFAULT(String, CHP_SHU_XING, ZH_WORDS_GETTER("Chuwei.field.CHP_SHU_XING"));
	//上架次序
	API_DTO_FIELD_DEFAULT(String, shang_jia_ci_xu, ZH_WORDS_GETTER("Chuwei.field.shang_jia_ci_xu"));
	//取货次序
	API_DTO_FIELD_DEFAULT(String, qu_huo_ci_xu, ZH_WORDS_GETTER("Chuwei.field.qu_huo_ci_xu"));
	//所属客户
	API_DTO_FIELD_DEFAULT(String, suo_shu_ke_hu, ZH_WORDS_GETTER("Chuwei.field.customer"));
	/*   DO中不需要这部分数据
	//最小批量
	API_DTO_FIELD_DEFAULT(String, suo_shu_ke_hu, ZH_WORDS_GETTER("Chuwei.field.customer"));
	//最大批量
	API_DTO_FIELD_DEFAULT(String, suo_shu_ke_hu, ZH_WORDS_GETTER("Chuwei.field.customer"));
	//储位组别
	API_DTO_FIELD_DEFAULT(String, ting_yong, ZH_WORDS_GETTER("Chuwei.field.state"));
	//出库口
	API_DTO_FIELD_DEFAULT(String, ting_yong, ZH_WORDS_GETTER("Chuwei.field.state"));
	*/
	//最大体积
	API_DTO_FIELD_DEFAULT(String, zui_da_ti_ji, ZH_WORDS_GETTER("Chuwei.field.zui_da_ti_ji"));
	//最大重量
	API_DTO_FIELD_DEFAULT(String, zui_da_zhong_liang, ZH_WORDS_GETTER("Chuwei.field.zui_da_zhong_liang"));
	//最大托盘
	API_DTO_FIELD_DEFAULT(String, zui_da_tuo_pan, ZH_WORDS_GETTER("Chuwei.field.zui_da_tuo_pan"));
	//长度
	API_DTO_FIELD_DEFAULT(String, chang, ZH_WORDS_GETTER("Chuwei.field.chang"));
	//宽度
	API_DTO_FIELD_DEFAULT(String, kuan, ZH_WORDS_GETTER("Chuwei.field.kuan"));
	//高度
	API_DTO_FIELD_DEFAULT(String, gao, ZH_WORDS_GETTER("Chuwei.field.gao"));
	//是否停用
	API_DTO_FIELD_DEFAULT(String, ting_yong, ZH_WORDS_GETTER("Chuwei.field.ting_yong"));
	//备注
	API_DTO_FIELD_DEFAULT(String, ming_xi, ZH_WORDS_GETTER("Chuwei.field.ming_xi"));
	//备注1
	API_DTO_FIELD_DEFAULT(String, ming_xi1, ZH_WORDS_GETTER("Chuwei.field.ming_xi1"));
	//备注2
	API_DTO_FIELD_DEFAULT(String, ming_xi2, ZH_WORDS_GETTER("Chuwei.field.ming_xi2"));
	//动线
	API_DTO_FIELD_DEFAULT(String, ming_xi3, ZH_WORDS_GETTER("Chuwei.field.ming_xi3"));
	//电子标签ID
	API_DTO_FIELD_DEFAULT(String, LORA_bqid, ZH_WORDS_GETTER("Chuwei.field.LORA_bqid"));
	//x坐标
	API_DTO_FIELD_DEFAULT(String, xnode, ZH_WORDS_GETTER("Chuwei.field.xnode"));
	//y坐标
	API_DTO_FIELD_DEFAULT(String, ynode, ZH_WORDS_GETTER("Chuwei.field.ynode"));
	//z坐标
	API_DTO_FIELD_DEFAULT(String, znode, ZH_WORDS_GETTER("Chuwei.field.znode"));
};

/**
 * 储位列表传输对象（根据id）
 */
class ChuWeiDTO : public ChuWeiBaseDTO
{
	DTO_INIT(ChuWeiDTO, ChuWeiBaseDTO);
	// 主键
	API_DTO_FIELD_DEFAULT(String, id, ZH_WORDS_GETTER("chuwei.id"));
};


/**
 * 储位列表分页数据对象
 */
class ChuWeiPageDTO : public PageDTO<ChuWeiDTO::Wrapper>
{
	DTO_INIT(ChuWeiPageDTO, PageDTO<ChuWeiDTO::Wrapper>);
};

/**
 * 删除储位，支持批量删除
 */
class BatchDeleteDTO : public oatpp::DTO {
	DTO_INIT(BatchDeleteDTO, DTO);
	// 使用 OATPP 列表类型
	DTO_FIELD(oatpp::List<oatpp::String>::ObjectWrapper, ids);
	DTO_FIELD_INFO(ids) {
		info->description = ZH_WORDS_GETTER("Chuwei.field.ids");
	}
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_CHUWEI_DTO_