#include "stdafx.h"
#include "QualityService2.h"
#include "../../dao/qcd/QualityDAO2.h"
#include "domain/do/qcd/QualityDO2.h"
#include "domain/vo/qcd/QualityVO2.h"
#include "domain/query/qcd/QualityQuery2.h"
#include "domain/dto/qcd/QualityDTO2.h"
#include "Macros.h"
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <ctime>

//删除数据
int QualityService::removeData(const std::vector<std::int32_t>& ids) {
	if (ids.empty()) {
		OATPP_LOGE("GoodsStateService", "No IDs provided for batch deletion");
		return false;
	}

	QualityDAO dao;
	int deletedCount = dao.deleteByIds(ids);

	if (deletedCount > 0) {
		OATPP_LOGI("QualityService", "Success deleted %d records", deletedCount);
		return deletedCount;
	}
	else {
		OATPP_LOGE("QualityService", "Failed to delete any records");
		return 0;
	}
}

// 新增数据
bool QualityService::importData(const std::vector<std::vector<std::string>>& data, const PayloadDTO& payload) {
	// 检查数据是否为空
	if (data.empty()) {
		OATPP_LOGE("QualityService", "No data found in Excel file");
		return false;
	}

	// 遍历 Excel 数据
	for (size_t i = 1; i < data.size(); i++) { // 跳过表头
		const auto& row = data[i];

		// 校验数据格式
		if (row.size() < 11) { // 确保每行有 11 列数据
			OATPP_LOGE("QualityService", "Invalid data format in row %zu", i);
			continue;
		}

		// 将 Excel 数据转换为 DO 对象
		QualityDO doo;

		try {
			UuidFacade uid(1);

			doo.setId(uid.genUuid());
			doo.setCreate_name(payload.getUsername());
			doo.setCreate_by(payload.getId());
			doo.setCreate_date(row[3]);
			doo.setUpdate_name(payload.getUsername());
			doo.setUpdate_by(payload.getUsername());
			doo.setUpdate_date(row[6]);
			doo.setSys_org_code(payload.getOrgcode());
			doo.setSys_company_code(payload.getCompanycode());
			doo.setQm_qa_code(row[9]);
			doo.setQm_qa_name(row[10]); 
		}
		catch (const std::exception& e) {
			OATPP_LOGE("QualityService", "Failed to parse data in row %zu: %s", i, e.what());
			continue;
		}

		// 调用 DAO 层插入数据
		QualityDAO dao;
		if (dao.insert2(doo) == 0) {
			OATPP_LOGE("QualityService", "Failed to insert data in row %zu", i);
			return false;
		}
	}

	return true;
}

// 导出数据
std::list<QualityDTO::Wrapper> QualityService::QueryAll(const QualityQuery::Wrapper& query)
{
	QualityDAO dao;
	auto result = dao.QueryWithPage(query);

	// 检查查询结果是否为空
	if (result.empty()) {
		OATPP_LOGE("QualityService", "No data found in ba_qm_qa table");
		return {}; // 返回空列表
	}
	// 转换为DTO列表
	std::list<QualityDTO::Wrapper> dtoList;
	for (const auto& doo : result) {
		auto dto = QualityDTO::createShared();
		dto->id = doo.getId();
		dto->create_name = doo.getCreate_name();
		dto->create_by = doo.getCreate_by();
		dto->create_date = doo.getCreate_date();
		dto->update_name = doo.getUpdate_name();
		dto->update_by = doo.getUpdate_by();
		dto->update_date = doo.getUpdate_date();
		dto->sys_org_code = doo.getSys_org_code();
		dto->sys_company_code = doo.getSys_company_code();
		dto->qm_qa_code = doo.getQm_qa_code();
		dto->qm_qa_name = doo.getQm_qa_name();
		dtoList.push_back(dto); 
	}
	return dtoList;
}
