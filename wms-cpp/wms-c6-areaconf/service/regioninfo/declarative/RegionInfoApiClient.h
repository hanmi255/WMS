//#pragma once
///*
// @Author: 002
// @Date: 2025.3.4
//*/
//#ifndef _REGION_INFO_APICLIENT_H_
//#define _REGION_INFO_APICLIENT_H_
//
//#include "oatpp/web/client/ApiClient.hpp"
//#include "ApiHelper.h"
//
///**
// * 定义声明式服务
// */
//class RegionInfoApiClient : public oatpp::web::client::ApiClient
//{
//	// 定义ApiClient控制器使用宏---开始
//#include OATPP_CODEGEN_BEGIN(ApiClient)
//
//	// 初始化定义
//	API_CLIENT_INIT(RegionInfoApiClient);
//
//	// 使用API_CALL或API_CALL_ASYNC声明调用服务接口
//
//	// 通过ID查询
//	API_CALL(API_M_GET, "/regioninfo/namelist", queryRegionByName, QUERY(String, area_name));
//
//#include OATPP_CODEGEN_END(ApiClient)
//	// 取消ApiClient控制器使用宏---结束
//};
//
//#endif