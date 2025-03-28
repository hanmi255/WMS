/*
 @Author: nanbowan
*/
#ifndef _Deg_CONTROLLER_
#define _Deg_CONTROLLER_

#include "domain/GlobalInclude.h"
#include"domain/vo/BaseJsonVO.h"
#include "domain/dto/library/LibraryDTO.h" 

#include OATPP_CODEGEN_BEGIN(ApiController)


class LibraryController : public oatpp::web::server::api::ApiController
{
    API_ACCESS_DECLARE(LibraryController);

public:
     //定义修改接口描述
    API_DEF_ENDPOINT_INFO_AUTH(ZH_WORDS_GETTER("dictionary.libraryope.modify.summary"), modifyLibrary, Uint64JsonVO::Wrapper);
    // 定义修改接口处理
    API_HANDLER_ENDPOINT_AUTH(API_M_PUT, "/repository/library/modify", modifyLibrary, BODY_DTO(ModifyLibraryDTO::Wrapper, dto), execModifyLibrary(dto));

    // 3.1 定义删除接口描述
    ENDPOINT_INFO(deleteLibrary) {
        // 定义标题和返回类型以及授权支持
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("dictionary.libraryope.delete.summary"), Uint64JsonVO::Wrapper);
        // 定义其他路径参数说明
        API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("dictionary.libraryope.delete.summary"), 1, true);
    }
    // 3.2 定义删除接口处理
    API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/repository/library/{id}", deleteLibrary, PATH(oatpp::String, id), execDeleteLibrary(id));


private:
    Uint64JsonVO::Wrapper execModifyLibrary(const ModifyLibraryDTO::Wrapper& dto);

    Uint64JsonVO::Wrapper execDeleteLibrary(const oatpp::String& id);
};

#include OATPP_CODEGEN_END(ApiController)

#endif // _ORDERTYPES_CONTROLLER_