package com.zeroone.star.project.dto.j5.basezl.cusother;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述: 第三方客户录入数据模型
 * </p>
 * <p>版权所有: &copy;枢璇</p>
 *
 * @author 枢璇
 * @Version 1.0.0
 * @since 2025/2/22 22:18
 */
@Getter
@Setter
@ToString
@ApiModel("第三方客户录入数据模型")
public class CusOtherAddDTO extends CusOtherBaseDTO{
    @ApiModelProperty(value = "首签日期", example = "2025-02-22 21:46:17")
    private String shouQianRiQi;

    @ApiModelProperty(value = "申请时间", example = "2025-02-22 21:47:17")
    private String shenQingShiJian;

    @ApiModelProperty(value = "批准机关", example = "北京市工商局")
    private String piZhunJiGuan;

    @ApiModelProperty(value = "批准文号", example = "京工商批字[2025]第0001号")
    private String piZhunWenHao;
}
