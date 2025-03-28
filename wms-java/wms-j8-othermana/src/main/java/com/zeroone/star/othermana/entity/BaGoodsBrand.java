package com.zeroone.star.othermana.entity;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableId;
import com.baomidou.mybatisplus.annotation.TableLogic;
import com.baomidou.mybatisplus.annotation.TableName;
import lombok.Data;

import java.io.Serializable;
import java.util.Date;

/**
 * 品牌信息
 * @TableName ba_goods_brand
 */
@TableName(value ="ba_goods_brand")
@Data
public class BaGoodsBrand implements Serializable {
    /**
     * 
     */
    @TableId(value = "id")
    private String id;

    /**
     * 创建人名称
     */
    @TableField(value = "create_name")
    private String createName;

    /**
     * 创建人登录名称
     */
    @TableField(value = "create_by")
    private String createBy;

    /**
     * 创建日期
     */
    @TableField(value = "create_date")
    private Date createDate;

    /**
     * 更新人名称
     */
    @TableField(value = "update_name")
    private String updateName;

    /**
     * 更新人登录名称
     */
    @TableField(value = "update_by")
    private String updateBy;

    /**
     * 更新日期
     */
    @TableField(value = "update_date")
    private Date updateDate;

    /**
     * 所属部门
     */
    @TableField(value = "sys_org_code")
    private String sysOrgCode;

    /**
     * 所属公司
     */
    @TableField(value = "sys_company_code")
    private String sysCompanyCode;

    /**
     * 品牌代码
     */
    @TableField(value = "goods_brand_code")
    private String goodsBrandCode;

    /**
     * 品牌名称
     */
    @TableField(value = "goods_brand_name")
    private String goodsBrandName;

    /**
     * 品牌网址
     */
    @TableField(value = "goods_brand_www")
    private String goodsBrandWww;

    /**
     * 品牌图片
     */
    @TableField(value = "goods_brand_pic")
    private String goodsBrandPic;

    /**
     * 备注
     */
    @TableField(value = "goods_brand_text")
    private String goodsBrandText;

    /**
     * 停用
     */
    @TableLogic(value = "0", delval = "1")
    private String goodsBrandDel;

    @TableField(exist = false)
    private static final long serialVersionUID = 1L;
}