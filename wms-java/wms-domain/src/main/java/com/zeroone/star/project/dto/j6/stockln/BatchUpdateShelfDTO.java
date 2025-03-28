package com.zeroone.star.project.dto.j6.stockln;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import java.util.List;

/**
 * <p>
 * 批量上架货物 DTO
 * </p>
 *
 * @author ting
 * @since 2025-03-07
 */
@ApiModel(value = "BatchUpdateShelfDTO", description = "批量上架货物参数传输对象")
public class BatchUpdateShelfDTO {
    @ApiModelProperty(value = "货物ID列表", required = true, example = "[\"1\", \"2\"]")
    private List<String> ids;


    public List<String> getIds() {
        return ids;
    }

    public void setIds(List<String> ids) {
        this.ids = ids;
    }


}