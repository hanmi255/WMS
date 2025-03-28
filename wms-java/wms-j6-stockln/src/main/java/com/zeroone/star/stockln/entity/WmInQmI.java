package com.zeroone.star.stockln.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;

import java.io.Serializable;
import java.util.Date;

/**
 * 验收记录
 * @TableName wm_in_qm_i
 */
@TableName(value ="wm_in_qm_i")
public class WmInQmI implements Serializable {
    /**
     * 主键
     */
    @TableId
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
    private Date createDate;

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
    private Date updateDate;

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
     * 重量
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

    /**
     * 
     */
    private String cusName;

    /**
     * 
     */
    private String goodsName;

    /**
     * 入库单号
     */
    private String imCusCode;

    /**
     * 
     */
    private String baseInGoodscount;

    /**
     * 
     */
    private String baseOutGoodscount;

    @TableField(exist = false)
    private static final long serialVersionUID = 1L;

    /**
     * 主键
     */
    public String getId() {
        return id;
    }

    /**
     * 主键
     */
    public void setId(String id) {
        this.id = id;
    }

    /**
     * 创建人名称
     */
    public String getCreateName() {
        return createName;
    }

    /**
     * 创建人名称
     */
    public void setCreateName(String createName) {
        this.createName = createName;
    }

    /**
     * 创建人登录名称
     */
    public String getCreateBy() {
        return createBy;
    }

    /**
     * 创建人登录名称
     */
    public void setCreateBy(String createBy) {
        this.createBy = createBy;
    }

    /**
     * 创建日期
     */
    public Date getCreateDate() {
        return createDate;
    }

    /**
     * 创建日期
     */
    public void setCreateDate(Date createDate) {
        this.createDate = createDate;
    }

    /**
     * 更新人名称
     */
    public String getUpdateName() {
        return updateName;
    }

    /**
     * 更新人名称
     */
    public void setUpdateName(String updateName) {
        this.updateName = updateName;
    }

    /**
     * 更新人登录名称
     */
    public String getUpdateBy() {
        return updateBy;
    }

    /**
     * 更新人登录名称
     */
    public void setUpdateBy(String updateBy) {
        this.updateBy = updateBy;
    }

    /**
     * 更新日期
     */
    public Date getUpdateDate() {
        return updateDate;
    }

    /**
     * 更新日期
     */
    public void setUpdateDate(Date updateDate) {
        this.updateDate = updateDate;
    }

    /**
     * 所属部门
     */
    public String getSysOrgCode() {
        return sysOrgCode;
    }

    /**
     * 所属部门
     */
    public void setSysOrgCode(String sysOrgCode) {
        this.sysOrgCode = sysOrgCode;
    }

    /**
     * 所属公司
     */
    public String getSysCompanyCode() {
        return sysCompanyCode;
    }

    /**
     * 所属公司
     */
    public void setSysCompanyCode(String sysCompanyCode) {
        this.sysCompanyCode = sysCompanyCode;
    }

    /**
     * 到货通知单
     */
    public String getImNoticeId() {
        return imNoticeId;
    }

    /**
     * 到货通知单
     */
    public void setImNoticeId(String imNoticeId) {
        this.imNoticeId = imNoticeId;
    }

    /**
     * 到货通知行项目
     */
    public String getImNoticeItem() {
        return imNoticeItem;
    }

    /**
     * 到货通知行项目
     */
    public void setImNoticeItem(String imNoticeItem) {
        this.imNoticeItem = imNoticeItem;
    }

    /**
     * 商品编码
     */
    public String getGoodsId() {
        return goodsId;
    }

    /**
     * 商品编码
     */
    public void setGoodsId(String goodsId) {
        this.goodsId = goodsId;
    }

    /**
     * 到货数量
     */
    public String getImQuat() {
        return imQuat;
    }

    /**
     * 到货数量
     */
    public void setImQuat(String imQuat) {
        this.imQuat = imQuat;
    }

    /**
     * 收货数量
     */
    public String getQmOkQuat() {
        return qmOkQuat;
    }

    /**
     * 收货数量
     */
    public void setQmOkQuat(String qmOkQuat) {
        this.qmOkQuat = qmOkQuat;
    }

    /**
     * 备注
     */
    public String getItemText() {
        return itemText;
    }

    /**
     * 备注
     */
    public void setItemText(String itemText) {
        this.itemText = itemText;
    }

    /**
     * 生产日期
     */
    public String getProData() {
        return proData;
    }

    /**
     * 生产日期
     */
    public void setProData(String proData) {
        this.proData = proData;
    }

