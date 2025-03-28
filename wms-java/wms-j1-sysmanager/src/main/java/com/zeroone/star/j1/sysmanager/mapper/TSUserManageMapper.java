package com.zeroone.star.j1.sysmanager.mapper;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.j1.sysmanager.entity.TSUserManage;
import com.zeroone.star.project.dto.j1.sysmanager.usermanager.UserListDTO;
import com.zeroone.star.project.query.j1.sysmanager.rolemanager.UserQuery;
import com.zeroone.star.project.query.j1.sysmanager.usermanager.UserManagementQuery;
import com.zeroone.star.project.vo.j1.sysmanager.rolemanager.UserVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

@Mapper
public interface TSUserManageMapper extends BaseMapper<TSUserManage> {



     Page<UserListDTO> listUserManage(@Param("page")Page<UserListDTO> page, @Param("query") UserManagementQuery query);

}
