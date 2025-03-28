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
#ifndef _RECV_G_WAY_MAPPER_
#define _RECV_G_WAY_MAPPER_

#include "Mapper.h"
#include "../../domain/do/recv-g-way/Recv-G-WayFileDo.h"

/**
 * 示例表字段匹配映射
 */
class Recv_G_WayMapper : public Mapper<Recv_G_WayDO>
{
public:
	Recv_G_WayDO mapper(ResultSet* resultSet) const override
	{
		Recv_G_WayDO data;
		data.setId(resultSet->getString(1));
		data.setDel_mode_code(resultSet->getString(3));
		data.setDel_mode_name(resultSet->getString(2));
		return data;
	}
};

/**
 * 示例表字段匹配映射-创建智能指针对象
 */
class PtrRecv_G_WayMapper : public Mapper<PtrRecv_G_WayDO>
{
public:
	PtrRecv_G_WayDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<Recv_G_WayDO>();
		data->setId(resultSet->getString(1));
		data->setDel_mode_name(resultSet->getString(2));
		data->setDel_mode_code(resultSet->getString(3));
		return data;
	}
};
#endif