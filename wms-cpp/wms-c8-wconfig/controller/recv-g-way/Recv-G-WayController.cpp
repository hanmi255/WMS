/*
 Copyright Zero One Star. All rights reserved.

 @Author: 猫头大蒜
 @Date: 2025/03/10 16:09:12

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
#include "Recv-G-WayController.h"
#include "../../service/recv-g-way/Recv-G-WayService.h"
#include "../ApiDeclarativeServicesHelper.h"
//删除接货
Uint64JsonVO::Wrapper Recv_G_WayController::execDelRecv_G_Way(const String& id)
{
	auto jvo = Uint64JsonVO::createShared();
	Recv_G_WayService service;
	uint64_t Idd = service.removeData(id);
	if (Idd > 0) {
		jvo->success(UInt64(Idd));
	}
	else
	{
		jvo->fail(UInt64(Idd));
	}
	return jvo;
	// 定义返回数据对象
}
//修改接货
Uint64JsonVO::Wrapper Recv_G_WayController::execEditRecv_G_Way(const Recv_G_WayEditDto::Wrapper& dto)
{
	auto jvo = Uint64JsonVO::createShared();
	dto->del_mode_code.getValue({});
	dto->del_mode_name.getValue({});
	dto->id.getValue({});
	// 参数校验
	if (!dto->id)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	Recv_G_WayService service;
	uint64_t id = service.updateData(dto);
	// 执行数据修改
	if (id>0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	// 响应结果
	return jvo;
}
//增加接货Recv_G_Way
Uint64JsonVO::Wrapper Recv_G_WayController::execAddRecv_G_Way(const Recv_G_WayAddDto::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象

	auto jvo = Uint64JsonVO::createShared();
	dto->del_mode_code.getValue({});
	dto->del_mode_name.getValue({});
	
	string a = dto->del_mode_code;
	string b = dto->del_mode_name;
	// 参数校验
	// 非空校验
	if (!dto->del_mode_code || !dto->del_mode_name)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验
	if (dto->del_mode_code->empty() || dto->del_mode_name->empty())
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个Service
	Recv_G_WayService service;
	// 执行数据新增
	uint64_t id = service.saveData(dto, payload.getUsername(), payload.getRealname(), payload.getOrgcode(), payload.getCompanycode());
	if (id >0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}
//查询接货
Recv_G_WayAllJsonVO::Wrapper Recv_G_WayController::execAllRecv_G_Way(const Recv_G_WayQuery::Wrapper& query, const PayloadDTO& payload)
{
	// 定义一个Service
	Recv_G_WayService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = Recv_G_WayAllJsonVO::createShared();
	jvo->success(result);
	return jvo;

}

//导入
StringJsonVO::Wrapper Recv_G_WayController::execUploadRecv_G_Way(std::shared_ptr<IncomingRequest> request)
{
	return StringJsonVO::Wrapper();
	
}
//下载
std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>Recv_G_WayController::execDownloadRecv_G_WayFile(const String& filename)
{
	return std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse>();

}