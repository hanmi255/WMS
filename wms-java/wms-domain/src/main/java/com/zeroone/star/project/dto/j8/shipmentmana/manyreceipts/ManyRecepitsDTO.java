package com.zeroone.star.project.dto.j8.shipmentmana.manyreceipts;


import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.util.Date;

@Getter
@Setter
@ToString
public class ManyRecepitsDTO {
    @ApiModelProperty(value = "主键ID", example = "2c9efaca91697e980192796e75d04d60")
    private String id;
    @ApiModelProperty(value = "创建人名称", example = "管理员")
    private String createName;
    @ApiModelProperty(value = "创建人登录名称", example = "admin")
    private String createBy;
    @ApiModelProperty(value = "创建时间", example = "2021-01-01 12:00:00")
    private Date createDate;
    @ApiModelProperty(value = "客户订单号",example = "XXXX...")
    private String imCusCode;
    @ApiModelProperty(value = "备注",example = "这是一条备注")
    private String omBeizhu;
    @ApiModelProperty(value = "出货单号",example = "CK20240925-0002")
    private String omNoticeId;
    @ApiModelProperty(value = "客户",example = "710500-可口可乐饮料有限公司")
    private String cusCode;
    @ApiModelProperty(value = "回单时间",example = "yyyy-MM-dd HH:mm:ss")
    private String delvData;
    @ApiModelProperty(value = " 收货人",example = "张三")
    private String delvMember;
    @ApiModelProperty(value = "收货人电话",example = "1xx-xxxx-xxxx")
    private String delvMobile;
    @ApiModelProperty(value = "收货人地址",example = "广东省深圳市南山区科技中一道1000号")
    private String delvAddr;
    @ApiModelProperty(value = "承运人",example = "李四")
    private String reMember;
    @ApiModelProperty(value = "承运人电话",example = "1xx-xxxx-xxxx")
    private String reMobile;
    @ApiModelProperty(value = "承运人车牌号",example = "粤B88888")
    private String reCarno;
    @ApiModelProperty(value = "发获月台",example = "可乐")
    private String omPlatNo;
    @ApiModelProperty(value = "回单状态",example = "未完成,复合完成")
    private String omSta;
    @ApiModelProperty(value = "更新人名称",example = "管理员")
    private String updateName;
    @ApiModelProperty(value = "更新人登录名称",example = "admin")
    private String updateBy;
    @ApiModelProperty(value = "更新时间",example = "yyyy-MM-dd HH:mm:ss")
    private Date updateDate;
    @ApiModelProperty(value = "所属部门",example = "xxx")
    private String sysOrgCode;
    @ApiModelProperty(value = "所属公司",example = "xxx")
    private String sysCompanyCode;
}
