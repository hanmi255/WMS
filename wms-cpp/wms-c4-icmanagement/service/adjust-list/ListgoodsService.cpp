#define _CRT_SECURE_NO_WARNINGS

/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei
 @Date: 2025/3/4 11:08

*/

#include "stdafx.h"
#include "../../dao/adjust-list/ListgoodsDAO.h"
#include "ListgoodsService.h"
#include "Macros.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"


//#define TEST_EXCEL_FN "./" + ZH_WORDS_GETTER("diff-post.excel.path.good-diff-post") + ".xlsx"
#define TEST_EXCEL_SN ZH_WORDS_GETTER("lis.excel.sheet.s1")


std::string ListGoodsService::exportData(const ExportDataQuery::Wrapper& query)
{
	ListGoodsDAO dao;
	list<Wm_To_Up_GoodsDO> result = dao.selectWithConditions(query);

	std::vector<Wm_To_Up_GoodsDO> datas(result.begin(), result.end());

	// 创建表头数据
	std::vector<std::string> headers = {
		ZH_WORDS_GETTER("lis.field.goodscode"),
		ZH_WORDS_GETTER("lis.field.goodsqua"),
		ZH_WORDS_GETTER("lis.field.orgbilltype"),
		ZH_WORDS_GETTER("lis.field.orgbillcode"),
		ZH_WORDS_GETTER("lis.field.orgbillrow"),
		ZH_WORDS_GETTER("lis.field.goodsupid"),
		ZH_WORDS_GETTER("lis.field.goodsunit"),
		ZH_WORDS_GETTER("lis.field.goodsbatch"),
		ZH_WORDS_GETTER("lis.field.goodscredata"),
		ZH_WORDS_GETTER("lis.field.acttypecode"),
		ZH_WORDS_GETTER("lis.field.kuweicode"),
		ZH_WORDS_GETTER("lis.field.tuobancode"),
		ZH_WORDS_GETTER("lis.field.huozhu"),
		ZH_WORDS_GETTER("lis.field.baseunit"),
		ZH_WORDS_GETTER("lis.field.basegoodscount"),
		ZH_WORDS_GETTER("lis.field.goodsname"),
	};
	std::vector<std::vector<std::string>> data;
	data.push_back(headers);

	for (int i = 0; i < datas.size(); ++i)
	{
		std::vector<std::string> row;

		row.push_back(datas[i].getGoodsId());
		row.push_back(datas[i].getGoodsQua());
		row.push_back(datas[i].getOrderTypeCode());
		row.push_back(datas[i].getOrderId());
		row.push_back(datas[i].getOrderIdI());
		row.push_back(datas[i].getWmToUpId());
		row.push_back(datas[i].getGoodsUnit());
		row.push_back(datas[i].getGoodsBatch());
		row.push_back(datas[i].getGoodsProData());//盘点单号
		row.push_back(datas[i].getActTypeCode());
		row.push_back(datas[i].getKuWeiBianMa());
		row.push_back(datas[i].getBinId());
		row.push_back(datas[i].getCusCode());
		row.push_back(datas[i].getBaseUnit());
		row.push_back(datas[i].getBaseGoodscount());
		row.push_back(datas[i].getGoodsName());
		data.push_back(row);
	}

	// 定义保存数据位置和页签名称
	// 注意：文件件名称和文件路径不能出现中文
	//std::string fileName = TEST_EXCEL_FN;
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要从配置文件中获取
	//std::string sheetName = TEST_EXCEL_SN;

	// 保存到文件
	ExcelComponent excel;
	//excel.writeVectorToFile("6666.xlsx", sheetName, data);
	auto buff = excel.writeVectorToBuff(TEST_EXCEL_SN, data);
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	FastDfsClient dfs("121.43.101.169");
	std::string upResult = dfs.uploadFile(tsData, buff.size(), "xlsx");
	if (upResult != "")
	{
		std::cout << "http://121.43.101.169:8888/" << upResult << std::endl;
		//下载
		std::string dir = "file";
		std::string fullPath = dfs.downloadFile(upResult, &dir);
		std::cout << fullPath << std::endl;
		return fullPath;
	}
	return "";
}
