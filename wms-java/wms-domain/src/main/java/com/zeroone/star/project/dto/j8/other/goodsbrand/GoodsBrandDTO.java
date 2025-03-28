package com.zeroone.star.project.dto.j8.other.goodsbrand;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;

import java.util.Date;

/**
 * @ClassName: GoodsBrandDTO
 * @Package: com.zeroone.star.project.dto.j8.other.goodsbrand
 * @Description: 商品品牌DTO对象
 * @Author: zk
 * @Create: 2025/2/26 - 上午9:03
 */
@Data
@ApiModel("商品品牌DTO对象")
public class GoodsBrandDTO {
    @ApiModelProperty(value = "主键", example = "402880d38e31aba8018e35414b7f0008")
    private String id;
    @ApiModelProperty(value = "创建人名字", example = "小智")
    private String createName;
    @ApiModelProperty(value = "创建人", example = "xiaozhi")
    private String createBy;
    @ApiModelProperty(value = "创建时间", example = "2025-02-26 09:09:18")
    private Date createDate;
    @ApiModelProperty(value = "修改人名字", example = "小智")
    private String updateName;
    @ApiModelProperty(value = "修改人", example = "xiaozhi")
    private String updateBy;
    @ApiModelProperty(value = "修改时间", example = "2025-02-26 09:09:18")
    private Date updateDate;
    @ApiModelProperty(value = "所属部门", example = "开发部")
    private String sysOrgCode;
    @ApiModelProperty(value = "所属公司", example = "上海零壹科技有限公司")
    private String sysCompanyCode;
    @ApiModelProperty(value = "商品品牌代码", example = "KC")
    private String goodsBrandCode;
    @ApiModelProperty(value = "商品品牌名称", example = "可口可乐")
    private String goodsBrandName;
    @ApiModelProperty(value = "商品品牌网址", example = "www.koukele.com")
    private String goodsBrandWww;
    @ApiModelProperty(value = "商品品牌图片", example = "http://www.koukele.com/logo.jpg")
    private String goodsBrandPic;
    @ApiModelProperty(value = "备注", example = "好喝的很")
    private String goodsBrandText;
    @ApiModelProperty(value = "是否删除", example = "0")
    private String goodsBrandDel;
}
