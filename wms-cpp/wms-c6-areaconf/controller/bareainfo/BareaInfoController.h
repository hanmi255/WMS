#ifndef _DISTRICTINFO_CONTROLLER_
#define _DISTRICTINFO_CONTROLLER_

#include "domain/GlobalInclude.h"
#include "domain/vo/districtinfo/BareaInfoVO.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/dto/regioninfo/RegioninfoDTO.h"
#include "domain/query/PageQuery.h"
#include "domain/dto/regioninfo/DareaInfoDTO.h"
#include "domain/vo/regioninfo/DareaInfoVO.h"
#include "domain/query/bareainfo/BareaInfoQuery.h"
#include "domain/vo/regioninfo/RegionNameJsonVO.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

class BareaInfoController : public oatpp::web::server::api::ApiController
{
	API_ACCESS_DECLARE(BareaInfoController);
public:
	// 导入片区信息
	API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("insert_region"), Import, StringJsonVO::Wrapper);
	API_HANDLER_ENDPOINT_AUTH(API_M_POST, "/areaconf/bareainfo/import", Import, REQUEST(std::shared_ptr<IncomingRequest>, request), execImport(request, authObject->getPayload()));
	// 导出片区信息
	ENDPOINT_INFO(Export) {
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("BareaInfo.export"));
		API_DEF_ADD_AUTH();
	}
	ENDPOINT(API_M_GET, "/areaconf/bareainfo/export", Export, API_HANDLER_AUTH_PARAME) {
		return execExport();
	}
	// 录入片区信息
	ENDPOINT_INFO(Add) {
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("add_region"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		API_DEF_ADD_QUERY_PARAMS(String, "region_code", ZH_WORDS_GETTER("region.field.code"), "001", true);
		API_DEF_ADD_QUERY_PARAMS(String, "region_name", ZH_WORDS_GETTER("region.field.name"), "barea-name-01", true);
		API_DEF_ADD_QUERY_PARAMS(String, "region_rdate", ZH_WORDS_GETTER("region.field.rdate"), "barea-rdate-01", true);
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(Uint64JsonVO);
	}
	ENDPOINT(API_M_POST, "/areaconf/bareainfo/add", Add, BODY_DTO(RegionInfoDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execAdd(dto, authObject->getPayload()));
	}
	// 删除片区信息
	ENDPOINT_INFO(Del) {
		// 定义标题和返回类型以及授权支持
		API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("delete_region"), StringJsonVO::Wrapper);
		// 定义其他路径参数说明
		API_DEF_ADD_QUERY_PARAMS(String, "code", ZH_WORDS_GETTER("region.field.code"), "", true);
	}
	ENDPOINT(API_M_DEL, "/areaconf/bareainfo/delete", Del, QUERY(String, code), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execDelete(code));
	}
	// 修改片区信息
	ENDPOINT_INFO(Modify)
	{
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("modify_region"));
		// 定义默认授权参数（可选定义，如果定义了，下面ENDPOINT里面需要加入API_HANDLER_AUTH_PARAME）
		API_DEF_ADD_AUTH();
		API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("region.field.id"), "12239656950316535808", true);
		API_DEF_ADD_QUERY_PARAMS(String, "region_code", ZH_WORDS_GETTER("region.field.code"), "BA-0001", true);
		API_DEF_ADD_QUERY_PARAMS(String, "region_name", ZH_WORDS_GETTER("region.field.name"), "xxxx", true);
		API_DEF_ADD_QUERY_PARAMS(String, "region_rdata", ZH_WORDS_GETTER("region.field.rdata"), "10", true);
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(StringJsonVO);
	}
	ENDPOINT(API_M_PUT, "/areaconf/bareainfo/modify", Modify, BODY_DTO(RegionModifyDTO::Wrapper, dto), API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execModify(dto, authObject->getPayload()));
	}
    // 获取片区信息名称列表
	ENDPOINT_INFO(NameList)
	{
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("BareaInfo.getnamelist"));
		API_DEF_ADD_AUTH();
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(BareaNameListJsonVO);
	}
	ENDPOINT(API_M_GET, "/areaconf/bareainfo/namelist", NameList, API_HANDLER_AUTH_PARAME) {
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execNameList());
	}
	// 获取片区信息列表(条件+分页)
	ENDPOINT_INFO(InfoList)
	{
		// 定义接口标题
		API_DEF_ADD_TITLE(ZH_WORDS_GETTER("BareaInfo.getinfolist"));
		API_DEF_ADD_AUTH();
		// 定义分页查询参数描述
		API_DEF_ADD_PAGE_PARAMS();
		API_DEF_ADD_QUERY_PARAMS(String, "barea_code", ZH_WORDS_GETTER("BareaInfo.excel.head1"), "BA-0001", false);
		API_DEF_ADD_QUERY_PARAMS(String, "barea_name", ZH_WORDS_GETTER("BareaInfo.excel.head2"), "xxx", false);
		// 定义响应参数格式
		API_DEF_ADD_RSP_JSON_WRAPPER(BareaInfoPageJsonVO);
	}
	ENDPOINT(API_M_GET, "/areaconf/bareainfo/infolist", InfoList, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
		// 解析查询参数为Query领域模型
		API_HANDLER_QUERY_PARAM(query, BareaInfoQuery, queryParams);
		// 呼叫执行函数响应结果
		API_HANDLER_RESP_VO(execInfoList(query));
	}
private:
	StringJsonVO::Wrapper execImport(std::shared_ptr<IncomingRequest> request, const PayloadDTO& payload);
	std::shared_ptr<OutgoingResponse> execExport();
	Uint64JsonVO::Wrapper execAdd(const RegionInfoDTO::Wrapper& dto, const PayloadDTO& payload);
	StringJsonVO::Wrapper execDelete(const String& region_code);
	StringJsonVO::Wrapper execModify(const RegionModifyDTO::Wrapper& dto, const PayloadDTO& payload);
	BareaNameListJsonVO::Wrapper execNameList();
	BareaInfoPageJsonVO::Wrapper execInfoList(const BareaInfoQuery::Wrapper& query);
};


#include OATPP_CODEGEN_END(ApiController)

#endif // !_DISTRICTINFO_CONTROLLER_
