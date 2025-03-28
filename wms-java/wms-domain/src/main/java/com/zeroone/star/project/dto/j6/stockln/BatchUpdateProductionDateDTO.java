package com.zeroone.star.project.dto.j6.stockln;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import java.util.List;

/**
 * <p>
 * 批量更新生产日期请求DTO
 * </p>
 *
 * @author ting
 * @since 2025-03-06
 */
@ApiModel(value = "BatchUpdateProductionDateDTO", description = "批量更新生产日期请求参数")
public class BatchUpdateProductionDateDTO {

    /**
     * 商品ID列表
     */
    @ApiModelProperty(value = "商品ID列表", required = true,example = "[\"1\", \"2\"]")
    private List<String> ids;

    /**
     * 新的生产日期
     */
    @ApiModelProperty(value = "新的生产日期", required = true,example = "2025-03-19")
    private String newProductionDate;

    public List<String> getIds() {
        return ids;
    }

    public void setIds(List<String> ids) {
        this.ids = ids;
    }

    public String getNewProductionDate() {
        return newProductionDate;
    }

    public void setNewProductionDate(String newProductionDate) {
        this.newProductionDate = newProductionDate;
    }
}