package com.zeroone.star.project.vo.j8.other.goodsbrand;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.web.multipart.MultipartFile;

@Data
@ApiModel("商品品牌更新操作响应VO")
public class GoodsBrandUpdateOprationRespVO {
    @ApiModelProperty(value = "主键ID", example = "1")
    private String Id;
    @ApiModelProperty(value = "商品品牌代码", example = "KC")
    private String goodsBrandCode;
    @ApiModelProperty(value = "商品品牌名称", example = "可口可乐")
    private String goodsBrandName;
    @ApiModelProperty(value = "商品品牌网址", example = "www.koukele.com")
    private String goodsBrandWww;
    @ApiModelProperty(value = "商品品牌图片", example = "koukele.png")
    private String goodsBrandPic;
    @ApiModelProperty(value = "备注", example = "好喝的很")
    private String goodsBrandText;
    @ApiModelProperty(value = "是否停用", example = "0")
    private String goodsBrandDel;
}
