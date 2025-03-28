#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/03/12 11:22:32

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
#ifndef _UPLOADFILEDO_
#define _UPLOADFILEDO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class UploadFileDO
{
	//行业分类ID
	CC_SYNTHESIZE(string, id, ID);
	// 企业分类编码
	CC_SYNTHESIZE(string, typecodes, TypeCode);
	// 行业分类名称
	CC_SYNTHESIZE(string, typenames, TypeNames);
	// 创建人
	CC_SYNTHESIZE(string, createname, CreateName);
	// 创建人登录名
	CC_SYNTHESIZE(string, createby, CreateBy);
	// 创建时间
	CC_SYNTHESIZE(string, createdate, CreateDate);
	// 所属部门
	CC_SYNTHESIZE(string, sysorgcode, SysorgCode);
	// 所属公司
	CC_SYNTHESIZE(string, syscompanycode, SysCompanyCode);
public:
	UploadFileDO() {
		id = "";
		typecodes = "";
		typenames = "";
		createname = "";
		createby = "admin";
		createdate = "";
		sysorgcode = "A05";
		syscompanycode = "A05";
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<UploadFileDO> PtrUploadFileDO;
#endif // !_SAMPLE_DO_
