package com.zeroone.star.project.dto.j5.basezl.rfid;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * 功能：
 * 作者：蕉太狼殿下
 * 日期：2025/2/22 16:31
 */
@ToString
@Getter
@Setter
@ApiModel("RFID基础数据模型")
public class RFIDBaseDTO {
    @ApiModelProperty(value = "创建人登记名称", example = "大江大河有限公司")
    private String createName;
    @ApiModelProperty(value = "类型", example = "weight")
    private String rfidType;
    @ApiModelProperty(value = "业务编号", example = "1")
    private String rfidBuseno;
    @ApiModelProperty(value = "RFID1", example = "aaa")
    private String rfidId1;
    @ApiModelProperty(value = "业务内容", example = "20.02")
    private String rfidBusecont;
}