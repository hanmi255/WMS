#pragma once
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "../../Macros.h"
#include "domain/vo/BaseJsonVO.h"
#include "domain/GlobalInclude.h"
#include "../arch-demo/Macros.h"
#include "../../domain/dto/BusstyDTO.h"
#include "../lib-oatpp/include/domain/vo/BaseJsonVO.h"
#include "../lib-oatpp/include/oatpp/core/data/mapping/type/Vector.hpp"
#include "../lib-common/include/ExcelComponent.h"
#include OATPP_CODEGEN_BEGIN(ApiController) ///< Begin ApiController codegen section

class BusstyController : public oatpp::web::server::api::ApiController {
    
    API_ACCESS_DECLARE(BusstyController);
public:
    ENDPOINT_INFO(delone) {
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("tydel.name1"), Uint64JsonVO::Wrapper);
        API_DEF_ADD_PATH_PARAMS(UInt64, "id", ZH_WORDS_GETTER("tydel.id"), 1, true);     
    }
    API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/repository/bussty-del-one/{id}", delone, PATH(UInt64, id), execDelOne(id));

    ENDPOINT_INFO(delpart) {
        API_DEF_ADD_COMMON_AUTH(ZH_WORDS_GETTER("tydel.name2"), Vector<UInt64>);
        API_DEF_ADD_PATH_PARAMS(UInt64, "ID", ZH_WORDS_GETTER("tydel.id"),1,false);
    }
    API_HANDLER_ENDPOINT_AUTH(API_M_DEL, "/repository/bussty-del-part/id", delpart, BODY_DTO(Vector<UInt64>,id), execDelPart(id));

    API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("tylead.name1"), leadin, StringJsonVO::Wrapper);
    API_HANDLER_ENDPOINT(API_M_POST, "/repository/bussty-upload", leadin, REQUEST(std::shared_ptr<IncomingRequest>, request), execLeadIn(request));

    API_DEF_ENDPOINT_INFO(ZH_WORDS_GETTER("tylead.name2"), leadout, Void);
    ENDPOINT(API_M_GET, "/repository/bussty-download", leadout, QUERY(String, filename))
    {
        return execLeadOut(filename);
    }

private:
    Uint64JsonVO::Wrapper execDelOne(const UInt64& id);
    Uint64JsonVO::Wrapper execDelPart(Vector<UInt64> ID);
    StringJsonVO::Wrapper execLeadIn(std::shared_ptr<IncomingRequest> request);
    std::shared_ptr<OutgoingResponse> execLeadOut(String filename);
};

#include OATPP_CODEGEN_END(ApiController) ///< End ApiController codegen section