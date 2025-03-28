#include "stdafx.h"
#include "CheckService.h"
#include "../../dao/check/CheckDAO.h"
#include "../../domain/dto/check/CheckDTO.h"

CheckPageDTO::Wrapper CheckService::listAll(const CheckQuery::Wrapper &query)
{
    // 构建返回对象
    auto pages = CheckPageDTO::createShared();
    pages->pageIndex = query->pageIndex;
    pages->pageSize = query->pageSize;

    // 查询数据总条数
    CheckDAO dao;
    uint64_t count = dao.count(query);
    if (count <= 0)
    {
        return pages;
    }

    // 分页查询数据
    pages->total = count;
    pages->calcPages();
    std::list<CheckDO> result = dao.selectWithPage(query);

    // 将DO转换成DTO
    for (const CheckDO &sub : result)
    {
        auto dto = CheckBaseDTO::createShared();
        ZO_STAR_DOMAIN_DO_TO_DTO(dto, sub,
                                 id, Id,
                                 create_name, Create_name,
                                 create_by, Create_by,
                                 create_date, Create_date,
                                 update_name, Update_name,
                                 update_by, Update_by,
                                 update_date, Update_date,
                                 sys_org_code, Sys_org_code,
                                 sys_company_code, Sys_company_code,
                                 bin_id, Bin_id,
                                 tin_id, Tin_id,
                                 goods_id, Goods_id,
                                 goods_name, Goods_name,
                                 goods_qua, Goods_qua,
                                 goods_unit, Goods_unit,
                                 goods_pro_data, Goods_pro_data,
                                 goods_batch, Goods_batch,
                                 stt_qua, Stt_qua,
                                 cus_name, Cus_name,
                                 cus_code, Cus_code,
                                 stt_sta, Stt_sta,
                                 base_unit, Base_unit,
                                 base_goodscount, Base_goodscount,
                                 stt_id, Stt_id,
                                 goods_code, Goods_code,
                                 stt_type, Stt_type,
                                 dong_xian, Dong_xian);
        pages->addData(dto);
    }
    return pages;
}

// 导出文件数据
list<CheckDO> CheckService::exportData(const CheckQuery::Wrapper &query)
{
    CheckDAO dao;
    return dao.selectWithPage(query);
}
