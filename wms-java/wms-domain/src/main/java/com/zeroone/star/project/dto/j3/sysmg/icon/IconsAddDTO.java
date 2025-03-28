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
@ApiModel("图标录入数据模型")
public class IconsAddDTO {
    @ApiModelProperty(value = "图标名称", example = "默认")
    private String name;
    @ApiModelProperty(value = "图标类型", example = "123")
    private Integer type;//图标类型
    @ApiModelProperty(value = "图标样式", example = "default")
    private String iconclas;//图标样式
//    @ApiModelProperty(value = "图标id", example = "8a8ab0b246dc81120146dc8180460000")
//    private String id;//图标id，通过设置图标路径
    @ApiModelProperty(value = "图标文件")
    private MultipartFile file;
}
