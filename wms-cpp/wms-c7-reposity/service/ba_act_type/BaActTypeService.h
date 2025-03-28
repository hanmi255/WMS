



#include <list>
#include "../../domain/vo/ba_act_type/BaActTypeVO.h"
#include "../../domain/query/ba_act_type/BaActTypeQuery.h"
#include "../../domain/do/ba_act_type/BaActTypeDO.h"
#include "../../domain/dto/ba_act_type/BaActTypeDTO.h"

/**
 * 作业类型服务类
 */

class BaActTypeService
{
public:
    // 分页查询作业类型
    BaActTypeListPageDTO::Wrapper listAll(const BaActTypeQuery::Wrapper& query);
    // 通过ID查询单个作业类型
    BaActTypeDTO::Wrapper getById(uint64_t id);
    // 添加作业类型
    uint64_t saveData(const BaActTypeAddDTO::Wrapper& dto);
    // 更新作业类型
    bool updateData(const BaActTypeDTO::Wrapper& dto);
    // 删除作业类型
    bool removeData(const std::string id);

    //
    std::list<BaActTypeDO> listAll();

    //不生成id存储
    uint64_t saveData_noid(const std::vector<std::vector<std::string>>& dto);

};