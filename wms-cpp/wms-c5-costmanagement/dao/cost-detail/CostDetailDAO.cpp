/*
 Copyright Zero One Star. All rights reserved.

 @Author: epiphany
 @Date: 2025/3/4 14:42

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
#include "CostDetailDAO.h"
#include "CostDetailMapper.h"
#include <sstream>

//收取费用,对应数据表wm_day_cost
int CostDetailDAO::charge(const oatpp::String& id)
{
	string sql = "UPDATE `wm_day_cost` SET `cost_js`='Y' WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id.getValue("-1"));
}
//取消收取费用
int CostDetailDAO::discharge(const oatpp::String& id)
{
	string sql = "UPDATE `wm_day_cost` SET `cost_js`='N' WHERE `id`=?";
	return sqlSession->executeUpdate(sql, "%s", id.getValue("-1"));
}
//新增数据
uint64_t CostDetailDAO::insert(const DayCostDO& iObj)
{
	/*cout << iObj.getCreateDate() << ":" << iObj.getUpdateDate() << ":" << iObj.getCostDate() << endl;*/
	string sql = "INSERT INTO `wm_day_cost` (`id`,`create_name`,`create_date`,`update_name`,`update_date`,`cus_code`,`cost_code`,`cost_data`,`day_cost_yj`,`day_cost_bhs`,`day_cost_se`,`day_cost_hsj`,`cost_ori`,`beizhu`,`cost_sta`,`cost_js`,`cost_sl`,`cost_unit`,`create_by`,`sys_org_code`,`sys_company_code`) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
	return sqlSession->executeUpdate(sql, "%s%s%dt%s%dt%s%s%dt%s%s%s%s%s%s%s%s%s%s%s%s%s", iObj.getId(), iObj.getCreateName(), iObj.getCreateDate(), iObj.getUpdateName(), iObj.getUpdateDate(), iObj.getCusCode(), iObj.getCostCode(), iObj.getCostDate(), iObj.getDayCostYj(), iObj.getDayCostBhs(), iObj.getDayCostSe(), iObj.getDayCostHsj(), iObj.getCostOri(), iObj.getBeiZhu(), iObj.getCostSta(), iObj.getCostJs(), iObj.getCostSl(), iObj.getCostUnit(), iObj.getCreateBy(), iObj.getSysOrgCode(), iObj.getSysCompanyCode());
}
//导出全部数据
list<DayCostDO> CostDetailDAO::exportAll(const oatpp::List<oatpp::String>& ids)
{
	string sql = "SELECT create_name,create_date,update_name,update_date,cus_code,cus_name,cost_code,cost_name,cost_data,day_cost_yj,day_cost_bhs,day_cost_se,day_cost_hsj,cost_ori,beizhu,cost_sta,cost_js,cost_sl,cost_unit FROM wm_day_cost";
	CostDetailMapper mapper;
	return sqlSession->executeQuery<DayCostDO>(sql, mapper);
}
//按id导出
DayCostDO CostDetailDAO::selectById(const oatpp::String& id)
{
	string sql = "SELECT create_name,create_date,update_name,update_date,cus_code,cus_name,cost_code,cost_name,cost_data,day_cost_yj,day_cost_bhs,day_cost_se,day_cost_hsj,cost_ori,beizhu,cost_sta,cost_js,cost_sl,cost_unit FROM wm_day_cost WHERE `id`=?";
	CostDetailMapper mapper;
	return sqlSession->executeQueryOne<DayCostDO>(sql, mapper,"%s",id.getValue("-1"));
}