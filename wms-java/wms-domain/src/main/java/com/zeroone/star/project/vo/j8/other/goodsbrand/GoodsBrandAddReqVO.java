package com.zeroone.star.project.vo.j8.other.goodsbrand;

import com.baomidou.mybatisplus.annotation.TableName;
import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import lombok.Data;
import org.springframework.web.multipart.MultipartFile;

@Data
@ApiModel("商品品牌添加请求VO对象")
public class GoodsBrandAddReqVO {
    @ApiModelProperty(value = "商品品牌代码", example = "KC")
    private String goodsBrandCode;
    @ApiModelProperty(value = "商品品牌名称", example = "可口可乐")
    private String goodsBrandName;
    @ApiModelProperty(value = "商品品牌网址", example = "www.koukele.com")
    private String goodsBrandWww;
    @ApiModelProperty(value = "商品品牌图片", example = "koukele.png")
    private MultipartFile goodsBrandPic;
    @ApiModelProperty(value = "备注", example = "好喝的很")
    private String goodsBrandText;
    @ApiModelProperty(value = "停用状态", example = "0正常|1停用")
    private String goodsBrandDel;
}
