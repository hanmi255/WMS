package com.zeroone.star.sysmgr.entity;


import com.alibaba.excel.annotation.ExcelProperty;
import io.swagger.annotations.ApiModel;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;


/**
 * <p>
 * 描述：组织机构导出导入
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 */
@Getter
@Setter
@ToString
@ApiModel("组织机构导出导入")
public class Depart {

    private  String parentDepartId;

    @ExcelProperty(value = "部门名称", index = 0)
    private String departName;

    @ExcelProperty(value = "部门描述", index = 1)
    private String description;

    @ExcelProperty(value = "机构编码", index = 2)
    private String orgCode;

    @ExcelProperty(value = "机构类型编码", index = 3)
    private String orgType;

    @ExcelProperty(value = "电话", index = 4)
    private String mobile;

    @ExcelProperty(value = "传真", index = 5)
    private String fax;

    @ExcelProperty(value = "地址", index = 6)
    private String address;
}
