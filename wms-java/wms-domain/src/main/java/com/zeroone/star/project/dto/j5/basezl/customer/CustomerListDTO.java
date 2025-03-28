package com.zeroone.star.project.dto.j5.basezl.customer;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：客户列表显示数据对象
 * </p>
 *
 * @author 小夏
 * @version 1.0.0
 */
@ToString
@Getter
@Setter
@ApiModel("客户列表显示数据对象")
public class CustomerListDTO extends CustomerBaseDTO {
    @ApiModelProperty(value = "客户ID", example = "4028e43e9588a54a019588c92ea60009")
    private String id;
    @NotBlank(message = "客户编码不为空")
    @ApiModelProperty(value = "客户编码", example = "CC001")
    private String keHuBianMa; // 原 customerCode（已在基类重命名）
}
