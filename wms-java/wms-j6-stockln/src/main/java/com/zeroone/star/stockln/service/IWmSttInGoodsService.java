package com.zeroone.star.stockln.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.j6.stockln.BatchUpdateBinDTO;
import com.zeroone.star.project.dto.j6.stockln.BatchUpdateProductionDateDTO;
import com.zeroone.star.project.dto.j6.stockln.BatchUpdateShelfDTO;
import com.zeroone.star.stockln.entity.WmSttInGoods;

/**
 * <p>
 * 盘点指令 服务类
 * </p>
 *
 * @author ting
 * @since 2025-03-06
 */
public interface IWmSttInGoodsService extends IService<WmSttInGoods> {
    /**
     * 批量修改储位
     * @param dto 包含待修改ID列表和新储位编码的DTO
     * @return 更新的记录数
     */
    int batchUpdateBinIds(BatchUpdateBinDTO dto);
    /**
     * 批量修改生产日期
     * @param dto 包含待修改ID列表和新生产日期的DTO
     * @return 更新的记录数
     */
    int batchUpdateProductionDate(BatchUpdateProductionDateDTO dto);

    int batchUpdateShelf(BatchUpdateShelfDTO dto);
}
