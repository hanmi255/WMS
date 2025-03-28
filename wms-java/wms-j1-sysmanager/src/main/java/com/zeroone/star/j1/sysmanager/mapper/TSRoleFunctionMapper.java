package com.zeroone.star.j1.sysmanager.mapper;

import com.zeroone.star.j1.sysmanager.entity.TSRoleFunction;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 * InnoDB free: 599040 kB; (`roleid`) REFER `jeecg/t_s_role`(`I Mapper 接口
 * </p>
 *
 * @author qpz
 * @since 2025-03-02
 */
@Mapper
public interface TSRoleFunctionMapper {
    @Select("SELECT functionid FROM t_s_role_function WHERE roleid = #{roleId}")
    List<TSRoleFunction> selectByRoleId(String roleId);

    @Delete("DELETE FROM t_s_role_function WHERE roleId = #{roleId}")
    int deleteByRoleId(String roleId);

    @Insert("INSERT INTO t_s_role_function (ID, roleid, functionid, operation, datarule) " +
            "VALUES (#{id}, #{roleid}, #{functionid}, #{operation}, #{datarule})")
    int insert(TSRoleFunction roleFunction);
}