package com.zeroone.star.project.query.j4.unitType;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;

/**
 * @author 1+5
 * @title UnitTypeQuery
 * @date 2025/2/23 21 27
 * @description 单位类型查询对象
 */

@Getter
@Setter
@ToString
@NoArgsConstructor
@AllArgsConstructor
public class UnitTypeListQuery extends PageQuery {

    @ApiModelProperty(value = "排序参考",example = "create_date")
    private String sort;

    @ApiModelProperty(value = "升序或降序",example = "desc")
    private String order;

}
