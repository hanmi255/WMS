package com.zeroone.star.j1.sysmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.j1.sysmanager.entity.TSUserManage;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.sysmanager.usermanager.UserListDTO;
import com.zeroone.star.project.query.j1.sysmanager.usermanager.UserManagementQuery;

public interface ITSUserManageService extends IService<TSUserManage> {

    /**
     * 根据条件查询用户
     * @param query
     * @return 查询结果
     */
    PageDTO<UserListDTO> listUserManage(UserManagementQuery query);


}
