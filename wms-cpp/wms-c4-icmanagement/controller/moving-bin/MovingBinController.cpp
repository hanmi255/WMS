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
#include "MovingBinController.h"
#include "../../service/moving-bin/MovingBinService.h"
#include "../ApiDeclarativeServicesHelper.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include <ExcelComponent.h>

MovingBinPageJsonVO::Wrapper MovingBinController::execQueryAll(const MovingBinQuery::Wrapper& query)
{
	// 定义一个Service
	MovingBinService service;
	// 查询数据
	auto result = service.listAll(query);
	// 响应结果
	auto jvo = MovingBinPageJsonVO::createShared();
	jvo->success(result);
	return jvo;
}

//导出动仓盘点报表
std::shared_ptr< oatpp::web::server::api::ApiController::OutgoingResponse> MovingBinController::execExportMovingBin(const MovingBinQuery::Wrapper& query)
{

	MovingBinService service;
	auto result = service.exportData(query);
	std::vector<MovingBinDO> datas(result.begin(), result.end());

	// 创建表头数据
	std::vector<std::string> headers = {
		ZH_WORDS_GETTER("bin.field.bin_id"),
		ZH_WORDS_GETTER("bin.field.tin_id"),
		ZH_WORDS_GETTER("bin.field.goods_id"),
		ZH_WORDS_GETTER("bin.field.goods_name"),
		ZH_WORDS_GETTER("bin.field.specification"),
		ZH_WORDS_GETTER("bin.field.goods_pro_date"),
		ZH_WORDS_GETTER("bin.field.goods_save_date"),
		ZH_WORDS_GETTER("bin.field.due_date"),
		ZH_WORDS_GETTER("bin.field.total_stock"),
		ZH_WORDS_GETTER("bin.field.last_pick_time"),
		ZH_WORDS_GETTER("bin.field.avail_stock"),
		ZH_WORDS_GETTER("bin.field.to_be_taken_down"),
		ZH_WORDS_GETTER("bin.field.goods_unit"),
	};
	std::vector<std::vector<std::string>> data;
	data.push_back(headers);

	for (int i = 0; i < datas.size(); ++i)
	{
		std::vector<std::string> row;

		row.push_back(datas[i].getBinId());
		row.push_back(datas[i].getTinId());
		row.push_back(datas[i].getGoodsId());
		row.push_back(datas[i].getGoodsName());
		row.push_back(datas[i].getGoodsSpecification());
		row.push_back(datas[i].getGoodsProDate());
		row.push_back(datas[i].getSaveDate());
		row.push_back(datas[i].getDueDate());
		row.push_back(datas[i].getTotalStock());//盘点单号
		row.push_back(datas[i].getLastPickTime());
		row.push_back(datas[i].getAvailStock());
		row.push_back(datas[i].getToBeTakenDown());
		row.push_back(datas[i].getGoodsUnit());
		data.push_back(row);
	}

	// 定义保存数据位置和页签名称
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要从配置文件中获取
	std::string sheetName = ZH_WORDS_GETTER("excel.sheet.s3");
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
	response->putHeader("Content-Disposition", "attachment; filename=MovingWarehouseInventory.xlsx");

	return response;
}

