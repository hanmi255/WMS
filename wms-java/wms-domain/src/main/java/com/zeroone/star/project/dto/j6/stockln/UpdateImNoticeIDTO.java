package com.zeroone.star.project.dto.j6.stockln;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

/**
@Author: Backa
* */
@Data
public class UpdateImNoticeIDTO extends ImportNoticeItemDTO {
    private String goodsFvol;
    private String goodsWeight;
}
