package com.zeroone.star.project.dto.j6.stockln;
import io.swagger.annotations.ApiModelProperty;

public class WvStockDTO {

    private String createDate;

    private String createName;

    private String createBy;
    @ApiModelProperty(value = "库存类型",example = "托盘上")
    private String kuctype;

    private Long goodsQua;
    @ApiModelProperty(value = "单位",example = "箱")
    private String goodsUnit;
    @ApiModelProperty(value = "数量",example = "45")
    private Long baseGoodscount;

    private String baseUnit;
    @ApiModelProperty(value = "储位",example = "1")
    private String kuWeiBianMa;
    @ApiModelProperty(value = "托盘",example = "A")
    private String binId;
    @ApiModelProperty(value = "客户编码",example = "001")
    private String cusCode;

    /**
     * 中文全称
     */
    @ApiModelProperty(value = "客户名称",example = "可口可乐饮料有限公司")
    private String zhongWenQch;

    private String goodsId;
    @ApiModelProperty(value = "商品编码",example = "0000")
    private String goodsCode;
    @ApiModelProperty(value = "商品名称",example = "可口可乐")
    private String shpMingCheng;

    private String shlDanWei;

    private String chlShl;
    @ApiModelProperty(value = "生产日期",example = "2099-12-31")
    private String goodsProData;
    @ApiModelProperty(value = "保质期",example = "360")
    private String bzhiQi;
    @ApiModelProperty(value = "规格",example = "支")
    private String shpGuiGe;
    @ApiModelProperty(value = "到期日",example = "2099-12-31")
    private String dqr;

    /**
     * 库位类型
     */
    @ApiModelProperty(value = "库位类型",example = "存储储位")
    private String kuWeiLeiXing;

    /**
     * 取货次序
     */
    private String quHuoCiXu;

    /**
     * 上架次序
     */
    private String shangJiaCiXu;

    /**
     * 仓库
     */
    private String binStore;

    private String tiJiCm;

    /**
     * 体积单位
     */
    private String tiJiDanWei;

    /**
     * 重量单位
     */
    private String zhongLiangDanWei;

    /**
     * 面积单位
     */
    private String mianJiDanWei;

    /**
     * 最大体积
     */
    private String zuiDaTiJi;

    /**
     * 最大面积
     */
    private String zuiDaMianJi;

}
