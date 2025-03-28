package com.zeroone.star.project.query.j2.msgmw;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.EqualsAndHashCode;

import java.io.Serializable;

@EqualsAndHashCode(callSuper = true)
@Data
public class MessageTemplateQuery extends PageQuery implements Serializable {
    /**
     * 模板名称
     */
    @ApiModelProperty(value = "模板名称", example = "订单发货提醒")
    private String templateName;

    /**
     * 模板类型
     */
    @ApiModelProperty(value = "模板类型", example = "EMAIL")
    private String type;

    @ApiModelProperty(value = "模版ID",example = "1")
    private Integer id;

}
