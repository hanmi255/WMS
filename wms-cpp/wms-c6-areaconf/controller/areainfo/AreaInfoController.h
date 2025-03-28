#ifndef _AREAINFO_CONTROLLER_
#define _AREAINFO_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/areainfo/AreaInfoDTO.h"
#include "domain/vo/areainfo/AreaInfoVO.h"
#include "domain/query/areainfo/AreaInfoQuery.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class AreaInfoController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(AreaInfoController);
public:
	// 获取地区信息名称树
	ENDPOINT_INFO(NameTree) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("AreaInfo.getnametree"), AreaNameTreeJsonVO::Wrapper);
	}
	ENDPOINT(API_M_GET, "/areaconf/areainfo/nametree", NameTree, API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execNameTreeAreaInfo());
	}
	// 获取地区信息列表
	ENDPOINT_INFO(InfoList) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("AreaInfo.get"));
		API_DEF_ADD_AUTH();
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "city_code", ZH_WORDS_GETTER("AreaInfo.city_code"), "xxxx", false);
		API_DEF_ADD_QUERY_PARAMS(String, "city_name", ZH_WORDS_GETTER("AreaInfo.city_name"), "001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "city_serc", ZH_WORDS_GETTER("AreaInfo.city_serc"), "001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "city_type_name", ZH_WORDS_GETTER("AreaInfo.city_type_name"), "C-0002", false);
		API_DEF_ADD_QUERY_PARAMS(String, "barea_name", ZH_WORDS_GETTER("AreaInfo.barea_name"), "BA-0001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "area_name", ZH_WORDS_GETTER("AreaInfo.area_name"), "A-000", false);
		API_DEF_ADD_QUERY_PARAMS(String, "city_del", ZH_WORDS_GETTER("AreaInfo.city_del"), "N", false);
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(AreaInfoPageJsonVO);
	}
	ENDPOINT(API_M_GET, "/areaconf/areainfo/get", InfoList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_QUERY_PARAM(query, AreaInfoQuery, queryParams);
		API_HANDLER_RESP_VO(execAreaInfoList(query));
	}
	// 录入地区信息
	ENDPOINT_INFO(Add) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("AreaInfo.add"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_QUERY_PARAMS(String, "city_code", ZH_WORDS_GETTER("AreaInfo.city_code"), "001", true);
		API_DEF_ADD_QUERY_PARAMS(String, "city_name", ZH_WORDS_GETTER("AreaInfo.city_name"), "city-name-01", true);
		API_DEF_ADD_QUERY_PARAMS(String, "city_serc", ZH_WORDS_GETTER("AreaInfo.city_serc"), "city-serc-01", true);
		API_DEF_ADD_QUERY_PARAMS(String, "city_del", ZH_WORDS_GETTER("AreaInfo.city_del"), "N", true);
		API_DEF_ADD_QUERY_PARAMS(String, "city_type_name", ZH_WORDS_GETTER("AreaInfo.city_type_name"), "type-name-01", true);
		API_DEF_ADD_QUERY_PARAMS(String, "barea_name", ZH_WORDS_GETTER("AreaInfo.barea_name"), "barea-name-01", true);
		API_DEF_ADD_QUERY_PARAMS(String, "area_name", ZH_WORDS_GETTER("AreaInfo.area_name"), "area-name-01", true);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_POST, "/areaconf/areainfo/add", Add, BODY_DTO(AreaInfoUpdDTO::Wrapper, dto) ,API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execAddAreaInfo(dto, authObject->getPayload()));
	}
	// 修改地区信息
	ENDPOINT_INFO(Modify) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("AreaInfo.modify"));
		API_DEF_ADD_AUTH();
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("AreaInfo.id"), "8a8418879555bfbf019555d61873000a", true);
		API_DEF_ADD_QUERY_PARAMS(String, "city_code", ZH_WORDS_GETTER("AreaInfo.city_code"), "8a8418879555bfbf019555d391fe0006", true);
		API_DEF_ADD_QUERY_PARAMS(String, "city_name", ZH_WORDS_GETTER("AreaInfo.city_name"), "03", true);
		API_DEF_ADD_QUERY_PARAMS(String, "city_serc", ZH_WORDS_GETTER("AreaInfo.city_serc"), "03", true);
		API_DEF_ADD_QUERY_PARAMS(String, "city_del", ZH_WORDS_GETTER("AreaInfo.city_del"), "N", true);
		API_DEF_ADD_QUERY_PARAMS(String, "city_type_name", ZH_WORDS_GETTER("AreaInfo.city_type_name"), "C-0002", true);
		API_DEF_ADD_QUERY_PARAMS(String, "barea_name", ZH_WORDS_GETTER("AreaInfo.barea_name"), "BA-0000", true);
		API_DEF_ADD_QUERY_PARAMS(String, "area_name", ZH_WORDS_GETTER("AreaInfo.area_name"), "A-000", true);
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_PUT, "/areaconf/areainfo/modify", Modify, BODY_DTO(AreaInfoUpdDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execModify(dto, authObject->getPayload()));
	}
	// 删除地区信息
	ENDPOINT_INFO(Delete) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("AreaInfo.delete"), StringJsonVO::Wrapper);
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("AreaInfo.id"), "8a8418879555bfbf019555d61873000a", false);
	}
	ENDPOINT(API_M_DEL, "/areaconf/areainfo/delete", Delete, BODY_DTO(String, dto), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execDelete(dto));
	}
	// 导出地区信息
	ENDPOINT_INFO(Export) {
		API_DEF_ADD_AUTH();
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("AreaInfo.export"));
	}
	ENDPOINT(API_M_GET, "/areaconf/areainfo/export", Export, API_HANDLER_AUTH_PARAME) {
		return execDownloadExcel();
	}
	// 导入地区信息
	ENDPOINT_INFO(Import) {
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("AreaInfo.import"), StringJsonVO::Wrapper);
	}
	ENDPOINT(API_M_POST, "/areaconf/areainfo/import", Import, REQUEST(std::shared_ptr<IncomingRequest>, request), API_HANDLER_AUTH_PARAME) {
		API_HANDLER_RESP_VO(execUploadExcel(request, authObject->getPayload()));
	}

private:
	AreaNameTreeJsonVO::Wrapper execNameTreeAreaInfo();
	AreaInfoPageJsonVO::Wrapper execAreaInfoList(const AreaInfoQuery::Wrapper& query);
	StringJsonVO::Wrapper execAddAreaInfo(const AreaInfoUpdDTO::Wrapper& dto, const PayloadDTO& payload);
	std::shared_ptr<OutgoingResponse> execDownloadExcel();
	StringJsonVO::Wrapper execUploadExcel(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
	StringJsonVO::Wrapper execModify(const AreaInfoUpdDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execDelete(const String& dto);
};
   

#include OATPP_CODEGEN_END(ApiController)

#endif // !_AREAINFO_CONTROLLER_
