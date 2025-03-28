#ifndef _AREAINFO_SERVICE_
#define _AREAINFO_SERVICE_
#include "domain/dto/areainfo/AreaInfoDTO.h"
#include "dao/areainfo/AreaInfoDAO.h"
#include "domain/query/areainfo/AreaInfoQuery.h"

class AreaInfoService
{
public:
	// 删除地区信息
	bool deleteData(const string& id);
	// 修改数据
	bool modifyData(const AreaInfoUpdDTO::Wrapper& dto, const PayloadDTO& payload);
	// 录入数据
	bool addData(const AreaInfoUpdDTO::Wrapper& dto, const PayloadDTO& payload);
	// 导入数据
	bool upload(const std::vector<std::vector<std::string>>& vec, const PayloadDTO& payload);
	// 获取全部地区信息
	std::vector<std::vector<std::string>> selectAll();
	// 获取地区信息名称树
	list<shared_ptr<TreeNode>> nameTree();
	// 获取地区信息列表
	AreaInfoPageDTO::Wrapper List(const AreaInfoQuery::Wrapper& query);
};

#endif // !_AREAINFO_SERVICE_
