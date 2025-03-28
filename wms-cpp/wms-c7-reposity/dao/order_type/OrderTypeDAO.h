#pragma once
#ifndef _ORDER_TYPE_DAO_H_
#define _ORDER_TYPE_DAO_H_
#include "BaseDAO.h"
#include "../../domain/do/order_type/OrderTypeDO.h"
#include "../../domain/query/order_type/OrderTypeQuery.h"

class OrderTypeDAO : public BaseDAO {
private:
    // 构建查询条件
    inline std::string queryConditionBuilder(const OrderTypeQuery::Wrapper& query, SqlParams& params);
public:
    // 查询总数
    uint64_t count(const OrderTypeQuery::Wrapper& query);
    uint64_t count(const PageQuery::Wrapper& query);

    // 查询订单类型名称列表
    std::list<OrderTypeNameDO> selectNameList();
    // 分页查询数据
    std::list<OrderTypeDO> selectWithPage(const OrderTypeQuery::Wrapper& query);
    // 插入数据
    uint64_t insert(const OrderTypeAddDO& iObj);

};

#endif //! _ORDER_TYPE_DAO_H_