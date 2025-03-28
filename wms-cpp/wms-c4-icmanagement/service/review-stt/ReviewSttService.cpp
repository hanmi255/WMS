/*
 Copyright Zero One Star. All rights reserved.

 @Author: qingbingwei
 @Date: 2025/2/26 11:08

*/

#include "stdafx.h"
#include "ReviewSttService.h"
#include "../../dao/review-stt/ReviewSttDAO.h"
#include "Macros.h"
#include "ExcelComponent.h"
#include "FastDfsClient.h"


#define TEST_EXCEL_FN "./" + ZH_WORDS_GETTER("review-stt.excel.path.good-diff-post") + ".xlsx"
#define TEST_EXCEL_SN ZH_WORDS_GETTER("review-stt.excel.sheet.s1")

// 条件分页查询所有数据
ReviewSttPageDTO::Wrapper ReviewSttService::listAll(const ReviewSttQuery::Wrapper& query)
{
	auto pages = ReviewSttPageDTO::createShared();
	pages->pageIndex = query->pageIndex;
	pages->pageSize = query->pageSize;

	// 查询数据总条数
	
	ReviewSttDAO dao;
	uint64_t count = dao.count(query);
	if (count <= 0)
	{
		return pages;
	}

	// 分页查询数据
	pages->total = count;
	pages->calcPages();
	list<Wm_Stt_In_GoodsDO> result = dao.selectWithPage(query);
	// 将DO转换成DTO
	for (Wm_Stt_In_GoodsDO sub : result)
	{
		auto dto = ReviewSttDTO::createShared();
		ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub, id, Id, create_name, CreateName, create_by, CreateBy, create_date, CreateDate, update_name, UpdateName, update_by, UpdateBy, update_date, UpdateDate, sys_org_code, SysOrgCode, sys_company_code, SysCompanyCode, bin_id, BinId, tin_id, TinId, goods_id, GoodsId, goods_name, GoodsName, goods_qua, GoodsQua, goods_unit, GoodsUnit, goods_pro_date, GoodsProDate, goods_batch, GoodsBatch, stt_qua, SttQua, cus_name, CusName, cus_code, CusCode, stt_sta, SttSta, base_unit, BaseUnit, base_goodscount, BaseGoodscount, stt_id, SttId, goods_code, GoodsCode, stt_type, SttType, dong_xian, DongXian);
		pages->addData(dto);
	}
	return pages;
}

//差异过账
bool ReviewSttService::updateData(const ReviewSttDTO::Wrapper& dto, const PayloadDTO& payload)
{
	// 组装DO数据
	Wm_Stt_In_GoodsDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data,dto,Id,id,CreateName,create_name,CreateBy,create_by,CreateDate,create_date,GoodsId,goods_id,GoodsName,goods_name,GoodsQua,goods_qua,GoodsUnit,goods_unit,GoodsProDate,goods_pro_date,GoodsBatch,goods_batch,SttQua,stt_qua,CusName,cus_name,CusCode,cus_code,SttSta,stt_sta,BaseUnit,base_unit,BaseGoodscount,base_goodscount,SttId,stt_id,GoodsCode,goods_code,SttType,stt_type,DongXian,dong_xian,UpdateName, update_name, UpdateBy, update_by, UpdateDate, update_date, SysOrgCode, sys_org_code, SysCompanyCode, sys_company_code, BinId, bin_id, TinId, tin_id);
	// 执行数据修改
	ReviewSttDAO dao;
	return dao.update(data,payload) == 1;
}

