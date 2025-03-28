#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 猫头大蒜
 @Date: 2025/03/10 16:09:12

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

	  https://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.ations under the License.
*/
#ifndef _SAMPLE_DO_
#define _SAMPLE_DO_
#include "../DoInclude.h"

/**
 * 示例数据库实体类
 */
class Recv_G_WayDO
{
	CC_SYNTHESIZE(string, id, Id);
	// 接货id
	CC_SYNTHESIZE(string, del_mode_code, Del_mode_code);
	// 接货名称
	CC_SYNTHESIZE(string, del_mode_name, Del_mode_name);

public:
	Recv_G_WayDO() {
		id = "";
		del_mode_code = "";
		del_mode_name = "";
		
	}
};

// 给SampleDO智能指针设定一个别名方便使用
typedef std::shared_ptr<Recv_G_WayDO> PtrRecv_G_WayDO;
#endif // !_SAMPLE_DO_