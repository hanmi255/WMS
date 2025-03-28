package com.zeroone.star.project.dto.j3.sysmg.multilang;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.sql.Timestamp;

/**
 * @program: wms-java
 * @description: 多语言管理列表显示DTO
 * @author: hamhuo
 **/

@ToString
@Getter
@Setter
@ApiModel(value = "语言对照列表DTO, 分页/条件查询使用")
public class MultiLangListDTO extends MultiLangBaseDTO{
    //创建人
    @ApiModelProperty(value = "创建人ID", example = "4028818d46f764fb0146f7661cb60052")
    private String createBy;

    //创建时间戳, 数据库精确到秒
    @ApiModelProperty(value = "创建时间 nnnn-yy-dd hh:mm:ss", example = "2014-07-04 23:27:53")
    private Timestamp createDate;

    //更新人
    @ApiModelProperty(value = "创建人ID", example = "4028818d46f764fb0146f7661cb60052")
    private String updateBy;

    //更新时间戳, 数据库精确到秒
    @ApiModelProperty(value = "更新时间 nnnn-yy-dd hh:mm:ss", example = "2014-07-04 23:27:53")
    private Timestamp updateDate;

    //排序字段, 默认ID
    @ApiModelProperty(value = "排序字段, 按照指定字段排序", example = "id")
    private String sort;

    //排序顺序, 默认自然顺序
    @ApiModelProperty(value = "顺序, 默认自然顺序", example = "desc")
    private String order;
}