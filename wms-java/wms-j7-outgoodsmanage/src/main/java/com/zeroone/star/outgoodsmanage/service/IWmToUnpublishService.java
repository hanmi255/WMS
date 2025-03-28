package com.zeroone.star.outgoodsmanage.service;

import com.zeroone.star.outgoodsmanage.entity.WmToUnpublish;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.downgoods.UnpublishDTO;
import com.zeroone.star.project.query.j7.downgoods.UnpublishQuery;

/**
 * <p>
 * 商品下架 服务类
 * </p>
 *
 * @author King
 * @since 2025-03-06
 */
public interface IWmToUnpublishService extends IService<WmToUnpublish> {
    
    /**
     * 获取下架列表（条件+分页）
     * @param query 查询条件
     * @return 分页结果
     */
    PageDTO<UnpublishDTO> queryUnpublishList(UnpublishQuery query);
    
    /**
     * 获取下架详情
     * @param id 下架单ID
     * @return 下架详情
     */
    UnpublishDTO getUnpublishById(String id);
    
    /**
     * 修改下架信息
     * @param dto 下架信息
     * @return 是否成功
     */
    boolean modifyUnpublish(UnpublishDTO dto);
}
