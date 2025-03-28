package com.zeroone.star.project.query.j5.basezl.goods;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * 功能：商品信息查询
 * 作者：蕉太狼殿下
 * 日期：2025/2/22 14:49
 */
@ToString
@Getter
@Setter
@ApiModel("商品信息查询对象")
public class GoodsQuery extends PageQuery {
    @ApiModelProperty(value = "所属货主", example = "X00001-XXXX-KH有限公司")
    private String sysCompanyCode;
    @ApiModelProperty(value = "商品名称", example = "蔗糖")
    private String shpMingCheng;
    @ApiModelProperty(value = "英文名称", example = "sucrose")
    private String ywMingCheng;
    @ApiModelProperty(value = "日文名称", example = "スクロース")
    private String rwMingCheng;
    @ApiModelProperty(value = "商品编码", example = "20222")
    private String shpBianMa;
    @ApiModelProperty(value = "客户商品编码", example = "123456789")
    private String shpBianMakh;
    @ApiModelProperty(value = "商品条码", example = "RL001")
    private String shpTiaoMa;
    @ApiModelProperty(value = "停用", example = "否")
    private String zhuangTai;

}
