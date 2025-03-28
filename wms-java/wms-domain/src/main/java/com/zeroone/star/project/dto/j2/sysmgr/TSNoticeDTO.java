package com.zeroone.star.project.dto.j2.sysmgr;


import cn.hutool.core.date.DateTime;
import com.baomidou.mybatisplus.annotation.TableName;
import com.zeroone.star.project.dto.PageDTO;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;
import java.util.Date;

@Data
@AllArgsConstructor
@ApiModel("系统通知对象")
@NoArgsConstructor
@TableName("t_s_notice")
public class TSNoticeDTO  {

    @ApiModelProperty(value = "id",example = "1")
    private String id;

    @ApiModelProperty(value = "通知标题",example = "通知标题1")
    private String noticeTitle;

    @ApiModelProperty(value = "通知公告内容",example = "[内容1]")
    private String noticeContent;
    @ApiModelProperty(value = "通知公告类型",example = "1")
    private String noticeType;

    @ApiModelProperty(value = "通知授权级别",example = "1")
    private String noticeLevel;


    @ApiModelProperty(value = "阅读期限",example = "2025-10-15 10:00:00")
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    private LocalDateTime noticeTerm;



}
