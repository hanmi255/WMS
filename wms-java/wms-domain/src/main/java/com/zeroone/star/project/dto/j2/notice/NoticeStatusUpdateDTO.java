package com.zeroone.star.project.dto.j2.notice;

import io.swagger.annotations.ApiModelProperty;
import io.swagger.models.auth.In;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
public class NoticeStatusUpdateDTO {

    @ApiModelProperty(value = "公告编号")
    private String noticeId;

    @ApiModelProperty(value = "是否阅读", example = "0未阅读,1已阅读")
    private Integer isRead;

    @ApiModelProperty(value = "是否删除", example = "0未删除,1已删除")
    private Integer delFlag;
}
