package com.zeroone.star.project.vo.j4.systemParameter;

import com.alibaba.excel.annotation.ExcelProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @author isme
 * @description
 * @title com.zeroone.star.project.vo.j4.BaseConfig.SystemParameterVO
 * @date 2025/3/3
 */
@Getter
@Setter
@ToString
@ApiModel(value = "系统参数类型Vo")
public class SystemParameterVO {
    @ApiModelProperty(value = "系统参数类型",example = "测试")
    @ExcelProperty(value = "系统参数类型")
    private String sysConfType;
    @ApiModelProperty(value = "业务操作环节",example = "1")
    @ExcelProperty(value = "业务操作环节")
    private String sysConfStep;
    @ApiModelProperty(value = "组织",example = "组织")
    @ExcelProperty(value = "组织")
    private String sysConfOrg;
    @ApiModelProperty(value = "合作伙伴",example = "中国")
    @ExcelProperty(value = "合作伙伴")
    private String sysConfPartner;
    @ApiModelProperty(value = "参数1",example = "加急")
    @ExcelProperty(value = "参数1")
    private String sysPara1;
    @ApiModelProperty(value = "参数2",example = "常规")
    @ExcelProperty(value = "参数2")
    private String sysPara2;
    @ApiModelProperty(value = "参数3",example = "紧急")
    @ExcelProperty(value = "参数3")
    private String sysPara3;
    @ApiModelProperty(value = "备注",example = "这是演示案例")
    @ExcelProperty(value = "备注")
    private String sysConfText;

}
