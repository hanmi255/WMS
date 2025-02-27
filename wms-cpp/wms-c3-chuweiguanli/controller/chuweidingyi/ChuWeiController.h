#pragma once

#ifndef _CHUWEI_CONTROLLER_
#define _CHUWEI_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/vo/chuweidingyi/ChuWeiVO.h"
#include "domain/query/chuweidingyi/ChuWeiQuery.h"
#include "domain/dto/chuweidingyi/QueryCWDTO.h"


#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class ChuWeiController : public oatpp::web::server::api::ApiController {//�̳п�����
	//����������������
	API_ACCESS_DECLARE(ChuWeiController);
	//����ӿ�
public:
	//[��ȡ��λ�б�����+��ҳ��]�ӿ�����
	ENDPOINT_INFO(queryChuwei) {
		//����ӿڱ���
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("chuwei.get.summary"));
		//����Ĭ����Ȩ��������ѡ���壬��������ˣ�����ENDPOINT������Ҫ����API_HANDLER_AUTH_PARAME��
		API_DEF_ADD_AUTH();
		// ������Ӧ������ʽ
		API_DEF_ADD_RSP_JSON_WRAPPER(ChuWeiPageJsonVO);
		// �����ҳ��ѯ��������
		API_DEF_ADD_PAGE_PARAMS();
		// ����������ѯ��������
		API_DEF_ADD_QUERY_PARAMS(String, "store", ZH_WORDS_GETTER("chuwei.field.store"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "store_code", ZH_WORDS_GETTER("chuwei.field.store_code"), "xxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "store_barcode", ZH_WORDS_GETTER("chuwei.field.store_barcode"), "xxx", false);
		//API_DEF_ADD_QUERY_PARAMS(String, "store_type", ZH_WORDS_GETTER("chuwei.field.store_type"), "��/��", false);   ����ѡ��ʵ�֣�
		API_DEF_ADD_QUERY_PARAMS(String, "x_axis", ZH_WORDS_GETTER("chuwei.field.x_axis"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "y_axis", ZH_WORDS_GETTER("chuwei.field.y_axis"), "N", false);
		API_DEF_ADD_QUERY_PARAMS(String, "z_axis", ZH_WORDS_GETTER("chuwei.field.z_axis"), "N", false);
	}

	// [��λ��ҳ��ѯ]�ӿڴ���
	ENDPOINT(API_M_GET, "/chuweiguanli/chuweidingyi/query-chuwei", queryChuwei, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// ������ѯ����ΪQuery����ģ��
		API_HANDLER_QUERY_PARAM(chuweiQuery, ChuWeiQuery, queryParams);
		// ����ִ�к�����Ӧ���
		API_HANDLER_RESP_VO(execQueryChuwei(chuweiQuery, authObject->getPayload()));
	}



	// [��λ�޸�]�ӿ�����
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("chuwei.modify.summary"), modifyChuwei, Uint64JsonVO::Wrapper);
	// [��λ�޸�]�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/chuweiguanli/chuweidingyi/modify-chuwei", modifyChuwei, BODY_DTO(ChuWeiDTO::Wrapper, dto), execModifyChuwei(dto));

	//[ɾ����λ]�ӿ�����
	ENDPOINT_INFO(removeChuwei) {	
		// �������ͷ��������Լ���Ȩ֧��
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("chuwei.delete.summary"), Uint64JsonVO::Wrapper);
		// ��������·������˵��
		API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("sample.field.id"), 1, true);

	}
	// [ɾ����λ]�ӿڴ���
	API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/chuweiguanli/chuweidingyi/delect-chuwei/{id}", removeChuwei, PATH(String, id), execRemoveChuwei(id));


private:
	//��ҳ��ѯ��λ����
	ChuWeiPageJsonVO::Wrapper ChuWeiController::execQueryChuwei(const ChuWeiQuery::Wrapper& query, const PayloadDTO& payload);
	//��λ�޸�����
	Uint64JsonVO::Wrapper ChuWeiController::execModifyChuwei(const ChuWeiDTO::Wrapper& dto);
	//��λɾ������
	Uint64JsonVO::Wrapper ChuWeiController::execRemoveChuwei(const String& id);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section
#endif // _CHUWEI_CONTROLLER_