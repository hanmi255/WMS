package com.zeroone.star.project.dto.j8.shipmentmana.receiptmana;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;

/**
 * 修改回单dto
 */
@Getter
@Setter
@ToString
@ApiModel(value = "修改回单DTO")
public class ReceiptPutDTO extends ReceiptBaseDTO{
    @ApiModelProperty(value = "id",example = "2c9efaca91697e980192796e75d04d60")
    @NotBlank(message = "id不能为空")
    private String id;
}
