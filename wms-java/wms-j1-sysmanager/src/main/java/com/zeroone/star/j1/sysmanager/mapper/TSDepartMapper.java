package com.zeroone.star.j1.sysmanager.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.j1.sysmanager.entity.TSDepart;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author PingShui
 * @since 2025-02-27
 */
@Mapper
public interface TSDepartMapper extends BaseMapper<TSDepart> {

    List<TSDepart> selectAllDeapatrment();
}
