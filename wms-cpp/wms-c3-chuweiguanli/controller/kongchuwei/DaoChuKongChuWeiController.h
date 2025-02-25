#pragma once
#ifndef _DAO_CHU_KONG_CHU_WEI_CONTROLLER_
#define _DAO_CHU_KONG_CHU_WEI_CONTROLLER_

#include "../../../lib-oatpp/include/ApiHelper.h"	
#include "domain/vo/BaseJsonVO.h"
#include "ApiHelper.h"
#include "ServerInfo.h"
#include "domain/vo/kongchuwei/DaoChuKongChuWeiVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * �ļ�����ʾ���ӿ�
 */
class DaoChuKongChuWeiController : public oatpp::web::server::api::ApiController
{
	// ����������������
	API_ACCESS_DECLARE(DaoChuKongChuWeiController);
public:
	// ����һ���ļ����ؽӿ�
	// ��������
	ENDPOINT_INFO(downloadFile) {
		API_DEF_ADD_COMMON(ZH_WORDS_GETTER("file.download.summary"), Void);
		API_DEF_ADD_QUERY_PARAMS(String, "filename", ZH_WORDS_GETTER("file.field.filename"), "file/test.xlsx", true);
	}
	// ����˵�
	ENDPOINT(API_M_GET, "/chuweiguanli/kongchuwei/export-excel", downloadFile, QUERY(String, filename)) {
		return execDownloadFile(filename);
	}

private: // ����ӿ�ִ�к���

	// ִ���ļ����ش���
	std::shared_ptr<OutgoingResponse> execDownloadFile(const String& filename);

};

#include OATPP_CODEGEN_END(ApiController)

#endif // !_DAO_CHU_KONG_CHU_WEI_CONTROLLER_