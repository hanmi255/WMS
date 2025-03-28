#include "stdafx.h"
#include "CDMService.h"


bool CdmService::updateData(const CdmDTO::Wrapper& dto) {
	// 组装DO数据
	CdmDO data;
	ZO_STAR_DOMAIN_DTO_TO_DO(data, dto, Id, id, Cname, cname, Cdate, cdate, Uname, uname, Uby, uby, Udate, udate, Soc, soc, Scc, scc, Cdn, cdn, Cdd, cdd);
	// 执行数据修改
	CdmDAO dao;
	return dao.update(data) == 1;
}


bool CdmService::removeData(vector<string>& id) {
	// 执行数据删除
	CdmDAO dao;
	return dao.deleteById(id) == 1;
}


// 返回企业属性的查询结果，准备下一步导入到execl文档中
vector<std::vector<std::string>> CdmService::getdata() {
	CdmDAO dao;
	std::list<CdmDO> AttriList = dao.getAllattri();//查询获取数据
	vector<std::vector<std::string>> resault_data;
	stringstream ss;

	for (auto index : AttriList)
	{
		std::vector<std::string> row;
		vector<string> tmpList = { index.getId() ,index.getCname() ,index.getCby() ,index.getCdate(),
								   index.getUname(),index.getUby(),index.getUdate(),index.getSoc(),index.getScc(),index.getCdn(),index.getCdd() };
		for (auto count : tmpList) {
			ss.clear();
			ss << count;
			row.push_back(ss.str());
			ss.str("");
		}

		resault_data.push_back(row);
	}
	return resault_data;
}
