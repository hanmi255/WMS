/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/03/12 9:13:11

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

#include "UploadFileService.h"
#include "dao/tradeclassifi/UploadFileDAO.h"
#include "domain/dto/tradeclassifi/UploadFileDTO.h"

// 将上传的行业分类保存到数据库
uint64_t UploadFileService::saveData(const UploadFileDTO::Wrapper& dto) {
	// 组装DO数据
	UploadFileDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, CreateName, creadename, CreateBy, createby, SysorgCode, sysorgcode, SysCompanyCode, syscompanycode, TypeCode, typecodes, TypeNames, typenames);
	UploadFileDAO dao;
	// 执行数据添加
	return dao.insert(data);
}
