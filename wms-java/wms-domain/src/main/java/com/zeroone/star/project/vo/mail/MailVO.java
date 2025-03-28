package com.zeroone.star.project.vo.mail;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.format.annotation.DateTimeFormat;

import java.util.Date;

/**
 * <p>
 * 描述：书写一个邮件发送结果显示数据模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Data
@ApiModel("邮件发送结果显示数据对象")
public class MailVO {
    @ApiModelProperty(value = "发送时间", example = "2024-11-21", required = true)
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ssS")
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ssS")
    private Date sentDate;
    @ApiModelProperty(value = "状态", example = "ok或fail", required = true)
    private String status;
    @ApiModelProperty(value = "错误信息", example = "错误信息")
    private String error;
}
