#include "stdafx.h"
#include "GoodsStateService.h"
#include "../../dao/goodsstate/GoodsStateDAO.h"
#include "domain/do/GoodsStateControllerDO/GoodsStateControllerDO.h"
#include "domain/vo/goodsstate/GoodsStateVO.h"
#include "domain/query/goodsstate/GoodStateQuery.h"
#include "domain/dto/goodsstate/GoodStateDTO.h"
#include "Macros.h"
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
// 批量删除
bool GoodsStateService::removeDates(const std::vector<std::string>& ids) {
    if (ids.empty()) {
        OATPP_LOGE("GoodsStateService", "No IDs provided for batch deletion");
        return false;
    }

    GoodsStateDAO dao;
    int deletedCount = dao.deleteByIds(ids);

    if (deletedCount > 0) {
        OATPP_LOGI("GoodsStateService", "Successfully deleted %d records", deletedCount);
        return true;
    }
    else {
        OATPP_LOGE("GoodsStateService", "Failed to delete any records");
        return false;
    }
}
// 导入数据
bool GoodsStateService::importData(const std::vector<std::vector<std::string>>& data) {
    // 1. 检查数据是否为空
    if (data.empty()) {
        return false;
    }
    // 2. 遍历 Excel 数据
    for (size_t i = 1; i < data.size(); i++) { // 跳过表头
        const auto& row = data[i];
        // 3. 检查数据格式
        if (row.size() < 11) { // 确保每行有  11 列数据
            continue;
        }
        GoodsStateControllerDO doo;
        try {
            // 4. 将 Excel 数据转换为 DO 对象
            UuidFacade uid(1);
    
            doo.setId(uid.genUuid()); // ID
            doo.setCreate_name(row[1]); // 创建姓名
            doo.setCreate_by(row[2]); // 创建者
            doo.setCreate_date(row[3]); // 创建日期
            doo.setUpdate_name(row[4]); // 更新姓名
            doo.setUpdate_by(row[5]); // 更新者
            doo.setUpdate_date(row[6]); // 更新日期
            doo.setSys_org_code(row[7]); // 所属部门
            doo.setSys_company_code(row[8]); // 所属公司
            doo.setQm_sta_code(row[9]); // 品质代码
            doo.setQm_sta_name(row[10]); // 品质代码名称
        }
        catch (const std::exception& e) {
            OATPP_LOGE("goodsstates", "Failed to parse data in row %zu: %s", i, e.what());
            continue;
        }
        // 5. 调用 DAO 层插入数据
        GoodsStateDAO dao;
        uint64_t res = dao.insert(doo);
        if (res == 0) {
            OATPP_LOGE("GoodsStateService", "Failed to insert data in row %zu", i);
            return false; // 标记为失败
        }
    }
    return true; // 返回是否所有数据都插入成功
}
//查询数据表中所有的数据--->导出数据
std::list<GoodStateDTO::Wrapper> GoodsStateService::QueryAll(const GoodStateQuery::Wrapper& query)
{
	GoodsStateDAO dao;
	//确保能导出多条数据 list作为返回值
	auto result = dao.QueryWithPage(query);

	// 检查查询结果是否为空 ,  很重要***
	if (result.empty()) {
		OATPP_LOGE("GoodsStateService", "No data found in ba_qm_sta table");
		return {}; // 返回空列表
	}
	// 2. 将 DO 列表转换为 DTO 列表
	std::list<GoodStateDTO::Wrapper> dtoList;
	for (const auto& doo : result) {
		auto dto = GoodStateDTO::createShared();
		dto->id = doo.getId();
		dto->create_name = doo.getCreate_name();
		dto->create_by = doo.getCreate_by();
		dto->create_date = doo.getCreate_date();
		dto->update_name = doo.getUpdate_name();
		dto->update_by = doo.getUpdate_by();
		dto->update_date = doo.getUpdate_date();
		dto->sys_org_code = doo.getSys_org_code();
		dto->sys_company_code = doo.getSys_company_code();
		dto->qm_sta_code = doo.getQm_sta_code();
		dto->qm_sta_name = doo.getQm_sta_name();
		dtoList.push_back(dto); // 将 DTO 添加到列表中
	}
	return dtoList;
}