#include "stdafx.h"
#include "CangKuDingYiService.h"
#include "../../dao/cangkudingyi/CangkuDAO.h"
#include "../../../lib-common/include/ExcelComponent.h"
#include "../../../lib-common/include/FastDfsClient.h"
#include "../../../lib-common/include/NacosClient.h"
#include "../../../nacos-register/Macros.h"

//	获取仓库名称列表(无参)
oatpp::List<CangkuNameListDTO::Wrapper> CangKuDingYiService::getCangkuNameList() {
	//	构建返回对象
	auto result = oatpp::List<CangkuNameListDTO::Wrapper>::createShared();

	//	查询仓库名称列表
	CangkuDAO dao;
	list<StoreDO> sum = dao.getCangkuNameList();

	for (StoreDO item : sum) {
		auto dto = CangkuNameListDTO::createShared();

		ZO_STAR_DOMAIN_DO_TO_DTO(dto, item, id, Id, store_code, StoreCode, store_name, StoreName);

		result->emplace_back(dto);
	}

	return result;
}
//	通过仓库ID删除仓库(支持批量)
bool CangKuDingYiService::deleteCangkuById_List(oatpp::List<oatpp::String>& id_list) {
	//	构建返回对象
	bool flag = true;

	//	从id_list中取出单个id执行删除操作
	CangkuDAO dao;
	for (auto id : *id_list) {
		flag &= dao.deleteCangkuById(id);
	}


	return flag;	
}
//	通过仓库代码列表导出仓库信息,返回下载链接
string CangKuDingYiService::getpath_exportCangkuByCodeList(oatpp::List<oatpp::String>& code_list) {
	
	ExcelComponent excel;
	CangkuDAO dao;

	//	根据仓库ID读取所需数据
	std::vector<std::vector<std::string>> data;
	if (code_list->empty()) {
		data = dao.getAllExcelData();
	}
	else {
		data.push_back({ ZH_WORDS_GETTER("Cangku.info.store_code"), ZH_WORDS_GETTER("Cangku.info.store_name"), ZH_WORDS_GETTER("Cangku.info.store_text") });
		for (auto code : *code_list) {
			data.emplace_back(dao.getExcelData(code));
		}
	}

	//	将数据上传到文件服务器中
	auto buff = excel.writeVectorToBuff("sheet1", data);
	const char* tsData = reinterpret_cast<const char*>(buff.data());

#ifdef LINUX
	ZO_CREATE_DFS_CLIENT_URL(dfs_client, pre_url);
    std::string url = dfs_client.uploadFile(tsData, buff.size(), "xlsx");
	return pre_url + url;
#else
	ZO_CREATE_DFS_CLIENT_URL(dfs,pre_url);
	std::string res = dfs.uploadFile(tsData, buff.size(), "xlsx");
	return  pre_url + res;
#endif

	
}