package com.zeroone.star.sysmgr.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.sysmgr.entity.TSNotice;
import com.zeroone.star.sysmgr.entity.TSRoleOrg;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * 针对TSRoleOrg表的操作
 */
@Mapper
public interface TSRoleOrgMapper extends BaseMapper<TSRoleOrg> {

    List<String> selectRoleIdsByOrgId(String orgId);

    void deleteByOrgId(String orgId);

    void batchInsert(List<TSRoleOrg> list);
}




