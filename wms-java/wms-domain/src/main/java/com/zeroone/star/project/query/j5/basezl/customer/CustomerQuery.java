package com.zeroone.star.project.query.j5.basezl.customer;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述：客户信息查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@ToString
@Getter
@Setter
@ApiModel("客户信息查询对象")
public class CustomerQuery extends PageQuery {
    @ApiModelProperty(value = "客户名称", example = "可口可乐公司")
    private String customerName;
    @ApiModelProperty(value = "客户编码", example = "CC001")
    private String customerCode;
    @ApiModelProperty(value = "合同号", example = "HT00001XDD")
    private String customerHeTong;
}
