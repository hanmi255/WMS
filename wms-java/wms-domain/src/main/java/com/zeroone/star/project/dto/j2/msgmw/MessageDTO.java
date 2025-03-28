package com.zeroone.star.project.dto.j2.msgmw;


import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * <p>
 * 描述：消息数据传输对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Maple
 * @version 1.0.0
 */
@Data
@NoArgsConstructor
@ApiModel(value = "消息数据传输对象")
public class MessageDTO extends MessageModifyDTO {
    @ApiModelProperty(value = "备注", example = "")
    private String remark;
    @ApiModelProperty(value = "发送人", example = "admin")
    private String esSender;
    @ApiModelProperty(value = "发送时间", example = "2025-02-22 20:01:50.0")
    private String esSendtime;
    @ApiModelProperty(value = "创建时间", example = "2025-02-18 12:30:34.0")
    private String createDate;
}
