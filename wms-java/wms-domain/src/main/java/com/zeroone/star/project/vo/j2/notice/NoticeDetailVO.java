package com.zeroone.star.project.vo.j2.notice;


import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

import java.util.Date;

/**
 * 描述：公告详情
 * @author heng
 */
@Data
@AllArgsConstructor
@NoArgsConstructor
public class NoticeDetailVO {

    @ApiModelProperty(value = "id")
    private String id;

    @ApiModelProperty(value = "通知标题")
    private String noticeTitle;

    @ApiModelProperty(value = "通知公告内容")
    private String noticeContent;

    @ApiModelProperty(value = "通知公告类型")
    private Integer noticeType;

    @ApiModelProperty(value = "阅读期限",required = true)
    private Date noticeTerm;

    @ApiModelProperty(value = "公告创建人姓名",required = true)
    private String createUser;

    @ApiModelProperty(value = "公告创建时间",required = true)
    private Date createTime;

}
