package com.zeroone.star.project.dto.j7.zccheck;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;
import org.w3c.dom.stylesheets.LinkStyle;

import java.util.List;

@Getter
@Setter
@ToString
@ApiModel("一键复核DTO")
public class OneClickReviewDTO {

    @ApiModelProperty("所有要复核的id")
    private List<String> omNoticeIds;
}
