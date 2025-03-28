#pragma once

#ifndef _UNLOADINGFEE_DTO_
#define _UNLOADINGFEE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 外包卸货费数据传输对象
 */
class UnloadingFeeDTO : public oatpp::DTO
{
	DTO_INIT(UnloadingFeeDTO, DTO);
	//费用
	DTO_FIELD(String, fee);
	DTO_FIELD_INFO(fee) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.fee");
	}
	//验收人
	DTO_FIELD(String, acceptor);
	DTO_FIELD_INFO(acceptor) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.acceptor");
	}
	//验收日期
	DTO_FIELD(String, acceptDate);
	DTO_FIELD_INFO(acceptDate) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.acceptorDate");
	}
	//单号
	DTO_FIELD(String, orderNo);
	DTO_FIELD_INFO(orderNo) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.orderNo");
	}
	//商品
	DTO_FIELD(String, goods);
	DTO_FIELD_INFO(goods) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.goods");
	}
	//商品名称
	DTO_FIELD(String, goodsName);
	DTO_FIELD_INFO(goodsName) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.goodsName");
	}
	//卸货数
	DTO_FIELD(Int32, unloadingNum);
	DTO_FIELD_INFO(unloadingNum) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.unloadingNum");
	}
	//卸货重量
	DTO_FIELD(Float64, unloadingWeight);
	DTO_FIELD_INFO(unloadingWeight) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.unloadingWeight");
	}
	//费用RMB
	DTO_FIELD(Float64, feeRMB);
	DTO_FIELD_INFO(feeRMB) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.feeRMB");
	}
	//单价
	DTO_FIELD(Float64, price);
	DTO_FIELD_INFO(price) {
		info->description = ZH_WORDS_GETTER("unloadingfee.field.price");
	}
};

/**
 * 外包卸货费分页数据传输对象
 */
class UnloadingFeePageDTO : public PageDTO<UnloadingFeeDTO::Wrapper>
{
	DTO_INIT(UnloadingFeePageDTO, PageDTO<UnloadingFeeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_UNLOADINGFEE_DO_