package com.zeroone.star.j1.sysmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.j1.sysmanager.entity.TSDepart;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.sysmanager.usermanager.DepartmentDTO;
import com.zeroone.star.project.query.j1.sysmanager.usermanager.DepartmentQuery;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author langyanyan
 * @since 2025-02-28
 */
public interface ITSDepartService extends IService<TSDepart> {
    /**
     * 查询所有组织机构
     * @param query
     * @return 查询结果
     */
    PageDTO<DepartmentDTO> listDepartAll(DepartmentQuery query);

}
