package com.zeroone.star.project.dto.j6.stockln;



import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;


import lombok.Data;
import lombok.ToString;

import java.util.List;

@ToString
@Data
@ApiModel("进货通知单抬头详细信息显示数据对象")
public class ImportNoticeDetailHeadDTO extends ImportNoticeBaseDTO{

    @ApiModelProperty(value = "预约库区", example = "A库区")
    private String areaCode;

    @ApiModelProperty(value = "仓库", example = "01")
    private String storeCode;

    @ApiModelProperty(value = "进货通知明细", example = "")
    private List<ImportNoticeDetailDTO> list;

    @ApiModelProperty(value = "附件", example = "")
    private String fuJian;

}

