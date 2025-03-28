package com.zeroone.star.project.dto.j5.basezl.provider;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * 功能：供应商继承数据模型
 * 作者：蕉太狼殿下
 * 日期：2025/2/22 16:31
 */
@Getter
@Setter
@ToString
@ApiModel("供应商继承数据模型")
public class ProviderBaseDTO {
    @ApiModelProperty(value = "供应商中文全称", example = "大江大河有限公司")
    private String zhongWenQch;
    @ApiModelProperty(value = "供应商编码", example = "G001")
    private String gysBianMa;
    @ApiModelProperty(value = "企业属性",example = "02")
    private String xingYeFenLei;
    @ApiModelProperty(value = "地址", example = "大江大河")
    private String diZhi;
    @ApiModelProperty(value = "主联系人", example = "G002")
    private String zhuLianXiRen;
    @ApiModelProperty(value = "电话", example = "028-011-011")
    private String dianHua;
    @ApiModelProperty(value = "手机", example = "138xxxxxxxxx")
    private String shouJi;
    @ApiModelProperty(value = "供应商email地址", example = "123456@qq.com")
    private String emaildiZhi;
    @ApiModelProperty(value = "供应商备注", example = "测试供应商")
    private String beiZhu;

}
