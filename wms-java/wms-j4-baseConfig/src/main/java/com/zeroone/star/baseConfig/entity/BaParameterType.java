package com.zeroone.star.baseConfig.entity;

import com.alibaba.excel.annotation.ExcelProperty;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;

import lombok.Data;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author qiaozhi
 * @since 2025-03-07
 */
@Data
@TableName("ba_sysp_type")
public class BaParameterType implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId
    private String id;

    /**
     * 创建人名称
     */
    @ExcelProperty(value = "创建人名称",index = 0)
    private String createName;

    /**
     * 创建人登录名称
     */
    @ExcelProperty(value = "创建人登录名称",index = 1)
    private String createBy;

    /**
     * 创建日期
     */
    @ExcelProperty(value = "创建日期",index = 2)
    private LocalDateTime createDate;

    /**
     * 更新人名称
     */
    @ExcelProperty(value = "更新人名称",index = 3)
    private String updateName;

    /**
     * 更新人登录名称
     */
    @ExcelProperty(value = "更新人登录名称",index = 4)
    private String updateBy;

    /**
     * 更新日期
     */
    @ExcelProperty(value = "更新日期",index = 5)
    private LocalDateTime updateDate;

    /**
     * 所属部门
     */
    @ExcelProperty(value = "所属部门",index = 6)
    private String sysOrgCode;

    /**
     * 所属公司
     */
    @ExcelProperty(value = "所属公司",index = 7)
    private String sysCompanyCode;

    /**
     * 系统参数类型代码
     */
    @ExcelProperty(value = "系统参数类型代码",index = 8)
    private String syspTypeCode;

    /**
     * 系统参数类型名称
     */
    @ExcelProperty(value = "系统参数类型名称",index = 9)
    private String syspTypeName;


}
