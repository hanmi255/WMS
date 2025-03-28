package com.zeroone.star.project.j2.sysmgr;

import com.zeroone.star.project.query.j2.sysmgr.AddUserQuery;
import com.zeroone.star.project.query.j2.sysmgr.DeleteUserQuery;
import com.zeroone.star.project.query.j2.sysmgr.ListUserQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.sysmgr.ListUserVO;

/**
 * @author Henry
 */

public interface OrgUserApis {
    /**
     * 获取组织成员
     * @param userQuery 要查询的组织成员的相关信息
     * @return 返回新增组织成员的信息
     */
    JsonVO<ListUserVO> listUser(ListUserQuery userQuery);

    /**
     * 删除组织成员
     * @param userQuery 要删除的组织成员的相关信息
     * @return 返回删除成功响应
     */
    JsonVO<Object> deleteUser(DeleteUserQuery userQuery);

    /**
     * 添加组织成员
     * @param userQuery 要新增的组织成员的相关信息
     * @return 返回添加成功响应
     */
    JsonVO<Object> addUser(AddUserQuery userQuery);
}
