package com.zeroone.star.project.dto.j5.basezl.cusother;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

/**
 * <p>
 * 描述: 第三方客户修改信息传输数据模型
 * </p>
 * <p>版权所有: &copy;枢璇</p>
 *
 * @author 枢璇
 * @Version 1.0.0
 * @since 2025/2/22 22:19
 */
@Getter
@Setter
@ToString
@ApiModel("第三方客户继承数据模型")
public class CusOtherModifyDTO extends CusOtherBaseDTO{
    @ApiModelProperty(value = "客户状态", example = "正常")
    private String keHuZhuangTai;

    @ApiModelProperty(value = "终止合作时间", example = "2025-02-22 21:47:17")
    private String zhongZhiHeShiJian;

}
