package com.zeroone.star.j1.sysmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.j1.sysmanager.entity.TSRole;
import com.zeroone.star.j1.sysmanager.entity.TSBaseUser;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 *  Mapper �ӿ�
 * </p>
 *
 * @author PingShui
 * @since 2025-02-27
 * @author lgl
 * 2025年03月02日 16:59
 */
@Mapper
public interface TSRoleMapper extends BaseMapper<TSRole> {
    @Select("select * from t_s_base_user where ID = #{id}")
    TSBaseUser selectBaseUserById(String id);

    List<TSRole> selectAllRoles();

    @Select("SELECT ID AS id FROM t_s_role WHERE rolecode = #{roleCode}")
    TSRole selectByRoleCode(String roleCode);

    @Delete("delete from t_s_role_function where roleid = #{id}")
    void deleteRoleFunction(String id);

    @Delete("delete from t_s_role_user where roleid = #{id}")
    void deleteRoleUser(String id);
}
