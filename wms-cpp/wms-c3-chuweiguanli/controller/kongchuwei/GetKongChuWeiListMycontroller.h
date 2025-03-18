#pragma once
#pragma once
#include"domain/vo/BaseJsonVO.h"
#include"domain/GlobalInclude.h" 
#include"domain/query/PageQuery.h"
#include "domain/query/kongchuwei/GetKongChuWeiListMycontrollerQuery.h"
#include "domain/dto/kongchuwei/GetKongChuWeiListMycontrollerDTO.h"
#include "domain/vo/kongchuwei/GetKongChuWeiListMycontrollervo.h"
#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class GetKongChuWeiListMycontroller : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(GetKongChuWeiListMycontroller);
public:
    /*
    * 空储位-获得空储位列表
    */
    ENDPOINT_INFO(quaryGetKongChuWeiListMycontroller) {
        // 定义默认授权参数
        API_DEF_ADD_AUTH();
        // 获得接口标题
        API_DEF_ADD_TITLE(ZH_WORDS_GETTER("kongchuwei.get"));
        // 定义响应参数格式
        API_DEF_ADD_RSP_JSON_WRAPPER(GetKongChuWeiListMycontrollerJsonVO);
        // 定义分页查询参数描述
        
        API_DEF_ADD_PAGE_PARAMS();
        //唯一标识
        API_DEF_ADD_QUERY_PARAMS(String, "id", ZH_WORDS_GETTER("kongchuwei.quary.id"), "", false);
        //仓库
        //API_DEF_ADD_QUERY_PARAMS(string, "bin_store", ZH_WORDS_GETTER("kongchuwei.quary.bin_store"), "", false);
        // 储位属性
        API_DEF_ADD_QUERY_PARAMS(String, "chuweishuxing", ZH_WORDS_GETTER("kongchuwei.quary.chuweishuxing"), "", false);
        // 产品属性
        API_DEF_ADD_QUERY_PARAMS(String, "chp_shu_xing", ZH_WORDS_GETTER("kongchuwei.quary.chp_shu_xing"), "", false);
        // 储位编码
        API_DEF_ADD_QUERY_PARAMS(String, "chuweibaima", ZH_WORDS_GETTER("kongchuwei.quary.chuweibianma"), "", false);
        // 所属客户
        API_DEF_ADD_QUERY_PARAMS(String, "suo_shu_ke_hu", ZH_WORDS_GETTER("kongchuwei.quary.suo_shu_ke_hu"), "", false);
        // 最大体积
        API_DEF_ADD_QUERY_PARAMS(String, "zui_da_ti_ji", ZH_WORDS_GETTER("kongchuwei.quary.zui_da_ti_ji"), "", false);
        // 上架次序
        API_DEF_ADD_QUERY_PARAMS(String, "shang_jia_ci_XU", ZH_WORDS_GETTER("kongchuwei.quary.shang_jia_ci_XU"), "", false);
        // 长度
        API_DEF_ADD_QUERY_PARAMS(String, "chang", ZH_WORDS_GETTER("kongchuwei.quary.chang"), "", false);
        // 宽度
        API_DEF_ADD_QUERY_PARAMS(String, "kuan", ZH_WORDS_GETTER("kongchuwei.quary.kuan"), "", false);
        // 高度
        API_DEF_ADD_QUERY_PARAMS(String, "gao", ZH_WORDS_GETTER("kongchuwei.quary.gao"), "", false);
        // 最大托盘
        API_DEF_ADD_QUERY_PARAMS(String, "zui_da_tuo_pan", ZH_WORDS_GETTER("kongchuwei.quary.zui_da_tuo_pan"), "", false);
        //是否停用
        API_DEF_ADD_QUERY_PARAMS(String, "zhuang_tai", ZH_WORDS_GETTER("kongchuwei.quary.zhuang_tai"), "", false);
        //库位类型
        API_DEF_ADD_QUERY_PARAMS(String, "ku_wei_lei_xing", ZH_WORDS_GETTER("kongchuwei.quary.ku_wei_lei_xing"), "", false);
    }
        //
        ENDPOINT(API_M_GET, "/chuweiguanli/kongchuwei/get-kongchuwei-list", quaryGetKongChuWeiListMycontroller, QUERIES(QueryParams, queryParams), API_HANDLER_AUTH_PARAME) {
            //解析查询参数
            API_HANDLER_QUERY_PARAM(pageQuery, GetKongChuWeiListMycontrollerQuery, queryParams);
            //响应处理结果
            API_HANDLER_RESP_VO(GetKongChuWeiListMycontrollerTest(pageQuery));

        }
private:
    GetKongChuWeiListMycontrollerJsonVO::Wrapper GetKongChuWeiListMycontrollerTest(const GetKongChuWeiListMycontrollerQuery::Wrapper & query);
 };

#include OATPP_CODEGEN_END(ApiController)
