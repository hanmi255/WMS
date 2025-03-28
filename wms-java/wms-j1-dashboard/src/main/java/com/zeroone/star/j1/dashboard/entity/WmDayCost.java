package com.zeroone.star.j1.dashboard.entity;

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
 * @author j1-yunyu
 * @since 2025-03-04
 */
@Getter
@Setter
@TableName("wm_day_cost")
public class WmDayCost implements Serializable {

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
     * 客户名称
     */
    private String cusName;

    /**
     * 费用
     */
    private String costCode;

    /**
     * 费用名称
     */
    private String costName;

    /**
     * 费用日期
     */
    private LocalDateTime costData;

    /**
     * 每日费用
     */
    private String dayCostYj;

    /**
     * 不含税价
     */
    private String dayCostBhs;

    /**
     * 税额
     */
    private String dayCostSe;

    /**
     * 含税价
     */
    private String dayCostHsj;

    /**
     * 费用来源
     */
    private String costOri;

    /**
     * 备注
     */
    private String beizhu;

    /**
     * 状态
     */
    private String costSta;

    /**
     * 计费数量
     */
    private String costSl;

    /**
     * 数量单位
     */
    private String costUnit;

    /**
     * 是否已结算
     */
    private String costJs;


}
