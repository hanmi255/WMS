/*
 Copyright Zero One Star. All rights reserved.

 @Author: blue
 @Date: 2025/03/12 9:26:52

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
#include "UploadFileDAO.h"
#include <sstream>
#include "../lib-common/src/id/UuidFacade.cpp"
#include <iomanip>

// 将execl的数据提出处理后，插入到数据库中
uint64_t UploadFileDAO::insert(const UploadFileDO& iObj) {

	/*
	* 8
	id -- 唯一标识符
	create_name -- 创建人--管理员
	create_by -- 被谁创建 --- admin
	create_date -- 创建时间
	sys_org_code -- 所属部门代码
	sys_company_code -- 所属公司代码
	com_type_code -- 行业分类编码
	com_type_name -- 行业分类名称
	*/

	// 准备sql语句 
	string sql = "INSERT INTO `ba_classfl` (`id`, `create_name`, `create_by`,`create_date`,`sys_org_code`, `sys_company_code`, `classfl_code`, `classfl_name`) VALUES (?,?,?,?,?,?,?,?)";

	// 准备字段1：唯一标识符	
	UuidFacade uf(1);
	string id = uf.genUuid();
	std::cout << uf.genUuid() << std::endl;

	// 准备插入时间
	using namespace std::chrono;
	auto now = system_clock::now(); // 获取当前时间点
	auto now_time_t = system_clock::to_time_t(now); // 转换为 time_t
	std::tm now_tm = *std::localtime(&now_time_t); // 转换为 tm 结构
	std::ostringstream oss; // 格式化为字符串（格式：YYYY-MM-DD HH:MM:SS）
	oss << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S");
	std::cout << "Current Time: " << oss.str() << std::endl; // 打印时间字符

	// 返回执行结果
	return sqlSession->executeInsert(sql, "%s%s%s%s%s%s%s%s", id, iObj.getCreateName(), iObj.getCreateBy(), oss.str(), iObj.getSysorgCode(), iObj.getSysCompanyCode(), iObj.getTypeCode(), iObj.getTypeNames());
}
