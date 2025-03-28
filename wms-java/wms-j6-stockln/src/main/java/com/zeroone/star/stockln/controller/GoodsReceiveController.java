package com.zeroone.star.stockln.controller;
import com.zeroone.star.project.dto.j6.stockln.BatchModifyBinDTO;
import com.zeroone.star.project.dto.j6.stockln.ModifyShelvesDTO;
import lombok.extern.slf4j.Slf4j;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.stockln.InboundQmIDTO;
import com.zeroone.star.project.dto.j6.stockln.ToShelvesDTO;
import com.zeroone.star.project.j6.stockln.GoodsReceiveApis;
import com.zeroone.star.project.query.j6.stockln.ToShelvesQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.stockln.InboundQmIVO;
import com.zeroone.star.stockln.service.IToShelvesService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.http.MediaType;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import javax.validation.Valid;

@Api(tags = "收货登记")
@RestController
@RequestMapping("/stock/good-receive")
@Validated
@Slf4j
public class GoodsReceiveController implements GoodsReceiveApis {

    @Resource
    IToShelvesService iToShelvesService;

    /**
     * 待上架货物列表分页查询
     *
     * @param
     * @return
     */
    @GetMapping("/query-all")
    @ApiOperation("待上架货物列表分页查询")
    public JsonVO<PageDTO<InboundQmIDTO>> pageToSheleves(ToShelvesQuery toShelvesQuery) {
        PageDTO<InboundQmIDTO> pageDTO = iToShelvesService.listall(toShelvesQuery);
        return JsonVO.success(pageDTO);
    }

    /**
     * 待上架货物详细信息查询
     *
     * @param
     * @return
     */
    @GetMapping("/{id}")
    @ApiOperation("待上架货物详细信息查询")
    public JsonVO<InboundQmIDTO> getShelevesByid(@PathVariable String id) {
        InboundQmIDTO dto = iToShelvesService.myGetById(id);
        return JsonVO.success(dto);
    }

    @ApiOperation(value = "录入待上架货物")
    @PostMapping("/addItem")
    public JsonVO<String> addItem(@RequestBody @Valid ToShelvesDTO dto) {
        log.info("收到前端请求，录入待上架货物: {}", dto);
        iToShelvesService.insertItem(dto);
        return JsonVO.success("添加成功");
    }

    @ApiOperation(value = "删除待上架货物")
    @DeleteMapping("/{id}")
    public JsonVO<String> removeItem(@PathVariable String id) {

        if (iToShelvesService.deleteById(id)) {
            return JsonVO.success("删除成功");
        }
        return JsonVO.fail("删除失败");
    }

    @ApiOperation(value = "修改待上架货物信息")
    @PostMapping("/modifyItem")
    public JsonVO<String> modifyItem(@RequestBody ModifyShelvesDTO dto) {
        // 调用 Service 层的方法进行修改操作
        iToShelvesService.modifyShelvesInfo(dto);
        return JsonVO.success("修改成功");
    }

    @ApiOperation(value = "批量修改储位")
    @PostMapping("/batchModifyBin")
    public JsonVO<String> batchModifyBin(@RequestBody BatchModifyBinDTO dto) {
        // 调用 Service 层的方法进行批量修改储位操作
        boolean result = iToShelvesService.batchModifyBin(dto.getIds(), dto.getBinId());

        // 根据操作结果返回相应的响应
        if (result) {
            return JsonVO.success("批量修改储位成功");
        } else {
            return JsonVO.fail("批量修改储位失败");
        }
    }

    // 导入报表接口
    @ApiOperation(value = "Excel批量导入待上架货物")
    @PostMapping(value = "/importItems", consumes = MediaType.MULTIPART_FORM_DATA_VALUE)
    public JsonVO<InboundQmIVO> importItems(
            @ApiParam(value = "Excel文件", required = true)
            @RequestParam("file") MultipartFile file) {
        return null;
    }


    @ApiOperation(value = "导出全部待上架货物报表")
    @GetMapping("/exportAllItems")
    public JsonVO<String> exportAllItems() {
        return null;
    }
}
