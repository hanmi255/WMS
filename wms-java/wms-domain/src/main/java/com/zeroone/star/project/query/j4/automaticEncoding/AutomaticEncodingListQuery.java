package com.zeroone.star.project.query.j4.automaticEncoding;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @author 1+5
 * @title UnitTypeQuery
 * @date 2025/2/23 21 27
 * @description 单位类型查询对象
 */

@Getter
@Setter
@ToString
@ApiModel("获取编码列表的条件")
public class AutomaticEncodingListQuery extends PageQuery {

    @ApiModelProperty(value = "创建人名称",example = "admin")
    private String createName;

    @ApiModelProperty(value = "编号类型 ID",example = "2c9efaca9516b1c201953be4e9b70111")
    private String id;

}