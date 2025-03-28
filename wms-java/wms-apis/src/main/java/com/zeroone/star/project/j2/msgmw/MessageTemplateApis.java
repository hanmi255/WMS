package com.zeroone.star.project.j2.msgmw;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.msgmw.MessageTemplateDTO;
import com.zeroone.star.project.dto.j2.msgmw.MessageTemplateListDTO;
import com.zeroone.star.project.query.j2.msgmw.MessageTemplateQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.servlet.http.HttpServletRequest;
import java.util.List;

public interface MessageTemplateApis {

    /**
     * 获取消息模板名称列表,每条数据包含（名称，编码，唯一标识等），用于表单输入，下拉列表与仓库列表一样
     *
     *
     * @return 消息模板名称列表
     */

    @ApiOperation(value = "获取消息模板名称列表")
    JsonVO<List<MessageTemplateListDTO>> getAllTemplateNames();

    /**
     * 获取消息模板列表（带条件和分页），列表中每条数据都包含一条完整数据，可以用查看或修改时候填充表单
     *
     * @param query 查询条件
     * @return 消息模板 DTO 列表
     */

    @ApiOperation(value = "获取消息模板列表（带条件和分页）")
    JsonVO<PageDTO<MessageTemplateDTO>> getMessageTemplates(@RequestBody MessageTemplateQuery query);

    /**
     * 录入新的消息模板
     *
     * @param messageTemplateDTO 消息模板 DTO
     * @return 是否成功
     */

    @ApiOperation(value = "录入新的消息模板")
    JsonVO<Boolean> addMessageTemplate(@RequestBody MessageTemplateDTO messageTemplateDTO, HttpServletRequest httpServletRequest);

    /**
     * 修改已存在的消息模板
     *
     * @param messageTemplateDTO 消息模板 DTO
     * @return 是否成功
     */

    @ApiOperation(value = "修改已存在的消息模板")
    JsonVO<Boolean> updateMessageTemplate(@RequestBody MessageTemplateListDTO messageTemplateDTO);

    /**
     * 删除消息模板（支持批量）
     *
     * @return 是否成功
     */

    @ApiOperation(value = "删除消息模板（支持批量）")
    JsonVO<Object> deleteMessageTemplates(@RequestBody List<MessageTemplateDTO> messageTemplateDTOs);
}
