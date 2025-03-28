#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: mao
 @Date: 2025/2/27 15:37:04

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
#ifndef _DEFPLAT_SERVICE_
#define _DEFPLAT_SERVICE_
#include <list>
#include "../../domain/dto/def-file/DefPlatDto.h"
#include "../../domain/query/def-file/DefPlatQuery.h"
#include "../../domain/vo/def-file/DefPlatVo.h"
#include "domain/vo/BaseJsonVO.h"
#include "./Macros.h"
#include "../../../lib-oatpp/include/ApiHelper.h"
#include "../../domain/GlobalInclude.h"
/**
 * 月台定义-删除月台服务实现
 */
class DefPlatService
{
public:
	// 通过ID删除数据
	bool DefDelData(const string id);
	// 修改数据
	bool DefEditData(const DefEditDto::Wrapper& dto, const PayloadDTO& payload);
	//导出表格
	std::string DefPutData(const PayloadDTO& payload);

};

#endif // !_DEFPLAT_SERVICE_

