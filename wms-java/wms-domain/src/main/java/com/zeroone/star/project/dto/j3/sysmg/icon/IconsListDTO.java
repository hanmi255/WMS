package com.zeroone.star.project.dto.j3.sysmg.icon;

import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

/**
 * @author Vast
 * @version 1.0
 * @function:图标管理列表数据模型
 */
@SuppressWarnings({"all"})
@ToString
@Getter
@Setter
@ApiModel("图标管理列表数据模型")
public class IconsListDTO {
//    @ApiModelProperty(value = "唯一标识", example = "8a8ab0b246dc81120146dc8180460000")
//    private String id;
    @ApiModelProperty(value = "图标名称", example = "默认")
    private String name;
    @ApiModelProperty(value = "图标样式", example = "default")
    private String iconclas;//图标样式
    @ApiModelProperty(value = "图标类型", example = "123")
    private Integer type;//图标类型
    @ApiModelProperty(value = "图标下载地址", example = "plug-in/accordion/images/default.png")
    private String url;//图标下载地址
//    @ApiModelProperty(value = "回显图标")
//    private ResponseEntity<byte[]> response;
//    @ApiModelProperty(value = "显示图标")
//    private MultipartFile file;
    @ApiModelProperty(value = "图标后缀", example = "png")
    private String extend;//图标后缀
}
