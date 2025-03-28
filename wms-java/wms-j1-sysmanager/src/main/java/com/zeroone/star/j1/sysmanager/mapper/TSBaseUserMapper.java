package com.zeroone.star.j1.sysmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.zeroone.star.project.query.j1.sysmanager.rolemanager.RoleUserQuery;
import com.zeroone.star.project.query.j1.sysmanager.rolemanager.UserQuery;
import com.zeroone.star.project.vo.j1.sysmanager.rolemanager.RoleUserVO;
import com.zeroone.star.project.vo.j1.sysmanager.rolemanager.UserVO;
import com.zeroone.star.j1.sysmanager.entity.TSBaseUser;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

/**
 * <p>
 * 系统用户 Mapper 接口
 * </p>
 *
 * @author liyunyi
 * @since 2025-02-19
 */
@Mapper
public interface TSBaseUserMapper extends BaseMapper<TSBaseUser> {

    /**
     * 连表查询实现分页，根据角色id查询`不属于`该角色的用户
     * realname,username字段模糊查询
     * @param page 分页对象
     * @param query 查询条件
     * @return 分页后的用户列表
     */
    IPage<UserVO> getUserList(@Param("page") IPage<UserVO> page,@Param("query") UserQuery query);

    /**
     * 连表查询实现分页，根据角色id查询`属于`该角色的用户
     * @param page 分页对象
     * @param roleUserQuery 查询条件
     * @return 分页后的用户列表
     */
    IPage<RoleUserVO> getUserList2(@Param("page") IPage<RoleUserVO> page,@Param("query") RoleUserQuery roleUserQuery);
}
