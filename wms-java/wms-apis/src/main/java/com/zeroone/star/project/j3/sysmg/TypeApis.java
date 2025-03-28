package com.zeroone.star.project.j3.sysmg;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.*;
import com.zeroone.star.project.query.j3.sysmg.datadictionary.TypeGroupQuery;
import com.zeroone.star.project.query.j3.sysmg.datadictionary.TypeQuery;
import com.zeroone.star.project.vo.JsonVO;

/**
 * @program: wms-java
 * @description: 字典类型接口
 * @author: 骞骧
 **/
public interface TypeApis {
    /**
     * 通过分类编码获取类型列表
     * @param typegroupCode 分类编码（字典Code）
     */
    JsonVO<PageDTO<TypeListDTO>> queryByGroupCode(String typegroupCode);

    /**
     * 查询字典类型列表
     * @param query 查询条件
     */
    JsonVO<PageDTO<TypeListDTO>> queryAll(TypeQuery query);

    /**
     * 新增字典类型
     * @param dto 字典类型数据
     */
    JsonVO<String> addType(TypeBaseDTO dto);

    /**
     * 修改字典类型
     * @param dto 字典类型数据
     */
    JsonVO<String> modifyType(TypeModifyDTO dto);

    /**
     * 删除字典类型
     * @param id 字典类型id
     */
    JsonVO<String> removeType(String id);
}
