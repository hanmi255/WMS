package com.zeroone.star.outgoodsmanage.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Getter;
import lombok.Setter;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 出库任务
 * </p>
 *
 * @author Longlive
 * @since 2025-02-21
 */

@Getter
@Setter
@TableName("wm_om_qm_i")
public class WmOmQmI implements Serializable {

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
     * 到货通知单
     */
    private String omNoticeId;

    /**
     * 到货通知行项目
     */
    private String iomNoticeItem;

    /**
     * 商品编码
     */
    private String goodsId;

    /**
     * 出货数量
     */
    private String omQuat;

    /**
     * 数量
     */
    private String qmOkQuat;

    /**
     * 备注
     */
    private String itemText;

    /**
     * 生产日期
     */
    private String proData;

    /**
     * 托盘
     */
    private String tinId;

    /**
     * 单位
     */
    private String goodsUnit;

    /**
     * 批次
     */
    private String goodsBatch;

    /**
     * 仓位
     */
    private String binId;

    /**
     * 体积
     */
    private String tinTj;

    /**
     * 重量
     */
    private String tinZhl;

    /**
     * 是否已下架
     */
    private String binSta;

    /**
     * 货主
     */
    private String cusCode;

    /**
     * 温度
     */
    private String recDeg;

    /**
     * 任务接收人
     */
    private String assignTo;

    /**
     * 基本单位
     */
    private String baseUnit;

    /**
     * 基本单位数量
     */
    private String baseGoodscount;

    /**
     * 客户名称
     */
    private String cusName;

    /**
     * 商品名称
     */
    private String goodsName;

    private String waveId;

    private String imCusCode;

    private String omBeiZhu;

    /**
     * 条码
     */
    private String barcode;

    /**
     * 保质期
     */
    private String baozhiqi;

    /**
     * 规格
     */
    private String shpGuiGe;

    /**
     * 拣货换算
     */
    private String pickNotice;

    private String firstRq;

    private String secondRq;

    private String sku;


}
