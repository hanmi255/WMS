package com.zeroone.star.sysmanager.service.impl;

import com.alibaba.cloud.commons.lang.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.support.SFunction;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.TypeGroupAddDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.TypeGroupListDTO;
import com.zeroone.star.project.dto.j3.sysmg.datadictionary.TypeGroupModifyDTO;
import com.zeroone.star.project.query.j3.sysmg.datadictionary.TypeGroupQuery;
import com.zeroone.star.sysmanager.entity.TypeGroup;
import com.zeroone.star.sysmanager.mapper.TypeGroupMapper;
import com.zeroone.star.sysmanager.service.TypeGroupService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.sql.Timestamp;
import java.time.LocalDateTime;
import java.util.UUID;

/**
 * @program: wms-java
 * @description:
 * @author: Hao
 **/
@Service
@Slf4j
public class TypeGroupServiceImpl extends ServiceImpl<TypeGroupMapper,TypeGroup> implements TypeGroupService {
    @Resource
    private TypeGroupMapper typeGroupMapper;

    @Override
    public PageDTO<TypeGroupListDTO> list(TypeGroupQuery query) {
        Page<TypeGroup> page = new Page<>(query.getPageIndex(), query.getPageSize());

        LambdaQueryWrapper<TypeGroup> queryWrapper = new LambdaQueryWrapper<TypeGroup>()
                .like(StringUtils.isNotBlank(query.getTypegroupname()), TypeGroup::getTypeGroupName, query.getTypegroupname())
                .like(StringUtils.isNotBlank(query.getTypegroupcode()), TypeGroup::getTypeGroupCode, query.getTypegroupcode());

        // 动态排序逻辑
        String sortField = query.getSort();
        String sortOrder = query.getOrder();

        if (StringUtils.isNotBlank(sortField)) {
            // 根据 sort 字段决定排序字段
            SFunction<TypeGroup, ?> field;
            switch (sortField) {
                case "字典名称":
                    field = TypeGroup::getTypeGroupName;
                    break;
                case "字典code":
                    field = TypeGroup::getTypeGroupCode;
                    break;
                default: // 无效字段默认使用 typegroupcode
                    field = TypeGroup::getTypeGroupCode;
            }

            // 根据 order 决定排序方向（默认 asc）
            if ("desc".equalsIgnoreCase(sortOrder)) {
                queryWrapper.orderByDesc(field);
            } else {
                queryWrapper.orderByAsc(field);
            }
        } else {
            // 默认按编码升序
            queryWrapper.orderByAsc(TypeGroup::getTypeGroupCode);
        }

        Page<TypeGroup> resultPage = this.page(page, queryWrapper);
        return PageDTO.create(resultPage, this::convertToDTO);
    }


    @Override
    @Transactional
    public void save(TypeGroupAddDTO dto) {
        TypeGroup entity = new TypeGroup();
        BeanUtils.copyProperties(dto,entity);

        Long count = lambdaQuery()
                .eq(TypeGroup::getTypeGroupCode, dto.getTypegroupCode())
                .count();
        if (count > 0) {
            throw new RuntimeException("该分类已存在");
        }

        String uuid = UUID.randomUUID().toString().replace("-", "");
        entity.setId(uuid);
        entity.setCreateDate(Timestamp.valueOf(LocalDateTime.now()));
        baseMapper.insert(entity);
    }

    @Override
    @Transactional
    public void update(TypeGroupModifyDTO dto) {
        TypeGroup typeGroup = this.getById(dto.getId());
        if(typeGroup == null){
            throw new RuntimeException("不存在该分类");
        }
        Long count = lambdaQuery()
                .eq(TypeGroup::getTypeGroupCode, dto.getTypegroupCode())
                .ne(TypeGroup::getId,dto.getId())
                .count();
        if (count > 0) {
            throw new RuntimeException("该分类已存在");
        }

        typeGroup.setTypeGroupCode(dto.getTypegroupCode());
        typeGroup.setTypeGroupName(dto.getTypegroupName());

        this.updateById(typeGroup);
    }

    @Override
    @Transactional
    public void remove(String id) {
        TypeGroup typeGroup = this.getById(id);
        if(typeGroup == null){
            throw new RuntimeException("不存在该分类");
        }
        if(!this.removeById(id)){
            throw new RuntimeException("删除失败");
        }
    }

    /**
     * 将实体对象转换为DTO
     * @param typeGroup 字典分类实体
     * @return 字典分类DTO
     */
    private TypeGroupListDTO convertToDTO(TypeGroup typeGroup) {
        if (typeGroup == null) {
            return null;
        }

        TypeGroupListDTO dto = new TypeGroupListDTO();
        BeanUtils.copyProperties(typeGroup, dto);

        return dto;
    }
}
