/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: epiphany
 @Date: 2025/2/27 10:24
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/
#include "stdafx.h"
#include "Router.h"
#include "ApiHelper.h"
#include "costmethod/MethodController.h"
#include "controller/cost-way/CostWayController.h"
#include "goods-class/GoodsClassController.h"
#include "controller/cost-attribute/CostAttributeController.h"
#include "controller/cost-attribute/CostSxController.h"

//#include "cost-goods/CostGoodsController.h"

// 如果定义了关闭Swagger文档宏
#ifdef CLOSE_SWAGGER_DOC
// 简化绑定控制器宏定义
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// 简化绑定控制器宏定义
#define ROUTER_SIMPLE_BIND(__CLASS__) \
BIND_CONTROLLER(docEndpoints, router, __CLASS__)
#endif

Router::Router(Endpoints* docEndpoints, HttpRouter* router)
{
	this->docEndpoints = docEndpoints;
	this->router = router;
}

void Router::initRouter()
{
	//#TIP :系统扩展路由定义，写在这个后面
	ROUTER_SIMPLE_BIND(MethodController);
	//ROUTER_SIMPLE_BIND(CostGoodsController);
	ROUTER_SIMPLE_BIND(GoodsClassController);
	ROUTER_SIMPLE_BIND(CostAttributeController);
	ROUTER_SIMPLE_BIND(CostSxController);
	ROUTER_SIMPLE_BIND(DeleteController);
	ROUTER_SIMPLE_BIND(DownloadExcelController);
	ROUTER_SIMPLE_BIND(UploadExcelController);

}