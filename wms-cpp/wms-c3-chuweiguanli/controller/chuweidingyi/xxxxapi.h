#pragma once

#ifndef _APIXIANGXIXINXI_
#define _APIXIANGXIXINXI_


#include "../../domain/dto/chuweidingyi/xxxxdto.h"
#include "../../domain/query/chuweidingyi/xxxxquery.h"
#include "../../domain/vo/chuweidingyi/xxxxvo.h"
#include "domain/GlobalInclude.h"
#include "ApiHelper.h"
#include "ServerInfo.h"



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
    ENDPOINT(API_M_GET, "chuweiguanli/chuweidingyi/huo-qu-chu-we-ixiang-xi-xin-xi", xinxiall, QUERIES(QueryParams, xxxx), API_HANDLER_AUTH_PARAME) {

        // 解析查询参数为Query领域模型
        API_HANDLER_QUERY_PARAM(cusall, xaingxixinxichaxun, xxxx);
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execxxxx(cusall));
    }

	//导入储位/文件上传--------------------------------------------------------------------
	ENDPOINT_INFO(daoruinto) {

		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("daoru.dr.wenjianshangchaun"));

		API_DEF_ADD_RSP_JSON_WRAPPER(daoruJsonVO);
		//API_DEF_ADD_QUERY_PARAMS(String, "cangku", ZH_WORDS_GETTER("daoru.dr.daoruwenjian"), ".xlsx", false);
	}
	ENDPOINT(API_M_POST, "chuweiguanli/chuweidingyi/dao-ru-chu-wei", daoruinto, QUERIES(QueryParams, scwj)) {

		API_HANDLER_QUERY_PARAM(cusscwj, daoruquery, scwj);
		API_HANDLER_RESP_VO(execsc(cusscwj));
	}

	//导出储位/文件下载------------------------------------------------------------------------
	ENDPOINT_INFO(daochuout) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("daochu.daochuwenjian"), daoruJsonVO::Void);
	}
	ENDPOINT(API_M_GET, "chuweiguanli/chuweidingyi/dao-chu-chu-wei", daochuout, QUERY(String, filename)) {
		return execxz(filename);
	}


private:
    xiangxixinxiJsonVO::Wrapper execxxxx(const xaingxixinxichaxun::Wrapper& xxxx);
    daoruJsonVO::Wrapper execsc(const daoruquery::Wrapper& sc);

	std::shared_ptr<OutgoingResponse> execxz(const String& filename);
};


// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _APIXIANGXIXINXI_