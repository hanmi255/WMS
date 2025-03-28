package com.zeroone.star.msgmw.service.impl;

import com.alibaba.cloud.commons.lang.StringUtils;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.msgmw.entity.TSSmsTemplate;
import com.zeroone.star.msgmw.mapper.TSSmsTemplateMapper;
import com.zeroone.star.msgmw.service.ITSSmsTemplateService;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.msgmw.MessageTemplateDTO;
import com.zeroone.star.project.dto.j2.msgmw.MessageTemplateListDTO;
import com.zeroone.star.project.query.j2.msgmw.MessageTemplateQuery;
import org.springframework.stereotype.Service;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.context.annotation.RequestScope;

import javax.servlet.http.HttpServletRequest;
import java.util.Date;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;
@RequestScope
@Service
public class TSSmsTemplateServiceImpl extends ServiceImpl<TSSmsTemplateMapper, TSSmsTemplate> implements ITSSmsTemplateService {

    @Autowired
    private TSSmsTemplateMapper tSSmsTemplateMapper;

    @Autowired
    private UserHolder userHolder;
    // 获取所有消息模板名称

    public List<MessageTemplateListDTO> getAllTemplateNames() {
        List<TSSmsTemplate> templates = this.list();  // MyBatis-Plus 提供的获取所有数据的方法
        return templates.stream()
                .map(template -> MessageTemplateListDTO.builder()
                        .id(Integer.valueOf(template.getId()))
                        .templateName(template.getTemplateName())
                        .type(template.getTemplateType())
                        .templateContent(template.getTemplateContent())
                        .build())
                .collect(Collectors.toList());
    }

    // 获取消息模板的详细信息，分页查询
    public PageDTO<MessageTemplateDTO> getMessageTemplates(MessageTemplateQuery query) {
        // 创建分页查询对象
        Page<TSSmsTemplate> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<TSSmsTemplate> wrapper = new QueryWrapper<>();

        // 如果有模板名称条件，加入查询条件
        if (query.getTemplateName() != null && !query.getTemplateName().isEmpty()) {
            wrapper.like("template_name", query.getTemplateName());
        }
        // 如果有模板类型条件，加入查询条件
        if (query.getType() != null && !query.getType().isEmpty()) {
            wrapper.eq("template_type", query.getType());  // 这里假设数据库字段是 `template_type`
        }
        if (query.getId() != null) {
            wrapper.eq("template_id", query.getId());
        }
        // 执行分页查询
        Page<TSSmsTemplate> resultPage = this.page(page, wrapper);
        // 将查询结果转换为 DTO
        List<MessageTemplateDTO> templateDTOList = resultPage.getRecords().stream()
                .map(template -> new MessageTemplateDTO(
                        template.getTemplateName(),
                        template.getTemplateContent(),
                        template.getTemplateType()
                ))
                .collect(Collectors.toList());
        // 构建分页结果
        PageDTO<MessageTemplateDTO> pageDTO = new PageDTO<>();
        pageDTO.setTotal(resultPage.getTotal());  // 总条数
        pageDTO.setRows(templateDTOList);        // 当前页数据
        pageDTO.setPageIndex(resultPage.getCurrent());  // 当前页码
        pageDTO.setPageSize(resultPage.getSize());      // 每页条数
        pageDTO.setPages(resultPage.getPages());        // 总页数

        return pageDTO;
    }

    // 根据模板名称、模板类型和模板内容获取对应的模板ID
    public String getTemplateIdByNameTypeAndContent(String templateName, String templateType, String templateContent) {
        // 构建查询条件
        QueryWrapper<TSSmsTemplate> wrapper = new QueryWrapper<>();
        wrapper.eq("template_name", templateName)  // 模板名称匹配
                .eq("template_type", templateType)  // 模板类型匹配
                .eq("template_content", templateContent);  // 模板内容匹配

        // 执行查询
        TSSmsTemplate template = this.getOne(wrapper);  // 使用 getOne 获取匹配的唯一记录

        // 如果找到了对应的模板，返回模板ID
        if (template != null) {
            return template.getId();
        }
        // 如果没有找到匹配的模板，返回 null 或抛出异常，根据需求来定
        return null;
    }

