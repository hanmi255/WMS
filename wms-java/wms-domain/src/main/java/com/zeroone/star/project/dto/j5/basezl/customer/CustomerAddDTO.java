package com.zeroone.star.project.dto.j5.basezl.customer;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;
import java.util.List;

/**
 * <p>
 * 描述：客户录入信息数据模型
 * </p>
 *
 * @author 小夏
 * @version 1.0.0
 */
@Getter
@Setter
@ToString
@ApiModel("客户录入信息数据模型")
public class CustomerAddDTO extends CustomerBaseDTO {
    @NotBlank(message = "客户编码不为空")
    @ApiModelProperty(value = "客户编码", example = "CC001")
    private String keHuBianMa; // 原 customerCode（已在基类重命名）

    @NotBlank(message = "客户属性不为空")
    @Pattern(regexp = "^(10|20)$", message = "输入的数字必须为10或20")
    @ApiModelProperty(value = "属性", example = "10",notes = "只能填10或20,10代表整体计重，20代表单SKU计重")
    private String keHuShuXing;

    @NotBlank(message = "出库计费方式不能为空")
    @Pattern(regexp = "^(10|20)$", message = "输入的数字必须为10或20")
    @ApiModelProperty(value = "出库计费方式", example = "10",notes = "只能填10或20,10代表按吨，20代表单按托盘")
    private String keHuZhuangTai; // 原 customerOutboundChargingMethod

    @ApiModelProperty(value = "附件的地址",example = "[\"group/storageId/文件名.格式\"]")
    private List<String> zuZhiJiGou;

    @ApiModelProperty(value = "营业执照", example = "1111xw2222")
    private String yingYeZhiZhao; // 原 customerBusinessLicense
}
