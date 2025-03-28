package com.zeroone.star.project.query.j8.other.port;

import com.zeroone.star.project.query.PageQuery;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.AllArgsConstructor;
import lombok.Data;
import lombok.NoArgsConstructor;
/**
 * <p>
 * 描述：港口信息查询对象
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author yjq
 * @version 1.0.0
 */
@Data
@NoArgsConstructor
@AllArgsConstructor
@ApiModel("港口信息查询对象")
public class PortQuery extends PageQuery {
    @ApiModelProperty(value = "港口代码", example = "")
    private String portCode;
    @ApiModelProperty(value = "中文名称", example = "")
    private String portZhName;
    @ApiModelProperty(value = "英文名称", example = "")
    private String portEnName;
    @ApiModelProperty(value = "港口三字代码", example = "")
    private String portThCode;
}
