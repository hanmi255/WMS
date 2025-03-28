package com.zeroone.star.j1.dashboard.entity;

import com.baomidou.mybatisplus.annotation.TableName;
import java.io.Serializable;
import java.time.LocalDateTime;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * 验收记录表
 * </p>
 *
 * @author j1-yunyu
 * @since 2025-02-27
 */
@Getter
@Setter
@TableName("wm_in_qm_i")
public class WmInQmI implements Serializable {

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
    private String imNoticeId;

    /**
     * 到货通知行项目
     */
    private String imNoticeItem;

    /**
     * 商品编码
     */
    private String goodsId;

    /**
     * 到货数量
     */
    private String imQuat;

    /**
     * 收货数量
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
     * 是否已上架(Y-已上架 N-待上架)
     */
    private String tinZhl;

    /**
     * 是否已上架
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
     * 基本单位
     */
    private String baseUnit;

    /**
     * 基本单位数量
     */
    private String baseGoodscount;

    /**
     * 基本单位收货数量
     */
    private String baseQmcount;

    private String cusName;

    private String goodsName;

    /**
     * 入库单号
     */
    private String imCusCode;

    private String baseInGoodscount;

    private String baseOutGoodscount;


}
