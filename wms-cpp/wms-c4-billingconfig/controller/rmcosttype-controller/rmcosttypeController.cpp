
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 10:58:42

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
#include "rmcosttypeController.h"
#include "../../service/costtype/costtypeService.h"
#include "../ApiDeclarativeServicesHelper.h"



//Uint64JsonVO::Wrapper rmcosttypeController::execRemovecosttype(const UInt64& id)
//{
//	// 定义返回数据对象
//	auto jvo = Uint64JsonVO::createShared();
//	// 参数校验
//	if (!id || id <= 0)
//	{
//		jvo->init(UInt64(-1), RS_PARAMS_INVALID);
//		return jvo;
//	}
//	// 定义一个Service
//	costtypeService service;
//	// 执行数据删除
//	if (service.removeData(id.getValue(0))) {
//		jvo->success(id);
//	}
//	else
//	{
//		jvo->fail(id);
//	}
//	// 响应结果
//	return jvo;
//	
//}

StringJsonVO::Wrapper rmcosttypeController::execRemovecosttype(const String& id)
{
    // 定义返回数据对象
    auto jvo = StringJsonVO::createShared();
    // 参数校验，检查字符串是否为空
    if (id->empty())
    {
        jvo->init(String(), RS_PARAMS_INVALID);
        return jvo;
    }
    // 定义一个Service
    costtypeService service;
    // 执行数据删除
    if (service.removeData(id.getValue(""))) {
        jvo->success(id);
    }
    else
    {
        jvo->fail(id);
    }
    // 响应结果
    return jvo;
}



StringJsonVO::Wrapper rmcosttypeController::execRemovecosttype_more(const String& ids)
{
    // 定义返回数据对象
    auto jvo = StringJsonVO::createShared();
    // 参数校验，检查字符串是否为空
    if (ids->empty())
    {
        jvo->init(String(), RS_PARAMS_INVALID);
        return jvo;
    }

    // 拆分 ids 字符串
    std::vector<std::string> idList;
    std::stringstream ss(URIUtil::urlDecode(ids.getValue("")));
    std::string id;
    while (std::getline(ss, id, ',')) {
        idList.push_back(id);
    }

    // 定义一个 Service
    costtypeService service;
    // 执行数据批量删除
    if (service.removeData_more(idList)) {
        jvo->success(ids);
    }
    else
    {
        jvo->fail(ids);
    }
    // 响应结果
    return jvo;
}