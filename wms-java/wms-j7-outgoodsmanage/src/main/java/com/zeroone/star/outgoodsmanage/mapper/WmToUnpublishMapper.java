package com.zeroone.star.outgoodsmanage.mapper;

import com.zeroone.star.outgoodsmanage.entity.WmToUnpublish;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.j7.downgoods.UnpublishDTO;
import com.zeroone.star.project.query.j7.downgoods.UnpublishQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

/**
 * <p>
 * 商品下架 Mapper 接口
 * </p>
 *
 * @author King
 * @since 2025-03-06
 */
@Mapper
public interface WmToUnpublishMapper extends BaseMapper<WmToUnpublish> {
    
    /**
     * 分页查询下架列表
     * @param page 分页参数
     * @param query 查询条件
     * @return 分页结果
     */
    Page<UnpublishDTO> selectUnpublishList(Page<UnpublishDTO> page, @Param("query") UnpublishQuery query);
    
    /**
     * 获取下架详情
     * @param id 下架单ID
     * @return 下架详情
     */
    UnpublishDTO getUnpublishById(@Param("id") String id);
}
