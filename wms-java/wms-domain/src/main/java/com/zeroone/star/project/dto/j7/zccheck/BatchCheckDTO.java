package com.zeroone.star.project.dto.j7.zccheck;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.util.List;

/**
 * <p>
 * 描述：批量复核操作多个对象
 * </p>
 *
 * @author chen
 * @since 2025/2/25 15:49
 */


@Getter
@Setter
@ToString
@ApiModel("选择复核对象")
public class BatchCheckDTO {

    @ApiModelProperty(value = "选择复核对象",example = "多条复核数据对象")
    private List<CheckDTO> checkDTOList;
}
