package com.zeroone.star.msgmw.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.core.toolkit.StringUtils;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.msgmw.entity.TSSmsTemplateSql;
import com.zeroone.star.msgmw.mapper.TSSmsTemplateSqlMapper;
import com.zeroone.star.msgmw.service.ITSSmsTemplateSqlService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.msgmw.TSSmsTemplateSqlAddDTO;
import com.zeroone.star.project.dto.j2.msgmw.TSSmsTemplateSqlDTO;
import com.zeroone.star.project.query.j2.msgmw.TSSmsTemplateSqlQuery;
import com.zeroone.star.project.vo.j2.msgmw.TSSmsTemplateSqlVO;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;


/**
 * <p>
 * 消息模板配置 服务实现类
 * </p>
 *
 * @author qunzhong
 * @since 2025-02-21
 */
@Service
@Slf4j
public class TSSmsTemplateSqlServiceImpl extends ServiceImpl<TSSmsTemplateSqlMapper, TSSmsTemplateSql> implements ITSSmsTemplateSqlService {
    @Resource
    UserHolder userHolder;

    @Autowired
    TSSmsTemplateSqlMapper templateSqlMapper;

    @Override
    public void add(TSSmsTemplateSqlAddDTO templateSqlAddDTO) throws Exception {
        TSSmsTemplateSql templateSql = new TSSmsTemplateSql();
        BeanUtils.copyProperties(templateSqlAddDTO, templateSql);
        //获取并设置用户信息
        UserDTO currentUser = userHolder.getCurrentUser();
        if (currentUser == null) {
            throw new Exception("当前用户信息不可用");
        }
        templateSql.setCreateBy(String.valueOf(currentUser.getId()));
        templateSql.setCreateName(currentUser.getUsername());
        templateSql.setCreateDate(LocalDateTime.now());

        templateSqlMapper.insert(templateSql);
    }

    @Transactional
    @Override
    public void update(TSSmsTemplateSqlDTO templateSqlDTO) throws Exception {
        TSSmsTemplateSql templateSql = new TSSmsTemplateSql();
        BeanUtils.copyProperties(templateSqlDTO, templateSql);
        //获取并设置用户信息
        UserDTO currentUser = userHolder.getCurrentUser();
        if (currentUser == null) {
            throw new Exception("当前用户信息不可用");
        }
        templateSql.setUpdateBy(String.valueOf(currentUser.getId()));
        templateSql.setUpdateName(currentUser.getUsername());
        templateSql.setUpdateDate(LocalDateTime.now());
        //更新表
        UpdateWrapper<TSSmsTemplateSql> updateWrapper = new UpdateWrapper<>();
        //这里要求前端传入所有必要的字段，无论该属性是否被更改
        //如果前端说只传被改过的，那就用if判断空值，并修改DTO中的合法性限制
        updateWrapper.eq("id", templateSql.getId())
                        .set("code", templateSql.getCode())
                        .set("name", templateSql.getName())
                        .set("sql_id", templateSql.getSqlId())
                        .set("template_id", templateSql.getTemplateId())
                        .set("update_by", templateSql.getUpdateBy())
                        .set("update_name", templateSql.getUpdateName())
                        .set("update_date", templateSql.getUpdateDate());

        templateSqlMapper.update(null, updateWrapper);
    }

    @Transactional
    @Override
    public void delete(List<Long> idList) {
        templateSqlMapper.deleteBatchIds(idList);
    }

    @Override
    public PageDTO<TSSmsTemplateSqlVO> query(
            TSSmsTemplateSqlQuery templateQuery, int page, int size) {
        //构建分页条件和查询条件
        Page<TSSmsTemplateSql> pageObj = new Page<>(page, size);
        LambdaQueryWrapper<TSSmsTemplateSql> wrapper = new LambdaQueryWrapper<>();
        if(templateQuery != null){
            if(StringUtils.isNotEmpty(templateQuery.getConfigCode()))
                wrapper.like(TSSmsTemplateSql::getCode, templateQuery.getConfigCode());
            if(StringUtils.isNotEmpty(templateQuery.getConfigName()))
                wrapper.like(TSSmsTemplateSql::getName, templateQuery.getConfigName());
            if(templateQuery.getCreateDateStart() != null)
                wrapper.ge(TSSmsTemplateSql::getCreateDate, templateQuery.getCreateDateStart());
            if(templateQuery.getCreateDateEnd() != null)
                wrapper.le(TSSmsTemplateSql::getCreateDate, templateQuery.getCreateDateEnd());
        }
        //查询
        try {
            Page<TSSmsTemplateSql> resultPage = page(pageObj, wrapper);
            return PageDTO.create(resultPage, TSSmsTemplateSqlVO.class);
        } catch (Exception e) {
            throw new RuntimeException("查询业务配置失败: " + e.getMessage());
        }

    }


}
