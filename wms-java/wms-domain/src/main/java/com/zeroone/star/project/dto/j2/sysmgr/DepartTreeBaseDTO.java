package com.zeroone.star.project.dto.j2.sysmgr;


import com.fasterxml.jackson.annotation.JsonProperty;
import com.zeroone.star.project.utils.tree.TreeNode;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.util.List;

@Getter
@Setter
@ToString
@ApiModel("组织树节点结构")
public class DepartTreeBaseDTO extends TreeNode {
    @JsonProperty("tnId")
    @ApiModelProperty(value = "部门ID", example = "2c9221a470adc6fc0170ecef9dd4029e")
    public String getTnId() {
        return tnId;
    }

    @JsonProperty("tnPid")
    @ApiModelProperty(value = "父部门ID", example = "2c9221a470adc6fc0170ecef9dd4029e")
    public String getTnPid() {
        return tnPid;
    }

//    @JsonProperty("tnDepth")
//    public Integer getTnDepth() {
//        return tnDepth;
//    }
    @ApiModelProperty(value = "组织名称", example = "广州华壹智能科技有限公司")
    private String departName;
    @ApiModelProperty(value = "类型（公司、组织、岗位）", example = "公司")
    private String type;

    @JsonProperty("tnChildren")
    @ApiModelProperty(value = "子节点", example = "'tnChildren' [ " +
            "{'departName': '测试岗位', " +
            "'type': '岗位' " +
            "'tnId': '402897819537330301953734249b0003', " +
            "'tnPid': '40289781952bc1ea01952c0b1822000d' }]")
    public List<TreeNode> getTnChildren() {
        return tnChildren;
    }
}
