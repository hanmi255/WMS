package com.zeroone.star.project.query.j2.sysmgr;


import com.fasterxml.jackson.annotation.JsonProperty;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.*;

import java.util.List;

/**
 * <p>
 * 描述：组织导出参数
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author TWTW
 * @version 1.0.0
 */
@Getter
@Setter
@ToString
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("组织导出参数")
public class OrgExportQuery {
    @ApiModelProperty(value = "部门ID列表")
    private List<String> departIds;
    @ApiModelProperty(value = "操作人名称", hidden = true)
    private String operatorName;

}
