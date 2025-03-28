package com.zeroone.star.project.dto.j7.taskconfirm;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import javax.validation.constraints.NotNull;
import javax.validation.constraints.Size;

@ApiModel
@Data
public class WaveGenDTO {
    @ApiModelProperty(value = "任务id(逗号隔开)",example = "123,234,567")
            @NotNull(message = "ids集合不能为空")

    String ids;
}
