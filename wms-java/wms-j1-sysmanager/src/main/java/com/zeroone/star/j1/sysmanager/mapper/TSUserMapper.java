package com.zeroone.star.j1.sysmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.j1.sysmanager.entity.TSUser;
import com.zeroone.star.project.vo.j1.sysmanager.usermanager.UserDetailVO;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * InnoDB free: 599040 kB; (`id`) REFER `jeecg/t_s_base_user`(` Mapper 接口
 * </p>
 *
 * @author PingShui
 * @since 2025-02-24
 */
@Mapper
public interface TSUserMapper extends BaseMapper<TSUser> {

    UserDetailVO selectUserDetail(String userId);
}