    // 添加消息模板
    public boolean addMessageTemplate(MessageTemplateDTO messageTemplateDTO, HttpServletRequest httpServletRequest) {
        TSSmsTemplate template = new TSSmsTemplate();
        template.setTemplateName(messageTemplateDTO.getTemplateName());
        template.setTemplateContent(messageTemplateDTO.getTemplateContent());
        template.setTemplateType(messageTemplateDTO.getType());
        try {
            // 获取当前用户信息
            UserDTO currentUser = userHolder.getCurrentUser();
            // 如果成功获取当前用户，使用其信息
            if (currentUser != null) {
                template.setCreateBy(String.valueOf(currentUser.getId()));  // 当前用户的ID
                template.setCreateName(currentUser.getUsername());  // 当前用户名
            } else {
                // 如果没有找到用户信息，使用默认值
                template.setCreateBy("system");
                template.setCreateName("系统");
            }
        } catch (Exception e) {
            // 如果获取用户信息失败，使用默认值
            template.setCreateBy("system");
            template.setCreateName("系统");
        }
        template.setCreateDate(new Date());  // 当前时间
        // 保存模板
        return this.save(template);  // MyBatis-Plus 提供的保存方法
    }
    @Transactional
    public Boolean updateMessageTemplate(MessageTemplateListDTO messageTemplateDTO) {
        // 参数校验
        if (messageTemplateDTO == null || StringUtils.isEmpty(messageTemplateDTO.getTemplateName())
                || StringUtils.isEmpty(messageTemplateDTO.getTemplateContent())
                || StringUtils.isEmpty(messageTemplateDTO.getType())) {
            return false;
        }

        // 获取现有模板
        TSSmsTemplate template = this.getById(
                messageTemplateDTO.getId()
        );

        if (template != null) {
            // 更新模板内容
            template.setTemplateName(messageTemplateDTO.getTemplateName());
            template.setTemplateContent(messageTemplateDTO.getTemplateContent());
            template.setTemplateType(messageTemplateDTO.getType());

            // 设置更新用户信息
            try {
                UserDTO currentUser ;
                try {
                    currentUser = userHolder.getCurrentUser();
                } catch (Exception e) {
                    throw new RuntimeException(e);
                }
                if (currentUser != null) {
                    template.setUpdateBy(String.valueOf(currentUser.getId()));  // 当前用户的ID
                    template.setUpdateName(currentUser.getUsername());  // 当前用户名
                } else {
                    template.setUpdateBy("system");
                    template.setUpdateName("系统");
                }
            } catch (RuntimeException e) {
                // 如果获取用户信息失败，使用默认值
                log.error("获取当前用户信息失败", e);
                template.setUpdateBy("system");
                template.setUpdateName("系统");
            }

            // 更新模板
            return this.updateById(template);  // 或者返回最新的模板列表
        }
        return false;
    }


    public void deleteMessageTemplates(List<MessageTemplateDTO> messageTemplateDTOS) {
        // 提取 MessageTemplateDTO 列表中的模板名称、类型、内容并获取对应的模板 ID 列表
        List<String> ids = messageTemplateDTOS.stream()
                .map(dto -> getTemplateIdByNameTypeAndContent(dto.getTemplateName(), dto.getType(), dto.getTemplateContent()))
                .filter(Objects::nonNull)  // 过滤掉没有找到模板 ID 的情况
                .collect(Collectors.toList());

        // 使用 MyBatis-Plus 提供的 removeByIds 方法删除对应的模板
        if (!ids.isEmpty()) {
            this.removeByIds(ids);
        } else {
            // 如果没有找到需要删除的模板，可以选择抛出异常或者做其他处理
            throw new IllegalArgumentException("删除失败");
        }
    }
}


