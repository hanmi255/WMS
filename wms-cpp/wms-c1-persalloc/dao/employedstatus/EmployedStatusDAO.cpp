#include "stdafx.h"
#include "EmployedStatusDAO.h"

int EmployedStatusDAO::deleteById(const EmployedStatusDO& id)
{
	auto str = id.getCode();
	string sql = "DELETE FROM `ba_pos_sta` WHERE `pos_sta_code`='" + str + "'";
	return sqlSession->executeUpdate(sql);
}

bool EmployedStatusDAO::exportAllData(vector<vector<string>>& xdata)
{
	try {
		int index = 0;
		auto conn = sqlSession->getConnection();
		if (conn == nullptr)return false;
		// 准备查询语句
		std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement("SELECT * FROM ba_pos_sta"));

		// 执行查询
		std::unique_ptr<sql::ResultSet> res(pstmt->executeQuery());
		// 遍历结果集
		while (res->next()) {
			vector<string> temp(2);
			temp[0] = res->getString("pos_sta_code").c_str();
			temp[1] = res->getString("pos_sta_name");
			xdata.push_back(temp);
		}
	}
	catch (sql::SQLException& ex) {
		cerr << ex.what() << endl;
		return false;
	}
	return true;
}

bool EmployedStatusDAO::importAllData(const vector<vector<string>>& xdata, const PayloadDTO& payload)
{
	// 固定字段
	string create_name = payload.getUsername();
	string create_by = payload.getId();
	string sys_org_code = payload.getOrgcode();
	string sys_company_code = payload.getCompanycode();

	string sql = "INSERT INTO `ba_pos_sta` \
	(`id`, `create_name`, `create_by`, `create_date`, `sys_org_code`, `sys_company_code`, `pos_sta_code`, `pos_sta_name`)\
	VALUE (?, ?, ?, NOW(), ?, ?, ?, ?)";

	try {
		// 获取连接
		auto conn = sqlSession->getConnection();
		if (conn == nullptr)return false;

		// 从Excel表的第二行开始遍历，第一行为表头
		for (int i = 1; i < xdata.size(); i++) {	
			UuidFacade uuidObj;			// 生成uuid
			string uid = uuidObj.genUuid();
			uid.erase(std::remove(uid.begin(), uid.end(), '-'), uid.end());
			string pos_sta_code = xdata[i][0];
			string pos_sta_name = xdata[i][1];
			// 准备查询语句
			std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(sql));
			pstmt->setString(1, uid);
			pstmt->setString(2, create_name);
			pstmt->setString(3, create_by);
			pstmt->setString(4, sys_org_code);
			pstmt->setString(5, sys_company_code);
			pstmt->setString(6, pos_sta_code);
			pstmt->setString(7, pos_sta_name);
			// 执行查询
			pstmt->executeUpdate();
		}
	}
	catch (sql::SQLException& ex) {
		cerr << ex.what() << endl;
		return false;
	}
	return true;
}
