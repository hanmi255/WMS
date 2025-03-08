/*
 Copyright Zero One Star. All rights reserved.

 @Author: awei
 @Date: 2024/11/18 10:26:58

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
#include "pch.h"
#include "../include/id/UuidFacade.h"

void UuidFacade::init()
{
	this->random_gen = nullptr;
#ifdef UUID_SYSTEM_GENERATOR
	this->system_gen = nullptr;
#endif
	// 创建随机生成器
	if (type == 0)
	{
		std::random_device rd;
		auto seed_data = std::array<int, std::mt19937::state_size>{};
		std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
		std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
		std::mt19937 generator(seq);
		this->random_gen = new uuids::uuid_random_generator(generator);
	}
#ifdef UUID_SYSTEM_GENERATOR
	// 创建系统生成器
	else if (type == 1)
	{
		this->system_gen = new uuids::uuid_system_generator();
	}
#endif
}

UuidFacade::UuidFacade(int type)
{
	this->type = type;
	init();
}

UuidFacade::UuidFacade()
{
#ifdef LINUX
	this->type = 1;
#else
	this->type = 0;
#endif
	init();
}

UuidFacade::~UuidFacade()
{
	if (this->random_gen)
	{
		delete this->random_gen;
		this->random_gen = nullptr;
	}
#ifdef UUID_SYSTEM_GENERATOR
	if (this->system_gen)
	{
		delete this->system_gen;
		this->system_gen = nullptr;
	}
#endif
}

std::string UuidFacade::genUuid()
{
	// 创建UUID对象
	uuids::uuid id;
	if (this->type == 0)
		id = (*(this->random_gen))();
#ifdef UUID_SYSTEM_GENERATOR
	else if (this->type == 1)
		id = (*(this->system_gen))();
#endif
	else
		return {};

	// 判断UUID是否合法
	if (id.is_nil()
		|| id.as_bytes().size() != 16
		|| id.version() != uuids::uuid_version::random_number_based
		|| id.variant() != uuids::uuid_variant::rfc)
		return {};

	// 返回UUID对应的字符串
	return uuids::to_string(id);
}
