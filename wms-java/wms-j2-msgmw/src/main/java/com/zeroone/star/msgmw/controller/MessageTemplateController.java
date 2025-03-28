package com.zeroone.star.msgmw.controller;

import com.zeroone.star.msgmw.service.impl.TSSmsTemplateServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.msgmw.MessageTemplateDTO;
import com.zeroone.star.project.dto.j2.msgmw.MessageTemplateListDTO;
import com.zeroone.star.project.j2.msgmw.MessageTemplateApis;
import com.zeroone.star.project.query.j2.msgmw.MessageTemplateQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.servlet.http.HttpServletRequest;
import java.util.List;

/**
 * 消息模板控制器类
 */
@RestController
@RequestMapping("/msgmw")
@Api(tags = "消息模板")
public class MessageTemplateController implements MessageTemplateApis {

    @Autowired
    private TSSmsTemplateServiceImpl tSSmsTemplateService;  // 注入服务层

    @Override
    @GetMapping("/get-messageTemplateName-list" )
    @ApiOperation(value = "获取消息模板名称列表")
    public JsonVO<List<MessageTemplateListDTO>> getAllTemplateNames() {
        try {
            // 调用服务层方法获取模板名称
            List<MessageTemplateListDTO> templateList = tSSmsTemplateService.getAllTemplateNames();
            return JsonVO.success(templateList);
        } catch (Exception e) {
            String errorMessage = "获取消息模板名称列表失败: " + e.getMessage();
            return JsonVO.create(null, 404, errorMessage);
        }
    }


    @Override
    @GetMapping("/page-messageTemplate-list")
    @ApiOperation(value = "获取消息模板详细信息")
    public JsonVO<PageDTO<MessageTemplateDTO>> getMessageTemplates(MessageTemplateQuery query) {
        try {
            // 调用服务层方法获取分页消息模板
            PageDTO<MessageTemplateDTO> page = tSSmsTemplateService.getMessageTemplates(query);
            return JsonVO.success(page);
        } catch (Exception e) {
            String errorMessage = "获取消息模板名称列表失败: " + e.getMessage();
            return JsonVO.create(null, 404, errorMessage);
        }
    }

    @Override
    @PostMapping("/add-messageTemplate")
    @ApiOperation(value = "录入消息模板")
    public JsonVO<Boolean> addMessageTemplate(@RequestBody MessageTemplateDTO messageTemplateDTO,HttpServletRequest request) {
        Boolean save = null;
        try {
            if (messageTemplateDTO == null) { return JsonVO.fail(save);}
            // 调用服务层方法录入新消息模板
            save = tSSmsTemplateService.addMessageTemplate(messageTemplateDTO, request);
            return JsonVO.success(save);
        }catch (Exception e) {
            return JsonVO.fail(save);
        }
    }

    @Override
    @PutMapping("/update-messageTemplate")
    @ApiOperation(value = "修改消息模板")
    public JsonVO<Boolean> updateMessageTemplate(@RequestBody MessageTemplateListDTO messageTemplateDTO) {
        Boolean save = null;
        try {
            if (messageTemplateDTO == null) { return JsonVO.fail(save);}
            // 调用服务层方法录入新消息模板
            save = tSSmsTemplateService.updateMessageTemplate(messageTemplateDTO);
            return JsonVO.success(save);
        }catch (Exception e) {
            return JsonVO.fail(save);
        }
    }

    @Override
    @DeleteMapping("/delete-messageTemplate")
    @ApiOperation(value = "删除消息模板，通过勾选对应的消息模版删除(可多项勾选)")
    public JsonVO<Object> deleteMessageTemplates(@RequestBody List<MessageTemplateDTO> messageTemplateDTOs) {
        try {
            // 调用服务层方法删除消息模板
            if(messageTemplateDTOs!=null)
            tSSmsTemplateService.deleteMessageTemplates(messageTemplateDTOs);
            else return JsonVO.fail("删除消息模板失败: ");
            return JsonVO.success("消息模板删除成功");
        } catch (Exception e) {
            return JsonVO.fail("删除消息模板失败: ");
        }
    }
}


