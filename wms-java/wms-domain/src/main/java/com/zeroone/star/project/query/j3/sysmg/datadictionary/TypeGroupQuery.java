package com.zeroone.star.project.query.j3.sysmg.datadictionary;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @program: wms-java
 * @description: 字典分类查询对象
 * @author: Hao
 **/
@ToString
@Getter
@Setter
@ApiModel("字典分类查询对象")
public class TypeGroupQuery extends PageQuery {
    @ApiModelProperty(value = "字典分类名称", example = "送货方式")
    private String typegroupname;

    @ApiModelProperty(value = "字典分类编码", example = "tms_thfs")
    private String typegroupcode;

    @ApiModelProperty(value = "用于排序的字段", example = "字典名称")
    private String sort;

    @ApiModelProperty(value = "排序顺序", example = "desc")
    private String order;
}
