package com.zeroone.star.project.dto.j7.outmanage;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
/**
 * 文件信息DTO
 */
@Data
@ApiModel("附件文件信息")
public class FileInfoDTO {
    @ApiModelProperty("group")
    String group;
    @ApiModelProperty("storedId")
    String storedId;
    @ApiModelProperty("附件文件名")
    String fileName;
}