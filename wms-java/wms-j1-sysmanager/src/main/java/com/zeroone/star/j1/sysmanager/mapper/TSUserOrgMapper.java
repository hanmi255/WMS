package com.zeroone.star.j1.sysmanager.mapper;

import com.zeroone.star.j1.sysmanager.entity.TSUserOrg;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author halo
 * @since 2025-03-01
 */
@Mapper
public interface TSUserOrgMapper extends BaseMapper<TSUserOrg> {

    @Delete("DELETE FROM t_s_user_org WHERE user_id = #{userId}")
    void deleteByUserId(String userId);
}
