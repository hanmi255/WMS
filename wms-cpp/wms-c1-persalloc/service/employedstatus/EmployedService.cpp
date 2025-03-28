#include "stdafx.h"
#include "EmployedService.h"
#include "ExcelComponent.h"
#include "../../dao/employedstatus/EmployedStatusDAO.h"


bool EmployedService::removeData(const EmployedStatusRemoveDTO::Wrapper& dto)
{
	// 组装DO数据
	EmployedStatusDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Code, code/*, Name, name, Id, id*/);
	// 执行数据修改
	EmployedStatusDAO dao;
	return dao.deleteById(data) == 1;
}

bool EmployedService::exportAllData(string localpath)
{
	EmployedStatusDAO dao;
	vector<vector<string>> xdata(0, vector<string>(2));

	// 表格第一行列名：在职状态代码、在职状态名称
	xdata.push_back({ ZH_WORDS_GETTER("employed.field.code"), ZH_WORDS_GETTER("employed.field.code") });
	bool success =  dao.exportAllData(xdata);
	if (!success) return false;

	ExcelComponent excel;

	// 将vector中的数据写入到.xlsx文件中
	excel.writeVectorToFile(localpath + "ba_pos_sta.xlsx", ZH_WORDS_GETTER("excel.sheet.s1"), xdata);// excel.sheet.s1:页签

	return true;
}

bool EmployedService::importAllData(const vector<vector<string>>& ptr_data, const PayloadDTO& payload)
{
	EmployedStatusDAO dao;
	return dao.importAllData(ptr_data, payload);
}

