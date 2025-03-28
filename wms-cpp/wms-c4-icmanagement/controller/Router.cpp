//#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/12/03 14:58:34

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

#include "../controller/removal-adjustment/RemovalAdjustController.h"
#include "../controller/addition-adjustment/AdditionAdjustController.h"
#include "inentorydifference/InventoryController.h"
#include "check/CheckController.h"
#include "../controller/goods-manage/GoodsDiffPostController.h"
#include "../controller/goods-manage/UpLoadAdjustController.h"
#include "../controller/review-stt/ReviewSttController.h"


#include "./adjulist-list/ListgoodsController.h"
#include "./overallInventory/OverallInventoryController.h"

#include "batch-modify-goods/DownGoodsController.h"
#include "moving-bin/MovingBinController.h"
#include "stt-on-move/SttOnMoveController.h"
#include "stt-task/SttTaskController.h"

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "ws/WSController.h"
#endif

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
#ifdef HTTP_SERVER_DEMO
	createSampleRouter();
#endif

	//#TIP :系统扩展路由定义，写在这个后面

	ROUTER_SIMPLE_BIND(RemovalController);
	ROUTER_SIMPLE_BIND(AdditionController);
	ROUTER_SIMPLE_BIND(InventoryController);
	ROUTER_SIMPLE_BIND(CheckController);
	ROUTER_SIMPLE_BIND(ListgoodsController);
	ROUTER_SIMPLE_BIND(OverallInventoryController);
	ROUTER_SIMPLE_BIND(UpLoadAdjustController);
	ROUTER_SIMPLE_BIND(GoodsDiffPostController);
	ROUTER_SIMPLE_BIND(DownGoodsController);
	ROUTER_SIMPLE_BIND(MovingBinController);
	ROUTER_SIMPLE_BIND(SttOnMoveController);
	ROUTER_SIMPLE_BIND(SttTaskController);
	ROUTER_SIMPLE_BIND(ReviewSttController);
}

#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// 绑定示例控制器
	ROUTER_SIMPLE_BIND(SampleController);
	// 绑定用户控制器
	ROUTER_SIMPLE_BIND(UserController);
	// 绑定文件控制器
	ROUTER_SIMPLE_BIND(FileController);
	
	// 绑定WebSocket控制器
	router->addController(WSContorller::createShared());
}
#endif
