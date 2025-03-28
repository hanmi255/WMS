package com.zeroone.star.exportmana.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.util.Date;
import lombok.Data;

/**
 * 出库通知抬头
 * @TableName wm_om_notice_h
 */
@TableName(value ="wm_om_notice_h")
@Data
public class ManyReceipts {
    /**
     * 主键
     */
    @TableId
    private String id;

    /**
     * 创建人名称
     */
    private String createName;

    /**
     * 创建人登录名称
     */
    private String createBy;

    /**
     * 创建日期
     */
    private Date createDate;

    /**
     * 更新人名称
     */
    private String updateName;

    /**
     * 更新人登录名称
     */
    private String updateBy;

    /**
     * 更新日期
     */
    private Date updateDate;

    /**
     * 所属部门
     */
    private String sysOrgCode;

    /**
     * 所属公司
     */
    private String sysCompanyCode;

    /**
     * 客户
     */
    private String cusCode;

    /**
     * 要求交货时间
     */
    private Date delvData;

    /**
     * 收货人
     */
    private String delvMember;

    /**
     * 收货人电话
     */
    private String delvMobile;

    /**
     * 收货人地址
     */
    private String delvAddr;

    /**
     * 承运人
     */
    private String reMember;

    /**
     * 承运人电话
     */
    private String reMobile;

    /**
     * 承运人车号
     */
    private String reCarno;

    /**
     * 发货月台
     */
    private String omPlatNo;

    /**
     * 备注
     */
    private String omBeizhu;

    /**
     * 状态
     */
    private String omSta;

    /**
     * 出货单号
     */
    private String omNoticeId;

    /**
     * 客户订单号
     */
    private String imCusCode;


}