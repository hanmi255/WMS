package com.zeroone.star.project.dto.j6.stockln;

import io.swagger.annotations.ApiModel;
import io.swagger.annotations.ApiModelProperty;
import java.util.List;

/**
 * <p>
 * 批量更新仓位 DTO
 * </p>
 *
 * @author ting
 * @since 2025-03-06
 */
@ApiModel(value = "BatchUpdateBinDTO", description = "批量更新储位参数传输对象")
public class BatchUpdateBinDTO {

    @ApiModelProperty(value = "需要更新的储位ID列表", required = true, example = "[\"1\", \"2\"]")
    private List<String> ids;

    @ApiModelProperty(value = "新的目标储位ID", required = true, example = "BIN-2025")
    private String newBinId;

    // Getter 和 Setter 方法
    public List<String> getIds() {
        return ids;
    }
    public void setIds(List<String> ids) {
        this.ids = ids;
    }
    public String getNewBinId() {
        return newBinId;
    }
    public void setNewBinId(String newBinId) {
        this.newBinId = newBinId;
    }
}