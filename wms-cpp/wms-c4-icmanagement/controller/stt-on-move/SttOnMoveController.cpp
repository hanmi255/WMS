/*
 Copyright Zero One Star. All rights reserved.

 @Author: fangtang
 @Date: 2025/03/03 10:58:42

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
#include "SttOnMoveController.h"
#include "../../service/stt-on-move/SttOnMoveService.h"
#include "../../service/stt-task/SttTaskService.h"

SttOnMovePageJsonVO::Wrapper SttOnMoveController::execQueryAll(const SttOnMoveQuery::Wrapper& query)
{
	// 定义业务逻辑层service
	SttOnMoveService service;
	// 查询数据
	auto result = service.listAll(query);
	// 将得到的数据转化为jsonVO格式的响应结果
	auto jvo = SttOnMovePageJsonVO::Wrapper::createShared();
	// 构建成功消息
	jvo->success(result);
	// 返回响应
	return jvo;
}

// 根据id查询动碰盘数据项
SttOnMoveDetailJsonVO::Wrapper SttOnMoveController::execQueryOne(const String& id)
{
	//定义返回数据对象
	auto jvo = SttOnMoveDetailJsonVO::createShared();
	// 定义一个Service
	SttOnMoveService service;
	// 执行数据查询service层返回DTO对象
	auto res = service.getById(id);
	// 构建消息
	if (res)
		jvo->success(res);
	else
		jvo->fail(res);
	return jvo;
}

// 生成盘点任务，返回id
//StringJsonVO::Wrapper SttOnMoveController::execInsertSttTask(const String& id, const PayloadDTO& payload)
//{
//	//定义返回数据对象
//	auto jvo = StringJsonVO::createShared();
//	// 定义一个Service
//	SttOnMoveService sttOnMoveService;
//	auto sttOnMoveListDTO = sttOnMoveService.getById(id);
//	if (!sttOnMoveListDTO)
//	{
//		// 查询不到，返回失败
//		jvo->fail(id);
//	}
//
//	SttTaskService sttTaskService;
//	auto res = sttTaskService.insert(sttOnMoveListDTO,payload);
//
//	jvo->success(id);
//
//	return jvo;
//}

SttOnMoveInsertTaskJsonVO::Wrapper SttOnMoveController::execInsertSttTaskMulti(const SttOnMoveInsertTaskDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义用来返回的id数组DTO
	auto returnDto = SttOnMoveInsertTaskDTO::createShared();
	returnDto->ids = Vector<String>::createShared();
	// 定义返回数据对象
	auto jvo = SttOnMoveInsertTaskJsonVO::createShared();

	// 参数校验
	if (!dto->ids || dto->ids->empty())
	{
		jvo->init(nullptr,RS_PARAMS_INVALID);
		return jvo;
	}

	// 定义一个servie
	SttTaskService sttTaskservice;
	SttOnMoveService sttOnMoveService;
	// 删除操作
	for (int i = 0 ; i < dto->ids->size();i++)
	{
		// 获取动碰盘列表数据
		auto sttOnMoveListDTO = sttOnMoveService.getById(dto->ids->at(i));

		// 将数据插入盘点任务列表
		auto res = sttTaskservice.insert(sttOnMoveListDTO,payload);

		returnDto->ids->push_back(dto->ids->at(i));
	}
	jvo->success(returnDto);
	return jvo;
}