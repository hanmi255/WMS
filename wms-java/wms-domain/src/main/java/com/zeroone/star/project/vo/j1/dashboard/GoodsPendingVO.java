package com.zeroone.star.project.vo.j1.dashboard;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述：货物待办统计显示数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author yunyu
 * @version 1.0.0
 */
@ApiModel("货物待办统计显示对象")
@Getter
@Setter
@ToString
public class GoodsPendingVO {

    @ApiModelProperty(value = "货物状态", example = "待收货")
    private String goodsStatus;

    @ApiModelProperty(value = "货物件数", example = "40")
    private String goodsNumber;



}
