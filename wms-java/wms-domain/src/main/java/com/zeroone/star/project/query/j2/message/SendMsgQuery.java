package com.zeroone.star.project.query.j2.message;

import com.zeroone.star.project.components.sms.aliyun.SmsComponent;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.annotation.Resource;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Pattern;

/**
 * @author Henry
 */
@Data
@ApiModel("发送短信消息对象")
public class SendMsgQuery {
    @Pattern(regexp = "^(?:\\+?86)?1[3-9]\\d{9}|\\+?[1-9]\\d{1,14}$")
    @ApiModelProperty(value = "手机号",example = "15012341234")
    private String phone;
    @NotNull
    @ApiModelProperty(value = "消息内容",example = "这是一条消息")
    private String message;
}
