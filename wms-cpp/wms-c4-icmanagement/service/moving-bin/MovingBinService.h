#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: 圣少游
 @Date: 2025/2/22 11:36:29

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
#ifndef _MOVINGBIN_SERVICE_
#define _MOVINGBIN_SERVICE_
#include <list>
#include "domain/vo/moving-bin/MovingBinVO.h"
#include "domain/query/moving-bin/MovingBinQuery.h"
#include "domain/dto/moving-bin/MovingBinDTO.h"
#include <domain/do/moving-bin/MovingBinDO.h>

/**
 * 动态盘点服务实现
 */
class MovingBinService
{
public:
	// 分页查询所有数据
	MovingBinPageDTO::Wrapper listAll(const MovingBinQuery::Wrapper& query);

	//生成导出数据
	list<MovingBinDO> exportData(const MovingBinQuery::Wrapper& query);
};

#endif // !_MOVINGBIN_SERVICE_
