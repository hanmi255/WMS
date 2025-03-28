package com.zeroone.star.project.dto.j3.sysmg.multilang;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

import javax.annotation.Nullable;

/**
 * @program: wms-java
 * @description: 多语言管理通用基础数据实体
 * <p>在更新/录入语言对照时使用</p>
 * @author: hamhuo
 **/

@ToString
@Getter
@Setter
@ApiModel(value = "语言对照基础DTO, 在更新和录入语言对照时使用")
public class MultiLangBaseDTO {
    //唯一标识, 录入时有系统分配id, 请求时可以传空值
    @ApiModelProperty(value = "唯一标识, 在语言对照录入时可以传入空值, 其余情况必须", example = "0ab1a1fddf14420fa0dbcbfb5d2e9e85")
    private String id;
    //语言码, 必须
    @ApiModelProperty(value = "语言码, 必须", example = "en", required = true)
    private String keyCode;
    //Key
    @ApiModelProperty(value = "语言键值, 必须", example = "common.password", required = true)
    private String langKey;
    //value
    @ApiModelProperty(value = "内容, 必须", example = "密码", required = true)
    private String langContext;
}