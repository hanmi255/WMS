package com.zeroone.star.project.dto.j7.taskconfirm;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：批量设置接收人
 * </p>
 *
 * @author zjx
 * @since 2025/2/23
 */

@ApiModel("批量设置接收人")
@Data
public class BatchSetRecipientsDTO {
    @ApiModelProperty("任务ID")
    private String taskId;
    @ApiModelProperty("任务接收人")
    private String assignTo;
}
