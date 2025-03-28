package com.zeroone.star.project.dto.j1.sysmanager.menumanager;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import java.util.Date;

@Getter
@Setter
@ToString
@ApiModel("录入菜单数据模型")
public class MenuCreateDTO extends MenuManagementBaseDTO{
//使用继承基础dto插入不进去，所以使用自己的


  //  private String id;

    @ApiModelProperty(value = "菜单地址打开方式", example = "0", required = false)
    private Integer functionIframe;

    //@ApiModelProperty(value = "菜单等级", example = "1", required = true)
    //private Integer functionLevel;

    //@ApiModelProperty(value = "菜单名称", example = "用户管理", required = true)
    //private String functionName;

    //@ApiModelProperty(value = "菜单顺序", example = "001", required = true)
   // private String functionOrder;

   // @ApiModelProperty(value = "URL", example = "/user", required = false)
    //private String functionUrl;

    @ApiModelProperty(value = "父菜单ID", example = "000")
    private String parentFunctionId;

    //@ApiModelProperty(value = "图标ID", example = "icon001")
   // private String iconId;

   // @ApiModelProperty(value = "桌面图标ID", example = "desk001")
    //private String deskIconId;

    //@ApiModelProperty(value = "菜单类型", example = "0", required = true)
    //private Integer functionType;

    //@ApiModelProperty(value = "ace图标样式", example = "default")
    //private String functionIconStyle;

    private String createBy;

    private String createName;

    private String updateBy;

    private Date createDate;

    private Date updateDate;

    private String updateName;

}
