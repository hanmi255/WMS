package com.zeroone.star.project.query.j5.basezl.rfid;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * 功能：RFID信息查询
 * 作者：蕉太狼殿下
 * 日期：2025/2/22 14:51
 */
@ToString
@Getter
@Setter
@ApiModel("RFID信息查询")
public class RFIDQuery extends PageQuery {
    @ApiModelProperty(value = "创建人登记名称", example = "大江大河有限公司")
    private String createName;
    @ApiModelProperty(value = "类型", example = "weight")
    private String Type;
    @ApiModelProperty(value = "业务编号", example = "1")
    private String buseCode;
    @ApiModelProperty(value = "RFID1", example = "aaa")
    private String rfid1;
    @ApiModelProperty(value = "业务内容", example = "20.02")
    private String buseContent;
}
