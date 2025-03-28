/*
 Copyright Zero One Star. All rights reserved.
 
 @Author: Ann
 @Date: 2025/2/23 17:47
 
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
#include "GoodsClassController.h"
#include "service/goods-class/GoodsClassService.h"


// 新增计费商品类接口处理
StringJsonVO::Wrapper GoodsClassController::execAddGoodsClass(const GoodsClassAddDTO::Wrapper& dto) {
	// 不需要参数验证
	// 直接传给service即可
	GoodsClassService service;

	// service执行插入,仍然使用DTO,返回操作的id 
	// 是否考虑只用返回是否操作成功 ?
	auto res = service.insert(dto);
	auto jvo = StringJsonVO::createShared();

	// 插入成功
	if (res != "") {
		jvo->success(res);
	}
	else {
		jvo->fail(res);
	}

	return jvo;

}



// 修改计费商品类接口处理
StringJsonVO::Wrapper GoodsClassController::execModifyGoodsClass(const GoodsClassModifyDTO::Wrapper& dto) {

	// 验证下id是否合法
	// 只要传入的id存在，我们就认为是合法的
	auto jvo = StringJsonVO::createShared();
	if (dto->id == "") {
		// 是否更新成功
		jvo->fail("");
	}
	else {
		GoodsClassService service;
		auto res = service.update(dto);
		if (res) {
			jvo->success(dto->id);
		}
		else {
			jvo->fail(dto->id);
		}
	}


	return jvo;

}



// 查询计费商品类名称接口处理
GoodsClassNameListPageJsonVO::Wrapper GoodsClassController::execQueryGoodClassName(const GoodClassQuery::Wrapper& query) {

	// 直接调用service
	GoodsClassService service;

	auto res = service.listName(query);

	// 报错 返回空
	auto jvo = GoodsClassNameListPageJsonVO::createShared();

	jvo->success(res);

	return jvo;

}



// 查询计费商品类(分页)接口处理
GoodsClassPageJsonVO::Wrapper GoodsClassController::execQueryGoodClassPage(const GoodClassQuery::Wrapper& query) {

	// 直接调用service
	GoodsClassService service;

	auto res = service.listAll(query);

	// 报错 返回空
	auto jvo = GoodsClassPageJsonVO::createShared();

	jvo->success(res);

	return jvo;

}




// 辅助方法：组装完整DTO
GoodsClassModifyDTO::Wrapper GoodsClassController::buildFullDTO(const GoodsClassBaseModifyDTO::Wrapper& baseDto, const PayloadDTO& payload) {
	auto fullDto = GoodsClassModifyDTO::createShared();

	// 复制基础字段
	fullDto->id = baseDto->id;
	fullDto->name = baseDto->name;
	fullDto->code = baseDto->code;


	// 填充Token中的信息
	//fullDto->create_name = payload.getUsername();
	//fullDto->create_by = payload.getUsername();
	fullDto->update_by = payload.getUsername();
	fullDto->sys_org_code = payload.getOrgcode();
	fullDto->sys_company_code = payload.getCompanycode();
	//fullDto->create_date = DateUtil::getCurrentTime();

	return fullDto;

}



GoodsClassAddDTO::Wrapper GoodsClassController::buildFullDTO(const GoodsClassBaseAddDTO::Wrapper& baseDto, const PayloadDTO& payload) {
	auto fullDto = GoodsClassAddDTO::createShared();

	// 复制基础字段
	fullDto->name = baseDto->name;
	fullDto->code = baseDto->code;


	// 填充Token中的信息
	//fullDto->create_name = payload.getUsername();
	fullDto->create_by = payload.getUsername();
	fullDto->update_by = payload.getUsername();
	fullDto->sys_org_code = payload.getOrgcode();
	fullDto->sys_company_code = payload.getCompanycode();
	//fullDto->sys_org_code = payload->getOrgCode();
	//fullDto->sys_company_code = payload->getCompanyCode();
	//fullDto->create_date = DateUtil::getCurrentTime();

	return fullDto;

}