package com.zeroone.star.project.dto.j7.zccheck;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述：选择复核操作数据对象
 * </p>
 *
 * @author chen
 * @since 2025/2/25 17:08
 */

@Getter
@Setter
@ApiModel("选择复核单个对象")
@ToString
public class CheckDTO {

    @ApiModelProperty(value = "id",example = "1")
    private String id;

    @ApiModelProperty(value = "复核数量",example = "4")
    private String goodsQuaok;

    @ApiModelProperty(value = "原始单据编码",example = "QT20250925-0001")
    private String omNoticeId;
}
