/*

 @Author: c7 group

*/
#include "stdafx.h"
#include "Router.h"
#include "ApiHelper.h"
#include "buss-type/BusstyController.h"

#ifdef HTTP_SERVER_DEMO
#include "user/UserController.h"
#include "sample/SampleController.h"
#include "file/FileController.h"
#include "ws/WSController.h"
#endif



#include"oper_step/OperStepController.h"
#include"temperature/TemperatureController.h"
#include"business-link/BusinessLinkController.h"
#include "act_type/ActTypeController.h"
#include"ba_act_type/BaActTypeController.h"

#include "busstype/BussTypeController.h"
#include"../controller/ordertypes/OrderTypesController.h"
#include"../controller/file/FileController.h"
#include"../controller/libraryfile/LibraryFileController.h"
#include"../controller/library/LibraryController.h"


#include "order_type/OrderTypeController.h"

// ��������˹ر�Swagger�ĵ���
#ifdef CLOSE_SWAGGER_DOC
// �򻯰󶨿������궨��
#define ROUTER_SIMPLE_BIND(__CLASS__) \
router->addController(__CLASS__::createShared())
#else
// �򻯰󶨿������궨��
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
	ROUTER_SIMPLE_BIND(OperStepController);
	ROUTER_SIMPLE_BIND(TemperatureController);
	ROUTER_SIMPLE_BIND(BusinessLinkController);
	ROUTER_SIMPLE_BIND(ActTypeController);
	ROUTER_SIMPLE_BIND(BaActTypeController);
	ROUTER_SIMPLE_BIND(OrderTypesController);
	ROUTER_SIMPLE_BIND(FileController);
	ROUTER_SIMPLE_BIND(BussTypeController);
	ROUTER_SIMPLE_BIND(BusstyController);
	ROUTER_SIMPLE_BIND(OrderTypeController);
	ROUTER_SIMPLE_BIND(LibraryController);
	ROUTER_SIMPLE_BIND(LibraryFileController);


}
#ifdef HTTP_SERVER_DEMO
void Router::createSampleRouter()
{
	// ��ʾ��������
	ROUTER_SIMPLE_BIND(SampleController);
	// ���û�������
	ROUTER_SIMPLE_BIND(UserController);
	// ���ļ�������
	ROUTER_SIMPLE_BIND(FileController);

	// ��WebSocket������
	router->addController(WSContorller::createShared());
}
#endif
