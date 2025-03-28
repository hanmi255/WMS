package com.zeroone.star.outgoodsmanage.entity;

import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 
 * </p>
 *
 * @author qiuye
 * @since 2025-02-22
 */
@Getter
@Setter
@TableName("wm_om_notice_h")
public class WmOmNoticeH implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键
     */
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
    private LocalDateTime createDate;

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
    private LocalDateTime updateDate;

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
    private LocalDateTime delvData;

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
     * 状态
     */
    @TableId
    private String omNoticeId;


    /**
     * 附件
     */
    private String fuJian;

    private String readOnly;

    private String whereCon;

    /**
     * 订单类型
     */
    private String orderTypeCode;

    /**
     * 三方客户
     */
    private String ocusCode;

    /**
     * 三方客户名称
     */
    private String ocusName;

    private String imCusCode;

    private String printStatus;

    /**
     * 对接单据类型
     */
    private String piClass;

    /**
     * 账套
     */
    private String piMaster;

    private String delvMethod;

    private String storeCode;

    /**
     * 拣货人
     */
    private String jhUser;

    /**
     * 复核人
     */
    private String fhUser;


}
