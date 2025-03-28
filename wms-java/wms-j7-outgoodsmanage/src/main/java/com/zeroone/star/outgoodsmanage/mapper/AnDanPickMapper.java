package com.zeroone.star.outgoodsmanage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.outgoodsmanage.entity.AnDanPickDO;
import com.zeroone.star.project.dto.j7.adpick.AdPickDTO;
import com.zeroone.star.project.dto.j7.adpick.AdPickListDTO;
import com.zeroone.star.project.dto.j7.adpick.OutDetailExcelDTO;
import com.zeroone.star.project.query.j7.adpick.AdPickQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * <p>
 *  按单拣货 Mapper 接口
 * </p>
 *
 * @author tang
 * @since 2025-02-25
 */

@Mapper
public interface AnDanPickMapper extends BaseMapper<AnDanPickDO> {
    /**
     * 更新单个拣货信息
     * @param adPickDTO 拣货信息DTO
     * @return 影响行数
     */
    int updateAdPick(@Param("adPickDTO") AdPickDTO adPickDTO);

    /**
     * 批量更新拣货信息
     * @param adPickListDTOs 拣货列表DTO集合
     * @return 影响行数
     */
    int batchUpdateAdPick(@Param("adPickListDTOs") List<AdPickListDTO> adPickListDTOs);


    /**
     * Excel导出获取数据
     * @param query 查询条件
     * @return 拣货信息列表
     */
    List<OutDetailExcelDTO> getExportData(@Param("query") AdPickQuery query);

}
