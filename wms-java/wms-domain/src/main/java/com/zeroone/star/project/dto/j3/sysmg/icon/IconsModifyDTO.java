package com.zeroone.star.project.dto.j3.sysmg.icon;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;
import org.springframework.web.multipart.MultipartFile;

/**
 * @author Vast
 * @version 1.0
 * @function:图标名称列表数据模型
 */
@SuppressWarnings({"all"})
@ToString
@Getter
@Setter
@ApiModel("图标编辑数据模型")
public class IconsModifyDTO {
    @ApiModelProperty(value = "图标名称", example = "默认")
    private String name;
    @ApiModelProperty(value = "图标类型", example = "123")
    private Integer type;//图标类型
    @ApiModelProperty(value = "图标样式", example = "default")
    private String iconclas;//图标样式
    @ApiModelProperty(value = "图标路径", example = "plug-in/accordion/images/default.png")
    private String url;//图标路径，用于回滚显示图标
    @ApiModelProperty(value = "图标文件")
    private MultipartFile file;
}
