package com.zeroone.star.project.dto.j8.shipmentmana.receiptmana;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;

@Getter
@Setter
@ToString
@ApiModel(value = "删除回单DTO")
public class ReceiptDeleteDTO {
    @ApiModelProperty(value = "主键",example = "2c9efaca91697e980192796e75d04d60")
    @NotBlank(message = "id不能为空")
    private String id;
}
