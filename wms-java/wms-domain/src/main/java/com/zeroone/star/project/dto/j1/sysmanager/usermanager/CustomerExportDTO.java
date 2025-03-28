package com.zeroone.star.project.dto.j1.sysmanager.usermanager;

import com.alibaba.excel.annotation.ExcelProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述：客户导出数据模型（匹配Excel模板）
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author halo
 * @version 1.0.0
 */
@ToString
@Setter
@Getter
@ApiModel(value = "客户导出数据模型")
public class CustomerExportDTO {

    @ExcelProperty(index = 0, value = "中文全称")
    @ApiModelProperty(value = "客户中文全称", example = "YYY-有限公司")
    private String chineseName;

    @ExcelProperty(index = 1, value = "合同号")
    @ApiModelProperty(value = "合同编号（可为空）", example = "333")
    private String contractNumber;

    @ExcelProperty(index = 2, value = "客户编码")
    @ApiModelProperty(value = "唯一客户编码", example = "001", required = true)
    private String customerCode;

    @ExcelProperty(index = 3, value = "企业意向书")
    @ApiModelProperty(value = "意向书编号", example = "10")
    private String enterpriseLetter;

    @ExcelProperty(index = 4, value = "企业属性")
    @ApiModelProperty(value = "企业分类属性", example = "01")
    private String enterpriseType;

    @ExcelProperty(index = 5, value = "客户属性")
    @ApiModelProperty(value = "客户类型属性", example = "10")
    private String customerType;

    @ExcelProperty(index = 6, value = "地址")
    @ApiModelProperty(value = "详细地址", example = "测试地址")
    private String address;

    @ExcelProperty(index = 7, value = "负责人")
    @ApiModelProperty(value = "负责人姓名", example = "何宗激")
    private String manager;

    @ExcelProperty(index = 8, value = "电话")
    @ApiModelProperty(value = "办公电话", example = "021-12345678")
    private String officePhone;

    @ExcelProperty(index = 9, value = "联系人")
    @ApiModelProperty(value = "联系人姓名", example = "张三")
    private String contactPerson;

    @ExcelProperty(index = 10, value = "联系人电话")
    @ApiModelProperty(value = "联系人座机", example = "021-87654321")
    private String contactPhone;

    @ExcelProperty(index = 11, value = "手机")
    @ApiModelProperty(value = "负责人手机号", example = "18621708083")
    private String mobile;

    @ExcelProperty(index = 12, value = "Email地址")
    @ApiModelProperty(value = "电子邮箱", example = "test@zeroone.com")
    private String email;

    @ExcelProperty(index = 13, value = "备注")
    @ApiModelProperty(value = "附加说明", example = "测试地址")
    private String remark;
}