#pragma once

#ifndef _APIXIANGXIXINXI_
#define _APIXIANGXIXINXI_



#include "../../domain/dto/chuweidingyi/xiangxixinxiDTO.h"
#include "../../domain/query/chuweidingyi/xiangxixinxiQUERY.h"
#include "../../domain/vo/chuweidingyi/xiangxixinxiVO.h"
#include "domain/vo/BaseJsonVO.h"



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
    ENDPOINT(API_M_GET, "chuweiguanli/chuweidingyi/huo-qu-chu-we-ixiang-xi-xin-xi", xinxiall, QUERIES(QueryParams, XiangXiXinXiZhanShi), API_HANDLER_AUTH_PARAME) {

        // ������ѯ����ΪQuery����ģ��
        API_HANDLER_QUERY_PARAM(cusXiangXiXinXiZhanShi, xaingxixinxichaxun, XiangXiXinXiZhanShi);
        // ����ִ�к�����Ӧ���
        API_HANDLER_RESP_VO(execXiangXiXinXiZhanShi(cusXiangXiXinXiZhanShi));
    }




	//���봢λ/���ļ�  �ļ��ϴ� ---------------------------------------------------------------------
	// ��������
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("daoru.dr.wenjianshangchaun"), daoruinto, StringJsonVO::Wrapper);
	// ����˵�
	API_HANDLER_ENDPOINT(API_M_POST, "chuweiguanli/chuweidingyi/dao-ru-chu-wei", daoruinto, REQUEST(std::shared_ptr<IncomingRequest>, ShangChuanWenJian), execDaoRuWenJian(ShangChuanWenJian));

	//���ļ��ϴ�
	//API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("daoru.dr.wenjianshangchaunmore"), daoruintomore, daoruJsonVO::Wrapper);
	// ����˵�
	//API_HANDLER_ENDPOINT(API_M_POST, "chuweiguanli/chuweidingyi/dao-ru-chu-wei-more", daoruintomore, REQUEST(std::shared_ptr<IncomingRequest>, ShangChuanWenJian), execDaoRuWenJianMore(ShangChuanWenJian));



	//������λ/�ļ�����------------------------------------------------------------------------
	ENDPOINT_INFO(daochuout) {
	
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("daochu.daochuwenjian"));
		//Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		//	������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//	����������ֿ����
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


// 0 ȡ��API������ʹ�ú�
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _APIXIANGXIXINXI_