package com.zeroone.star.oauth2.mapper;

import com.zeroone.star.oauth2.entity.TSRole;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 角色信息 Mapper 接口
 * </p>
 *
 * @author nefertari
 * @since 2025-02-25
 */
@Mapper
public interface TSRoleMapper extends BaseMapper<TSRole> {


    /**
     * 根据用户id查询角色
     * @param id 用户id
     */
    List<TSRole> selectRoleByUserId(String id);

    /**
     * 获取菜单对应的角色
     */
    List<TSRole> selectRoleByFunctionUrl(String functionurl);
}
