package com.zeroone.star.project.query.j7.outdetail;
import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述：出库明细查询对象 查询条件就在query里
 * </p>
 *
 * @author chen
 * @since 2025/2/22 12:47
 */

@Getter
@Setter
@ToString
public class OutDetailQuery extends PageQuery {
    @ApiModelProperty(value = "出库单号",example = "QT20240925-0001")
    private String omNoticeId;
    @ApiModelProperty(value = "第三方单号",example = "12313")
    private String imCusCode;
    @ApiModelProperty(value = "第三方客户",example = "null")
    private String cusCode;
    @ApiModelProperty(value = "第三方客户名称",example = "可口可乐")
    private String ocusName;
    @ApiModelProperty(value = "备注",example = "备注")
    private String omBeizhu;
    @ApiModelProperty(value = "地址",example = "收获地址")
    private String delvAddr;
    @ApiModelProperty(value = "商品编码",example = "RL001")
    private String goodsId;
    @ApiModelProperty(value = "商品名称",example = "RL001-牛羊肉半成品-箱")
    private String goodsName;
}
