package com.zeroone.star.project.vo.j2.msgmw;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

@Data
@ApiModel("业务配置数据前端展示对象")
public class TSSmsTemplateSqlVO {
    @ApiModelProperty(value = "配置的唯一id,可以不展示",
            example = "4028b8815ddbca3a015ddbfc67d1000a")
    private String id;          //配置的唯一id
    @ApiModelProperty(value = "配置CODE", example = "JKRQ01")
    private String code;         // 配置CODE
    @ApiModelProperty(value = "配置名称", example = "入库预约通知")
    private String name;         // 配置名称
    @ApiModelProperty(value = "业务SqlID", example = "1")
    private String sqlId;        // 业务SqlID
    @ApiModelProperty(value = "消息模板ID", example = "3")
    private String templateId;   // 消息模板ID
    @ApiModelProperty(value = "消息模板创建时间", example = "2017-08-13")
    private Date createDate;     // 创建日期
}
