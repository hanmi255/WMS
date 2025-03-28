package com.zeroone.star.sysmanager.service.impl;

import com.alibaba.cloud.commons.lang.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.TypeBaseDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.TypeListDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.TypeModifyDTO;
import com.zeroone.star.project.query.j3.sysmg.datadictionary.TypeQuery;
import com.zeroone.star.sysmanager.entity.Type;
import com.zeroone.star.sysmanager.entity.TypeGroup;
import com.zeroone.star.sysmanager.mapper.TypeGroupMapper;
import com.zeroone.star.sysmanager.mapper.TypeMapper;
import com.zeroone.star.sysmanager.service.ITypeService;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;
import java.util.UUID;

@Service
public class TypeServiceImpl extends ServiceImpl<TypeMapper, Type> implements ITypeService {

    @Resource
    private TypeGroupMapper typeGroupMapper;

    /**
     * 添加字典类型
     * @param dto 字典类型数据模型
     */
    @Override
    @Transactional
    public void addType(TypeBaseDTO dto) {
        // 0. 生成UUID作为ID（根据需求选择生成方式）
        String uuid = UUID.randomUUID().toString().replace("-", "");

        // 1. 校验字典分类是否存在
        TypeGroup typeGroup = typeGroupMapper.selectById(dto.getTypeGroupId());
        if (typeGroup == null) {
            throw new RuntimeException("字典分类不存在");
        }

        // 2. 校验类型编码唯一性
        Long count = lambdaQuery()
                .eq(Type::getTypeGroupId, dto.getTypeGroupId())
                .eq(Type::getTypeCode, dto.getTypeCode())
                .count();
        if (count > 0) {
            throw new RuntimeException("类型编码已存在");
        }

        // 3. DTO转Entity并填充字段
        Type entity = new Type();
        BeanUtils.copyProperties(dto, entity);
        entity.setId(uuid); // 手动设置ID
        entity.setCreateDate(LocalDateTime.now());

        // 4. 持久化数据
        baseMapper.insert(entity);
    }

    /**
     * 删除字典类型
     * @param id 字典类型ID
     */
    @Override
    @Transactional
    public void removeType(String id) {
        // 1. 校验数据存在性
        Type type = this.getById(id);
        if (type == null) {
            throw new RuntimeException("要删除的字典类型不存在");
        }

        // 2. 检查是否被其他数据关联
        Long childCount = lambdaQuery()
                .eq(Type::getTypePid, id)
                .count();
        if (childCount > 0) {
            throw new RuntimeException("存在子类型关联，无法删除");
        }

        // 3. 执行删除
        if (!this.removeById(id)) {
            throw new RuntimeException("删除操作失败");
        }
    }

    /**
     * 修改字典类型
     * @param dto 字典类型修改数据模型
     */
    @Override
    @Transactional
    public void modifyType(TypeModifyDTO dto) {
        // 1. 校验数据存在性
        Type entity = this.getById(dto.getId());
        if (entity == null) {
            throw new RuntimeException("要修改的字典类型不存在");
        }

        // 2. 获取原分类ID用于校验编码唯一性
        String originalTypeGroupId = entity.getTypeGroupId();

        // 3. 校验编码唯一性（排除自身）
        Long count = lambdaQuery()
                .eq(Type::getTypeGroupId, originalTypeGroupId)
                .eq(Type::getTypeCode, dto.getTypeCode())
                .ne(Type::getId, dto.getId()) // 排除当前记录
                .count();
        if (count > 0) {
            throw new RuntimeException("类型编码已存在");
        }

        // 4. 更新字段
        entity.setTypeCode(dto.getTypeCode());
        entity.setTypeName(dto.getTypeName());

        // 5. 执行更新
        if (!this.updateById(entity)) {
            throw new RuntimeException("更新操作失败");
        }
    }

    /**
     * 分页查询字典类型
     * @param query 查询条件
     */
    @Override
    public PageDTO<TypeListDTO> queryTypePage(TypeQuery query) {
        // 1. 构建分页条件
        Page<Type> page = new Page<>(query.getPageIndex(), query.getPageSize());

        // 2. 构建查询条件
        LambdaQueryWrapper<Type> wrapper = new LambdaQueryWrapper<Type>()
                .eq(Type::getTypeGroupId, query.getTypegroupid()) // 必须条件
                .like(StringUtils.isNotBlank(query.getTypeName()), Type::getTypeName, query.getTypeName())
                .like(StringUtils.isNotBlank(query.getTypeCode()), Type::getTypeCode, query.getTypeCode())
                .orderByAsc(Type::getTypeCode); // 按编码自然排序

        // 3. 执行查询
        Page<Type> typePage = this.page(page, wrapper);

        // 4. 转换为DTO
        return PageDTO.create(typePage, this::convertToDTO);
    }

    /**
     * 根据字典分类编码查询字典类型
     * @param typegroupCode 分类编码
     */
    @Override
    public PageDTO<TypeListDTO> queryByGroupCode(String typegroupCode) {
        // 1. 查询字典分类
        TypeGroup typeGroup = typeGroupMapper.selectOne(
                new LambdaQueryWrapper<TypeGroup>()
                        .eq(TypeGroup::getTypeGroupCode, typegroupCode)
        );
        if (typeGroup == null) {
            throw new RuntimeException("字典分类不存在");
        }

        // 2. 查询关联类型（获取全部数据）
        List<Type> types = this.lambdaQuery()
                .eq(Type::getTypeGroupId, typeGroup.getId())
                .orderByAsc(Type::getTypeCode) // 按编码自然排序
                .list();

        // 3. 转换为分页格式（兼容前端）
        Page<Type> page = new Page<>(1, types.size());
        page.setRecords(types);
        page.setTotal(types.size());

        // 4. DTO转换
        return PageDTO.create(page, this::convertToDTO);
    }

    private TypeListDTO convertToDTO(Type entity) {
        TypeListDTO dto = new TypeListDTO();
        BeanUtils.copyProperties(entity, dto);
        dto.setId(entity.getId());
        return dto;
    }
}