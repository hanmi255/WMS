package com.zeroone.star.project.dto.j3.daycheck.delay;


import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.time.LocalDateTime;

/**
 * <p>
 * 描述：分页查询进货延时示警
 * 该功能连根据字段查询功能都没有，只需要从数据库拉取数据就行，没有修改，删除，新增等功能
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */

@ToString
@Getter
@Setter
@ApiModel("进货延时列表显示数据对象")
public class WaringAllDTO extends PageQuery {
    @ApiModelProperty(value = "创建人", example = "admin")
    private String createName;

    @ApiModelProperty(value = "创建时间", example = "2024-09-24 22:43:02")
    private LocalDateTime createDate;

    @ApiModelProperty(value = "货主", example = "XXXX-GYS有限公司")
    private String supName;

    @ApiModelProperty(value = "计划日期", example = "2024-09-24 22:43:02")
    private LocalDateTime imData;

    @ApiModelProperty(value = "司机", example = "老王")
    private String imCarDri;

    @ApiModelProperty(value = "司机电话", example = "3512345234")
    private String imCarMobile;

    @ApiModelProperty(value = "备注", example = "zhengcha")
    private String imBeizhu;

    @ApiModelProperty(value = "车号", example = "111111")
    private String imCarNo;

    @ApiModelProperty(value = "状态", example = "计划中")
    private String imSta;

    @ApiModelProperty(value = "到货通知单号", example = "RK20241006-0001")
    private String noticeId;  // ✅ 与实体类 im_notice_id 一致
}
