/*
 @Author: S4turday
 @Date: 2025年3月8日16:15:26

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
#include "QualityController.h"
#include "../../service/quality/QualityService.h"
#include "../ApiDeclarativeServicesHelper.h"




Uint64JsonVO::Wrapper QualityController::execUpdate(const QualityListDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	if (!dto->id || !dto->qm_qa_name || !dto->qm_qa_code)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 定义一个Service
	QualityService service;
	// 执行数据修改
	uint64_t id = service.updateData(dto, payload);
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	// 响应结果
	return jvo;
}

Uint64JsonVO::Wrapper QualityController::execAdd(const QualityAddDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 定义返回数据对象
	auto jvo = Uint64JsonVO::createShared();
	// 参数校验
	// 非空校验
	if (!dto->qm_qa_name || !dto->qm_qa_code)
	{
		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验

	// 定义一个Service
	QualityService service;
	// 执行数据新增
	uint64_t id = service.InsertData(dto, payload);
	// 执行数据修改
	if (id > 0) {
		jvo->success(UInt64(id));
	}
	else
	{
		jvo->fail(UInt64(id));
	}
	//响应结果
	return jvo;
}

QualityPageJsonVO::Wrapper QualityController::execquery(const QualityQuery::Wrapper& query)
{
	// 定义一个Service
	QualityService service;
	// 查询数据
	auto result = service.getData(query);
	// 响应结果
	auto jvo = QualityPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

QualityJsonVO::Wrapper QualityController::execQueryByCode(const String& code)
{
	// 定义返回数据对象
	auto jvo = QualityJsonVO::createShared();

	// 参数校验
	// 非空校验
	if (code == "")
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验


	// 定义一个Service
	QualityService service;
	// 执行数据查询
	auto res = service.getByCode(code);
	jvo->success(res);

	//响应结果
	return jvo;
}

QualityJsonVO::Wrapper QualityController::execQueryByName(const String& name)
{
	// 定义返回数据对象
	auto jvo = QualityJsonVO::createShared();

	// 参数校验
	// 非空校验
	if (name == "")
	{
		jvo->init(nullptr, RS_PARAMS_INVALID);
		return jvo;
	}
	// 有效值校验


	// 定义一个Service
	QualityService service;
	// 执行数据查询
	auto res = service.getByName(name);
	jvo->success(res);

	//响应结果
	return jvo;
}



