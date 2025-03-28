package com.zeroone.star.project.dto.j7.outbound;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 出库通知项
 * </p>
 *
 * @author lenyan
 * @since 2025-02-21
 */
@Getter
@Setter
@ApiModel("出库通知项")
public class WmOmNoticeIDTO implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键
     */
    @ApiModelProperty(value = "主键", example = "1")
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
    @ApiModelProperty(value = "创建日期", example = "2025-02-21T13:51:00")
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
    @ApiModelProperty(value = "更新日期", example = "2025-02-21T14:30:00")
    private LocalDateTime updateDate;

    /**
     * 所属部门
     */
    @ApiModelProperty(value = "所属部门", example = "技术部")
    private String sysOrgCode;

    /**
     * 所属公司
     */
    @ApiModelProperty(value = "所属公司", example = "01星球有限公司")
    private String sysCompanyCode;

    /**
     * 出货通知ID
     */
    @ApiModelProperty(value = "出货通知ID", example = "NOTICE123456")
    private String omNoticeId;

    /**
     * 出货商品
     */
    @ApiModelProperty(value = "出货商品", example = "GOODS123")
    private String goodsId;

    /**
     * 出货数量
     */
    @ApiModelProperty(value = "出货数量", example = "100")
    private String goodsQua;

    /**
     * 出货单位
     */
    @ApiModelProperty(value = "出货单位", example = "件")
    private String goodsUnit;

    /**
     * 生产日期
     */
    @ApiModelProperty(value = "生产日期", example = "2025-02-15T00:00:00")
    private LocalDateTime goodsProData;

    /**
     * 批次
     */
    @ApiModelProperty(value = "批次", example = "BATCH001")
    private String goodsBatch;

    /**
     * 出货仓位
     */
    @ApiModelProperty(value = "出货仓位", example = "BIN001")
    private String binOm;

    /**
     * 已出货数量
     */
    @ApiModelProperty(value = "已出货数量", example = "50")
    private String goodsQuaok;

    /**
     * 预约出货时间
     */
    @ApiModelProperty(value = "预约出货时间", example = "2025-02-22 10:00")
    private String delvData;

    /**
     * 客户
     */
    @ApiModelProperty(value = "客户", example = "CUS001")
    private String cusCode;

    /**
     * 客户名称
     */
    @ApiModelProperty(value = "客户名称", example = "客户A")
    private String cusName;

    /**
     * 商品名称
     */
    @ApiModelProperty(value = "商品名称", example = "商品名称A")
    private String goodsText;

    /**
     * 波次号
     */
    @ApiModelProperty(value = "波次号", example = "WAVE001")
    private String waveId;

    /**
     * 状态
     */
    @ApiModelProperty(value = "状态", example = "待发货")
    private String omSta;

    /**
     * 基本单位
     */
    @ApiModelProperty(value = "基本单位", example = "个")
    private String baseUnit;

    /**
     * 基本单位数量
     */
    @ApiModelProperty(value = "基本单位数量", example = "200")
    private String baseGoodscount;

    /**
     * 下架计划生成
     */
    @ApiModelProperty(value = "下架计划生成", example = "未生成")
    private String planSta;

    /**
     * 商品名称（冗余字段）
     */
    @ApiModelProperty(value = "商品名称（冗余字段）", example = "商品详细名称")
    private String goodsName;

    /**
     * 其他ID
     */
    @ApiModelProperty(value = "其他ID", example = "OTHERID001")
    private String otherId;

    /**
     * 仓位ID
     */
    @ApiModelProperty(value = "仓位ID", example = "BINID001")
    private String binId;

    /**
     * 客户代码（进口）
     */
    @ApiModelProperty(value = "客户代码（进口）", example = "IMCUS001")
    private String imCusCode;

    /**
     * 备注
     */
    @ApiModelProperty(value = "备注", example = "无")
    private String omBeiZhu;

    /**
     * 保质期
     */
    @ApiModelProperty(value = "保质期", example = "365")
    private String bzhiQi;

    /**
     * 产品属性
     */
    @ApiModelProperty(value = "产品属性", example = "普通")
    private String chpShuXing;

    /**
     * 条形码
     */
    @ApiModelProperty(value = "条形码", example = "123456789012")
    private String barcode;

    /**
     * SKU
     */
    @ApiModelProperty(value = "SKU", example = "SKU001")
    private String sku;
}
