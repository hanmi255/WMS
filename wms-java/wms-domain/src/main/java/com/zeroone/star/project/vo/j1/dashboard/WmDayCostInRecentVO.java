package com.zeroone.star.project.vo.j1.dashboard;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述：每天费用合计统计显示数据对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author yunyu
 * @version 1.0.0
 */
@ApiModel("每天费用合计对象")
@Getter
@Setter
@ToString
public class WmDayCostInRecentVO {

    @ApiModelProperty(value = "每日费用", example = "10000")
    private String dayCostYj;

    @ApiModelProperty(value = "费用日期", example = "2025-1-23")
    private String costData;
}
