package com.zeroone.star.outgoodsmanage.entity;


import cn.hutool.core.date.DateTime;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.io.Serializable;

/**
 * <p>
 * 描述：批量复核操作数据库对象
 * </p>
 *
 * @author chen
 * @since 2025/3/4 19:31
 */

@Getter
@Setter
@ToString
public class LoadCheckDO implements Serializable {
    private String id;
    private String goodsQuaok; //复核数量
    private String omNoticeId; //订单编号
    private String omSta; //状态
    private DateTime updateDate; //h表的修改状态
    private String updateBy; //down表的修改日期状态
}
