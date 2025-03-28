package com.zeroone.star.j1.sysmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.j1.sysmanager.entity.TSDepart;
import com.zeroone.star.j1.sysmanager.mapper.TSDepartMapper;
import com.zeroone.star.j1.sysmanager.service.ITSDepartService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.sysmanager.usermanager.DepartmentDTO;
import com.zeroone.star.project.query.j1.sysmanager.usermanager.DepartmentQuery;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

@Mapper(componentModel = "spring")
interface MsDepartMapper{
    /**
     * 将do对象：TSDepart 转换为DepartmentDTO
     * @param
     * @return 转换后的对象
     */
    DepartmentDTO TSDepartToDepartmentDto(TSDepart tsDepart);
}
/**
 * <p>
 * 用户管理 服务实现类
 * </p>
 *
 * @author langyanyan
 * @since 2025-02-28
 */
@Service
public class TSDepartServiceImpl extends ServiceImpl<TSDepartMapper, TSDepart> implements ITSDepartService {
    @Resource
    MsDepartMapper msMapper;
    /**
     * 查询组织机构名
     * @param query
     * @return PageDTO<DepartmentDTO>
     */
    @Override
    public PageDTO<DepartmentDTO> listDepartAll(DepartmentQuery query) {
        //构建分页对象
        Page<TSDepart> page = new Page<>();
        //构建查询条件
        QueryWrapper<TSDepart> queryWrapper = new QueryWrapper<>();
       //查询数据
        Page<TSDepart> tsDeparts = baseMapper.selectPage(page,queryWrapper);
        System.out.println(tsDeparts.getRecords());

        return PageDTO.create(tsDeparts,msMapper::TSDepartToDepartmentDto);
    }
}
