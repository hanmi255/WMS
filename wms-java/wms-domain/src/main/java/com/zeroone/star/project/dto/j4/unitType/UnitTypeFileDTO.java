package com.zeroone.star.project.dto.j4.unitType;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;
/**
 * 文件dto
 *
 * @author adi
 * #Date: 2025/3/10 21:14
 */
@Getter
@Setter
@ToString
@ApiModel(value = "系统参数类型导出/导入DTO对象")
public class UnitTypeFileDTO {

    @ApiModelProperty(value = "单位类型代码",example = "TEST001")
    private String unit_type_code;
    @ApiModelProperty(value = "单位类型名称",example = "测试参数类型")
    private String unit_type_name;

}
