package com.zeroone.star.project.dto.j4.encodingType;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * @author lostAngel
 * @title EncodingType
 * @date 2025/2/21 21:40
 * @description 编码类型列表显示数据对象
 */
@Getter
@Setter
@ToString
@ApiModel("编码类型列表显示数据对象")
public class EncodingTypeListDTO extends EncodingTypeBaseDTO {

    @ApiModelProperty(value = "id", example = "1")
    private String id;

}
