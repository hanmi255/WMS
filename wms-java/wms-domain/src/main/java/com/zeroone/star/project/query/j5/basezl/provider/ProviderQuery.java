package com.zeroone.star.project.query.j5.basezl.provider;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * 功能：供应商信息查询
 * 作者：蕉太狼殿下
 * 日期：2025/2/22 14:50
 */
@ToString
@Getter
@Setter
@ApiModel("供应商信息查询对象")
public class ProviderQuery extends PageQuery {
    @ApiModelProperty(value = "供应商中文全称", example = "大江大河有限公司")
    private String zhongWenQch;
    @ApiModelProperty(value = "供应商编码", example = "G002")
    private String gysBianMa;
    @ApiModelProperty(value = "供应商简称", example = "大江大河")
    private String gysJianCheng;
    @ApiModelProperty(value = "助记码", example = "123456")
    private String zhuJiMa;
}
