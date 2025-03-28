package com.zeroone.star.project.dto.j2.notice;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import java.io.Serializable;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("获取消息标题列表")
public class NoticeTitleDTO implements Serializable {
    /**
     * 消息标题
     */
    @ApiModelProperty(value = "测试通知", example = "YYY-有限公司的测试消息")
    private String noticeTitle;

    /**
     * 公告id
     */
    @ApiModelProperty(value = "公告id",example = "1")
    private String noticeId;
}
