#pragma once

#ifndef _LOADINGFEE_DTO_
#define _LOADINGFEE_DTO_

#include "../../GlobalInclude.h"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 * 外包装车费数据传输对象
 */
class LoadingFeeDTO : public oatpp::DTO
{
	DTO_INIT(LoadingFeeDTO, DTO);
	//费用
	DTO_FIELD(String, fee);
	DTO_FIELD_INFO(fee) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.fee");
	}
	//操作人
	DTO_FIELD(String, Operator);//operator是关键字，所以改为Operator
	DTO_FIELD_INFO(Operator) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.operator");
	}
	//操作日期
	DTO_FIELD(String, operateDate);
	DTO_FIELD_INFO(operateDate) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.operateDate");
	}
	//单号
	DTO_FIELD(String, orderNo);
	DTO_FIELD_INFO(orderNo) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.orderNo");
	}
	//商品
	DTO_FIELD(String, goods);
	DTO_FIELD_INFO(goods) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.goods");
	}
	//商品名称
	DTO_FIELD(String, goodsName);
	DTO_FIELD_INFO(goodsName) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.goodsName");
	}
	//装车数
	DTO_FIELD(Int32, goodsNum);
	DTO_FIELD_INFO(goodsNum) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.goodsNum");
	}
	//装车重量
	DTO_FIELD(Float64, goodsWeight);
	DTO_FIELD_INFO(goodsWeight) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.goodsWeight");
	}
	//费用RMB
	DTO_FIELD(Float64, feeRMB);
	DTO_FIELD_INFO(feeRMB) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.feeRMB");
	}
	//单价
	DTO_FIELD(Float64, price);
	DTO_FIELD_INFO(price) {
		info->description = ZH_WORDS_GETTER("loadingfee.field.price");
	}
};

/**
 * 外包装车费分页数据传输对象
 */
class LoadingFeePageDTO : public PageDTO<LoadingFeeDTO::Wrapper>
{
	DTO_INIT(LoadingFeePageDTO, PageDTO<LoadingFeeDTO::Wrapper>);
};

#include OATPP_CODEGEN_END(DTO)

#endif // !_LOADINGFEE_DTO_