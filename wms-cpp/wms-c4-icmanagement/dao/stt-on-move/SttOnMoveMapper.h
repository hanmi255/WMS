#pragma once
/*
 Copyright Zero One Star. All rights reserved.

 @Author: fangtang
 @Date: 2025/03/02 16:24:55

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

#ifndef _STT_ON_MOVE_MAPPER_
#define _STT_ON_MOVE_MAPPER_

#include "Mapper.h"
#include "../../domain/do/stt-on-move/SttOnMoceDO.h"

/*
* ∂Ø≈ˆ≈Ã ”Õº◊÷∂Œ∆•≈‰”≥…‰
*/

class SttOnMoveMapper : public Mapper<SttOnMoveDO>
{
public:
	SttOnMoveDO mapper(ResultSet* resultSet) const override
	{
		SttOnMoveDO data;
		data.setLastMove(resultSet->getString(1));
		data.setKuctype(resultSet->getString(2));
		data.setKuWeiBianMa(resultSet->getString(3));
		data.setBinId(resultSet->getString(4));
		data.setCusCode(resultSet->getString(5));
		data.setZhongWenQch(resultSet->getString(6));
		data.setGoodsId(resultSet->getString(7));
		data.setGoodsQua(resultSet->getString(8));
		data.setShpMingCheng(resultSet->getString(9));
		data.setGoodsProData(resultSet->getString(10));
		data.setBzhiQi(resultSet->getString(11));
		data.setGoodsUnit(resultSet->getString(12));
		data.setSttSta(resultSet->getString(13));
		data.setId(resultSet->getString(14));
		return data;
	}
};

/**
 * ∂Ø≈ˆ≈Ã ”Õº◊÷∂Œ∆•≈‰”≥…‰-¥¥Ω®÷«ƒ‹÷∏’Î∂‘œÛ
 */
class PtrSttOnMoveMapper : public Mapper<PtrSttOnMoveDO>
{
public:
	PtrSttOnMoveDO mapper(ResultSet* resultSet) const override
	{
		auto data = std::make_shared<SttOnMoveDO>();
		data->setLastMove(resultSet->getString(1));
		data->setKuctype(resultSet->getString(2));
		data->setKuWeiBianMa(resultSet->getString(3));
		data->setBinId(resultSet->getString(4));
		data->setCusCode(resultSet->getString(5));
		data->setZhongWenQch(resultSet->getString(6));
		data->setGoodsId(resultSet->getString(7));
		data->setGoodsQua(resultSet->getString(8));
		data->setShpMingCheng(resultSet->getString(9));
		data->setGoodsProData(resultSet->getString(10));
		data->setBzhiQi(resultSet->getString(11));
		data->setGoodsUnit(resultSet->getString(12));
		data->setSttSta(resultSet->getString(13));
		data->setId(resultSet->getString(14));
		return data;
	}
};

#endif