#ifndef _TREEAREANAME_MAPPER_
#define _TREEAREANAME_MAPPER_
#include "tree/TreeNodeMapper.h"
#include "domain/do/areainfo/AreaInfoDO.h"
#include "domain/dto/areainfo/AreaInfoDTO.h"

class TreeAreaNameMapper : public TreeNodeMapper<AreaNameTreeDO>
{
public:
	shared_ptr<TreeNode> objectMapper(AreaNameTreeDO* source) const override
	{
		// 创建结果数据对象
		auto res = make_shared<AreaNameTreeDTO>();
		// 计算层级结构属性映射
		res->_id(source->getCid());
		res->_pid(source->getParentId());
		// 扩展属性映射
		res->id = source->getId();
		res->name = source->getCity_name();
		return res;
	}
};


#endif // !_TREEAREANAME_MAPPER_