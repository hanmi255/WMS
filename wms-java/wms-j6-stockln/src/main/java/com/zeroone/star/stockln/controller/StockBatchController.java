package com.zeroone.star.stockln.controller;

import com.zeroone.star.project.dto.j6.stockln.*;
import com.zeroone.star.project.j6.stockln.StockBatchApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.stockln.service.IWmSttInGoodsService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

@RestController
@RequestMapping("/stockln")
@Api(tags = "收货登记")
public class StockBatchController implements StockBatchApis {

    @Resource
    private IWmSttInGoodsService sttInGoodsService;


    @PutMapping("/wm-stt-in-goods/batch-update-bin")
    @ApiOperation(value = "批量修改储位")
    public JsonVO<String> batchUpdateBin(@RequestBody BatchUpdateBinDTO dto) {
        if (dto.getIds() == null || dto.getIds().isEmpty()) {
            return JsonVO.fail("货物ID列表不能为空,请提供有效的货物ID列表");
        }
        int updatedCount = sttInGoodsService.batchUpdateBinIds(dto);
        return updatedCount > 0
                ? JsonVO.success("批量修改仓位成功,更新了" + updatedCount + "条记录")
                : JsonVO.fail("批量修改仓位失败");
    }

    @PutMapping("/wm-stt-in-goods/batch-update-production-date")
    @ApiOperation(value = "批量修改生产日期")
    public JsonVO<String> batchUpdateProductionDate(@RequestBody BatchUpdateProductionDateDTO dto) {
        // 校验ID列表是否为空
        if (dto.getIds() == null || dto.getIds().isEmpty()) {
            return JsonVO.fail("货物ID列表不能为空,请提供有效的货物ID列表");
        }
        int updatedCount = sttInGoodsService.batchUpdateProductionDate(dto);
        return updatedCount > 0
                ? JsonVO.success("批量修改生产日期成功,更新了" + updatedCount + "条记录")
                : JsonVO.fail("批量修改生产日期失败");
    }

    @PutMapping("/wm-stt-in-goods/batch-update-shelf")
    @ApiOperation(value = "批量上架货物")
    public JsonVO<String> batchUpdateShelf(@RequestBody BatchUpdateShelfDTO dto) {
        List<String> ids = dto.getIds();
        if (ids == null || ids.isEmpty()) {
            return JsonVO.fail("货物ID列表不能为空,请提供有效的货物ID列表");
        }
        int updatedCount = sttInGoodsService.batchUpdateShelf(dto);
        return updatedCount > 0
                ? JsonVO.success("批量上架成功,更新了"+ updatedCount +"条记录")
                : JsonVO.fail("批量上架失败");
    }
}