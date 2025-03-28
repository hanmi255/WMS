package com.zeroone.star.project.dto.j2.msgmw;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * <p>
 * 描述：消息数据列表传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Maple
 * @version 1.0.0
 */
@Data
@NoArgsConstructor
@ApiModel(value = "消息数据列表传输对象")
public class MessageListDTO extends MessageDTO{
    @ApiModelProperty(value = "前端显示消息ID",example = "1")
    private String virtualId;
}
