package com.zeroone.star.login.mapper;


import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.login.entity.TSFunction;
import com.zeroone.star.project.vo.login.FunctionTreeVO;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

/**
 * <p>
 * 菜单管理 Mapper 接口
 * </p>
 *
 * @author nefertari
 * @since 2025-02-25
 */
@Mapper
public interface TSFunctionMapper extends BaseMapper<TSFunction> {

    // 通过角色查询菜单
    List<FunctionTreeVO> selectFunctionsByRoleName(String roleName);
}
