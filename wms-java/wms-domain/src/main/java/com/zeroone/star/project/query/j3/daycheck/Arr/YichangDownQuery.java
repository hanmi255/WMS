package com.zeroone.star.project.query.j3.daycheck.Arr;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;
import org.springframework.format.annotation.DateTimeFormat;

import java.time.LocalDate;

/**
 * @author aaa
 * @version 1.0
 * @description TODO
 * @date 2025/2/22 13:52
 */
@EqualsAndHashCode(callSuper = true)
@Data
@ApiModel("出库异常//下架与复核")
public class YichangDownQuery extends PageQuery {
    @ApiModelProperty(value = "下架日期")//wm_to_down_goods
    @DateTimeFormat(pattern = "yyyy-MM-dd")
    private LocalDate create_date;

    @ApiModelProperty(value = "下架人")//wm_to_down_goods
    private String create_name;

    @ApiModelProperty(value = "复核人")//wm_to_down_goods
    private String update_name;

    @ApiModelProperty(value = "储位")//wm_to_down_goods
    private String ku_wei_bian_ma;

    @ApiModelProperty(value = "下架托盘")//wm_om_qm_i
    private String bin_id;

    @ApiModelProperty(value = "客户名称")//md_cus
    private String zhong_wen_qch;
}
