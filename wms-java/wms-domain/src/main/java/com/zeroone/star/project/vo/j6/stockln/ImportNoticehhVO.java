package com.zeroone.star.project.vo.j6.stockln;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.List;

/**
 * han
 * 分页条件查询通知单VO
 */
@Data
@ApiModel("传输数据对象")
public class ImportNoticehhVO {

    @ApiModelProperty(value = "id", example = "123456")
    private List<String> id;
}
