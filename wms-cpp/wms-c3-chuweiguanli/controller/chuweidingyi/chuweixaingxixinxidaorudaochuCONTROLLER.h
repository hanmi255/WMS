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
		API_DEF_ADD_QUERY_PARAMS(String, "weiyiid", ZH_WORDS_GETTER("chuweixiangxixinxi.bs.id"), "2ce255sad", false);
	}
    ENDPOINT(API_M_GET, "chuweiguanli/chuweidingyi/huo-qu-chu-wei-xiang-xi-xin-xi", xinxiall, QUERIES(QueryParams, weiyiid), API_HANDLER_AUTH_PARAME) {

        // 解析查询参数为Query领域模型
        API_HANDLER_QUERY_PARAM(cusZhanShi, xiangxixinxiQUERY, weiyiid);
        // 呼叫执行函数响应结果
        //API_HANDLER_RESP_VO(execXiangXiXinXiZhanShi(cusZhanShi));
		API_HANDLER_RESP_VO(execXiangXiXinXiZhanShi(cusZhanShi, authObject->getPayload()));
    }



	//导出储位/文件下载------------------------------------------------------------------------
	//
	ENDPOINT_INFO(daochuout) {
	
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("daochu.daochuwenjian"));
		//默认授权参数
		API_DEF_ADD_AUTH();
		//	定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);

		API_DEF_ADD_QUERY_PARAMS(String, "weiyiid", ZH_WORDS_GETTER("chuweixiangxixinxi.bs.id"), "2ce255sad", false);
	}
	ENDPOINT(API_M_GET, "chuweiguanli/chuweidingyi/dao-chu-chu-wei", daochuout, BODY_DTO(daochuchuweiDTO::Wrapper, id_zhi), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execDaoChuChuWei(id_zhi, authObject->getPayload()));
	}




	ENDPOINT_INFO(daoru) {

		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("daoru.dr.wenjianshangchaun"));
		//默认授权参数
		API_DEF_ADD_AUTH();
		//	定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);

		
	}
	ENDPOINT(API_M_POST, "/chuweiguanli/chuweidingyi/dao-ru-chu-wei", daoru, REQUEST(std::shared_ptr<IncomingRequest>, request), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execDaoRuWenJianOne(request, authObject->getPayload()));
	}
	

private:
    xiangxixinxiJsonVO::Wrapper execXiangXiXinXiZhanShi(const xiangxixinxiQUERY::Wrapper& query, const PayloadDTO& payload);


	StringJsonVO::Wrapper execDaoChuChuWei(const daochuchuweiDTO::Wrapper& id_zhi, const PayloadDTO& payload);


	StringJsonVO::Wrapper execDaoRuWenJianOne(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);


};


// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _APIXIANGXIXINXI_