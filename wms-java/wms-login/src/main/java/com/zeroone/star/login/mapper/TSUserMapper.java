package com.zeroone.star.login.mapper;


import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.login.entity.TSUser;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 系统用户扩展 Mapper 接口
 * </p>
 *
 * @author nefertari
 * @since 2025-02-25
 */
@Mapper
public interface TSUserMapper extends BaseMapper<TSUser> {

    // 通过用户名查询用户信息
    TSUser selectUserMesssageByUsername(String username);
}
