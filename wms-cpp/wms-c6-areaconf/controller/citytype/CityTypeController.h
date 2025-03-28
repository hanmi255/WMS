#ifndef _CITYTYPE_CONTROLLER_
#define _CITYTYPE_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/query/citytype/CityTypeQuery.h"
#include "domain/dto/citytype/CityTypeDTO.h"
#include "domain/vo/citytype/CityTypeVO.h"
#include "domain/vo/BaseJsonVO.h"
#include "service/citytype/CityTypeService.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class CityTypeController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(CityTypeController);
public:
	// 修改城市类型
    ENDPOINT_INFO(Modify) {
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("citytype.modify"));
        API_DEF_ADD_AUTH();
        // 定义其他查询参数描述
        API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("citytype.name"), "c43cbea3-a6af-4c80-8be8-ebaf33a25cd3", true);
        API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("citytype.name"), "city-01", true);
        API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("citytype.code"), "code-01", true);
        API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
    }
    ENDPOINT(API_M_PUT, "/areaconf/citytype/modify", Modify, BODY_DTO(CityTypeDTO::Wrapper, citytypeDTO), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_RESP_VO(execModifyCityTypeCode(citytypeDTO, authObject->getPayload()));
    }
    // 获取城市类型名称列表
    ENDPOINT_INFO(NameList) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("citytype.get_names_list"));
        API_DEF_ADD_AUTH();
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(CityTypeNameListJsonVO);
    }
    ENDPOINT(API_M_GET, "/areaconf/citytype/namelist", NameList, API_HANDLER_AUTH_PARAME) {
    // 呼叫执行函数响应结果
    API_HANDLER_RESP_VO(execGetCityTypeNamesList());
}
    // 获取城市类型列表
    ENDPOINT_INFO(Get) {
    API_DEF_ADD_TITLE(ZH_WORDS_GETTER("citytype.querycitytypelist"));
    API_DEF_ADD_AUTH();
    API_DEF_ADD_QUERY_PARAMS(String, "city_type_code", ZH_WORDS_GETTER("citytype.code"), "C-0001", false);
    API_DEF_ADD_QUERY_PARAMS(String, "city_type_name", ZH_WORDS_GETTER("citytype.name"), "xxx", false);
    API_DEF_ADD_RSP_JSON_WRAPPER(CityTypePageJsonVO); 
    API_DEF_ADD_PAGE_PARAMS();
    }
    ENDPOINT(API_M_GET, "/areaconf/citytype/list", Get, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_QUERY_PARAM(query, CityTypeQuery, queryParams);
        API_HANDLER_RESP_VO(execGetCityTypeList(query));
    }
    // 录入城市类型
    ENDPOINT_INFO(Add) {
        // 定义接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("citytype.add"));
        // 定义默认授权参数
        API_DEF_ADD_AUTH();
        API_DEF_ADD_QUERY_PARAMS(String, "name", ZH_WORDS_GETTER("citytype.name"), "city-01", true);
        API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("citytype.code"), "code-01", true);
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
    }
    ENDPOINT(API_M_POST, "/areaconf/citytype/add", Add, BODY_DTO(CitytypeBaseDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
        // 呼叫执行函数响应结果
        API_HANDLER_RESP_VO(execCreateCityType(dto, authObject->getPayload()));
    }
    // 删除城市类型
    ENDPOINT_INFO(Del) {
        // 定义标题和返回类型以及授权支持
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("del.city.type"), String);
        // 定义其他路径参数说明
        API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("citytype.uniq_id"), "", true);
    }
    ENDPOINT(API_M_DEL, "/areaconf/citytype/del", Del, QUERY(String, id), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_RESP_VO(execCitytypeDel(id));
    }
	// 导入城市类型
	ENDPOINT_INFO(Import) {
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("citytype.upload"), StringJsonVO::Wrapper);
        API_DEF_ADD_AUTH();
	}
    ENDPOINT(API_M_POST, "/areaconf/citytype/import", Import, REQUEST(std::shared_ptr<IncomingRequest>, request), API_HANDLER_AUTH_PARAME) {
        API_HANDLER_RESP_VO(execCitytypeUpload(request, authObject->getPayload()));
    }
	// 导出城市类型
	ENDPOINT_INFO(Export) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("citytype.download"));
        API_DEF_ADD_AUTH();
	}
	ENDPOINT(API_M_GET, "/areaconf/citytype/export", Export, API_HANDLER_AUTH_PARAME) {
        return execCitytypeDownload();
	}

private:
    StringJsonVO::Wrapper execModifyCityTypeCode(const CityTypeDTO::Wrapper& dto, const PayloadDTO& payload);
    CityTypeNameListJsonVO::Wrapper execGetCityTypeNamesList();
    CityTypePageJsonVO::Wrapper execGetCityTypeList(const CityTypeQuery::Wrapper& query);
    StringJsonVO::Wrapper execCreateCityType(const CitytypeBaseDTO::Wrapper& citytypeDTO, const PayloadDTO& payload);
    StringJsonVO::Wrapper execCitytypeDel(const String& id);
	StringJsonVO::Wrapper execCitytypeUpload(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
	std::shared_ptr<OutgoingResponse> execCitytypeDownload();
};


#include OATPP_CODEGEN_END(ApiController)
#endif // !_CITYTYPE_CONTROLLER_
