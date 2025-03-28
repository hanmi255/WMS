

#include "BaseDAO.h"
#include "../../domain/query/ba_act_type/BaActTypeQuery.h"
#include "../../domain/do/ba_act_type/BaActTypeDO.h"
#include"BaActTypeMapper.h"

/**
 * 作业类型数据库操作实现
 */
class BaActTypeDAO : public BaseDAO
{
private:
	inline std::string queryConditionBuilder(const BaActTypeQuery::Wrapper& query, SqlParams& params);
public:
	
	uint64_t count(const BaActTypeQuery::Wrapper& query);

	std::list<BaActTypeDO> selectWithPage(const BaActTypeQuery::Wrapper& query);

	PtrBaActTypeDO selectById(const std::string& id);

	uint64_t insert(const BaActTypeDO& iObj);

	int update(const BaActTypeDO& uObj);

	int deleteById(const std::string id);

	std::list<BaActTypeDO> listAllDO();

	uint64_t insert_noid(const BaActTypeDO& iObj);


};
