#include "stdafx.h"
#include "CheckController.h"
#include "../../service/check/CheckService.h"
#include "../ApiDeclarativeServicesHelper.h"

// FastDFS需要导入的头
#include "ServerInfo.h"
#include "NacosClient.h"
#include "FastDfsClient.h"
#include "SimpleDateTimeFormat.h"
#include <ExcelComponent.h>
// 查询
CheckPageJsonVO::Wrapper CheckController::execQueryCheck(const CheckQuery::Wrapper &query)
{
    // 定义一个Service
    CheckService service;
    // 查询数据
    auto result = service.listAll(query);
    // 响应结果
    auto jvo = CheckPageJsonVO::createShared();
    jvo->success(result);
    return jvo;
}

std::shared_ptr<oatpp::web::server::api::ApiController::OutgoingResponse> CheckController::execExportCheck(const CheckQuery::Wrapper &query)
{
    CheckService service;
    auto result = service.exportData(query);
    std::vector<CheckDO> datas(result.begin(), result.end());

    // 创建表头数据
    std::vector<std::string> headers = {
        ZH_WORDS_GETTER("mql.rest.id"),              // ID
        ZH_WORDS_GETTER("mql.creat.create_name"),    // 创建人名称
        ZH_WORDS_GETTER("mql.creat.create_by"),      // 创建人登录名称
        ZH_WORDS_GETTER("mql.creat.create_date"),    // 创建日期
        ZH_WORDS_GETTER("mql.update.update_name"),   // 更新人名称
        ZH_WORDS_GETTER("mql.update.update_by"),     // 更新人登录名称
        ZH_WORDS_GETTER("mql.update.update_date"),   // 更新日期
        ZH_WORDS_GETTER("mql.sys.sys_org_code"),     // 所属部门
        ZH_WORDS_GETTER("mql.sys.sys_company_code"), // 所属公司
        ZH_WORDS_GETTER("mql.rest.bin_id"),          // 储位
        ZH_WORDS_GETTER("mql.rest.tin_id"),          // 托盘
        ZH_WORDS_GETTER("mql.goods.goods_id"),       // 商品编码
        ZH_WORDS_GETTER("mql.goods.goods_name"),     // 商品名称
        ZH_WORDS_GETTER("mql.goods.goods_qua"),      // 数量
        ZH_WORDS_GETTER("mql.goods.goods_unit"),     // 单位
        ZH_WORDS_GETTER("mql.goods.goods_pro_data"), // 生产日期
        ZH_WORDS_GETTER("mql.goods.goods_batch"),    // 批次
        ZH_WORDS_GETTER("mql.stt.stt_qua"),          // 盘点数量
        ZH_WORDS_GETTER("mql.cus.cus_name"),         // 客户名称
        ZH_WORDS_GETTER("mql.cus.cus_code"),         // 客户
        ZH_WORDS_GETTER("mql.stt.stt_sta"),          // 盘点状态
        ZH_WORDS_GETTER("mql.base.base_unit"),       // 基本单位
        ZH_WORDS_GETTER("mql.base.base_goodscount"), // 基本单位数量
        "stt_id",
        ZH_WORDS_GETTER("mql.goods.goods_code"), // 商品统一编码
        ZH_WORDS_GETTER("mql.stt.stt_type"),     // 盘点类型
        ZH_WORDS_GETTER("mql.rest.dong_xian")    // 动线

    };

    std::vector<std::vector<std::string>> data;
    data.push_back(headers);

    for (const auto &item : datas)
    {
        std::vector<std::string> row;
        row.push_back(item.getId());
        row.push_back(item.getCreate_name());
        row.push_back(item.getCreate_by());
        row.push_back(item.getCreate_date());
        row.push_back(item.getUpdate_name());
        row.push_back(item.getUpdate_by());
        row.push_back(item.getUpdate_date());
        row.push_back(item.getSys_org_code());
        row.push_back(item.getSys_company_code());
        row.push_back(item.getBin_id());
        row.push_back(item.getTin_id());
        row.push_back(item.getGoods_id());
        row.push_back(item.getGoods_name());
        row.push_back(item.getGoods_qua());
        row.push_back(item.getGoods_unit());
        row.push_back(item.getGoods_pro_data());
        row.push_back(item.getGoods_batch());
        row.push_back(item.getStt_qua());
        row.push_back(item.getCus_name());
        row.push_back(item.getCus_code());
        row.push_back(item.getStt_sta());
        row.push_back(item.getBase_unit());
        row.push_back(item.getBase_goodscount());
        row.push_back(item.getStt_id());
        row.push_back(item.getGoods_code());
        row.push_back(item.getStt_type());
        row.push_back(item.getDong_xian());

        data.push_back(row);
    }

    // 定义保存数据位置和页签名称
    // 注意：因为xlnt不能存储非utf8编码的字符，所以中文字需要从配置文件中获取
    std::string sheetName = ZH_WORDS_GETTER("excel.sheet.s3");
    // 文件名
    std::string filename = ZH_WORDS_GETTER("bin.download.mql") + ".xlsx";

    // 保存到文件
    ExcelComponent excel;
    auto buff = excel.writeVectorToBuff(sheetName, data);
    const char *tsData = reinterpret_cast<const char *>(buff.data());
    auto fstring = String(tsData, buff.size());

    if (!fstring)
    {
        std::cerr << "Failed to open file: " << std::strerror(errno) << std::endl;
        return createResponse(Status::CODE_404, "File Not Found");
    }

    // 创建响应头
    auto response = createResponse(Status::CODE_200, fstring);

    // 设置响应头信息
    response->putHeader("Content-Disposition", "attachment; filename=TaskListInventory.xlsx");

    return response;
}
