package com.zeroone.star.sysmgr.service;

import com.zeroone.star.project.query.j2.sysmgr.AddUserQuery;
import com.zeroone.star.project.query.j2.sysmgr.DeleteUserQuery;
import com.zeroone.star.project.query.j2.sysmgr.ListUserQuery;
import com.zeroone.star.project.vo.j2.sysmgr.ListUserVO;
import com.zeroone.star.sysmgr.entity.TSUserOrg;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author henry
 * @since 2025-02-21
 */
public interface ITSUserOrgService extends IService<TSUserOrg> {

    ListUserVO listUser(ListUserQuery userQuery);

    int deleteUser(DeleteUserQuery userQuery);

    boolean addUser(AddUserQuery userQuery);
}
