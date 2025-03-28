package com.zeroone.star.project.query.j4.encodingType;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
 * @author qiaozhi
 * @title EncodingType
 * @date 2025/2/21 21:40
 * @description 编码类型query
 */
@Data
@ApiModel(value = "编码类型query")
public class EncodingTypeQuery extends PageQuery {
    @ApiModelProperty(value = "编码类型代码",example = "11")
    private String snroTypeCode;
    @ApiModelProperty(value = "编码类型名称",example = "编码1")
    private String snroTypeName;
}
