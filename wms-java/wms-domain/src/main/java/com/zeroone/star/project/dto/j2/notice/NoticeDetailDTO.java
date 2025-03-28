package com.zeroone.star.project.dto.j2.notice;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.util.Date;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("获取消息详情")
public class NoticeDetailDTO implements Serializable {

    /**
     * 消息标题
     */
    @ApiModelProperty(value = "消息标题", example = "YYY-有限公司的测试消息")
    private String noticeTitle;

    /**
     * 消息内容
     */
    @ApiModelProperty(value = "消息内容", example = "YYY-有限责任公司的订单QTRK2024将于2024.12.10发货")
    private String noticeContent;

    /**
     * 消息创建时间
     */
    @ApiModelProperty(value = "消息创建时间", example = "2024.12.10 04:45:50.0")
    private Date createTime;
}
