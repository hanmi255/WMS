package com.zeroone.star.stockln.service;


import com.zeroone.star.project.query.j6.stockln.ToAcceptQuery;
import com.zeroone.star.project.vo.j6.stockln.ToAcceptDetailVO;
import com.zeroone.star.project.vo.j6.stockln.ToAcceptPageVO;

public interface ToAcceptService {

    /**
     * 获取待验收货物列表，支持条件查询和分页查询
     * @param query 查询条件
     * @param page 页码
     * @param size 每页数量
     * @return 返回分页的待验收货物列表
     */
    ToAcceptPageVO getAcceptanceItems(ToAcceptQuery query, int page, int size);

    /**
     * 根据ID查询单个待验收货物
     * @param id 货物ID
     * @return 返回待验收货物的详细信息
     */
    ToAcceptDetailVO getAcceptanceItemById(String id);
}
