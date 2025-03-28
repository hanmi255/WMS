package com.zeroone.star.project.query.j2.msgmw;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

@Data
@ApiModel("业务配置数据查询对象")
public class TSSmsTemplateSqlQuery {
    @ApiModelProperty(value = "查询配置CODE", example = "JKRQ01")
    private String configCode;       // 配置CODE
    @ApiModelProperty(value = "查询配置名称", example = "入库预约通知")
    private String configName;       // 配置名称
    @ApiModelProperty(value = "创建起始日期范围", example = "2012-03-01 00:00:00")
    private Date createDateStart;    // 创建起始日期范围
    @ApiModelProperty(value = "创建结束日期范围", example = "2025-03-01 00:00:00")
    private Date createDateEnd;      // 创建结束日期范围
}
