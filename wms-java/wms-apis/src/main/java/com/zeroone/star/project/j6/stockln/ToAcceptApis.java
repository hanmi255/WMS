package com.zeroone.star.project.j6.stockln;


import com.zeroone.star.project.query.j6.stockln.ToAcceptQuery;
import com.zeroone.star.project.vo.j6.stockln.ToAcceptDetailVO;
import com.zeroone.star.project.vo.j6.stockln.ToAcceptPageVO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * <p>
 * 描述：待验收货物相关接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @version 1.0.0
 */
public interface ToAcceptApis {

    /**
     * 获取待验收货物列表，支持条件查询和分页查询
     * @param query 查询条件（包括到货通知单、商品编码等）
     * @param page 页码
     * @param size 每页数量
     * @return 返回分页的待验收货物列表
     */
    JsonVO<ToAcceptPageVO> getAcceptanceItems(ToAcceptQuery query, int page, int size);

    /**
     * 根据ID查询单个待验收货物
     * @param id 货物ID
     * @return 返回待验收货物的详细信息
     */
    JsonVO<ToAcceptDetailVO> getAcceptanceItemById(String id);
}
