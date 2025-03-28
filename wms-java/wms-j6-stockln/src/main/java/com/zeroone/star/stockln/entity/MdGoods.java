package com.zeroone.star.stockln.entity;

import com.baomidou.mybatisplus.annotation.IdType;
import java.time.LocalDateTime;
import com.baomidou.mybatisplus.annotation.TableId;
import java.io.Serializable;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;
import lombok.experimental.Accessors;

/**
 * <p>
 * 商品信息
 * </p>
 *
 * @author Backa
 * @since 2025-03-18
 */
@Data
@EqualsAndHashCode(callSuper = false)
@Accessors(chain = true)
@ApiModel(value="MdGoods对象", description="商品信息")
public class MdGoods implements Serializable {

    private static final long serialVersionUID = 1L;

    @TableId(value = "id", type = IdType.AUTO)
    private String id;

    @ApiModelProperty(value = "创建人名称")
    private String createName;

    @ApiModelProperty(value = "创建人登录名称")
    private String createBy;

    @ApiModelProperty(value = "创建日期")
    private LocalDateTime createDate;

    @ApiModelProperty(value = "更新人名称")
    private String updateName;

    @ApiModelProperty(value = "更新人登录名称")
    private String updateBy;

    @ApiModelProperty(value = "更新日期")
    private LocalDateTime updateDate;

    @ApiModelProperty(value = "所属部门")
    private String sysOrgCode;

    @ApiModelProperty(value = "所属公司")
    private String sysCompanyCode;

    @ApiModelProperty(value = "所属客户")
    private String suoShuKeHu;

    @ApiModelProperty(value = "商品名称")
    private String shpMingCheng;

    @ApiModelProperty(value = "商品简称")
    private String shpJianCheng;

    @ApiModelProperty(value = "商品编码")
    private String shpBianMa;

    @ApiModelProperty(value = "商品型号")
    private String shpXingHao;

    @ApiModelProperty(value = "商品规格")
    private String shpGuiGe;

    @ApiModelProperty(value = "商品颜色")
    private String shpYanSe;

    @ApiModelProperty(value = "产品属性")
    private String chpShuXing;

    @ApiModelProperty(value = "存放温层")
    private String cfWenCeng;

    @ApiModelProperty(value = "拆零控制")
    private String chlKongZhi;

    @ApiModelProperty(value = "码盘单层数量")
    private String mpDanCeng;

    @ApiModelProperty(value = "码盘层高")
    private String mpCengGao;

    @ApiModelProperty(value = "计费商品类")
    private String jfShpLei;

    @ApiModelProperty(value = "商品品牌")
    private String shpPinPai;

    @ApiModelProperty(value = "商品条码")
    private String shpTiaoMa;

    @ApiModelProperty(value = "品牌图片")
    private String ppTuPian;

    @ApiModelProperty(value = "保质期")
    private String bzhiQi;

    @ApiModelProperty(value = "单位")
    private String shlDanWei;

    @ApiModelProperty(value = "拆零单位")
    private String jshDanWei;

    @ApiModelProperty(value = "体积")
    private String tiJiCm;

    @ApiModelProperty(value = "净重")
    private String zhlKg;

    @ApiModelProperty(value = "拆零数量")
    private String chlShl;

    @ApiModelProperty(value = "件数与体积比")
    private String jtiJiBi;

    @ApiModelProperty(value = "件数与毛重比")
    private String jmZhongBi;

    @ApiModelProperty(value = "件数与净重比")
    private String jjZhongBi;

    @ApiModelProperty(value = "尺寸单位")
    private String chcDanWei;

    @ApiModelProperty(value = "长单品")
    private String chDanPin;

    @ApiModelProperty(value = "宽单品")
    private String kuDanPin;

    @ApiModelProperty(value = "高单品")
    private String gaoDanPin;

    @ApiModelProperty(value = "长整箱")
    private String chZhXiang;

    @ApiModelProperty(value = "宽整箱")
    private String kuZhXiang;

    @ApiModelProperty(value = "高整箱")
    private String gaoZhXiang;

    @ApiModelProperty(value = "商品描述")
    private String shpMiaoShu;

    @ApiModelProperty(value = "停用")
    private String zhuangTai;

    @ApiModelProperty(value = "毛重")
    private String zhlKgm;

    @ApiModelProperty(value = "商品客户编码")
    private String shpBianMakh;

    @ApiModelProperty(value = "基准温度")
    private String jizhunWendu;

    private String ywMingCheng;

    private String rwMingCheng;

    private String cusName;

    private String peisongdian;

    @ApiModelProperty(value = "分类")
    private String categoryCode;

    private String categoryId;

    private String minStock;

    private String sku;


}
