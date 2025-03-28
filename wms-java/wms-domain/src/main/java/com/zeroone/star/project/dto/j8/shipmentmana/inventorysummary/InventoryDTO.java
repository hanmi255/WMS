package com.zeroone.star.project.dto.j8.shipmentmana.inventorysummary;

import com.baomidou.mybatisplus.annotation.TableField;
import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import java.time.LocalDate;


@TableName("wv_last_picking_stock") // 指定表名
@Data
public class InventoryDTO {
    @ApiModelProperty(value = "储位编码", example = "09999")
    @TableField("ku_wei_bian_ma")
    private String kuWeiBianMa;

    @ApiModelProperty(value = "托盘编号", example = "10")
    @TableField("bin_id")
    private String binId;

    @ApiModelProperty(value = "客户编码", example = "710500")
    @TableField("cus_code")
    private String cusCode;

    @ApiModelProperty(value = "中文描述", example = "可口可乐饮料有限公司")
    @TableField("zhong_wen_qch")
    private String zhongWenQch;

    @ApiModelProperty(value = "商品ID", example = "0000")
    @TableField("goods_id")
    private String goodsId;

    @ApiModelProperty(value = "商品编码", example = "0000")
    @TableField("goods_code")
    private String goodsCode;

    @ApiModelProperty(value = "商品名称", example = "可口可乐")
    @TableField("shp_ming_cheng")
    private String shpMingCheng;

    @ApiModelProperty(value = "商品规格", example = "")
    @TableField("shp_gui_ge")
    private String shpGuiGe;

    @ApiModelProperty(value = "处理数量", example = "1")
    @TableField("chl_shl")
    private long chlShl;

    @ApiModelProperty(value = "生产日期", example = "2099-12-31")
    @TableField("goods_pro_data")
    private LocalDate goodsProData;

    @ApiModelProperty(value = "保质期", example = "")
    @TableField("bzhi_qi")
    private int bzhiQi;

    @ApiModelProperty(value = "到期日", example = "2099-12-31")
    @TableField("dqr")
    private LocalDate dqr;

    @ApiModelProperty(value = "库位类型", example = "存储储位")
    @TableField("ku_wei_lei_xing")
    private String kuWeiLeiXing;

    @ApiModelProperty(value = "取货次序", example = "22")
    @TableField("qu_huo_ci_xu")
    private int quHuoCiXu;

    @ApiModelProperty(value = "上架次序", example = "11")
    @TableField("shang_jia_ci_xu")
    private int shangJiaCiXu;

    @ApiModelProperty(value = "库位存储", example = "09999")
    @TableField("bin_store")
    private String binStore;

    @ApiModelProperty(value = "基础库存数量", example = "45")
    @TableField("base_goodscount")
    private long baseGoodscount;

    @ApiModelProperty(value = "最后日期", example = "8/10/2024 23:02:50")
    @TableField("LAST_date")
    private LocalDate lastDate;

    @ApiModelProperty(value = "可用库存", example = "45")
    @TableField("keyongkucun")
    private long keyongkucun;

    @ApiModelProperty(value = "待下架数量", example = "")
    @TableField("daixiaj")
    private long daixiaj;

    @ApiModelProperty(value = "基础单位", example = "")
    @TableField("base_unit")
    private String baseUnit;
}