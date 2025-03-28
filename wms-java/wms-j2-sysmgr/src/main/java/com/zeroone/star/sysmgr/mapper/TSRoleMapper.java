package com.zeroone.star.sysmgr.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.sysmgr.entity.TSNotice;
import com.zeroone.star.sysmgr.entity.TSRole;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * 针对TSRole表操作
 */
@Mapper
public interface TSRoleMapper extends BaseMapper<TSRole> {

    List<TSRole> selectListByIds(List<String> roleIds);
}




