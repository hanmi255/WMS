package com.zeroone.star.outgoodsmanage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.outgoodsmanage.entity.WmToDownGoods;
import com.zeroone.star.project.dto.j7.adpick.AdPickExportDTO;
import com.zeroone.star.project.dto.j7.adpick.AdPickModifyBaseDTO;
import com.zeroone.star.project.dto.j7.adpick.AdPickModifyDTO;
import com.zeroone.star.project.dto.j7.downgoods.DownGoodsDTO;
import com.zeroone.star.project.query.j7.adpick.AdPickQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * <p>
 * 商品下架 Mapper 接口
 * </p>
 *
 * @author rocklin
 * @since 2025-02-23
 */
@Mapper
public interface WmToDownGoodsMapper extends BaseMapper<WmToDownGoods> {
    // 批量修改下架商品信息
    int batchUpdateDownGoods(@Param("downGoodsDTOList") List<DownGoodsDTO> downGoodsDTOList);
    // 下架商品
    int downGoods(@Param("ids") List<String> ids);
    // 删除下架任务
    int deleteDownGoods(String id);
    /**
     * 更新拣货单
     * @param adPickModifyDTO 修改DTO列表
     * @return 影响的总行数
     */
    int updateByGoodsAndOrder(AdPickModifyDTO adPickModifyDTO);
    /**
     * 批量更新拣货单
     * @param list 批量修改DTO列表
     * @return 影响的总行数
     */
    int updateBatchByGoodsAndOrder(@Param("list") List<AdPickModifyBaseDTO> list);
    /**
     * 获取excel数据拣货单
     * @param
     * @return 影响的总行数
     */
    List<AdPickExportDTO> selectExportData(AdPickQuery adPickQuery);
}
