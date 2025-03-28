package com.zeroone.star.project.query.j5.basezl.cusother;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述: 第三方客户信息查询对象
 * </p>
 * <p>版权所有: &copy;枢璇</p>
 *
 * @author 枢璇
 * @Version 1.0.0
 * @since 2025/2/22 21:51
 */
@ToString
@Getter
@Setter
@ApiModel("第三方客户信息查询对象")
public class CusOtherQuery extends PageQuery {

    @ApiModelProperty(value = "所属客户", example = "01-star")
    private String suoShuKeHu;

    @ApiModelProperty(value = "中文全称", example = "零壹星球")
    private String zhongWenQch;

    @ApiModelProperty(value = "客户编码", example = "01STAR")
    private String keHuBianMa;
}