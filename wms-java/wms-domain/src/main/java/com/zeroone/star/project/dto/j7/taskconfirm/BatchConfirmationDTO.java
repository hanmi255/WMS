package com.zeroone.star.project.dto.j7.taskconfirm;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：批量确认任务
 * </p>
 *
 * @author zjx
 * @since 2025/2/23
 */
@ApiModel("批量确认任务")
@Data
public class BatchConfirmationDTO {
    @ApiModelProperty("任务id")
    private String taskId;
    @ApiModelProperty("是否已经下架")
    private String binSta;
}
