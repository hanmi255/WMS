#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2022/10/25 0:27:04

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
#ifndef _SAMPLE_CONTROLLER_
#define _SAMPLE_CONTROLLER_

#include "domain/vo/BaseJsonVO.h"
#include "domain/query/costtype/costtypeQuery.h"
#include "domain/dto/costtype/costtypeDTO.h"
#include "domain/vo/costtype/costtypeVO.h"

// 0 定义API控制器使用宏
#include OATPP_CODEGEN_BEGIN(ApiController) //<- Begin Codegen

/**
 * 示例控制器，演示基础接口的使用
 */
class rmcosttypeController : public oatpp::web::server::api::ApiController {
    API_ACCESS_DECLARE(rmcosttypeController)
public:
    //删除费用类型
    //// 3.1 定义删除接口描述
    //ENDPOINT_INFO(remove) {
    //    // 定义标题和返回类型以及授权支持
    //    API_DEF_ADD_COMMON_AUTH("delete cost type", Uint64JsonVO::Wrapper);
    //    // 定义其他路径参数说明
    //    API_DEF_ADD_PATH_PARAMS(UInt64, "id", "id", 1, true);
    //}
    //// 3.2 定义删除接口处理
    //API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/sample/{id}", remove, PATH(UInt64, id), execRemovecosttype(id));
    //Uint64JsonVO::Wrapper execRemovecosttype(const UInt64& id);


   
// 3.1 定义删除接口描述
    ENDPOINT_INFO(remove) {
        // 定义标题和返回类型以及授权支持
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("costtype.delete"), StringJsonVO::Wrapper);
        // 定义其他路径参数说明，将 UInt64 改为 oatpp::String
        API_DEF_ADD_PATH_PARAMS(String, "id", "id", 1, true);
    }
    // 3.2 定义删除接口处理
    API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/rm/{id}", remove, PATH(String, id), execRemovecosttype(id));
    StringJsonVO::Wrapper execRemovecosttype(const String& id);




    ENDPOINT_INFO(remove_more) {
        // 定义标题和返回类型以及授权支持
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("costtype.mdelete"), StringJsonVO::Wrapper);
        // 定义其他路径参数说明，将 UInt64 改为 oatpp::String
        API_DEF_ADD_PATH_PARAMS(String, "ids", "Comma-separated list of ids", 1, true);
    }
    // 3.2 定义删除接口处理
    API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/rm_more/{ids}", remove_more, PATH(String, ids), execRemovecosttype_more(ids));
    StringJsonVO::Wrapper execRemovecosttype_more(const String& ids);
};

// 0 取消API控制器使用宏
#include OATPP_CODEGEN_END(ApiController) //<- End Codegen
#endif // _SAMPLE_CONTROLLER_

