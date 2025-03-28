/*
 Copyright Zero One Star. All rights reserved.

<<<<<<< HEAD
 @Author: zhaori
 @Date: 2025/3/8 13:33:36

=======
 @Author: awei
 @Date: 2022/12/03 14:58:34
>>>>>>> remotes/origin/c2-killerqueen

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

#include "tradeclassifi/UploadFileController.h"
#include "companyattribute/ComNameListController.h"
#include "comconfig/ComdegController.h"
#include "cominfo/ComInfoController.h"
#include "company-conf/CompanyController.h"
#include "file/InfoFileController.h"
#include "companyattributes/AttriInfoController.h"
#include "companyattr/CompanyattrController.h"
#include "enterprise-status-file/StatusFileController.h"
#include "enterpriseController/enterprise-level/getLevelNameController.h"
#include "modify-industry-class/ModifyController.h"
#include "delete-industry-class/DeleteController.h"
#include "export-industry-class/ExportController.h"
#include "comconfig/EnterpriseStatusController.h"
#include "controller/costconfig/CostConfigController.h"
#include "costconfig/GoodsDiffPostController.h"
#include "controller/costconfig/CDMController.h"
#include "./companystate/CompanyStateController.h"
#include "cominfo/ComInfoController.h"
#include "companyinfo/CompanyInfoController.h"
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

	ROUTER_SIMPLE_BIND(ComdegController);
	ROUTER_SIMPLE_BIND(ComInfoController);
	ROUTER_SIMPLE_BIND(CompanyController);
	ROUTER_SIMPLE_BIND(InfoFileController);
	ROUTER_SIMPLE_BIND(UploadFileController);
	ROUTER_SIMPLE_BIND(ComNameListController);
	ROUTER_SIMPLE_BIND(ModifyController);
	ROUTER_SIMPLE_BIND(DeleteController);
	ROUTER_SIMPLE_BIND(ExportController);
	ROUTER_SIMPLE_BIND(AttriController);
	ROUTER_SIMPLE_BIND(CompanyattrController);
	ROUTER_SIMPLE_BIND(StatusFileController);
	ROUTER_SIMPLE_BIND(LevelNameController);
	ROUTER_SIMPLE_BIND(CompanyStateController);
	ROUTER_SIMPLE_BIND(EnterpriseController);
	ROUTER_SIMPLE_BIND(enterpriseController);
	ROUTER_SIMPLE_BIND(CostConfigController);
	ROUTER_SIMPLE_BIND(CDMController);
	ROUTER_SIMPLE_BIND(GoodsDiffPostController);
	ROUTER_SIMPLE_BIND(CompanyController);	
	ROUTER_SIMPLE_BIND(ComInfoController);
	ROUTER_SIMPLE_BIND(CompanyInfoController);
	
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
