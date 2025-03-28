package com.zeroone.star.stockln.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 上架记录
 * </p>
 *
 * @author ting
 * @since 2025-03-07
 */
@TableName("wm_to_up_goods")
public class WmToUpGoods implements Serializable {

    private static final long serialVersionUID = 1L;

    /**
     * 主键
     */
    @TableId(value = "id", type = IdType.AUTO)
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
     * 商品编码
     */
    private String goodsId;

    /**
     * 数量
     */
    private String goodsQua;

    /**
     * 原始单据类型
     */
    private String orderTypeCode;

    /**
     * 原始单据编码
     */
    private String orderId;

    /**
     * 原始单据行项目
     */
    private String orderIdI;

    /**
     * 上架ID
     */
    private String wmToUpId;

    /**
     * 单位
     */
    private String goodsUnit;

    /**
     * 批次
     */
    private String goodsBatch;

    /**
     * 生产日期
     */
    private String goodsProData;

    /**
     * 作业类型
     */
    private String actTypeCode;

    /**
     * 库位编码
     */
    private String kuWeiBianMa;

    /**
     * 托盘码
     */
    private String binId;

    /**
     * 货主
     */
    private String cusCode;

    /**
     * 基本单位
     */
    private String baseUnit;

    /**
     * 基本单位数量
     */
    private String baseGoodscount;

    private String goodsName;

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }
    public String getCreateName() {
        return createName;
    }

    public void setCreateName(String createName) {
        this.createName = createName;
    }
    public String getCreateBy() {
        return createBy;
    }

    public void setCreateBy(String createBy) {
        this.createBy = createBy;
    }
    public LocalDateTime getCreateDate() {
        return createDate;
    }

    public void setCreateDate(LocalDateTime createDate) {
        this.createDate = createDate;
    }
    public String getUpdateName() {
        return updateName;
    }

    public void setUpdateName(String updateName) {
        this.updateName = updateName;
    }
    public String getUpdateBy() {
        return updateBy;
    }

    public void setUpdateBy(String updateBy) {
        this.updateBy = updateBy;
    }
    public LocalDateTime getUpdateDate() {
        return updateDate;
    }

    public void setUpdateDate(LocalDateTime updateDate) {
        this.updateDate = updateDate;
    }
    public String getSysOrgCode() {
        return sysOrgCode;
    }

    public void setSysOrgCode(String sysOrgCode) {
        this.sysOrgCode = sysOrgCode;
    }
    public String getSysCompanyCode() {
        return sysCompanyCode;
    }

    public void setSysCompanyCode(String sysCompanyCode) {
        this.sysCompanyCode = sysCompanyCode;
    }
    public String getGoodsId() {
        return goodsId;
    }

    public void setGoodsId(String goodsId) {
        this.goodsId = goodsId;
    }
    public String getGoodsQua() {
        return goodsQua;
    }

    public void setGoodsQua(String goodsQua) {
        this.goodsQua = goodsQua;
    }
    public String getOrderTypeCode() {
        return orderTypeCode;
    }

    public void setOrderTypeCode(String orderTypeCode) {
        this.orderTypeCode = orderTypeCode;
    }
    public String getOrderId() {
        return orderId;
    }

    public void setOrderId(String orderId) {
        this.orderId = orderId;
    }
    public String getOrderIdI() {
        return orderIdI;
    }

    public void setOrderIdI(String orderIdI) {
        this.orderIdI = orderIdI;
    }
    public String getWmToUpId() {
        return wmToUpId;
    }

    public void setWmToUpId(String wmToUpId) {
        this.wmToUpId = wmToUpId;
    }
    public String getGoodsUnit() {
        return goodsUnit;
    }

    public void setGoodsUnit(String goodsUnit) {
        this.goodsUnit = goodsUnit;
    }
    public String getGoodsBatch() {
        return goodsBatch;
    }

    public void setGoodsBatch(String goodsBatch) {
        this.goodsBatch = goodsBatch;
    }
    public String getGoodsProData() {
        return goodsProData;
    }

    public void setGoodsProData(String goodsProData) {
        this.goodsProData = goodsProData;
    }
    public String getActTypeCode() {
        return actTypeCode;
    }

    public void setActTypeCode(String actTypeCode) {
        this.actTypeCode = actTypeCode;
    }
    public String getKuWeiBianMa() {
        return kuWeiBianMa;
    }

    public void setKuWeiBianMa(String kuWeiBianMa) {
        this.kuWeiBianMa = kuWeiBianMa;
    }
    public String getBinId() {
        return binId;
    }

    public void setBinId(String binId) {
        this.binId = binId;
    }
    public String getCusCode() {
        return cusCode;
    }

    public void setCusCode(String cusCode) {
        this.cusCode = cusCode;
    }
    public String getBaseUnit() {
        return baseUnit;
    }

    public void setBaseUnit(String baseUnit) {
        this.baseUnit = baseUnit;
    }
    public String getBaseGoodscount() {
        return baseGoodscount;
    }

    public void setBaseGoodscount(String baseGoodscount) {
        this.baseGoodscount = baseGoodscount;
    }
    public String getGoodsName() {
        return goodsName;
    }

    public void setGoodsName(String goodsName) {
        this.goodsName = goodsName;
    }

    @Override
    public String toString() {
        return "WmToUpGoods{" +
            "id=" + id +
            ", createName=" + createName +
            ", createBy=" + createBy +
            ", createDate=" + createDate +
            ", updateName=" + updateName +
            ", updateBy=" + updateBy +
            ", updateDate=" + updateDate +
            ", sysOrgCode=" + sysOrgCode +
            ", sysCompanyCode=" + sysCompanyCode +
            ", goodsId=" + goodsId +
            ", goodsQua=" + goodsQua +
            ", orderTypeCode=" + orderTypeCode +
            ", orderId=" + orderId +
            ", orderIdI=" + orderIdI +
            ", wmToUpId=" + wmToUpId +
            ", goodsUnit=" + goodsUnit +
            ", goodsBatch=" + goodsBatch +
            ", goodsProData=" + goodsProData +
            ", actTypeCode=" + actTypeCode +
            ", kuWeiBianMa=" + kuWeiBianMa +
            ", binId=" + binId +
            ", cusCode=" + cusCode +
            ", baseUnit=" + baseUnit +
            ", baseGoodscount=" + baseGoodscount +
            ", goodsName=" + goodsName +
        "}";
    }
}
