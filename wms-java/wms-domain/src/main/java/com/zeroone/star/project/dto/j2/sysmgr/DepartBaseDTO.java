/**
 * @ClassName : OrganizationBaseDTO  //类名
 * @Description : 组织机构继承数据模型  //描述
 * @Author : 全息主角 //作者
 * @Date: 2025/2/22  13:18
 */

package com.zeroone.star.project.dto.j2.sysmgr;

import com.baomidou.mybatisplus.annotation.FieldStrategy;
import com.baomidou.mybatisplus.annotation.TableField;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
@ApiModel("组织机构基础数据对象")
public class DepartBaseDTO {

    /**
     * 组织机构id
     */
    @ApiModelProperty(value = "组织机构id", example = "2c9221a470adc6fc0170ecef9dd4029e")
    private String id;
    /**
     * 组织机构名称
     */
    @ApiModelProperty(value = "组织机构名称", example = "上海零壹星辰科技有限公司")
    private String departName;

    /**
     * 组织机构描述
     */
    @ApiModelProperty(value = "组织机构描述", example = "这是一家做家电售卖的企业")
    private String description;


    /**
     * 组织机构类型
     */
    @ApiModelProperty(value = "组织机构编码", example = "1:公司(前端) 2:组织机构")
    private String orgType;

    /**
     * 组织机构编码
     */
    @ApiModelProperty(value = "组织机构类型", example = "A31")
    private String orgCode;

    /**
     * 电话
     */
    @ApiModelProperty(value = "电话", example = "123456789")
    private String mobile;

    /**
     * 传真
     */
    @ApiModelProperty(value = "传真", example = "26737123")
    private String fax;

    /**
     * 地址
     */
    @ApiModelProperty(value = "地址", example = "上海市浦东新区")
    private String address;

    @TableField(value = "parentdepartid", updateStrategy = FieldStrategy.IGNORED)
    @ApiModelProperty(value = "上级组织机构", example = "2c9221a470adc6fc0170ecef9dd4029e:厦门境图智能科技有限公司(前端显示)")
    private String parentId;

    /**
     * 是否存在成员
     */
    @ApiModelProperty(value = "是否存在成员0代表没有1代表有", example = "0")
    @TableField(value = "depart_order", updateStrategy = FieldStrategy.IGNORED)
    private String departOrder;

    public void setDepartOrder(String departOrder) {
        // 如果传入的是字符串 "null"，将其转换为真正的 null
        if ("null".equalsIgnoreCase(departOrder)) {
            this.departOrder = null;
        } else {
            this.departOrder = departOrder;
        }
    }

}
