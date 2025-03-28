package com.zeroone.star.project.dto.j7.taskconfirm;

import io.swagger.annotations.Api;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * <p>
 * 描述：修改任务DTO
 * </p>
 *
 * @author zjx
 * @since 2025/2/23
 */
@ApiModel("修改任务")
@Data
public class ModifyTaskDTO {
    @ApiModelProperty(value = "id",example = "2c9efaca91697e9801927c3522be4e0e")
    private String id;
    @ApiModelProperty(value = "任务接收人",example = "cangku001")
    private String assignTo; //i表
    @ApiModelProperty(value = "生产日期",example = "2024-03-20")
    private String proData; //i表
    @ApiModelProperty(value = "托盘",example = "100")
    private String tinId; // i表
    @ApiModelProperty(value = "仓位",example = "2")
    private String binId; // i表
    @ApiModelProperty(value = "基本单位数量",example = "9.0")
    private String baseGoodsCount;
    @ApiModelProperty(value = "数量",example = "9.0")
    private String qmOkQuat;
    @ApiModelProperty("备注")
    private String itemText;

}
