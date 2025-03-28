package com.zeroone.star.stockln.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 预约进货通知抬头
 * </p>
 *
 * @author juhao
 * @since 2025-03-06
 */
@Getter
@Setter
@TableName("wm_im_notice_h")
public class WmImNoticeH implements Serializable {

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
     * 客户编码
     */
    private String cusCode;

    /**
     * 预计到货时间
     */
    private LocalDateTime imData;

    /**
     * 客户订单号
     */
    private String imCusCode;

    /**
     * 司机
     */
    private String imCarDri;

    /**
     * 司机电话
     */
    private String imCarMobile;

    /**
     * 车号
     */
    private String imCarNo;

    /**
     * 订单类型
     */
    private String orderTypeCode;

    /**
     * 月台
     */
    private String platformCode;

    /**
     * 备注
     */
    private String imBeizhu;

    /**
     * 单据状态
     */
    private String imSta;

    /**
     * 进货通知单号
     */
    private String noticeId;

    /**
     * 附件
     */
    private String fuJian;

    private String readOnly;

    private String whereCon;

    /**
     * 供应商编码
     */
    private String supCode;

    /**
     * 供应商名称
     */
    private String supName;

    /**
     * 对接单据类型
     */
    private String piClass;

    /**
     * 账套
     */
    private String piMaster;

    private String areaCode;

    private String storeCode;


}
