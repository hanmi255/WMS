package com.zeroone.star.project.dto.j7.outbound;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 出库通知抬头
 * </p>
 *
 * @author lenyan
 * @since 2025-02-21
 */
@Data
@ApiModel("出库通知抬头对象")
public class WmOmNoticeHDTO implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键
     */
    @ApiModelProperty(value = "主键", example = "123e4567-e89b-12d3-a456-426614174000")
    private String id;

    /**
     * 创建人名称
     */
    @ApiModelProperty(value = "创建人名称", example = "张三")
    private String createName;

    /**
     * 创建人登录名称
     */
    @ApiModelProperty(value = "创建人登录名称", example = "zhangsan")
    private String createBy;

    /**
     * 创建日期
     */
    @ApiModelProperty(value = "创建日期", example = "2025-02-21T12:34:56")
    private LocalDateTime createDate;

    /**
     * 更新人名称
     */
    @ApiModelProperty(value = "更新人名称", example = "李四")
    private String updateName;

    /**
     * 更新人登录名称
     */
    @ApiModelProperty(value = "更新人登录名称", example = "lisi")
    private String updateBy;

    /**
     * 更新日期
     */
    @ApiModelProperty(value = "更新日期", example = "2025-02-21T12:34:56")
    private LocalDateTime updateDate;

    /**
     * 所属部门
     */
    @ApiModelProperty(value = "所属部门", example = "IT部")
    private String sysOrgCode;

    /**
     * 所属公司
     */
    @ApiModelProperty(value = "所属公司", example = "01星球")
    private String sysCompanyCode;

    /**
     * 客户
     */
    @ApiModelProperty(value = "客户", example = "CUST001")
    private String cusCode;

    /**
     * 要求交货时间
     */
    @ApiModelProperty(value = "要求交货时间", example = "2025-02-21T12:34:56")
    private LocalDateTime delvData;

    /**
     * 收货人
     */
    @ApiModelProperty(value = "收货人", example = "王五")
    private String delvMember;

    /**
     * 收货人电话
     */
    @ApiModelProperty(value = "收货人电话", example = "13800138000")
    private String delvMobile;

    /**
     * 收货人地址
     */
    @ApiModelProperty(value = "收货人地址", example = "北京市朝阳区")
    private String delvAddr;

    /**
     * 承运人
     */
    @ApiModelProperty(value = "承运人", example = "赵六")
    private String reMember;

    /**
     * 承运人电话
     */
    @ApiModelProperty(value = "承运人电话", example = "13800138001")
    private String reMobile;

    /**
     * 承运人车号
     */
    @ApiModelProperty(value = "承运人车号", example = "京A12345")
    private String reCarno;

    /**
     * 发货月台
     */
    @ApiModelProperty(value = "发货月台", example = "A01")
    private String omPlatNo;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注", example = "紧急订单")
    private String omBeizhu;

    /**
     * 状态
     */
    @ApiModelProperty(value = "状态", example = "已发货")
    private String omSta;

    /**
     * 出货单号
     */
    @ApiModelProperty(value = "出货单号", example = "OM202502210001")
    private String omNoticeId;

    /**
     * 附件
     */
    @ApiModelProperty(value = "附件", example = "attachment.pdf")
    private String fuJian;

    @ApiModelProperty(value = "只读字段", example = "readOnly")
    private String readOnly;

    @ApiModelProperty(value = "查询条件", example = "whereCon")
    private String whereCon;

    /**
     * 订单类型
     */
    @ApiModelProperty(value = "订单类型", example = "普通订单")
    private String orderTypeCode;

    /**
     * 三方客户
     */
    @ApiModelProperty(value = "三方客户", example = "THIRD001")
    private String ocusCode;

    /**
     * 三方客户名称
     */
    @ApiModelProperty(value = "三方客户名称", example = "第三方客户")
    private String ocusName;

    @ApiModelProperty(value = "IM客户代码", example = "IMCUST001")
    private String imCusCode;

    @ApiModelProperty(value = "打印状态", example = "已打印")
    private String printStatus;

    /**
     * 对接单据类型
     */
    @ApiModelProperty(value = "对接单据类型", example = "对接类型A")
    private String piClass;

    /**
     * 账套
     */
    @ApiModelProperty(value = "账套", example = "账套A")
    private String piMaster;

    @ApiModelProperty(value = "交货方式", example = "快递")
    private String delvMethod;

    @ApiModelProperty(value = "仓库代码", example = "WH001")
    private String storeCode;

    /**
     * 拣货人
     */
    @ApiModelProperty(value = "拣货人", example = "拣货人A")
    private String jhUser;

    /**
     * 复核人
     */
    @ApiModelProperty(value = "复核人", example = "复核人A")
    private String fhUser;

}
