package com.zeroone.star.project.dto.j8.other.port;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * <p>
 * 描述：修改港口信息数据模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author yjq
 * @version 1.0.0
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("修改港口信息数据模型")
public class PortModifyDTO extends PortBaseDTO{
    @ApiModelProperty(value = "更新人名称", example = "管理员")
    private String updateName;
    @ApiModelProperty(value = "更新人登录名称", example = "admin")
    private String updateBy;
    @ApiModelProperty(value = "更新日期", example = "2025-02-26 18:24:01")
    private String updateDate;

}
