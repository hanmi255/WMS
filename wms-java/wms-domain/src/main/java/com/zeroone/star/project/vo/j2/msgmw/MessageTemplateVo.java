package com.zeroone.star.project.vo.j2.msgmw;

import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;

@Data
public class MessageTemplateVo implements Serializable {
    /**
     * 模板 ID
     */
    @ApiModelProperty(value = "模板 ID", example = "1")
    private Long id;

    /**
     * 模板名称
     */
    @ApiModelProperty(value = "模板名称", example = "订单发货提醒")
    private String templateName;

    /**
     * 模板内容
     */
    @ApiModelProperty(value = "模板内容", example = "您的订单将在 {date} 发货")
    private String templateContent;

    /**
     * 模板类型
     */
    @ApiModelProperty(value = "模板类型", example = "EMAIL")
    private String type;


}

