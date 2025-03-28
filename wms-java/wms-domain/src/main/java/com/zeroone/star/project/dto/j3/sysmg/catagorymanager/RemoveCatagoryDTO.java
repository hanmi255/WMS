package com.zeroone.star.project.dto.j3.sysmg.catagorymanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;

@Data
@AllArgsConstructor
@NoArgsConstructor
@ApiModel("删除分类")
public class RemoveCatagoryDTO {

    //唯一标识
    @ApiModelProperty(value = "分类的唯一编号", example = "1")
    private String id;




}
