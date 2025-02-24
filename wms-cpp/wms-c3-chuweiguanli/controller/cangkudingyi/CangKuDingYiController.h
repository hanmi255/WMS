#pragma once

#ifndef _CANGKUDINGYICONTROLLER_H_
#define _CANGKUDINGYICONTROLLER_H_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/PageQuery.h"
#include "domain/dto/cangkudingyi/CangkuNameListDTO.h"
#include "domain/dto/cangkudingyi/CangkuListDTO.h"
#include "domain/dto/cangkudingyi/deleteCangkuDTO.h"
#include "domain/vo/cangkudingyi/CangkuVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class CangKuDingYiController : public oatpp::web::server::api::ApiController
{
	//	����������������
	API_ACCESS_DECLARE(CangKuDingYiController);

	//  ����ӿ�
public:

	//	�����ȡ�ֿ������б�ӿ�����
	ENDPOINT_INFO(listCangkuName) {
		//	����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Cangku.EndPoint.get_cangku_name_list"));
		//	����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		//	������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CangkuNameListJsonVO);
	}
	//	���� ��ȡ�ֿ������б�ӿ� ����
	ENDPOINT(API_M_GET, "/chuweiguanli/query-cangku-name-list", listCangkuName, API_HANDLER_AUTH_PARAME) {
		//	����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execListCangkuName(authObject->getPayload()));
	}

	//	���� ɾ���ֿ� �ӿ�����
	ENDPOINT_INFO(deleteCangku) {
		//	����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Cangku.EndPoint.delete_cangku.summary"));
		//	����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		//	������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		////	����������ֿ�ID�б�
		//API_DEF_ADD_PATH_PARAMS(oatpp::List<UInt64>, "id_list", ZH_WORDS_GETTER("Cangku.EndPoint.delete_cangku.params.ids"), 10086, false);

	}
	//	���� ɾ���ֿ� �ӿ� ����
	ENDPOINT(API_M_DEL, "/chuweiguanli/delete-cangku-by-id", deleteCangku, BODY_DTO(DeleteCangkuDTO::Wrapper, id_list), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execDeleteCangku(id_list, authObject->getPayload()));
	}

	//	���� �����ֿ�ӿ� ����
	ENDPOINT_INFO(downLoadCangkuExcel) {
		//	����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Cangku.EndPoint.down_load_cangku_excel.summary"));
		//	����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		//	������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
		//	����������ֿ����
		API_DEF_ADD_QUERY_PARAMS(oatpp::String, "store_code", ZH_WORDS_GETTER("Cangku.EndPoint.down_load_cangku_excel.params.store_code"), "001-FKD", false);
	}
	//	���� �����ֿ�ӿ� ����
	ENDPOINT(API_M_GET, "/chuweiguanli/down-load-cangku-excel", downLoadCangkuExcel, QUERY(String, store_code), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execDownLoadCangkuExcel(store_code, authObject->getPayload()));
	}

	//	���� ��ȡ�ֿ��б�ӿ� ����
	ENDPOINT_INFO(listCangku)
	{
		//	����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("Cangku.EndPoint.get_cangku_list"));
		//	�����������
		API_DEF_ADD_PAGE_PARAMS();
		//	����Ĭ����Ȩ����
		API_DEF_ADD_AUTH();
		//	������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(CangkuListJsonVO);
	}

	//	���� ��ȡ�ֿ��б�ӿ� ����
	ENDPOINT(API_M_GET, "/chuweiguanli/query-cangku-list", listCangku, API_HANDLER_AUTH_PARAME)
	{
		//	����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execListCangku(authObject->getPayload()));
	}


	// ���� ����ֿ� ����
	API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("Cangku.EndPoint.up_load_cangku_excel.summary"), upload, StringJsonVO::Wrapper);
	// ���� ����ֿ� ����
	API_HANDLER_ENDPOINT(API_M_POST, "/chuweiguanli/upload", upload, REQUEST(std::shared_ptr<IncomingRequest>, request), execUpload(request));

private:
	//	��ȡ�ֿ������б�ִ�к���
	CangkuNameListJsonVO::Wrapper execListCangkuName(const PayloadDTO& payload);
	//	ɾ���ֿ�ִ�к���
	StringJsonVO::Wrapper execDeleteCangku(const DeleteCangkuDTO::Wrapper& id_list, const PayloadDTO& payload);
	//	�����ֿ�ִ�к���
	StringJsonVO::Wrapper execDownLoadCangkuExcel(const String& store_code, const PayloadDTO& payload);
	//	��ȡ�ֿ��б�ִ�к���
	StringJsonVO::Wrapper execListCangku(const PayloadDTO& payload);
	// ����ֿ�ִ�к���
	StringJsonVO::Wrapper execUpload(std::shared_ptr<IncomingRequest> request);
};

#include OATPP_CODEGEN_END(ApiController)



#endif // _CANGKUDINGYICONTROLLER_H_
