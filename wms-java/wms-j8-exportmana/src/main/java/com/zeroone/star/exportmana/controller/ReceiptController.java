package com.zeroone.star.exportmana.controller;

import com.zeroone.star.exportmana.service.impl.ReceiptServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.receiptmana.ReceiptBaseDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.receiptmana.ReceiptDeleteDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.receiptmana.ReceiptListDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.receiptmana.ReceiptPutDTO;
import com.zeroone.star.project.j8.shipmentmana.ReceiptApis;
import com.zeroone.star.project.query.j8.shipmentmana.receiptmana.ReceiptQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;

@RestController
@RequestMapping("exportmana")
@Api(tags = "回单管理")
public class ReceiptController implements ReceiptApis {
    @Resource
    private ReceiptServiceImpl Service;

    @GetMapping("/receipt/query")
    @ApiOperation(value = "查询回单接口")
    @Override
    public JsonVO<PageDTO<ReceiptListDTO>> queryReceiptList(@ModelAttribute ReceiptQuery query) {
        PageDTO<ReceiptListDTO> receipts = Service.getReceipt(query);
        return JsonVO.success(receipts);
    }

    @PostMapping("/receipt/add")
    @ApiOperation(value = "添加回单接口")
    @Override
    public JsonVO<String> addReceipt(@Validated @RequestBody ReceiptBaseDTO dto) {
        int res = Service.addReceipt(dto);
        if (res > 0) {
            return JsonVO.success("添加成功");
        }
        return JsonVO.fail("添加失败");
    }

    @PutMapping("/receipt/put")
    @ApiOperation(value = "修改回单接口")
    @Override
    public JsonVO<String> putReceipt(@Validated @RequestBody ReceiptPutDTO dto) {
        int res = Service.updateReceipt(dto);
        if (res > 0) {
            return JsonVO.success("修改成功");
        }
        return JsonVO.fail("修改失败");
    }

    @DeleteMapping("/receipt/delete")
    @ApiOperation(value = "撤销回单接口")
    @Override
    public JsonVO<String> deleteReceipt(@Validated @RequestBody ReceiptDeleteDTO dto) {
        int res = Service.deleteReceipt(dto);
        if (res > 0) {
            return JsonVO.success("撤销成功");
        }
        return JsonVO.fail("撤销失败");
    }

    @PostMapping("/receipt/import")
    @ApiOperation(value = "导入excel接口")
    @Override
    public JsonVO<String> imExcel(MultipartFile file) {
        int res = Service.importExcel(file);
        if (res > 0){
            return JsonVO.success("导入成功，导入"+res+"条数据");
        }
        return JsonVO.fail("导入失败");
    }

    @GetMapping(value = "/receipt/export",produces = "application/octet-stream")
    @ApiOperation("导出excel接口")
    @Override
    public ResponseEntity<byte[]> exExcel() {
        return Service.exportExcel();
    }
}
