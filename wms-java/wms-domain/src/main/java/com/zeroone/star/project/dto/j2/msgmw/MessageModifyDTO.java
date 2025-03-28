package com.zeroone.star.project.dto.j2.msgmw;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import lombok.NoArgsConstructor;

/**
 * <p>
 * 描述：消息数据更新对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author Maple
 * @version 1.0.0
 */
@Data
@NoArgsConstructor
@ApiModel(value = "消息数据更新对象")
public class MessageModifyDTO {
    @ApiModelProperty(value = "消息标题", example = "XX通知")
    private String esTitle;
    @ApiModelProperty(value = "消息类型", example = "1")
    private String esType;
    @ApiModelProperty(value = "接收人", example = "admin")
    private String esReceiver;
    @ApiModelProperty(value = "发送状态", example = "3")
    private String esStatus;
    @ApiModelProperty(value = "消息内容", example = "YYY-有限公司客户的订单QTRK20250218-0001将于送到，请准备收货。")
    private String esContent;
    @ApiModelProperty(value = "消息ID", example = "4028318195171486019517527243002d")
    private String id;
}
