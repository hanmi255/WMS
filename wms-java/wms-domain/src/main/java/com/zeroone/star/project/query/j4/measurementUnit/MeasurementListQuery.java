package com.zeroone.star.project.query.j4.measurementUnit;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @author adi
 *Description 获取单位列表的条件
 * #Date: 2025/2/23 21:44
 */
@ToString
@Getter
@Setter
@ApiModel("获取单位列表的条件")
public class MeasurementListQuery extends PageQuery {

    @ApiModelProperty(value = "单位代码", example = "个")
    private String unitCode;

    @ApiModelProperty(value = "单位名称", example = "个")
    private String unitZhName;

    @ApiModelProperty(value = "英文名称", example = "piece")
    private String unitEnName;

}
