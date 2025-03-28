package com.zeroone.star.baseConfig.entity;

import com.alibaba.excel.annotation.ExcelProperty;
import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;

/**
 * <p>
 * 
 * </p>
 *
 * @author neko
 * @since 2025-03-01
 */
@Getter
@Setter
@TableName("ba_unit")
public class ExcelMeasurementUnit implements Serializable {

    /**
     * 单位代码
     */
    @ExcelProperty(value = "unit_code",index = 9)
    private String unitCode;

    /**
     * 单位名称
     */
    @ExcelProperty(value = "unit_zh_name",index = 10)
    private String unitZhName;

    /**
     * 英文名称
     */
    @ExcelProperty(value = "unit_en_name",index = 11)
    private String unitEnName;

    @TableId(type = IdType.ASSIGN_UUID)
    private String id;

}
