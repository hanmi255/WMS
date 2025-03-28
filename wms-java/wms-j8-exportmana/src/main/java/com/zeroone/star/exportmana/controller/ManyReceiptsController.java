package com.zeroone.star.exportmana.controller;

import com.zeroone.star.exportmana.service.ManyReceiptsService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.manyreceipts.ManyRecepitsDTO;
import com.zeroone.star.project.j8.shipmentmana.ManyReceiptsApis;
import com.zeroone.star.project.query.j8.shipmentmana.manyreceipts.ManyReceiptsQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("exportmana")
@Api(tags = "批量回单")
public class ManyReceiptsController implements ManyReceiptsApis {

    @Autowired
    private ManyReceiptsService manyReceiptsService;

    @Override
    @PostMapping("/manyreceipts/query")
    @ApiOperation(value = "查询批量回单")
    public JsonVO<PageDTO<ManyRecepitsDTO>> queryManyReceiptsList(@RequestBody ManyReceiptsQuery manyReceiptsQuery) {
        PageDTO<ManyRecepitsDTO> pageDTO = manyReceiptsService.queryManyReceiptsList(manyReceiptsQuery);
        return JsonVO.success(pageDTO);
    }

    @PutMapping("/manyreceipts/put")
    @ApiOperation(value = "更新批量回单")
    @Override
    public JsonVO<String> putManyReceipts(@RequestBody List<ManyRecepitsDTO> manyReceiptsDTOList) {
        int count = manyReceiptsService.updateListManyReceipts(manyReceiptsDTOList);
        if (count > 0) {
            return JsonVO.success("更新成功");
        }else {
            return JsonVO.fail("更新失败");
        }
    }


}
