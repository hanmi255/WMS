package com.zeroone.star.project.dto.j2.message;

import com.zeroone.star.project.constant.MessageTags;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @Author: dashuai
 * @Description: websocket传输消息需要的dto
 */
@ApiModel("websocket传输消息需要的dto")
@Data
public class WsRqMsgDto {
    @ApiModelProperty(value = "目标户端id", example = "123 || all")
    private String target;
    @ApiModelProperty(value = "消息类型", example = "LOGIN || ANNOUNCEMENT || MESSAGE || LOGOUT")
    private String messageType;
    @ApiModelProperty(value = "消息内容", example = "YYY-有限责任公司的订单QTRK2024将于2024.12.10发货")
    private String content;
}
