package com.zeroone.star.sysmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.TypeGroupAddDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.TypeGroupListDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.TypeGroupModifyDTO;
import com.zeroone.star.project.query.j3.sysmg.datadictionary.TypeGroupQuery;
import com.zeroone.star.sysmanager.entity.TypeGroup;

/**
 * @program: wms-java
 * @description: 分类服务接口
 * @author: Hao
 **/
public interface TypeGroupService extends IService<TypeGroup>{
    /**
     * 分页查询
     */
    PageDTO<TypeGroupListDTO> list(TypeGroupQuery query);

    /**
     * 新增
     * @param dto
     */
    void save(TypeGroupAddDTO dto);

    /**
     * 修改
     * @param dto
     */
    void update(TypeGroupModifyDTO dto);

    /**
     * 删除
     * @param id
     */
    void remove(String id);
}
