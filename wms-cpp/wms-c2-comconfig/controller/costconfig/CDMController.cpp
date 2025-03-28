#include"stdafx.h"
#include"CDMController.h"
#include"domain/dto/CDMattr/CDMDTO.h"


/*
inline void init(const CDMDTO::Wrapper& correct, const CDMDTO::Wrapper& wrong) {
	correct->id = "1";
	correct->cname = "1";
	correct->cby = "1";
	correct->cdate = "1";
	correct->uname = "1";
	correct->uby = "1";
	correct->udate = "1";
	correct->soc = "1";
	correct->scc = "1";
	correct->cdn = "1";
	correct->cdd = "1";

	wrong->id = "";
	wrong->cname = "";
	wrong->cby = "";
	wrong->cdate = "";
	wrong->uname = "";
	wrong->uby = "";
	wrong->udate = "";
	wrong->soc = "";
	wrong->scc = "";
	wrong->cdn = "";
	wrong->cdd = "";

}


CDMVO::Wrapper CDMController::execModify(const CDMDTO::Wrapper& dto )
{
	

		auto jvo = StringJsonVO::createShared();

		auto correct = CDMAddInfoDTO::createShared();
		auto wrong = CDMAddInfoDTO::createShared();

       init(correct, wrong);

	   // 参数校验
	   if (!dto->id)
	   {
 	   jvo->fail(String{ "fail" });
		   return jvo;
	   }
	   // 定义一个Service
	   CDMService service;
	   // 执行数据修改
	   if (service.updateData(dto)) {
   jvo->success(String{ "sucess" });
	   }
	   else
	 {
	   jvo->fail(String{ "fail" });
	   }
	   // 响应结果
	   return jvo;
}

*/

StringJsonVO::Wrapper CDMController::execModify(const CdmDTO::Wrapper& dto)
{
	auto jvo = StringJsonVO::createShared();


	CdmService service;
	if (service.updateData(dto)) {
		jvo->success("success");
	}
	else
	{
		jvo->fail( "fail" );
	}
	return jvo;

}