    /**
     * 托盘
     */
    public String getTinId() {
        return tinId;
    }

    /**
     * 托盘
     */
    public void setTinId(String tinId) {
        this.tinId = tinId;
    }

    /**
     * 单位
     */
    public String getGoodsUnit() {
        return goodsUnit;
    }

    /**
     * 单位
     */
    public void setGoodsUnit(String goodsUnit) {
        this.goodsUnit = goodsUnit;
    }

    /**
     * 批次
     */
    public String getGoodsBatch() {
        return goodsBatch;
    }

    /**
     * 批次
     */
    public void setGoodsBatch(String goodsBatch) {
        this.goodsBatch = goodsBatch;
    }

    /**
     * 仓位
     */
    public String getBinId() {
        return binId;
    }

    /**
     * 仓位
     */
    public void setBinId(String binId) {
        this.binId = binId;
    }

    /**
     * 体积
     */
    public String getTinTj() {
        return tinTj;
    }

    /**
     * 体积
     */
    public void setTinTj(String tinTj) {
        this.tinTj = tinTj;
    }

    /**
     * 重量
     */
    public String getTinZhl() {
        return tinZhl;
    }

    /**
     * 重量
     */
    public void setTinZhl(String tinZhl) {
        this.tinZhl = tinZhl;
    }

    /**
     * 是否已上架
     */
    public String getBinSta() {
        return binSta;
    }

    /**
     * 是否已上架
     */
    public void setBinSta(String binSta) {
        this.binSta = binSta;
    }

    /**
     * 货主
     */
    public String getCusCode() {
        return cusCode;
    }

    /**
     * 货主
     */
    public void setCusCode(String cusCode) {
        this.cusCode = cusCode;
    }

    /**
     * 温度
     */
    public String getRecDeg() {
        return recDeg;
    }

    /**
     * 温度
     */
    public void setRecDeg(String recDeg) {
        this.recDeg = recDeg;
    }

    /**
     * 基本单位
     */
    public String getBaseUnit() {
        return baseUnit;
    }

    /**
     * 基本单位
     */
    public void setBaseUnit(String baseUnit) {
        this.baseUnit = baseUnit;
    }

    /**
     * 基本单位数量
     */
    public String getBaseGoodscount() {
        return baseGoodscount;
    }

    /**
     * 基本单位数量
     */
    public void setBaseGoodscount(String baseGoodscount) {
        this.baseGoodscount = baseGoodscount;
    }

    /**
     * 基本单位收货数量
     */
    public String getBaseQmcount() {
        return baseQmcount;
    }

    /**
     * 基本单位收货数量
     */
    public void setBaseQmcount(String baseQmcount) {
        this.baseQmcount = baseQmcount;
    }

    /**
     * 
     */
    public String getCusName() {
        return cusName;
    }

    /**
     * 
     */
    public void setCusName(String cusName) {
        this.cusName = cusName;
    }

    /**
     * 
     */
    public String getGoodsName() {
        return goodsName;
    }

    /**
     * 
     */
    public void setGoodsName(String goodsName) {
        this.goodsName = goodsName;
    }

    /**
     * 入库单号
     */
    public String getImCusCode() {
        return imCusCode;
    }

    /**
     * 入库单号
     */
    public void setImCusCode(String imCusCode) {
        this.imCusCode = imCusCode;
    }

    /**
     * 
     */
    public String getBaseInGoodscount() {
        return baseInGoodscount;
    }

    /**
     * 
     */
    public void setBaseInGoodscount(String baseInGoodscount) {
        this.baseInGoodscount = baseInGoodscount;
    }

    /**
     * 
     */
    public String getBaseOutGoodscount() {
        return baseOutGoodscount;
    }

    /**
     * 
     */
    public void setBaseOutGoodscount(String baseOutGoodscount) {
        this.baseOutGoodscount = baseOutGoodscount;
    }

