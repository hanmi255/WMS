package com.zeroone.star.outgoodsmanage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.outgoodsmanage.entity.AnDanPickDO;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.adpick.AdPickDTO;
import com.zeroone.star.project.dto.j7.adpick.AdPickListDTO;
import com.zeroone.star.project.query.j7.adpick.AdPickQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 *  按单拣货 服务类
 * </p>
 *
 * @author qiuye
 * @since 2025-02-25
 */
public interface IAnDanPickService extends IService<AnDanPickDO> {
    /**
     * 修改拣货信息
     * @param adPickDTO 拣货信息DTO
     * @return 修改结果
     */
    JsonVO<PageDTO<AdPickDTO>> modify(AdPickDTO adPickDTO);

    /**
     * 批量修改拣货信息
     * @param adPickListDTOs 拣货列表DTO
     * @return 修改结果
     */
    JsonVO<PageDTO<AdPickListDTO>> modifyList(List<AdPickListDTO> adPickListDTOs);

    /**
     * 获取拣货数据用于导出Excel
     * @param adPickQuery 查询条件
     * @return 拣货数据列表
     */
    byte[] exportExcel(AdPickQuery adPickQuery);

}
