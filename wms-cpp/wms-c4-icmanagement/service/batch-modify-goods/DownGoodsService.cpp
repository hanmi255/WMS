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

#include "stdafx.h"
#include "DownGoodsService.h"
#include "dao/batch-modify-goods/DownGoodsDAO.h"

bool DownGoodsService::updateData(const DownGoodsBatchDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	std::vector<bool> flags;
	flags.reserve(dto->dtoList->size()); // 预分配空间
	for (const auto& sub : *dto->dtoList)
	{
		if (!sub) continue; // 避免空数据
		DownGoodsModifyDO data;
		ZO_STAR_DOMAIN_DTO_TO_DO(data, sub, Id, id, GoodsQua, goods_qua, GoodsQuaok, goods_quaok, GoodsProDate, goods_pro_date, BaseUnit, base_unit, BinIdFrom, bin_id_from, KuWeiBianMa,ku_wei_bian_ma);
		// 执行数据修改
		DownGoodsDAO dao;
		flags.push_back(dao.update(data, payload));
	}
	return std::all_of(flags.begin(), flags.end(), [](bool success) { return success; });
}

list<DownGoodsDO> DownGoodsService::exportData(const DownGoodsQuery::Wrapper& query)
{
	DownGoodsDAO dao;

	list<DownGoodsDO> result = dao.selectWithConditions(query);

	return result;

}
