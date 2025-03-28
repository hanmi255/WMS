package com.zeroone.star.project.dto.j6.stockln;

import com.fasterxml.jackson.annotation.JsonFormat;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.time.LocalDateTime;

@ToString
@Getter
@Setter
@ApiModel("进货通知列表显示数据对象")
public class ImportNoticeListDTO extends ImportNoticeBaseDTO{

    @ApiModelProperty(value = "创建人名称", example = "管理员")
    private String createName;

    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ApiModelProperty(value = "创建日期", example = "2024-09-24 22:43:02")
    private LocalDateTime createDate;

    @ApiModelProperty(value = "单据状态", example = "已完成")
    private String imSta;

    @ApiModelProperty(value = "进货通知单号", example = "RK20240924-0001")
    private String noticeId;

    @ApiModelProperty(value="货主名",example="001-YYY-有限公司")
    private String cusName;
}
