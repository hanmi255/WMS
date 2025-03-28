package com.zeroone.star.project.dto.j2.notice;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.io.Serializable;
import java.util.Date;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class NoticeListDTO implements Serializable {

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
    @JsonFormat(shape = JsonFormat.Shape.STRING, pattern = "yyyy-MM-dd HH:mm:ss")
    private Date noticeTime;

    /**
     * 公告是否阅读
     */
    @ApiModelProperty(value = "是否阅读", example = "0未阅读,1已阅读")
    private Integer isRead;

    /**
     * 公告id
     */
    @ApiModelProperty(value = "公告id", example = "1")
    private String noticeId;
}
