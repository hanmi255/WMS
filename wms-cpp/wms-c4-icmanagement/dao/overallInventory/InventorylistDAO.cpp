#include "stdafx.h"
#include "InventorylistDAO.h"
#include "InventorylistMapper.h"
#include <sstream>
inline std::string InventorylistDAO::queryConditionBuilder(const InventorylistQuery::Wrapper& query, SqlParams& params)
{
    stringstream sqlCondition;
    sqlCondition << " WHERE 1=1";
    // 移动日期
    if (query->yidongriqi)
    {
        sqlCondition << "AND `bin_id` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->yidongriqi.getValue(""));
    }
    // 库存类型
    if (query->cktype)
    {
        sqlCondition << " AND `tin_id` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->cktype.getValue(""));
    }
    // 储位
    if (query->chuwei)
    {
        sqlCondition << " AND `goods_id` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->chuwei.getValue(""));
    }
    // 托盘
    if (query->tuopan)
    {
        sqlCondition << " AND `goods_name` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->tuopan.getValue(""));
    }
    // 货主
    if (query->huozhu)
    {
        sqlCondition << " AND `goods_pro_data` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->huozhu.getValue(""));
    }
    // 货主名称
    if (query->huozhumingcheng)
    {
        sqlCondition << " AND `goods_batch` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->huozhumingcheng.getValue(""));
    }
    // 商品编码
    if (query->shangpinbianma)
    {
        sqlCondition << " AND `cus_name` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->shangpinbianma.getValue(""));
    }
    // 商品数量
    if (query->shangpinshuliang)
    {
        sqlCondition << " AND `cus` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->shangpinshuliang.getValue(""));
    }
    // 商品名称
    if (query->shangpinmincheng)
    {
        sqlCondition << " AND `stt_sta` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->shangpinmincheng.getValue(""));
    }
    // 生产日期
    if (query->shengchanriqi)
    {
        sqlCondition << " AND `stt_sta` =?";
        SQLPARAMS_PUSH(params, "s", std::string, query->shengchanriqi.getValue(""));
    }
    return sqlCondition.str();
}
// 统计数据条数
uint64_t InventorylistDAO::count(const InventorylistQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT COUNT(*) FROM wm_stt_in_goods";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);
    // 执行查询
    return sqlSession->executeQueryNumerical(sql, params);
}
// 分页查询数据 wm_stt_in_goods
std::list<InventorylistDo> InventorylistDAO::selectWithPage(const InventorylistQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT * FROM wm_stt_in_goods";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);
    // 构建分页条件
    sql += " LIMIT " + std::to_string(((query->pageIndex - 1) * query->pageSize)) + "," + std::to_string(query->pageSize);
    // 执行查询
    InventorylistMapper mapper;
    return sqlSession->executeQuery<InventorylistDo>(sql, mapper, params);
}
// 查询数据---不分页
std::list<InventorylistDo> InventorylistDAO::selectWithConditions(const InventorylistQuery::Wrapper& query)
{
    SqlParams params;
    string sql = "SELECT * FROM wm_stt_in_goods";
    // 构建查询条件
    sql += queryConditionBuilder(query, params);
    // 执行查询
    InventorylistMapper mapper;
    return sqlSession->executeQuery<InventorylistDo>(sql, mapper, params);
}
// 通过姓名查询数据
//std::list<InventorylistDo> GoodsManageDAO::selectByName(const string& name)
// {
// 
// }
// 通过ID查询数据
PtrInventorylistDo InventorylistDAO::selectById(uint64_t id)
{
    return {};
}
// 插入数据
uint64_t InventorylistDAO::insert(const InventorylistDo& iObj)
{
    return {};
}
// 修改数据
int InventorylistDAO::update(const InventorylistDo& uObj)
{
    if (uObj.getSttSta() == ZH_WORDS_GETTER("review-stt.goods.stt_sta.sta1"))
    {
        string sql = "UPDATE `wm_stt_in_goods` SET `stt_sta`=? WHERE `id`=?";
        return sqlSession->executeUpdate(sql, "%s%s", ZH_WORDS_GETTER("review-stt.goods.stt_sta.sta3"), uObj.getId());
    }
    return 0;
}
// 通过ID删除数据
//int InventorylistDAO::deleteById(uint64_t id)
//{
//    return {};
//}