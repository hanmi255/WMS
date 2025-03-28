package com.zeroone.star.project.dto.j5.basezl.customer;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.validation.constraints.NotBlank;
import javax.validation.constraints.Pattern;

/**
 * <p>
 * 描述：客户继承数据模型
 * </p>
 *
 * @author 小夏
 * @version 1.0.0
 */
@Getter
@Setter
@ToString
@ApiModel("客户继承数据模型")
public class CustomerBaseDTO {
        // 原字段名 -> 新字段名（对应 MdCus 字段）
        @NotBlank(message = "中文全称不为空")
        @ApiModelProperty(value = "中文全称", example = "可口可乐公司")
        private String zhongWenQch; // 原 customerName

        @ApiModelProperty(value = "合同号", example = "333")
        private String zhuJiMa; // 原 customerHeTong

        @ApiModelProperty(value = "企业属性", example = "01",notes = "01代表客户，02代表供应商")
        @Pattern(regexp = "^(01|02)$", message = "输入的数字必须为01或02")
        private String xingYeFenLei; // 原 customerEnterprise

        @ApiModelProperty(value = "地址", example = "地址")
        private String diZhi; // 原 customerAddress

        @ApiModelProperty(value = "负责人", example = "张三")
        private String zhuLianXiRen; // 原 customerPrincipal

        @ApiModelProperty(value = "电话", example = "028-011-011")
        private String dianHua; // 原 customerPhone

        @ApiModelProperty(value = "手机", example = "138xxxxxxxxx")
        private String shouJi; // 原 customerMobile

        @ApiModelProperty(value = "联系人1", example = "李四")
        private String zhuLianXiRen1; // 原 customerContact

        @ApiModelProperty(value = "电话1", example = "028-011-012")
        private String dianHua1; // 原 customerPhone1

        @ApiModelProperty(value = "Email地址", example = "192@qq.com")
        private String emaildiZhi; // 原 customerEmail

        @ApiModelProperty(value = "备注", example = "这是一个长期合作的客户")
        private String beiZhu; // 原 customerRemark

}
