package com.zeroone.star.stockln.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableName;

import java.io.Serializable;
import java.util.Date;

/**
 * 预约进货通知明细
 * @TableName wm_im_notice_i
 */
@TableName(value ="wm_im_notice_i")
public class WmImNI implements Serializable {
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
     * 到货通知单号
     */
    private String imNoticeId;

    /**
     * 到货通知项目
     */
    private String imNoticeItem;

    /**
     * 商品编码
     */
    private String goodsCode;

    /**
     * 数量
     */
    private String goodsCount;

    /**
     * 生产日期
     */
    private Date goodsPrdData;

    /**
     * 批次
     */
    private String goodsBatch;

    /**
     * 库位整理
     */
    private String binPre;

    /**
     * 体积
     */
    private String goodsFvol;

    /**
     * 重量
     */
    private String goodsWeight;

    /**
     * 计划库位
     */
    private String binPlan;

    /**
     * 单位
     */
    private String goodsUnit;

    /**
     * 未清数量
     */
    private String goodsWqmCount;

    /**
     * 收货登记数量
     */
    private String goodsQmCount;

    /**
     * 行项目状态
     */
    private String noticeiSta;

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
    private String goodsName;

    /**
     * 
     */
    private String otherId;

    /**
     * 
     */
    private String imCusCode;

    /**
     * 
     */
    private String imBeizhu;

    /**
     * 
     */
    private String barcode;

    /**
     * 规格
     */
    private String shpGuiGe;

    /**
     * 
     */
    private String bzhiQi;

    /**
     * 产品属性
     */
    private String chpShuXing;

    /**
     * 
     */
    private String tinId;

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
     * 到货通知单号
     */
    public String getImNoticeId() {
        return imNoticeId;
    }

    /**
     * 到货通知单号
     */
    public void setImNoticeId(String imNoticeId) {
        this.imNoticeId = imNoticeId;
    }

    /**
     * 到货通知项目
     */
    public String getImNoticeItem() {
        return imNoticeItem;
    }

    /**
     * 到货通知项目
     */
    public void setImNoticeItem(String imNoticeItem) {
        this.imNoticeItem = imNoticeItem;
    }

    /**
     * 商品编码
     */
    public String getGoodsCode() {
        return goodsCode;
    }

    /**
     * 商品编码
     */
    public void setGoodsCode(String goodsCode) {
        this.goodsCode = goodsCode;
    }

    /**
     * 数量
     */
    public String getGoodsCount() {
        return goodsCount;
    }

    /**
     * 数量
     */
    public void setGoodsCount(String goodsCount) {
        this.goodsCount = goodsCount;
    }

    /**
     * 生产日期
     */
    public Date getGoodsPrdData() {
        return goodsPrdData;
    }

