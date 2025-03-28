package com.zeroone.star.project.vo.j1.dashboard;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述：每天的总上架数量显示数据对象
 * 该VO的字段命名要与mapper中sql起的别名要一致否则无法映射
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author yunyu
 * @version 1.0.0
 */
@ApiModel("当天货物上架数量显示对象")
@Getter
@Setter
@ToString
public class GoodsUpInRecentVO {

    @ApiModelProperty(value = "当天上架总商品数量", example = "200")
    private String totalGoodsUpQua;

    @ApiModelProperty(value = "日期", example = "2025-1-23")
    private String createDateDay;
}
