package com.zeroone.star.login.service;



import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.login.entity.TSFunction;
import com.zeroone.star.project.vo.login.FunctionTreeVO;

import java.util.List;

/**
 * <p>
 * 菜单管理 服务类
 * </p>
 *
 * @author nefertari
 * @since 2025-02-25
 */
public interface ITSFunctionService extends IService<TSFunction> {

    // 通过角色获取对应菜单
    List<FunctionTreeVO> listFunctionByRoleName(List<String> roleNames);
}
