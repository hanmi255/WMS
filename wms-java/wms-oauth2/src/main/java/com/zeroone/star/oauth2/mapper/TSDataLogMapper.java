package com.zeroone.star.oauth2.mapper;

import com.zeroone.star.oauth2.entity.TSDataLog;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 数据日志 Mapper 接口
 * </p>
 *
 * @author nefertari
 * @since 2025-02-27
 */
@Mapper
public interface TSDataLogMapper extends BaseMapper<TSDataLog> {

    //  通过用户名获取用户所属部门
    String selectOrgCodeByUserRealanme(String username);

    // 通过用户名获取用户所属公司
    String selectCompanyCodeByUserRealname(String username);
}
