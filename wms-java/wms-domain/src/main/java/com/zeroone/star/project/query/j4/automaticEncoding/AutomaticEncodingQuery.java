package com.zeroone.star.project.query.j4.automaticEncoding;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.ToString;

/**
 * @ClassName: AutomaticEncodingQuery
 * @Description:
 * @Author: lzm
 * @Date: 2025-02-23 00:28
 */
@Data
@ToString
@EqualsAndHashCode(callSuper = true)
public class AutomaticEncodingQuery extends PageQuery {
    /**
     * 编号类型
     */
    @ApiModelProperty(value = "编号类型")
    private String snroTypeCode;

    /**
     * 组织机构
     */
    @ApiModelProperty(value = "组织机构")
    private String snroOrg;
}
