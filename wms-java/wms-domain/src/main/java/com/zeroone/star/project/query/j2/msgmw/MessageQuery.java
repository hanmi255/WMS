package com.zeroone.star.project.query.j2.msgmw;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;

import javax.validation.constraints.NotEmpty;

/**
 * <p>
 * 描述：消息查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Maple
 * @version 1.0.0
 */
@Data
@NoArgsConstructor
@ApiModel("消息查询对象")
public class MessageQuery extends PageQuery {
    @NotEmpty
    @ApiModelProperty(value = "消息类型", example = "1（对应短信提醒）")
    private String esType;
    @ApiModelProperty(value = "消息标题", example = "xx通知")
    private String esTitle;
    @NotEmpty
    @ApiModelProperty(value = "发送状态", example = "3（对应未发送）")
    private String esStatus;
}