    /**
     * 生产日期
     */
    public void setGoodsPrdData(Date goodsPrdData) {
        this.goodsPrdData = goodsPrdData;
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
     * 库位整理
     */
    public String getBinPre() {
        return binPre;
    }

    /**
     * 库位整理
     */
    public void setBinPre(String binPre) {
        this.binPre = binPre;
    }

    /**
     * 体积
     */
    public String getGoodsFvol() {
        return goodsFvol;
    }

    /**
     * 体积
     */
    public void setGoodsFvol(String goodsFvol) {
        this.goodsFvol = goodsFvol;
    }

    /**
     * 重量
     */
    public String getGoodsWeight() {
        return goodsWeight;
    }

    /**
     * 重量
     */
    public void setGoodsWeight(String goodsWeight) {
        this.goodsWeight = goodsWeight;
    }

    /**
     * 计划库位
     */
    public String getBinPlan() {
        return binPlan;
    }

    /**
     * 计划库位
     */
    public void setBinPlan(String binPlan) {
        this.binPlan = binPlan;
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
     * 未清数量
     */
    public String getGoodsWqmCount() {
        return goodsWqmCount;
    }

    /**
     * 未清数量
     */
    public void setGoodsWqmCount(String goodsWqmCount) {
        this.goodsWqmCount = goodsWqmCount;
    }

    /**
     * 收货登记数量
     */
    public String getGoodsQmCount() {
        return goodsQmCount;
    }

    /**
     * 收货登记数量
     */
    public void setGoodsQmCount(String goodsQmCount) {
        this.goodsQmCount = goodsQmCount;
    }

    /**
     * 行项目状态
     */
    public String getNoticeiSta() {
        return noticeiSta;
    }

    /**
     * 行项目状态
     */
    public void setNoticeiSta(String noticeiSta) {
        this.noticeiSta = noticeiSta;
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
     * 
     */
    public String getOtherId() {
        return otherId;
    }

    /**
     * 
     */
    public void setOtherId(String otherId) {
        this.otherId = otherId;
    }

    /**
     * 
     */
    public String getImCusCode() {
        return imCusCode;
    }

    /**
     * 
     */
    public void setImCusCode(String imCusCode) {
        this.imCusCode = imCusCode;
    }

    /**
     * 
     */
    public String getImBeizhu() {
        return imBeizhu;
    }

    /**
     * 
     */
    public void setImBeizhu(String imBeizhu) {
        this.imBeizhu = imBeizhu;
    }

    /**
     * 
     */
    public String getBarcode() {
        return barcode;
    }

    /**
     * 
     */
    public void setBarcode(String barcode) {
        this.barcode = barcode;
    }

    /**
     * 规格
     */
    public String getShpGuiGe() {
        return shpGuiGe;
    }

    /**
     * 规格
     */
    public void setShpGuiGe(String shpGuiGe) {
        this.shpGuiGe = shpGuiGe;
    }

    /**
     * 
     */
    public String getBzhiQi() {
        return bzhiQi;
    }

    /**
     * 
     */
    public void setBzhiQi(String bzhiQi) {
        this.bzhiQi = bzhiQi;
    }

    /**
     * 产品属性
     */
    public String getChpShuXing() {
        return chpShuXing;
    }

    /**
     * 产品属性
     */
    public void setChpShuXing(String chpShuXing) {
        this.chpShuXing = chpShuXing;
    }

    /**
     * 
     */
    public String getTinId() {
        return tinId;
    }

    /**
     * 
     */
    public void setTinId(String tinId) {
        this.tinId = tinId;
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
        WmImNI other = (WmImNI) that;
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
            && (this.getGoodsCode() == null ? other.getGoodsCode() == null : this.getGoodsCode().equals(other.getGoodsCode()))
            && (this.getGoodsCount() == null ? other.getGoodsCount() == null : this.getGoodsCount().equals(other.getGoodsCount()))
            && (this.getGoodsPrdData() == null ? other.getGoodsPrdData() == null : this.getGoodsPrdData().equals(other.getGoodsPrdData()))
            && (this.getGoodsBatch() == null ? other.getGoodsBatch() == null : this.getGoodsBatch().equals(other.getGoodsBatch()))
            && (this.getBinPre() == null ? other.getBinPre() == null : this.getBinPre().equals(other.getBinPre()))
            && (this.getGoodsFvol() == null ? other.getGoodsFvol() == null : this.getGoodsFvol().equals(other.getGoodsFvol()))
            && (this.getGoodsWeight() == null ? other.getGoodsWeight() == null : this.getGoodsWeight().equals(other.getGoodsWeight()))
            && (this.getBinPlan() == null ? other.getBinPlan() == null : this.getBinPlan().equals(other.getBinPlan()))
            && (this.getGoodsUnit() == null ? other.getGoodsUnit() == null : this.getGoodsUnit().equals(other.getGoodsUnit()))
            && (this.getGoodsWqmCount() == null ? other.getGoodsWqmCount() == null : this.getGoodsWqmCount().equals(other.getGoodsWqmCount()))
            && (this.getGoodsQmCount() == null ? other.getGoodsQmCount() == null : this.getGoodsQmCount().equals(other.getGoodsQmCount()))
            && (this.getNoticeiSta() == null ? other.getNoticeiSta() == null : this.getNoticeiSta().equals(other.getNoticeiSta()))
            && (this.getBaseUnit() == null ? other.getBaseUnit() == null : this.getBaseUnit().equals(other.getBaseUnit()))
            && (this.getBaseGoodscount() == null ? other.getBaseGoodscount() == null : this.getBaseGoodscount().equals(other.getBaseGoodscount()))
            && (this.getBaseQmcount() == null ? other.getBaseQmcount() == null : this.getBaseQmcount().equals(other.getBaseQmcount()))
            && (this.getGoodsName() == null ? other.getGoodsName() == null : this.getGoodsName().equals(other.getGoodsName()))
            && (this.getOtherId() == null ? other.getOtherId() == null : this.getOtherId().equals(other.getOtherId()))
            && (this.getImCusCode() == null ? other.getImCusCode() == null : this.getImCusCode().equals(other.getImCusCode()))
            && (this.getImBeizhu() == null ? other.getImBeizhu() == null : this.getImBeizhu().equals(other.getImBeizhu()))
            && (this.getBarcode() == null ? other.getBarcode() == null : this.getBarcode().equals(other.getBarcode()))
            && (this.getShpGuiGe() == null ? other.getShpGuiGe() == null : this.getShpGuiGe().equals(other.getShpGuiGe()))
            && (this.getBzhiQi() == null ? other.getBzhiQi() == null : this.getBzhiQi().equals(other.getBzhiQi()))
            && (this.getChpShuXing() == null ? other.getChpShuXing() == null : this.getChpShuXing().equals(other.getChpShuXing()))
            && (this.getTinId() == null ? other.getTinId() == null : this.getTinId().equals(other.getTinId()));
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
        result = prime * result + ((getGoodsCode() == null) ? 0 : getGoodsCode().hashCode());
        result = prime * result + ((getGoodsCount() == null) ? 0 : getGoodsCount().hashCode());
        result = prime * result + ((getGoodsPrdData() == null) ? 0 : getGoodsPrdData().hashCode());
        result = prime * result + ((getGoodsBatch() == null) ? 0 : getGoodsBatch().hashCode());
        result = prime * result + ((getBinPre() == null) ? 0 : getBinPre().hashCode());
        result = prime * result + ((getGoodsFvol() == null) ? 0 : getGoodsFvol().hashCode());
        result = prime * result + ((getGoodsWeight() == null) ? 0 : getGoodsWeight().hashCode());
        result = prime * result + ((getBinPlan() == null) ? 0 : getBinPlan().hashCode());
        result = prime * result + ((getGoodsUnit() == null) ? 0 : getGoodsUnit().hashCode());
        result = prime * result + ((getGoodsWqmCount() == null) ? 0 : getGoodsWqmCount().hashCode());
        result = prime * result + ((getGoodsQmCount() == null) ? 0 : getGoodsQmCount().hashCode());
        result = prime * result + ((getNoticeiSta() == null) ? 0 : getNoticeiSta().hashCode());
        result = prime * result + ((getBaseUnit() == null) ? 0 : getBaseUnit().hashCode());
        result = prime * result + ((getBaseGoodscount() == null) ? 0 : getBaseGoodscount().hashCode());
        result = prime * result + ((getBaseQmcount() == null) ? 0 : getBaseQmcount().hashCode());
        result = prime * result + ((getGoodsName() == null) ? 0 : getGoodsName().hashCode());
        result = prime * result + ((getOtherId() == null) ? 0 : getOtherId().hashCode());
        result = prime * result + ((getImCusCode() == null) ? 0 : getImCusCode().hashCode());
        result = prime * result + ((getImBeizhu() == null) ? 0 : getImBeizhu().hashCode());
        result = prime * result + ((getBarcode() == null) ? 0 : getBarcode().hashCode());
        result = prime * result + ((getShpGuiGe() == null) ? 0 : getShpGuiGe().hashCode());
        result = prime * result + ((getBzhiQi() == null) ? 0 : getBzhiQi().hashCode());
        result = prime * result + ((getChpShuXing() == null) ? 0 : getChpShuXing().hashCode());
        result = prime * result + ((getTinId() == null) ? 0 : getTinId().hashCode());
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
        sb.append(", goodsCode=").append(goodsCode);
        sb.append(", goodsCount=").append(goodsCount);
        sb.append(", goodsPrdData=").append(goodsPrdData);
        sb.append(", goodsBatch=").append(goodsBatch);
        sb.append(", binPre=").append(binPre);
        sb.append(", goodsFvol=").append(goodsFvol);
        sb.append(", goodsWeight=").append(goodsWeight);
        sb.append(", binPlan=").append(binPlan);
        sb.append(", goodsUnit=").append(goodsUnit);
        sb.append(", goodsWqmCount=").append(goodsWqmCount);
        sb.append(", goodsQmCount=").append(goodsQmCount);
        sb.append(", noticeiSta=").append(noticeiSta);
        sb.append(", baseUnit=").append(baseUnit);
        sb.append(", baseGoodscount=").append(baseGoodscount);
        sb.append(", baseQmcount=").append(baseQmcount);
        sb.append(", goodsName=").append(goodsName);
        sb.append(", otherId=").append(otherId);
        sb.append(", imCusCode=").append(imCusCode);
        sb.append(", imBeizhu=").append(imBeizhu);
        sb.append(", barcode=").append(barcode);
        sb.append(", shpGuiGe=").append(shpGuiGe);
        sb.append(", bzhiQi=").append(bzhiQi);
        sb.append(", chpShuXing=").append(chpShuXing);
        sb.append(", tinId=").append(tinId);
        sb.append(", serialVersionUID=").append(serialVersionUID);
        sb.append("]");
        return sb.toString();
    }
}