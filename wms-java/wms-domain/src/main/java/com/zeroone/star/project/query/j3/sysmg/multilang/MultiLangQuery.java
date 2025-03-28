package com.zeroone.star.project.query.j3.sysmg.multilang;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.annotation.Nullable;

/**
 * @program: wms-java
 * @description: 分页/条件查询实体
 * <p> 分页查询/条件查询实体</p>
 * 继承基本分页查询, 允许用户传入key/value或者分页参数
 * @author: hamhuo
 **/

@ToString
@Getter
@Setter
@ApiModel(value = "语言对照分页/条件Query")
public class MultiLangQuery extends PageQuery {
    //Key
    @ApiModelProperty(value = "语言键值", example = "common.password")
    private String langKey;
    //value
    @ApiModelProperty(value = "内容", example = "密码")
    private String langContext;
    //排序字段, 指定字段排序, 默认id
    @ApiModelProperty(value = "排序字段", example = "id")
    private String sort;
    //排列顺序
    @ApiModelProperty(value = "排列顺序", example = "desc")
    private String order;
}