package com.zeroone.star.project.j3.sysmg;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.*;
import com.zeroone.star.project.query.j3.sysmg.datadictionary.TypeGroupQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @program: wms-java
 * @description: 字典分类接口
 * @author: Hao
 **/
public interface TypeGroupApis {
    /**
     * 查询字典分类列表
     * @param query 查询条件
     * @return 响应数据结果
     */
    JsonVO<PageDTO<TypeGroupListDTO>> queryAll(TypeGroupQuery query);

    /**
     * 新增字典分类
     * @param dto 字典分类
     * @return 响应数据结果
     */
    JsonVO<String> addTypeGroup(TypeGroupAddDTO dto);

    /**
     * 删除字典分类
     * @param id
     * @return 响应数据结果
     */
    JsonVO<String> removeTypeGroup(String id);

    /**
     * 修改字典分类
     * @param dto 字典分类
     * @return 响应数据结果
     */
    JsonVO<String> modifyTypeGroup(TypeGroupModifyDTO dto);
}