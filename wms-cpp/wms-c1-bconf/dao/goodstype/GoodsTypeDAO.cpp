#include "stdafx.h"
#include "GoodsTypeDAO.h"
#include "GoodsTypeMapper.h"

uint64_t GoodsTypeDAO::insert(const GoodsTypeDO& iObj, const PayloadDTO& payload)
{
	// 固定字段
	string create_name = payload.getUsername();
	string create_by = payload.getId();
	string sys_org_code = payload.getOrgcode();
	string sys_company_code = payload.getCompanycode();

	string sql = "INSERT INTO `ba_goods_type` \
(`id`, `create_name`, `create_by`, `create_date`, `sys_org_code`, `sys_company_code`, `goods_type_code`, `goods_type_name`)\
VALUE (?, ?, ?, NOW(), ?, ?, ?, ?)";

	try {
		// 获取连接
		auto conn = sqlSession->getConnection();
		if (conn == nullptr)return false;

		UuidFacade uuidObj;			// 生成uuid
		string uid = uuidObj.genUuid();
		uid.erase(std::remove(uid.begin(), uid.end(), '-'), uid.end());		// 删除连接符'-'

		// 准备查询语句
		std::unique_ptr<sql::PreparedStatement> pstmt(conn->prepareStatement(sql));
		pstmt->setString(1, uid);
		pstmt->setString(2, create_name);
		pstmt->setString(3, create_by);
		pstmt->setString(4, sys_org_code);
		pstmt->setString(5, sys_company_code);
		pstmt->setString(6, iObj.getCode());
		pstmt->setString(7, iObj.getName());
		// 执行插入数据
		pstmt->executeUpdate();

	}
	catch (sql::SQLException& ex) {
		cerr << ex.what() << endl;
		return false;
	}
	return true;
}
