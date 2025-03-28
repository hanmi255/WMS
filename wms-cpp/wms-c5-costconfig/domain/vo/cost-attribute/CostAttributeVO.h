#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: JOHAN LIN
 @Date: 2025/02/21 06:31:00

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

      https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, softwarebO
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
*/

#ifndef _COST_ATTRIBUTE_VO_
#define _COST_ATTRIBUTE_VO_
#include "../../wms-c5-costconfig/domain/dto/cost-attribute/CostAttributeDTO.h"
#include "../../wms-c5-costconfig/domain/GlobalInclude.h"


#include OATPP_CODEGEN_BEGIN(DTO)


/*
    删除客户计费属性
*/
class DeleteCostAttributeVO : public JsonVO<DeleteCostAttributeDTO::Wrapper> {
    DTO_INIT(DeleteCostAttributeVO, JsonVO<DeleteCostAttributeDTO::Wrapper>);
};

/*
    导入客户计费属性
*/
class ImportCostAttributeVO : public JsonVO<ImportCostAttributeDTO::Wrapper> {
	DTO_INIT(ImportCostAttributeVO, JsonVO<ImportCostAttributeDTO::Wrapper>);

};

/*
    导出客户计费属性
*/
class ExportCostAttributeVO : public JsonVO<ExportCostAttributeQuery::Wrapper> {
    DTO_INIT(ExportCostAttributeVO, JsonVO<ExportCostAttributeQuery::Wrapper>);

    // Excel文件名
    API_DTO_FIELD_DEFAULT(String, fileName, ZH_WORDS_GETTER("excel.name.export"));

    // Excel文件URL
    API_DTO_FIELD_DEFAULT(String, fileURL, ZH_WORDS_GETTER("excel.url.export"));
};

#include OATPP_CODEGEN_END(DTO)
#endif // !_COST_ATTRIBUTE_VO_