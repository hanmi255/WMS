package com.zeroone.star.daycheck.entity;

import com.alibaba.excel.annotation.ExcelProperty;
import com.baomidou.mybatisplus.annotation.TableName;
import com.fasterxml.jackson.annotation.JsonFormat;
import lombok.AllArgsConstructor;
import lombok.Builder;
import lombok.Data;
import lombok.NoArgsConstructor;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDateTime;

@Data
@Builder
@AllArgsConstructor
@NoArgsConstructor
@TableName("zo_wms.wm_wendu")
public class Temperature {
    //id
    @ExcelProperty(value = "id",index = 0)
    private String id;

    // 创建人名称
    @ExcelProperty(value = "createName",index = 1)
    private String createName;

    // 创建人登录名称
    @ExcelProperty(value = "createBy",index = 2)
    private String createBy;

    // 创建日期
    @DateTimeFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ExcelProperty(value = "createDate",index = 3)
    private LocalDateTime createDate;

    // 更新人名称
    @ExcelProperty(value = "updateName",index = 4)
    private String updateName;

    // 更新人登录名称
    @ExcelProperty(value = "updateBy",index = 5)
    private String updateBy;

    // 更新日期
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ExcelProperty(value = "updateDate",index = 6)
    private LocalDateTime updateDate;

    // 所属部门
    @ExcelProperty(value = "sysOrgCode",index = 7)
    private String sysOrgCode;

    // 所属公司
    @ExcelProperty(value = "sysCompanyCode",index = 8)
    private String sysCompanyCode;

    // 流程状态
    @ExcelProperty(value = "bpmStatus",index = 9)
    private String bpmStatus;

    // 温度地点
    @ExcelProperty(value = "wenduDd",index = 10)
    private String wenduDd;

    // 采集时间
    @JsonFormat(pattern = "yyyy-MM-dd HH:mm:ss")
    @ExcelProperty(value = "wenduCjsj",index = 11)
    private LocalDateTime wenduCjsj;

    // 温度值摄氏度
    @ExcelProperty(value = "wenduZhi",index = 12)
    private Double wenduZhi;

    // 备注
    @ExcelProperty(value = "wenduBz",index = 13)
    private String wenduBz;
}