    @Override
    public boolean equals(Object that) {
        if (this == that) {
            return true;
        }
        if (that == null) {
            return false;
        }
        if (getClass() != that.getClass()) {
            return false;
        }
        WmInQmI other = (WmInQmI) that;
        return (this.getId() == null ? other.getId() == null : this.getId().equals(other.getId()))
            && (this.getCreateName() == null ? other.getCreateName() == null : this.getCreateName().equals(other.getCreateName()))
            && (this.getCreateBy() == null ? other.getCreateBy() == null : this.getCreateBy().equals(other.getCreateBy()))
            && (this.getCreateDate() == null ? other.getCreateDate() == null : this.getCreateDate().equals(other.getCreateDate()))
            && (this.getUpdateName() == null ? other.getUpdateName() == null : this.getUpdateName().equals(other.getUpdateName()))
            && (this.getUpdateBy() == null ? other.getUpdateBy() == null : this.getUpdateBy().equals(other.getUpdateBy()))
            && (this.getUpdateDate() == null ? other.getUpdateDate() == null : this.getUpdateDate().equals(other.getUpdateDate()))
            && (this.getSysOrgCode() == null ? other.getSysOrgCode() == null : this.getSysOrgCode().equals(other.getSysOrgCode()))
            && (this.getSysCompanyCode() == null ? other.getSysCompanyCode() == null : this.getSysCompanyCode().equals(other.getSysCompanyCode()))
            && (this.getImNoticeId() == null ? other.getImNoticeId() == null : this.getImNoticeId().equals(other.getImNoticeId()))
            && (this.getImNoticeItem() == null ? other.getImNoticeItem() == null : this.getImNoticeItem().equals(other.getImNoticeItem()))
            && (this.getGoodsId() == null ? other.getGoodsId() == null : this.getGoodsId().equals(other.getGoodsId()))
            && (this.getImQuat() == null ? other.getImQuat() == null : this.getImQuat().equals(other.getImQuat()))
            && (this.getQmOkQuat() == null ? other.getQmOkQuat() == null : this.getQmOkQuat().equals(other.getQmOkQuat()))
            && (this.getItemText() == null ? other.getItemText() == null : this.getItemText().equals(other.getItemText()))
            && (this.getProData() == null ? other.getProData() == null : this.getProData().equals(other.getProData()))
            && (this.getTinId() == null ? other.getTinId() == null : this.getTinId().equals(other.getTinId()))
            && (this.getGoodsUnit() == null ? other.getGoodsUnit() == null : this.getGoodsUnit().equals(other.getGoodsUnit()))
            && (this.getGoodsBatch() == null ? other.getGoodsBatch() == null : this.getGoodsBatch().equals(other.getGoodsBatch()))
            && (this.getBinId() == null ? other.getBinId() == null : this.getBinId().equals(other.getBinId()))
            && (this.getTinTj() == null ? other.getTinTj() == null : this.getTinTj().equals(other.getTinTj()))
            && (this.getTinZhl() == null ? other.getTinZhl() == null : this.getTinZhl().equals(other.getTinZhl()))
            && (this.getBinSta() == null ? other.getBinSta() == null : this.getBinSta().equals(other.getBinSta()))
            && (this.getCusCode() == null ? other.getCusCode() == null : this.getCusCode().equals(other.getCusCode()))
            && (this.getRecDeg() == null ? other.getRecDeg() == null : this.getRecDeg().equals(other.getRecDeg()))
            && (this.getBaseUnit() == null ? other.getBaseUnit() == null : this.getBaseUnit().equals(other.getBaseUnit()))
            && (this.getBaseGoodscount() == null ? other.getBaseGoodscount() == null : this.getBaseGoodscount().equals(other.getBaseGoodscount()))
            && (this.getBaseQmcount() == null ? other.getBaseQmcount() == null : this.getBaseQmcount().equals(other.getBaseQmcount()))
            && (this.getCusName() == null ? other.getCusName() == null : this.getCusName().equals(other.getCusName()))
            && (this.getGoodsName() == null ? other.getGoodsName() == null : this.getGoodsName().equals(other.getGoodsName()))
            && (this.getImCusCode() == null ? other.getImCusCode() == null : this.getImCusCode().equals(other.getImCusCode()))
            && (this.getBaseInGoodscount() == null ? other.getBaseInGoodscount() == null : this.getBaseInGoodscount().equals(other.getBaseInGoodscount()))
            && (this.getBaseOutGoodscount() == null ? other.getBaseOutGoodscount() == null : this.getBaseOutGoodscount().equals(other.getBaseOutGoodscount()));
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + ((getId() == null) ? 0 : getId().hashCode());
        result = prime * result + ((getCreateName() == null) ? 0 : getCreateName().hashCode());
        result = prime * result + ((getCreateBy() == null) ? 0 : getCreateBy().hashCode());
        result = prime * result + ((getCreateDate() == null) ? 0 : getCreateDate().hashCode());
        result = prime * result + ((getUpdateName() == null) ? 0 : getUpdateName().hashCode());
        result = prime * result + ((getUpdateBy() == null) ? 0 : getUpdateBy().hashCode());
        result = prime * result + ((getUpdateDate() == null) ? 0 : getUpdateDate().hashCode());
        result = prime * result + ((getSysOrgCode() == null) ? 0 : getSysOrgCode().hashCode());
        result = prime * result + ((getSysCompanyCode() == null) ? 0 : getSysCompanyCode().hashCode());
        result = prime * result + ((getImNoticeId() == null) ? 0 : getImNoticeId().hashCode());
        result = prime * result + ((getImNoticeItem() == null) ? 0 : getImNoticeItem().hashCode());
        result = prime * result + ((getGoodsId() == null) ? 0 : getGoodsId().hashCode());
        result = prime * result + ((getImQuat() == null) ? 0 : getImQuat().hashCode());
        result = prime * result + ((getQmOkQuat() == null) ? 0 : getQmOkQuat().hashCode());
        result = prime * result + ((getItemText() == null) ? 0 : getItemText().hashCode());
        result = prime * result + ((getProData() == null) ? 0 : getProData().hashCode());
        result = prime * result + ((getTinId() == null) ? 0 : getTinId().hashCode());
        result = prime * result + ((getGoodsUnit() == null) ? 0 : getGoodsUnit().hashCode());
        result = prime * result + ((getGoodsBatch() == null) ? 0 : getGoodsBatch().hashCode());
        result = prime * result + ((getBinId() == null) ? 0 : getBinId().hashCode());
        result = prime * result + ((getTinTj() == null) ? 0 : getTinTj().hashCode());
        result = prime * result + ((getTinZhl() == null) ? 0 : getTinZhl().hashCode());
        result = prime * result + ((getBinSta() == null) ? 0 : getBinSta().hashCode());
        result = prime * result + ((getCusCode() == null) ? 0 : getCusCode().hashCode());
        result = prime * result + ((getRecDeg() == null) ? 0 : getRecDeg().hashCode());
        result = prime * result + ((getBaseUnit() == null) ? 0 : getBaseUnit().hashCode());
        result = prime * result + ((getBaseGoodscount() == null) ? 0 : getBaseGoodscount().hashCode());
        result = prime * result + ((getBaseQmcount() == null) ? 0 : getBaseQmcount().hashCode());
        result = prime * result + ((getCusName() == null) ? 0 : getCusName().hashCode());
        result = prime * result + ((getGoodsName() == null) ? 0 : getGoodsName().hashCode());
        result = prime * result + ((getImCusCode() == null) ? 0 : getImCusCode().hashCode());
        result = prime * result + ((getBaseInGoodscount() == null) ? 0 : getBaseInGoodscount().hashCode());
        result = prime * result + ((getBaseOutGoodscount() == null) ? 0 : getBaseOutGoodscount().hashCode());
        return result;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(getClass().getSimpleName());
        sb.append(" [");
        sb.append("Hash = ").append(hashCode());
        sb.append(", id=").append(id);
        sb.append(", createName=").append(createName);
        sb.append(", createBy=").append(createBy);
        sb.append(", createDate=").append(createDate);
        sb.append(", updateName=").append(updateName);
        sb.append(", updateBy=").append(updateBy);
        sb.append(", updateDate=").append(updateDate);
        sb.append(", sysOrgCode=").append(sysOrgCode);
        sb.append(", sysCompanyCode=").append(sysCompanyCode);
        sb.append(", imNoticeId=").append(imNoticeId);
        sb.append(", imNoticeItem=").append(imNoticeItem);
        sb.append(", goodsId=").append(goodsId);
        sb.append(", imQuat=").append(imQuat);
        sb.append(", qmOkQuat=").append(qmOkQuat);
        sb.append(", itemText=").append(itemText);
        sb.append(", proData=").append(proData);
        sb.append(", tinId=").append(tinId);
        sb.append(", goodsUnit=").append(goodsUnit);
        sb.append(", goodsBatch=").append(goodsBatch);
        sb.append(", binId=").append(binId);
        sb.append(", tinTj=").append(tinTj);
        sb.append(", tinZhl=").append(tinZhl);
        sb.append(", binSta=").append(binSta);
        sb.append(", cusCode=").append(cusCode);
        sb.append(", recDeg=").append(recDeg);
        sb.append(", baseUnit=").append(baseUnit);
        sb.append(", baseGoodscount=").append(baseGoodscount);
        sb.append(", baseQmcount=").append(baseQmcount);
        sb.append(", cusName=").append(cusName);
        sb.append(", goodsName=").append(goodsName);
        sb.append(", imCusCode=").append(imCusCode);
        sb.append(", baseInGoodscount=").append(baseInGoodscount);
        sb.append(", baseOutGoodscount=").append(baseOutGoodscount);
        sb.append(", serialVersionUID=").append(serialVersionUID);
        sb.append("]");
        return sb.toString();
    }
}