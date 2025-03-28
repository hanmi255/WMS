package com.zeroone.star.oauth2.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.oauth2.entity.TSFunction;
import com.zeroone.star.oauth2.mapper.TSFunctionMapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.oauth2.service.ITSFunctionService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 菜单管理 服务实现类
 * </p>
 *
 * @author nefertari
 * @since 2025-02-25
 */
@Service
public class TSFunctionServiceImpl extends ServiceImpl<TSFunctionMapper, TSFunction> implements ITSFunctionService {

    @Autowired
    TSFunctionMapper functionMapper;

    /**
     * 获取所有菜单的url
     */
    @Override
    public List<TSFunction> listAllLinkUrl() {
        // 构造查询条件
        LambdaQueryWrapper<TSFunction> wrapper = new LambdaQueryWrapper<>();
        wrapper.select(TSFunction::getFunctionurl).isNotNull(TSFunction::getFunctionurl).eq(TSFunction::getFunctiontype, 1);
        // 返回查询结果
        return functionMapper.selectList(wrapper);
    }
}
