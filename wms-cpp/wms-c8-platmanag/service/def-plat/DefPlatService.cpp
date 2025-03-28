/*
 Copyright Zero One Star. All rights reserved.

 @Author: mao
 @Date: 2025/2/27 16:22:11

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
#include "DefPlatService.h"
#include "../../dao/def-plat/DefPlatDAO.h"
#include "../lib-common/include/ExcelComponent.h"
#include "../lib-common/include/FastDfsClient.h"
#include <chrono>
#include <ctime>
#include "../lib-common/include/NacosClient.h"
#include "../lib-common/include/gtest/gtest.h"
#include "../../Macros.h"
#include "../../ServerInfo.h"

// 获取当前时间并转化为可传入SQL语句的形式
std::string getCurrentTime() {
	auto now = std::chrono::system_clock::now();
	std::time_t now_time = std::chrono::system_clock::to_time_t(now);

	// 转换为本地时间
	std::tm* local_time = std::localtime(&now_time);

	// 创建一个字符串流
	std::stringstream ss;

	// 格式化时间
	ss << std::put_time(local_time, "%Y-%m-%d %H:%M:%S");

	return ss.str();
}

bool DefPlatService::DefDelData(const string id)
{
	DefPlatDAO dao;
	return dao.deleteById(id) == 1;
}
bool DefPlatService::DefEditData(const DefEditDto::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	PlatDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, PlatformCode, platform_code, PlatformName, platform_name);
	data.setupdate_name(payload.getUsername());
	data.setupdate_by(payload.getRealname());
	data.setupdate_date(getCurrentTime());
	// 执行数据修改
	DefPlatDAO dao;
	return dao.update(dto->id, data) == 1;
}
std::string DefPlatService::DefPutData(const PayloadDTO& payload) {
	DefPlatDAO dao;
	std::list<PlatDO> table = dao.queryAll();
	//xlnt::workbook wb;
	//xlnt::worksheet ws = wb.active_sheet();
	//ws.merge_cells("A1:B1");
	//ws.merge_cells("A2:B2");
	//std::list<PlatDO>::iterator it; int i = 0;
	//for (i = 0,it = table.begin(); it != table.end(); it++, i++) {
	//	ws.cell("A" + std::to_string(2 + i)).value(it->getid());
	//	ws.cell("B" + std::to_string(2 + i)).value(it->getname());
	//}
	std::vector<std::vector<std::string>> data;
	std::string info = "def.put.description";
	//	std::string info = ZH_WORDS_GETTER("excel.content.info");
	std::stringstream ss;
	std::list<PlatDO>::iterator it = table.begin();
	for (int i = 0; i < 3; i++) {
		data.push_back(std::vector<std::string>());
	}
	data[0].push_back(ZH_WORDS_GETTER("def.put.data"));
	data[1].push_back(ZH_WORDS_GETTER("def.put.putter") + payload.getRealname());
	data[2].push_back(ZH_WORDS_GETTER("def.put.name")), data[2].push_back(ZH_WORDS_GETTER("def.put.code"));
	for (; it != table.end(); it++) {
		std::vector<std::string> row;
		row.push_back(it->getplatform_name()), row.push_back(it->getplatform_code());
		data.push_back(row);
	}
	xlnt::workbook wb;
	xlnt::worksheet ws = wb.active_sheet();
	ws.title("testtable");
	ws.merge_cells("A1:B1");
	ws.merge_cells("A2:B2");
	int i = 0;
	ws.cell("A" + std::to_string(1)).value(ZH_WORDS_GETTER("def.put.data"));
	ws.cell("A" + std::to_string(2)).value(ZH_WORDS_GETTER("def.put.putter") + ":" + payload.getRealname());
	ws.cell("A" + std::to_string(3)).value(ZH_WORDS_GETTER("def.put.name"));
	ws.cell("B" + std::to_string(3)).value(ZH_WORDS_GETTER("def.put.code"));
	for (i = 0, it = table.begin(); it != table.end(); it++, i++) {
		ws.cell("A" + std::to_string(4 + i)).value(it->getplatform_name());
		ws.cell("B" + std::to_string(4 + i)).value(it->getplatform_code());
	}

	std::stringstream buffer;
	wb.save(buffer);

	// 数据上传到文件服务器
	cout << ServerInfo::getInstance().getDbHost() << endl;
#ifdef LINUX
	NacosClient ns(ServerInfo::getInstance().getNacosAddr(), ServerInfo::getInstance().getNacosNs());
	// 从Nacos配置中心获取FastDFS客户端配置数据
	std::string config = ns.getConfigText("client.conf");
	// 定义客户端对象
	FastDfsClient dfs(config,false);
#else
	FastDfsClient dfs(ServerInfo::getInstance().getDbHost(), 22122);
#endif
	std::string result = dfs.uploadFile(buffer.str().c_str(), buffer.str().size(), "xlsx");

	if (result != "") {
		cout << OPT_USERNAME << endl;
		return "http://"+ServerInfo::getInstance().getDbHost()+":8888/" + result;
	}
	return "";
}
//std::string DefPutData(const PayloadDTO& payload) {
//    DefPlatDAO dao;
//    std::list<PlatDO> table = dao.queryAll();
//    std::vector<std::vector<std::string>> data;
//    std::string info = "def.put.description";
//    std::stringstream ss;
//    int i = 1;
//    std::list<PlatDO>::iterator it = table.begin();
//    for (int i = 0; i < 3; i++) {
//        data.push_back(std::vector<std::string>());
//    }
//    data[0].push_back(ZH_WORDS_GETTER("def.put.data"));
//    data[1].push_back(ZH_WORDS_GETTER("def.put.putter") + payload.getRealName());
//    data[2].push_back(ZH_WORDS_GETTER("def.put.name")), data[2].push_back(ZH_WORDS_GETTER("def.put.code"));
//    for (; it != table.end(); it++) {
//        std::vector<std::string> row;
//        row.push_back(it->getplatform_name()), row.push_back(it->getplatform_code());
//        data.push_back(row);
//    }
//
//    xlnt::workbook wb;
//    xlnt::worksheet ws = wb.active_sheet();
//    ws.title("Test Table");
//
//    // 合并单元格
//    ws.merge_cells("A1:B1");
//    ws.merge_cells("A2:B2");
//
//    // 填充数据
//    int row = 3; // 从第三行开始填充数据
//    for (const auto& row_data : data) {
//        for (size_t col = 0; col < row_data.size(); ++col) {
//            ws.cell(xlnt::cell_reference(++row, col + 1)).value(row_data[col]);
//        }
//    }
//
//    // 将 Excel 数据写入缓冲区
//    std::stringstream buffer;
//    wb.save(buffer);
//
//    // 数据上传到文件服务器
//    FastDfsClient dfs("192.168.10.138");
//    std::string result = dfs.uploadFile(buffer.str().c_str(), buffer.str().size(), "xlsx");
//    if (result != "") {
//        std::cout << OPT_USERNAME << std::endl;
//        return "<url id=\"cv4r44e97i0op7920840\" type=\"url\" status=\"failed\" title=\"\" wc=\"0\">http://192.168.10.138:8888/</url>" + result;
//    }
//    return "";
//}
