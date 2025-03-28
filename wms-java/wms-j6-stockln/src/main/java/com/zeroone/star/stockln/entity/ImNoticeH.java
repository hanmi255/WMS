package com.zeroone.star.stockln.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import com.baomidou.mybatisplus.annotation.IdType;
import java.time.LocalDateTime;
import com.baomidou.mybatisplus.annotation.TableId;
import java.io.Serializable;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.experimental.Accessors;

/**
 * <p>
 * 预约进货通知抬头
 * </p>
 *
 * @author Backa
 * @since 2025-03-04
 */
@Data
@EqualsAndHashCode(callSuper = false)
@Accessors(chain = true)
@TableName("wm_im_notice_h")
@ApiModel(value="ImNoticeH对象", description="预约进货通知抬头")
public class ImNoticeH implements Serializable {

    private static final long serialVersionUID = 1L;

    @ApiModelProperty(value = "主键")
    @TableId(value = "id", type = IdType.AUTO)
    private String id;

    @ApiModelProperty(value = "创建人名称")
    private String createName;

    @ApiModelProperty(value = "创建人登录名称")
    private String createBy;

    @ApiModelProperty(value = "创建日期")
    private LocalDateTime createDate;

    @ApiModelProperty(value = "更新人名称")
    private String updateName;

    @ApiModelProperty(value = "更新人登录名称")
    private String updateBy;

    @ApiModelProperty(value = "更新日期")
    private LocalDateTime updateDate;

    @ApiModelProperty(value = "所属部门")
    private String sysOrgCode;

    @ApiModelProperty(value = "所属公司")
    private String sysCompanyCode;

    @ApiModelProperty(value = "客户编码")
    private String cusCode;

    @ApiModelProperty(value = "预计到货时间")
    private LocalDateTime imData;

    @ApiModelProperty(value = "客户订单号")
    private String imCusCode;

    @ApiModelProperty(value = "司机")
    private String imCarDri;

    @ApiModelProperty(value = "司机电话")
    private String imCarMobile;

    @ApiModelProperty(value = "车号")
    private String imCarNo;

    @ApiModelProperty(value = "订单类型")
    private String orderTypeCode;

    @ApiModelProperty(value = "月台")
    private String platformCode;

    @ApiModelProperty(value = "备注")
    private String imBeizhu;

    @ApiModelProperty(value = "单据状态")
    private String imSta;

    @ApiModelProperty(value = "进货通知单号")
    private String noticeId;

    @ApiModelProperty(value = "附件")
    private String fuJian;

    private String readOnly;

    private String whereCon;

    @ApiModelProperty(value = "供应商编码")
    private String supCode;

    @ApiModelProperty(value = "供应商名称")
    private String supName;

    @ApiModelProperty(value = "对接单据类型")
    private String piClass;

    @ApiModelProperty(value = "账套")
    private String piMaster;

    private String areaCode;

    private String storeCode;


}
