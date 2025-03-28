package com.zeroone.star.project.dto.j2.msgmw;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Pattern;

@Data
@ApiModel("业务配置数据传输对象")
public class TSSmsTemplateSqlDTO {
    @ApiModelProperty(value = "配置的唯一id,可以不展示", required = true,
            example = "4028b8815ddbca3a015ddbfc67d1000a")
    @NotBlank(message = "配置id不能为空")
    private String id;          //配置的唯一id

    @ApiModelProperty(value = "配置CODE", required = true, example = "JKRQ01")
    @NotBlank(message = "配置CODE不能为空")
    private String code;         // 配置CODE

    @ApiModelProperty(value = "配置名称", required = true, example = "入库预约通知")
    @NotBlank(message = "配置名称不能为空")
    private String name;         // 配置名称

    @ApiModelProperty(value = "业务SqlID", required = true, example = "1")
    @Pattern(regexp = "^[1-3]$", message = "业务SqlID必须是1、2或3")
    @NotNull(message = "业务SqlID不能为空")
    private String sqlId;        // 业务SqlID

    @ApiModelProperty(value = "消息模板ID", required = true, example = "3")
    @Pattern(regexp = "^[1-3]$", message = "业务SqlID必须是1、2或3")
    @NotNull(message = "消息模板ID不能为空")
    private String templateId;   // 消息模板ID
}
