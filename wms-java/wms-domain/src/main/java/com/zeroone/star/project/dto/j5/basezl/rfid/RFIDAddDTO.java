package com.zeroone.star.project.dto.j5.basezl.rfid;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * 功能：
 * 作者：蕉太狼殿下
 * 日期：2025/2/22 16:32
 */
@ToString
@Getter
@Setter
@ApiModel("RFID录入数据模型")
public class RFIDAddDTO extends RFIDBaseDTO {
    @ApiModelProperty(value = "RFID2", example = "bbb")
    private String rfidId2;
    @ApiModelProperty(value = "RFID3", example = "ccc")
    private String rfidId3;
}