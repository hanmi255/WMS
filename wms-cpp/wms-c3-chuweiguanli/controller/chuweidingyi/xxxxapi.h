#pragma once

#ifndef _APIXIANGXIXINXI_
#define _APIXIANGXIXINXI_


#include "../../domain/dto/chuweidingyi/xxxxdto.h"
#include "../../domain/query/chuweidingyi/xxxxquery.h"
#include "../../domain/vo/chuweidingyi/xxxxvo.h"
#include "domain/GlobalInclude.h"
#include "ApiHelper.h"
#include "ServerInfo.h"



// 0 ����API������ʹ�ú�
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen


class apixiangxixinxi : public oatpp::web::server::api::ApiController 
{
	API_ACCESS_DECLARE(apixiangxixinxi);

public:
 
	//��ѯ��������--------------------------
	ENDPOINT_INFO(xinxiall) {
		// ����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("chuweixiangxixinxi.api.chaxunxinxi"));
		// ����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(xiangxixinxiJsonVO);
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "cangku", ZH_WORDS_GETTER("chuweixiangxixinxi.bs.bioashi"), "2ce255sad", false);
	}
    ENDPOINT(API_M_GET, "chuweiguanli/chuweidingyi/huo-qu-chu-we-ixiang-xi-xin-xi", xinxiall, QUERIES(QueryParams, xxxx), API_HANDLER_AUTH_PARAME) {

        // ������ѯ����ΪQuery����ģ��
        API_HANDLER_QUERY_PARAM(cusall, xaingxixinxichaxun, xxxx);
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execxxxx(cusall));
    }

	//���봢λ/�ļ��ϴ�--------------------------------------------------------------------
	ENDPOINT_INFO(daoruinto) {

		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("daoru.dr.wenjianshangchaun"));

		API_DEF_ADD_RSP_JSON_WRAPPER(daoruJsonVO);
		//API_DEF_ADD_QUERY_PARAMS(String, "cangku", ZH_WORDS_GETTER("daoru.dr.daoruwenjian"), ".xlsx", false);
	}
	ENDPOINT(API_M_POST, "chuweiguanli/chuweidingyi/dao-ru-chu-wei", daoruinto, QUERIES(QueryParams, scwj)) {

		API_HANDLER_QUERY_PARAM(cusscwj, daoruquery, scwj);
		API_HANDLER_RESP_VO(execsc(cusscwj));
	}

	//������λ/�ļ�����------------------------------------------------------------------------
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


// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _APIXIANGXIXINXI_