std::string ReviewSttService::exportData(const ReviewSttQuery::Wrapper& query)
{
	ReviewSttDAO dao;
	list<Wm_Stt_In_GoodsDO> result = dao.selectWithConditions(query);

	std::vector<Wm_Stt_In_GoodsDO> datas(result.begin(), result.end());

	// 创建表头数据
	std::vector<std::string> headers = {
		ZH_WORDS_GETTER("review-stt.excel.headers.create_name"),
		ZH_WORDS_GETTER("review-stt.excel.headers.create_by"),
		ZH_WORDS_GETTER("review-stt.excel.headers.create_date"),
		ZH_WORDS_GETTER("review-stt.excel.headers.update_name"),
		ZH_WORDS_GETTER("review-stt.excel.headers.update_by"),
		ZH_WORDS_GETTER("review-stt.excel.headers.update_date"),
		ZH_WORDS_GETTER("review-stt.excel.headers.sys_org_code"),
		ZH_WORDS_GETTER("review-stt.excel.headers.sys_company_code"),
		ZH_WORDS_GETTER("review-stt.excel.headers.stt_id"),
		ZH_WORDS_GETTER("review-stt.excel.headers.bin_id"),
		ZH_WORDS_GETTER("review-stt.excel.headers.dong_xian"),
		ZH_WORDS_GETTER("review-stt.excel.headers.tin_id"),
		ZH_WORDS_GETTER("review-stt.excel.headers.goods_id"),
		ZH_WORDS_GETTER("review-stt.excel.headers.goods_name"),
		ZH_WORDS_GETTER("review-stt.excel.headers.goods_qua"),
		ZH_WORDS_GETTER("review-stt.excel.headers.goods_unit"),
		ZH_WORDS_GETTER("review-stt.excel.headers.goods_pro_date"),
		ZH_WORDS_GETTER("review-stt.excel.headers.goods_batch"),
		ZH_WORDS_GETTER("review-stt.excel.headers.stt_qua"),
		ZH_WORDS_GETTER("review-stt.excel.headers.cus_name"),
		ZH_WORDS_GETTER("review-stt.excel.headers.cus_code"),
		ZH_WORDS_GETTER("review-stt.excel.headers.stt_sta"),
		ZH_WORDS_GETTER("review-stt.excel.headers.stt_type"),
		ZH_WORDS_GETTER("review-stt.excel.headers.base_unit"),
		ZH_WORDS_GETTER("review-stt.excel.headers.base_goodscount"),
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
		row.push_back(datas[i].getCreateDate());//盘点单号
		row.push_back(datas[i].getBinId());
		row.push_back(datas[i].getDongXian());
		row.push_back(datas[i].getTinId());
		row.push_back(datas[i].getGoodsId());
		row.push_back(datas[i].getGoodsName());
		row.push_back(datas[i].getGoodsQua());
		row.push_back(datas[i].getGoodsUnit());
		row.push_back(datas[i].getGoodsProDate());
		row.push_back(datas[i].getGoodsBatch());
		row.push_back(datas[i].getSttQua());
		row.push_back(datas[i].getCusName());
		row.push_back(datas[i].getCusCode());
		row.push_back(datas[i].getSttSta());
		row.push_back(datas[i].getSttType());
		row.push_back(datas[i].getBaseUnit());
		row.push_back(datas[i].getBaseGoodscount());
		data.push_back(row);
	}

	// 定义保存数据位置和页签名称
	// 注意：文件件名称和文件路径不能出现中文
	std::string fileName = TEST_EXCEL_FN;
	// 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要从配置文件中获取
	std::string sheetName = TEST_EXCEL_SN;

	// 保存到文件
	ExcelComponent excel;
	//excel.writeVectorToFile("6666.xlsx", sheetName, data);
	auto buff = excel.writeVectorToBuff(TEST_EXCEL_SN, data);
	const char* tsData = reinterpret_cast<const char*>(buff.data());
	FastDfsClient dfs("121.43.101.169");
	std::string upResult = dfs.uploadFile(tsData,buff.size(),"xlsx");
	if (upResult != "")
	{
		std::cout << "http://121.43.101.169:8888/" << upResult << std::endl;
		//下载
		std::string dir = "file";
		std::string fullPath = dfs.downloadFile(upResult,&dir);
		std::cout << fullPath << std::endl;
		return fullPath;
	}
	return "";
}

// 通过条件分页查询数据
/*GoodsDiffPostListDTO::Wrapper GoodsManageService::getByCondition(const GoodsDiffPostQuery::Wrapper& query)
{
	return {};
}*/