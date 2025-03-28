package com.zeroone.star.project.j6.stockln;

import com.zeroone.star.project.dto.j6.stockln.*;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;

/**
 * 描述：库存批量操作API接口
 * 提供库存管理相关批量操作的接口定义
 */
public interface StockBatchApis {

    /**
     * 批量修改储位
     * @param dto 包含待修改ID列表和新储位编码的DTO
     * @return 更新成功的记录数
     */
    JsonVO<String> batchUpdateBin(@RequestBody BatchUpdateBinDTO dto);

    /**
     * 批量修改生产日期
     * @param dto 包含待修改ID列表和新生产日期的DTO
     * @return 更新成功的记录数
     */
   JsonVO<String> batchUpdateProductionDate(@RequestBody BatchUpdateProductionDateDTO dto);

    /**
     * 批量上架货物
     * @param dto 包含待上架ID列表、新储位和状态的DTO
     * @return 更新成功的记录数
     */
   JsonVO<String> batchUpdateShelf(@RequestBody BatchUpdateShelfDTO dto);
}