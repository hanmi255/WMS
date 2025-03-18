#pragma once
#include"domain/vo/BaseJsonVO.h"
#include"domain/GlobalInclude.h" 
#include"domain/query/PageQuery.h"
#include "domain/query/lihuorenwu/GettasklistControllerQuery.h"
#include "domain/dto/lihuorenwu/GettasklistControllerDTO.h"
#include "domain/vo/lihuorenwu/GettasklistControllervo.h"
#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class GettasklistController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(GettasklistController);
public:
   
    /*
    * 理货任务-导出数据
    */
    ENDPOINT_INFO(outputGettasklistController) {
        info->summary = ZH_WORDS_GETTER("guanli.task.data");
        API_DEF_ADD_QUERY_PARAMS(Int64, "id", ZH_WORDS_GETTER("output.con.lihuo"), 1, false);
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(GettasklistControllerJsonVO);

    }
    ENDPOINT("GET", "/kuneiguanli/lihuorenwu/daochudata", outputGettasklistController) {

        return createResponse(Status::CODE_200, "Hello World!");
    }
    /*
    * 理货任务-获得任务列表
    */
    ENDPOINT_INFO(quaryGettasklistController) {
        // 定义默认授权参数
        API_DEF_ADD_AUTH();
        // 获得接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("guanli.task.get"));
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(GettasklistControllerJsonVO);
        // 定义分页查询参数描述
        API_DEF_ADD_PAGE_PARAMS();
        //唯一标识
        API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("assignment.field.id"), "", false);
        //库内类型
        API_DEF_ADD_QUERY_PARAMS(String, "inventoryType", ZH_WORDS_GETTER("output.con.inventoryType"), "", false);
        // 数量
        API_DEF_ADD_QUERY_PARAMS(String, "goods_qua", ZH_WORDS_GETTER("output.con.goods_qua"), "", false);
        // 单位
        API_DEF_ADD_QUERY_PARAMS(String, "shl_dan_wei", ZH_WORDS_GETTER("output.con.shl_dan_wei"), "", false);
        // 基本单位数量
        API_DEF_ADD_QUERY_PARAMS(String, "base_goodscount", ZH_WORDS_GETTER("output.con.base_goodscount"), "", false);
        // 基本单位
        API_DEF_ADD_QUERY_PARAMS(String, "base_unit", ZH_WORDS_GETTER("output.con.base_unit"), "", false);
        // 储位
        API_DEF_ADD_QUERY_PARAMS(String, "bin", ZH_WORDS_GETTER("output.con.bin"), "", false);
        //托盘
        API_DEF_ADD_QUERY_PARAMS(String, "tin", ZH_WORDS_GETTER("output.con.tin"), "", false);
        // 货主
        API_DEF_ADD_QUERY_PARAMS(String, "cusCode", ZH_WORDS_GETTER("output.con.cusCode"), "", false);
        // 货主名称
        API_DEF_ADD_QUERY_PARAMS(String, "cusName", ZH_WORDS_GETTER("output.con.cusName"), "", false);
        //商品
        API_DEF_ADD_QUERY_PARAMS(String, "commodity", ZH_WORDS_GETTER("output.con.commodity"), "", false);
        //商品名称
        API_DEF_ADD_QUERY_PARAMS(String, "shp_ming_cheng", ZH_WORDS_GETTER("output.con.shp_ming_cheng"), "", false);
        //生产日期
        API_DEF_ADD_QUERY_PARAMS(String, "goods_pro_data", ZH_WORDS_GETTER("output.con.goods_pro_data"), "", false);
        //保质期
        API_DEF_ADD_QUERY_PARAMS(String, "bzhi_qi", ZH_WORDS_GETTER("output.con.bzhi_qi"), "", false);
        //到期日
        API_DEF_ADD_QUERY_PARAMS(String, "to_goods_pro_data", ZH_WORDS_GETTER("output.con.to_goods_pro_data"), "", false);
        //仓库
        API_DEF_ADD_QUERY_PARAMS(String, "bin_store", ZH_WORDS_GETTER("output.con.bin_store"), "", false);
    }
    //
    ENDPOINT(API_M_GET, "/kuneiguanli/lihuorenwu/get-task-list", quaryGettasklistController, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
        //解析查询参数
        API_HANDLER_QUERY_PARAM(pageQuery, GettasklistControllerQuery, queryParams);
        //响应处理结果
        API_HANDLER_RESP_VO(GettasklistControllerTest(pageQuery));



    }
private:
    GettasklistControllerJsonVO::Wrapper GettasklistControllerTest(const GettasklistControllerQuery::Wrapper& query);
};

#include OATPP_CODEGEN_END(ApiController) 