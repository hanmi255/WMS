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
#include "DownGoodsController.h"
#include "../../service/batch-modify-goods/DownGoodsService.h"
#include "../ApiDeclarativeServicesHelper.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include <ExcelComponent.h>

// 3.2 定义修改接口处理
StringJsonVO::Wrapper DownGoodsController::execModifyGoods(const DownGoodsBatchDTO::Wrapper& dto, const PayloadDTO& payload)
{
	String resultfail = String("fail");
	String resultsuccess = String("success");
	// 定义返回数据对象
	auto jvo = StringJsonVO::createShared();
	// 参数校验
	if (!dto || !dto->dtoList || dto->dtoList->empty()) {
		jvo->fail(resultfail);
		return jvo;
	}
	// 定义一个Service
	DownGoodsService service;
	// 执行数据修改

	if (service.updateData(dto, payload)) {
		jvo->success(resultsuccess);	
	}
	else
	{
		jvo->fail(resultfail);
	}
	return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> DownGoodsController::execExportGoods(const DownGoodsQuery::Wrapper& query)
{

	DownGoodsService service;
	auto result = service.exportData(query);
	std::vector<DownGoodsDO> datas(result.begin(), result.end());

	// 创建表头数据
	std::vector<std::string> headers = {
		ZH_WORDS_GETTER("goods.field.create_name"),
		ZH_WORDS_GETTER("goods.field.create_by"),
		ZH_WORDS_GETTER("goods.field.create_date"),
		ZH_WORDS_GETTER("goods.field.update_name"),
		ZH_WORDS_GETTER("goods.field.update_by"),
		ZH_WORDS_GETTER("goods.field.update_date"),
		ZH_WORDS_GETTER("goods.field.sys_org_code"),
		ZH_WORDS_GETTER("goods.field.sys_company_code"),
		ZH_WORDS_GETTER("goods.field.stt_id"),
		ZH_WORDS_GETTER("goods.field.bin_id"),
		ZH_WORDS_GETTER("goods.field.dong_xian"),
		ZH_WORDS_GETTER("goods.field.tin_id"),
		ZH_WORDS_GETTER("goods.field.goods_id"),
		ZH_WORDS_GETTER("goods.field.goods_name"),
		ZH_WORDS_GETTER("goods.field.goods_qua"),
		ZH_WORDS_GETTER("goods.field.goods_unit"),
		ZH_WORDS_GETTER("goods.field.goods_pro_date"),
		ZH_WORDS_GETTER("goods.field.goods_batch"),
		ZH_WORDS_GETTER("goods.field.stt_qua"),
		ZH_WORDS_GETTER("goods.field.cus_name"),
		ZH_WORDS_GETTER("goods.field.cus_code"),
		ZH_WORDS_GETTER("goods.field.stt_sta"),
		ZH_WORDS_GETTER("goods.field.stt_type"),
		ZH_WORDS_GETTER("goods.field.base_unit"),
		ZH_WORDS_GETTER("goods.field.base_goodscount"),
	};
	std::vector<std::vector<std::string>> data;
	data.push_back(headers);

	for (int i = 0; i < datas.size(); ++i)
	{
		std::vector<std::string> row;

		row.push_back(datas[i].getCreateName());
		row.push_back(datas[i].getCreateBy());
		row.push_back(datas[i].getCreateDate());
		row.push_back(datas[i].getUpdateName());
		row.push_back(datas[i].getUpdateBy());
		row.push_back(datas[i].getUpdateDate());
		row.push_back(datas[i].getSysOrgCode());
		row.push_back(datas[i].getSysCompanyCode());
		row.push_back(datas[i].getGoodsId());
		row.push_back(datas[i].getGoodsQua());
		row.push_back(datas[i].getGoodsQuaok());
		row.push_back(datas[i].getOrderId());
		row.push_back(datas[i].getOrderIdi());
		row.push_back(datas[i].getGoodsUnit());
		row.push_back(datas[i].getGoodsProDate());
		row.push_back(datas[i].getGoodsBatch());
		row.push_back(datas[i].getActTypeCode());
		row.push_back(datas[i].getBinIdTo());
		row.push_back(datas[i].getBinIdFrom());
		row.push_back(datas[i].getCus());
		row.push_back(datas[i].getDownSta());
		row.push_back(datas[i].getBaseUnit());
		row.push_back(datas[i].getBaseGoodscount());
		data.push_back(row);
	}

	// 定义保存数据位置和页签名称
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要从配置文件中获取
	std::string sheetName = ZH_WORDS_GETTER("excel.sheet.s1");
	//文件名
	std::string filename = ZH_WORDS_GETTER("bin.download.excelname") + ".xlsx";


	// 保存到文件
	ExcelComponent excel;
	auto buff = excel.writeVectorToBuff(sheetName, data);
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	auto fstring = String(tsData, buff.size());

	// 判断是否读取成功
	if (!fstring)
	{
		std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
		return createResponse(Status::CODE_404, "File Not Found");
	}

	// 创建响应头
	auto response = createResponse(Status::CODE_200, fstring);

	// 设置响应头信息
	response->putHeader("Content-Disposition", "attachment; filename=OffRackAdjustment.xlsx");

	return response;
}