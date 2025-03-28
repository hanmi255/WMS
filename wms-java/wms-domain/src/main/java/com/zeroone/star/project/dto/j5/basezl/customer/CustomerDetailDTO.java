package com.zeroone.star.project.dto.j5.basezl.customer;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;

/**
 * <p>
 * 描述：客户详细数据模型
 * </p>
 *
 * @author 小夏
 * @version 1.0.0
 */
@Getter
@Setter
@ToString
@ApiModel("客户详细数据模型")
public class CustomerDetailDTO extends CustomerAddDTO {

}
