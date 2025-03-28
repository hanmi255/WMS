package com.zeroone.star.j1.sysmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.j1.sysmanager.entity.TSUserManage;
import com.zeroone.star.j1.sysmanager.mapper.TSUserManageMapper;
import com.zeroone.star.j1.sysmanager.service.ITSUserManageService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.sysmanager.usermanager.UserListDTO;
import com.zeroone.star.project.query.j1.sysmanager.usermanager.UserManagementQuery;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 *  获取用户信息，服务实现类
 * </p>
 *
 * @author langyanyan
 * @since 2025-03-04
 */
//@Mapper(componentModel = "spring")
//interface MsUserManageMapper{
//    /**
//     * 将do对象：TSUserManage 转换为UserListDTO
//     * @param
//     * @return 转换后的对象
//     */
//    UserListDTO TSUserManageToUserListDTO(TSUserManage tsUserManage);
//
//}


@Service
public class ITSUserManageServiceImpl extends ServiceImpl<TSUserManageMapper, TSUserManage> implements ITSUserManageService {
//    @Resource
//    MsUserManageMapper msUserManageMapper;
    @Resource
    TSUserManageMapper tsUserManageMapper;

    @Override
    public PageDTO<UserListDTO> listUserManage(UserManagementQuery query) {
        //构建分页对象
        Page<UserListDTO> page = new Page<>(query.getPageIndex(),query.getPageSize());
        //使用mp分页插件，xml形式查询
        Page<UserListDTO> result=tsUserManageMapper.listUserManage(page,query);



        //手动转换，不使用PageDTO.create();
        PageDTO<UserListDTO> pageResult=new PageDTO<>();
        pageResult.setTotal(result.getTotal());
        pageResult.setRows(result.getRecords());
        pageResult.setPageIndex(result.getCurrent());
        pageResult.setPageSize(result.getSize());
        pageResult.setPages(result.getPages());




        return pageResult;
    }
}
