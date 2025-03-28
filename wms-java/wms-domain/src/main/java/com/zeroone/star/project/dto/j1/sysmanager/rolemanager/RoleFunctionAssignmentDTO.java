package com.zeroone.star.project.dto.j1.sysmanager.rolemanager;

import com.fasterxml.jackson.annotation.JsonInclude;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.util.List;

/**
 * <p>
 * 描述：角色资源分配数据模型
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @author 匿名的好友
 * @version 1.0.0
 */
@Getter
@Setter
@ToString
@ApiModel(value = "角色资源分配数据模型")
@JsonInclude(JsonInclude.Include.NON_NULL) // 忽略 null 字段
public class RoleFunctionAssignmentDTO{

    @ApiModelProperty(value = "角色编码", example = "cw")
    private String roleCode;

    @ApiModelProperty(value = "语言", example = "zh-cn")
    private String langType;

    @ApiModelProperty(value = "资源列表")
    private List<RoleFunctionDTO> roleFunctionAssignment;

    // 新增错误状态字段
    private String errorCode;
    private String errorMessage;

    public void setError(String errorCode, String errorMessage) {
        this.errorCode = errorCode;
        this.errorMessage = errorMessage;
    }
    public boolean hasError() {
        return errorCode != null;
    }
    public String getErrorCode() { return errorCode; }
    public String getErrorMessage() { return errorMessage; }
}