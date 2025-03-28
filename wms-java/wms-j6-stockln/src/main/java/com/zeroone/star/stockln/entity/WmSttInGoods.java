package com.zeroone.star.stockln.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;

import java.io.Serializable;
import java.time.LocalDateTime;

/**
 * <p>
 * 盘点指令
 * </p>
 *
 * @author ting
 * @since 2025-03-06
 */
@TableName("wm_stt_in_goods")
public class WmSttInGoods implements Serializable {

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
     * 库位编码
     */
    private String binId;

    /**
     * 托盘编码
     */
    private String tinId;

    /**
     * 商品编码
     */
    private String goodsId;

    /**
     * 商品名称
     */
    private String goodsName;

    /**
     * 数量
     */
    private String goodsQua;

    /**
     * 单位
     */
    private String goodsUnit;

    /**
     * 生产日期
     */
    private String goodsProData;

    /**
     * 批次
     */
    private String goodsBatch;

    /**
     * 盘点数量
     */
    private String sttQua;

    /**
     * 客户名称
     */
    private String cusName;

    /**
     * 客户
     */
    private String cusCode;

    /**
     * 盘点状态
     */
    private String sttSta;

    /**
     * 基本单位
     */
    private String baseUnit;

    /**
     * 基本单位数量
     */
    private String baseGoodscount;

    private String sttId;

    /**
     * 商品统一编码
     */
    private String goodsCode;

    /**
     * 盘点类型
     */
    private String sttType;

    /**
     * 动线
     */
    private String dongXian;

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
    public String getBinId() {
        return binId;
    }

    public void setBinId(String binId) {
        this.binId = binId;
    }
    public String getTinId() {
        return tinId;
    }

    public void setTinId(String tinId) {
        this.tinId = tinId;
    }
    public String getGoodsId() {
        return goodsId;
    }

    public void setGoodsId(String goodsId) {
        this.goodsId = goodsId;
    }
    public String getGoodsName() {
        return goodsName;
    }

    public void setGoodsName(String goodsName) {
        this.goodsName = goodsName;
    }
    public String getGoodsQua() {
        return goodsQua;
    }

    public void setGoodsQua(String goodsQua) {
        this.goodsQua = goodsQua;
    }
    public String getGoodsUnit() {
        return goodsUnit;
    }

    public void setGoodsUnit(String goodsUnit) {
        this.goodsUnit = goodsUnit;
    }
    public String getGoodsProData() {
        return goodsProData;
    }

    public void setGoodsProData(String goodsProData) {
        this.goodsProData = goodsProData;
    }
    public String getGoodsBatch() {
        return goodsBatch;
    }

    public void setGoodsBatch(String goodsBatch) {
        this.goodsBatch = goodsBatch;
    }
    public String getSttQua() {
        return sttQua;
    }

    public void setSttQua(String sttQua) {
        this.sttQua = sttQua;
    }
    public String getCusName() {
        return cusName;
    }

    public void setCusName(String cusName) {
        this.cusName = cusName;
    }
    public String getCusCode() {
        return cusCode;
    }

    public void setCusCode(String cusCode) {
        this.cusCode = cusCode;
    }
    public String getSttSta() {
        return sttSta;
    }

    public void setSttSta(String sttSta) {
        this.sttSta = sttSta;
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
    public String getSttId() {
        return sttId;
    }

    public void setSttId(String sttId) {
        this.sttId = sttId;
    }
    public String getGoodsCode() {
        return goodsCode;
    }

    public void setGoodsCode(String goodsCode) {
        this.goodsCode = goodsCode;
    }
    public String getSttType() {
        return sttType;
    }

    public void setSttType(String sttType) {
        this.sttType = sttType;
    }
    public String getDongXian() {
        return dongXian;
    }

    public void setDongXian(String dongXian) {
        this.dongXian = dongXian;
    }

    @Override
    public String toString() {
        return "WmSttInGoods{" +
            "id=" + id +
            ", createName=" + createName +
            ", createBy=" + createBy +
            ", createDate=" + createDate +
            ", updateName=" + updateName +
            ", updateBy=" + updateBy +
            ", updateDate=" + updateDate +
            ", sysOrgCode=" + sysOrgCode +
            ", sysCompanyCode=" + sysCompanyCode +
            ", binId=" + binId +
            ", tinId=" + tinId +
            ", goodsId=" + goodsId +
            ", goodsName=" + goodsName +
            ", goodsQua=" + goodsQua +
            ", goodsUnit=" + goodsUnit +
            ", goodsProData=" + goodsProData +
            ", goodsBatch=" + goodsBatch +
            ", sttQua=" + sttQua +
            ", cusName=" + cusName +
            ", cusCode=" + cusCode +
            ", sttSta=" + sttSta +
            ", baseUnit=" + baseUnit +
            ", baseGoodscount=" + baseGoodscount +
            ", sttId=" + sttId +
            ", goodsCode=" + goodsCode +
            ", sttType=" + sttType +
            ", dongXian=" + dongXian +
        "}";
    }
}
