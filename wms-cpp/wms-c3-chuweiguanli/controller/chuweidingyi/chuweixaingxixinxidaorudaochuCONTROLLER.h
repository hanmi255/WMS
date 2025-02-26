#pragma once

#ifndef _APIXIANGXIXINXI_
#define _APIXIANGXIXINXI_



#include "../../domain/dto/chuweidingyi/xiangxixinxiDTO.h"
#include "../../domain/query/chuweidingyi/xiangxixinxiQUERY.h"
#include "../../domain/vo/chuweidingyi/xiangxixinxiVO.h"
#include "domain/vo/BaseJsonVO.h"



// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class apixiangxixinxi : public oatpp::web::server::api::ApiController 
{
	API_ACCESS_DECLARE(apixiangxixinxi);

public:
 
	//查询所有数据--------------------------
	ENDPOINT_INFO(xinxiall) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("chuweixiangxixinxi.api.chaxunxinxi"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(xiangxixinxiJsonVO);
		// 定义其他查询参数描述
		API_DEF_ADD_QUERY_PARAMS(String, "cangku", ZH_WORDS_GETTER("chuweixiangxixinxi.bs.bioashi"), "2ce255sad", false);
	}
    ENDPOINT(API_M_GET, "chuweiguanli/chuweidingyi/huo-qu-chu-we-ixiang-xi-xin-xi", xinxiall, QUERIES(QueryParams, XiangXiXinXiZhanShi), API_HANDLER_AUTH_PARAME) {

        // 解析查询参数为Query领域模型
        API_HANDLER_QUERY_PARAM(cusXiangXiXinXiZhanShi, xaingxixinxichaxun, XiangXiXinXiZhanShi);
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execXiangXiXinXiZhanShi(cusXiangXiXinXiZhanShi));
    }




	//导入储位/单文件  文件上传 ---------------------------------------------------------------------
	// 定义描述
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("daoru.dr.wenjianshangchaun"), daoruinto, StringJsonVO::Wrapper);
	// 定义端点
	API_HANDLER_ENDPOINT(API_M_POST, "chuweiguanli/chuweidingyi/dao-ru-chu-wei", daoruinto, REQUEST(std::shared_ptr<IncomingRequest>, ShangChuanWenJian), execDaoRuWenJian(ShangChuanWenJian));

	//多文件上传
	//API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("daoru.dr.wenjianshangchaunmore"), daoruintomore, daoruJsonVO::Wrapper);
	// 定义端点
	//API_HANDLER_ENDPOINT(API_M_POST, "chuweiguanli/chuweidingyi/dao-ru-chu-wei-more", daoruintomore, REQUEST(std::shared_ptr<IncomingRequest>, ShangChuanWenJian), execDaoRuWenJianMore(ShangChuanWenJian));



	//导出储位/文件下载------------------------------------------------------------------------
	ENDPOINT_INFO(daochuout) {
	
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("daochu.daochuwenjian"));
		//默认授权参数
		API_DEF_ADD_AUTH();
		//	定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//	定义参数：仓库代码
		API_DEF_ADD_QUERY_PARAMS(oatpp::String, "id_zhi", ZH_WORDS_GETTER("daochu.daochuid"), "2ce43gh", true);
	}
	ENDPOINT(API_M_GET, "chuweiguanli/chuweidingyi/dao-chu-chu-wei", daochuout, QUERY(String, id_zhi), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execDaoChuChuWei(id_zhi, authObject->getPayload()));
	}



private:
    xiangxixinxiJsonVO::Wrapper execXiangXiXinXiZhanShi(const xaingxixinxichaxun::Wrapper& XiangXiXinXiZhanShi);

	StringJsonVO::Wrapper execDaoRuWenJian(std::shared_ptr<IncomingRequest> sc);
	//StringJsonVO::Wrapper execDaoRuWenJianMore(std::shared_ptr<IncomingRequest> sc);

	StringJsonVO::Wrapper execDaoChuChuWei(const String& id_zhi, const PayloadDTO& payload);
};


// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _APIXIANGXIXINXI_