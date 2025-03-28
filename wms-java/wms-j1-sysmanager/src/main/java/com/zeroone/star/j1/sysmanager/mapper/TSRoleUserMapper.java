package com.zeroone.star.j1.sysmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.j1.sysmanager.entity.TSRoleUser;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 角色用户 Mapper 接口
 * </p>
 *
 * @author liyunyi
 * @since 2025-02-19
 */
@Mapper
public interface TSRoleUserMapper extends BaseMapper<TSRoleUser> {

    @Delete("DELETE FROM t_s_role_user WHERE userid = #{userId} and roleid = #{roleId}")
    Boolean deleteRoleUser(String roleId, String userId);

    @Insert("INSERT INTO `zo_wms`.`t_s_role_user` (`ID`, `roleid`, `userid`) VALUES (#{id},#{roleId},#{userId})")
    Boolean insertRoleUser(String id,String roleId, String userId);
}