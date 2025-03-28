package com.zeroone.star.oauth2.service;

import com.zeroone.star.oauth2.entity.TSFunction;
import com.baomidou.mybatisplus.extension.service.IService;

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

    // 获取所有菜单的url
    List<TSFunction> listAllLinkUrl();
}
