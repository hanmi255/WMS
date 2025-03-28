package com.zeroone.star.exportmana.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 回单
 * </p>
 *
 * @author asta
 * @since 2025-02-27
 */
@Getter
@Setter
@TableName("wm_notice_conf")
public class Receipt implements Serializable {

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
     * 单号
     */
    private String wmNoticeId;

    /**
     * 备注
     */
    private String beizhu;

    /**
     * 货主
     */
    private String cusCode;

    /**
     * 回单时间
     */
    private LocalDateTime hdData;


}
