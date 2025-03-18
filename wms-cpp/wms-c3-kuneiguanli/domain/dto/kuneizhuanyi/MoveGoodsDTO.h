#pragma once

#include "domain/GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
* 基础DTO，包含所有转移任务的公共字段
*/
class MoveGoodsBaseDTO : public oatpp::DTO {
    DTO_INIT(MoveGoodsBaseDTO, DTO);
    // 转移任务Id
    DTO_FIELD(String, id);
    DTO_FIELD_INFO(id) {
        info->description = ZH_WORDS_GETTER("movegoods.field.id");
    }
    // 移动数量
<<<<<<< HEAD
    DTO_FIELD(String, base_goodscount);
    DTO_FIELD_INFO(base_goodscount) {
        info->description = ZH_WORDS_GETTER("movegoods.field.base_goodscount");
=======
    DTO_FIELD(String, moveNum);
    DTO_FIELD_INFO(moveNum) {
        info->description = ZH_WORDS_GETTER("move-goods.field.move-num");
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0
    }
    // 到托盘
    DTO_FIELD(String, tin_id);
    DTO_FIELD_INFO(tin_id) {
        info->description = ZH_WORDS_GETTER("movegoods.field.tin_id");
    }
    // 到储位
    DTO_FIELD(String, bin_to);
    DTO_FIELD_INFO(bin_to) {
        info->description = ZH_WORDS_GETTER("movegoods.field.bin_to");
    }
};

/**
* 修改转移任务的DTO
* 包含所有修改转移任务所需的字段
*/
class MoveGoodsModifyDTO : public MoveGoodsBaseDTO {
    DTO_INIT(MoveGoodsModifyDTO, MoveGoodsBaseDTO);
    // 转移客户
    DTO_FIELD(String, to_cus_code);
    DTO_FIELD_INFO(to_cus_code) {
        info->description = ZH_WORDS_GETTER("movegoods.field.to_cus_code");
    }
    // 转移客户名称
    DTO_FIELD(String, to_cus_name);
    DTO_FIELD_INFO(to_cus_name) {
        info->description = ZH_WORDS_GETTER("movegoods.field.to_cus_name");
    }
    // 生产日期
    DTO_FIELD(String, goods_pro_data);
    DTO_FIELD_INFO(goods_pro_data) {
        info->description = ZH_WORDS_GETTER("movegoods.field.goods_pro_data");
    }
    // 到生产日期
    DTO_FIELD(String, to_goods_pro_data);
    DTO_FIELD_INFO(to_goods_pro_data) {
        info->description = ZH_WORDS_GETTER("movegoods.field.to_goods_pro_data");
    }
    // 状态
    DTO_FIELD(String, move_sta);
    DTO_FIELD_INFO(move_sta) {
        info->description = ZH_WORDS_GETTER("movegoods.field.move_sta");
    }
};

/**
* 获取转移任务详细信息的DTO
* 包含所有获取转移任务详细信息所需的字段
*/
class MoveGoodsDetailedDTO : public oatpp::DTO {
    DTO_INIT(MoveGoodsDetailedDTO, DTO);
    // 商品编码
    DTO_FIELD(String, goods_id);
    DTO_FIELD_INFO(goods_id) {
        info->description = ZH_WORDS_GETTER("movegoods.field.goods_id");
    }
    // 商品名称
    DTO_FIELD(String, goods_name);
    DTO_FIELD_INFO(goods_name) {
        info->description = ZH_WORDS_GETTER("movegoods.field.goods_name");
    }
    // 现有数量
<<<<<<< HEAD
    DTO_FIELD(String, goods_qua);
    DTO_FIELD_INFO(goods_qua) {
        info->description = ZH_WORDS_GETTER("movegoods.field.goods_qua");
    }
    // 移动数量
    DTO_FIELD(String, base_goodscount);
    DTO_FIELD_INFO(base_goodscount) {
        info->description = ZH_WORDS_GETTER("movegoods.field.base_goodscount");
=======
    DTO_FIELD(String, nowNum);
    DTO_FIELD_INFO(nowNum) {
        info->description = ZH_WORDS_GETTER("move-goods.field.now-num");
    }
    // 移动数量
    DTO_FIELD(String, moveNum);
    DTO_FIELD_INFO(moveNum) {
        info->description = ZH_WORDS_GETTER("move-goods.field.move-num");
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0
    }
    // 生产日期
    DTO_FIELD(String, goods_pro_data);
    DTO_FIELD_INFO(goods_pro_data) {
        info->description = ZH_WORDS_GETTER("movegoods.field.goods_pro_data");
    }
    // 到生产日期
    DTO_FIELD(String, to_goods_pro_data);
    DTO_FIELD_INFO(to_goods_pro_data) {
        info->description = ZH_WORDS_GETTER("movegoods.field.to_goods_pro_data");
    }
    // 单位
    DTO_FIELD(String, goods_unit);
    DTO_FIELD_INFO(goods_unit) {
        info->description = ZH_WORDS_GETTER("movegoods.field.goods_unit");
    }
    // 客户编码
    DTO_FIELD(String, cus_code);
    DTO_FIELD_INFO(cus_code) {
        info->description = ZH_WORDS_GETTER("movegoods.field.cus_code");
    }
    // 客户名称
    DTO_FIELD(String, cus_name);
    DTO_FIELD_INFO(cus_name) {
        info->description = ZH_WORDS_GETTER("movegoods.field.cus_name");
    }
    // 转移客户
    DTO_FIELD(String, to_cus_code);
    DTO_FIELD_INFO(to_cus_code) {
        info->description = ZH_WORDS_GETTER("movegoods.field.to_cus_code");
    }
    // 转移客户名称
    DTO_FIELD(String, to_cus_name);
    DTO_FIELD_INFO(to_cus_name) {
        info->description = ZH_WORDS_GETTER("movegoods.field.to_cus_name");
    }
    // 源托盘
    DTO_FIELD(String, tin_from);
    DTO_FIELD_INFO(tin_from) {
        info->description = ZH_WORDS_GETTER("movegoods.field.tin_from");
    }
    // 到托盘
    DTO_FIELD(String, tin_id);
    DTO_FIELD_INFO(tin_id) {
        info->description = ZH_WORDS_GETTER("movegoods.field.tin_id");
    }
    // 源储位
    DTO_FIELD(String, bin_from);
    DTO_FIELD_INFO(bin_from) {
        info->description = ZH_WORDS_GETTER("movegoods.field.bin_from");
    }
    // 到储位
    DTO_FIELD(String, bin_to);
    DTO_FIELD_INFO(bin_to) {
        info->description = ZH_WORDS_GETTER("movegoods.field.bin_to");
    }
    // 状态
    DTO_FIELD(String, move_sta);
    DTO_FIELD_INFO(move_sta) {
        info->description = ZH_WORDS_GETTER("movegoods.field.move_sta");
    }
};

/**
* 导出转移任务的DTO
* 包含导出转移任务生成的excel表格的地址
*/
class MoveGoodsDownLoadDTO : public oatpp::DTO {
    DTO_INIT(MoveGoodsDownLoadDTO, oatpp::DTO);
<<<<<<< HEAD
	// 返回导出转移任务文件地址
	DTO_FIELD(String, download_movegoods);
	DTO_FIELD_INFO(download_movegoods) {
		info->description = ZH_WORDS_GETTER("movegoods.field.download_movegoods");
	}
=======
    // 返回导出转移任务文件地址
    DTO_FIELD(String, downLoadMoveGoods);
    DTO_FIELD_INFO(downLoadMoveGoods) {
        info->description = ZH_WORDS_GETTER("move-goods.field.down-load-move-goods");
    }
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0
};

/**
<<<<<<< HEAD
 * 批量转移任务的DTO
 */
class MoveGoodsBatchModifyDTO : public MoveGoodsBaseDTO {
    DTO_INIT(MoveGoodsBatchModifyDTO, DTO);
=======
* 批量转移任务的DTO
*/
class MoveGoodsBatchDTO : public oatpp::DTO {
    DTO_INIT(MoveGoodsBatchDTO, DTO);
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0
    DTO_FIELD(Vector<Object<MoveGoodsBaseDTO>>, items);
    DTO_FIELD_INFO(items) {
        info->description = ZH_WORDS_GETTER("movegoods.field.items");
    }
};

<<<<<<< HEAD
/**
 * 删除转移任务（支持批量）的DTO
 */
class BatchRemoveMoveGoodsDTO : public oatpp::DTO {
    DTO_INIT(BatchRemoveMoveGoodsDTO, DTO);
    DTO_FIELD(Vector<String>, items);
    DTO_FIELD_INFO(items) {
        info->description = ZH_WORDS_GETTER("movegoods.field.items");
    }
};

/**
 * 传输对象
 * 包含单个转移任务的信息
 */
class MoveGoodsDTO : public MoveGoodsDetailedDTO {
    DTO_INIT(MoveGoodsDTO, MoveGoodsDetailedDTO);
    // 转移任务Id
    DTO_FIELD(String, id);
    DTO_FIELD_INFO(id) {
        info->description = ZH_WORDS_GETTER("movegoods.field.id");
    }
    // 创建人名称
    DTO_FIELD(String, create_name);
    DTO_FIELD_INFO(create_name) {
        info->description = ZH_WORDS_GETTER("movegoods.field.create_name");
    }
    // 创建日期
    DTO_FIELD(String, create_date);
    DTO_FIELD_INFO(create_date) {
        info->description = ZH_WORDS_GETTER("movegoods.field.create_date");
    }
    // 更新人名称
    DTO_FIELD(String, update_name);
    DTO_FIELD_INFO(update_name) {
        info->description = ZH_WORDS_GETTER("movegoods.field.update_name");
    }
    // 更新日期
    DTO_FIELD(String, update_date);
    DTO_FIELD_INFO(update_date) {
        info->description = ZH_WORDS_GETTER("movegoods.field.update_date");
    }
    // 执行状态
    DTO_FIELD(String, run_sta);
    DTO_FIELD_INFO(run_sta) {
        info->description = ZH_WORDS_GETTER("movegoods.field.run_sta");
    }
=======

/**
* 传输对象
* 包含单个转移任务的信息
*/
class MoveGoodsDTO : public MoveGoodsModifyDTO {
    DTO_INIT(MoveGoodsDTO, MoveGoodsModifyDTO);
>>>>>>> 05f7ec7fb45d4bc1f52eea780440c95f076c61f0
};

/**
* 分页获取转移任务对象
*/
class MoveGoodsPageDTO : public PageDTO<MoveGoodsDTO::Wrapper> {
    DTO_INIT(MoveGoodsPageDTO, PageDTO<MoveGoodsDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
