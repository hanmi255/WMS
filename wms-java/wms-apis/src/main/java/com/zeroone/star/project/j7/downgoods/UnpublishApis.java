package com.zeroone.star.project.j7.downgoods;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.downgoods.UnpublishDTO;
import com.zeroone.star.project.query.j7.downgoods.UnpublishQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 出库任务下架接口
 * </p>
 *
 * @author King
 * @since 2025-02-25
 */
public interface UnpublishApis {

    /**
     * 获取下架列表（条件+分页）
     * @param query 查询条件
     * @return 分页结果
     */
    JsonVO<PageDTO<UnpublishDTO>> queryUnpublishList(UnpublishQuery query);

    /**
     * 获取下架详情
     * @param id 下架单ID
     * @return 下架详情
     */
    JsonVO<UnpublishDTO> getUnpublishById(String id);

    /**
     * 修改下架信息
     * @param dto 下架信息
     * @return 操作结果
     */
    JsonVO<String> modifyUnpublish(UnpublishDTO dto);
}