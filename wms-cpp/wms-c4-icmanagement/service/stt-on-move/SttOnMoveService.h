#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: fangtang
 @Date: 2025/03/02 15:34:56

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

#ifndef _STT_ON_MOVE_SERVICE_
#define _STT_ON_MOVE_SERVICE_
#include <list>
#include "domain/vo/stt-on-move/SttOnMoveVO.h"
#include "domain/query/stt-on-move/SttOnMoveQuery.h"
#include "domain/dto/stt-on-move/SttOnMoveDTO.h"

/*
* 动碰盘服务实现
*/
class SttOnMoveService
{
public:
	// 分页查询数据
	SttOnMovePageDTO::Wrapper listAll(const SttOnMoveQuery::Wrapper& query);
	// 通过ID查询单个数据
	SttOnMoveDetailDTO::Wrapper getById(const string& id);
};

#endif