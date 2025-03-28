package com.zeroone.star.project.query.j7.outbound;

import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@ToString
@Setter
@Getter
public class WonQuery {
    /**
     * 出货通知ID
     */
    @ApiModelProperty(value = "出货通知ID", example = "QT20241011-0001")
    private String omNoticeId;

}
