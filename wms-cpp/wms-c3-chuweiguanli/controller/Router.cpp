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
#include "kongchuwei/DaoChuKongChuWeiController.h"
#include "cangweitu/HuoQuCangWeiShuJuController.h"


#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "ws/WSController.h"
#endif

#include "controller/cangkudingyi/StoreController.h"
#include "controller/keyongchuwei/BinController.h"
#include "tuopandingyi/TuopanController.h"
#include "cangkudingyi/CangKuDingYiController.h"
#include "tuopandingyi/TPController.h"
#include "controller/chuweidingyi/ChuWeiController.h"
#include "controller/chuweidingyi/ChuWeiDingYiController.h"
#include "kongchuwei/GetKongChuWeiListMycontroller.h"
#include "controller/chuweidingyi/chuweixaingxixinxidaorudaochuCONTROLLER.h"

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
	ROUTER_SIMPLE_BIND(ChuWeiDingYiController);
	ROUTER_SIMPLE_BIND(DaoChuKongChuWeiController);
	ROUTER_SIMPLE_BIND(HuoQuCangWeiShuJuController);	
	ROUTER_SIMPLE_BIND(CangKuDingYiController);
	ROUTER_SIMPLE_BIND(TuopanController);	
	ROUTER_SIMPLE_BIND(TPController);
	ROUTER_SIMPLE_BIND(StoreController);
	ROUTER_SIMPLE_BIND(BinController);
	ROUTER_SIMPLE_BIND(ChuWeiController);
	ROUTER_SIMPLE_BIND(GetKongChuWeiListMycontroller);
	ROUTER_SIMPLE_BIND(apixiangxixinxi);
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
