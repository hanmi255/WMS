package com.zeroone.star.j1.sysmanager.mapper;

import com.zeroone.star.j1.sysmanager.entity.TSIcon;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author qpz
 * @since 2025-03-02
 */
@Mapper
public interface TSIconMapper {

    @Select("SELECT ID, iconclas, path FROM t_s_icon")
    List<TSIcon> selectIcons();
}
