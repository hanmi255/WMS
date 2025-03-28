package com.zeroone.star.sysmanager.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.TypeAddDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.TypeBaseDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.TypeListDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.TypeModifyDTO;
import com.zeroone.star.project.query.j3.sysmg.datadictionary.TypeQuery;
import com.zeroone.star.sysmanager.entity.Type;

public interface ITypeService extends IService<Type> {

    /**
     * 新增字典类型
     * @param dto 字典类型数据模型
     */
    void addType(TypeBaseDTO dto);

    /**
     * 删除字典类型
     * @param id 字典类型ID
     */
    void removeType(String id);

    /**
     * 修改字典类型
     * @param dto 修改数据模型
     */
    void modifyType(TypeModifyDTO dto);

    /**
     * 分页查询字典类型
     * @param query 查询条件
     * @return 分页结果
     */
    PageDTO<TypeListDTO> queryTypePage(TypeQuery query);

    /**
     * 通过分类编码查询类型列表
     * @param typegroupCode 分类编码
     * @return 分页数据（实际不分页，返回全部结果）
     */
    PageDTO<TypeListDTO> queryByGroupCode(String typegroupCode);
}
