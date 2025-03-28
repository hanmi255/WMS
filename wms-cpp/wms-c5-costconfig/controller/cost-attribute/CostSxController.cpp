 /*
  Copyright Zero One Star. All rights reserved.

  @Author: wrzljrj
 @Date: 2025/02/22 18:33:26

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
 #include "CostSxController.h"
 #include "service/cost-attribute/CostAttributeService.h"


 // 辅助方法
 CostSxModifyDTO::Wrapper CostSxController::buildFullDTO(const CostSxBaseModifyDTO::Wrapper& baseDto, const PayloadDTO& payload) {
 	auto fullDto = CostSxModifyDTO::createShared();

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

 CostSxAddDTO::Wrapper CostSxController::buildFullDTO(const CostSxBaseAddDTO::Wrapper& baseDto, const PayloadDTO& payload) {
 	auto fullDto = CostSxAddDTO::createShared();

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


 // 新增用户属性接口处理
 StringJsonVO::Wrapper CostSxController::execAddCostSx(const CostSxAddDTO::Wrapper& dto) {

 	// 不需要参数验证
 	// 直接传给service即可
 	CostAttributeService service;

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
 // 修改用户属性接口处理
 StringJsonVO::Wrapper CostSxController::execModifyCostSx(const CostSxModifyDTO::Wrapper& dto) {

 	// 验证下id是否合法
 	// 理论上来讲只要传入的id存在，我们就认为是合法的
 	auto jvo = StringJsonVO::createShared();
 	if (dto->id == "") {
 		// 是否更新成功
 		jvo->fail("");
 	}
 	else {
 		CostAttributeService service;
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
 // 查询用户属性名称接口处理
 CostSxNameListPageJsonVO::Wrapper CostSxController::execQuerySxName(const CostSxQuery::Wrapper& query) {

 	// 直接调用service
 	CostAttributeService service;

 	auto res = service.listName(query);

 	// 拿到的应该是个列表 ?
 	// 怎么考虑报错 ? 就直接返回空呗
 	auto jvo = CostSxNameListPageJsonVO::createShared();

 	jvo->success(res);

 	return jvo;
 }
 // 查询用户属性(分页)接口处理 和前面的名称查询基本一致
 CostSxPageJsonVO::Wrapper CostSxController::execQuerySxPage(const CostSxQuery::Wrapper& query) {

 	// 直接调用service
 	CostAttributeService service;

 	auto res = service.listAll(query);

 	// 拿到的应该是个列表 ?
 	// 怎么考虑报错 ? 就直接返回空呗
 	auto jvo = CostSxPageJsonVO::createShared();

 	jvo->success(res);

 	return jvo;
 }