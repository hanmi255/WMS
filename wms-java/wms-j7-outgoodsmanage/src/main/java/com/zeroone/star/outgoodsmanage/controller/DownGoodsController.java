package com.zeroone.star.outgoodsmanage.controller;


import com.zeroone.star.outgoodsmanage.service.IWmToDownGoodsService;
import com.zeroone.star.outgoodsmanage.service.IWmToUnpublishService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.downgoods.DownGoodsDTO;
import com.zeroone.star.project.dto.j7.downgoods.UnpublishDTO;
import com.zeroone.star.project.j7.downgoods.DownGoodsApis;
import com.zeroone.star.project.j7.downgoods.UnpublishApis;
import com.zeroone.star.project.query.j7.downgoods.UnpublishQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.constraints.Min;
import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 商品下架 前端控制器
 * </p>
 *
 * @author rocklin
 * @since 2025-02-23
 */
@RestController
@RequestMapping("/outgoodsmanage/wm-to-down-goods/")
@Api(tags = "商品下架接口实现")
public class DownGoodsController implements DownGoodsApis, UnpublishApis {

    @Resource
    IWmToDownGoodsService wmToDownGoodsService;



    @Resource
    private IWmToUnpublishService wmToUnpublishService;

    @Override
    @ApiOperation("获取下架列表（条件+分页）")
    @GetMapping("list")
    public JsonVO<PageDTO<UnpublishDTO>> queryUnpublishList(@Validated @ModelAttribute UnpublishQuery query) {
        // 参数校验
        if (query.getPageIndex() <= 0) {
            query.setPageIndex(1L);
        }
        if (query.getPageSize() <= 0) {
            query.setPageSize(10L);
        }

        // 调用服务层方法
        PageDTO<UnpublishDTO> pageDTO = wmToUnpublishService.queryUnpublishList(query);

        // 返回结果
        return JsonVO.success(pageDTO);
    }

    @Override
    @ApiOperation("获取下架详情")
    @GetMapping("{id}")
    public JsonVO<UnpublishDTO> getUnpublishById(@PathVariable String id) {
        // 参数校验
        if (id == null || id.isEmpty()) {
            return JsonVO.fail(null);
        }

        // 调用服务层方法
        UnpublishDTO dto = wmToUnpublishService.getUnpublishById(id);

        // 返回结果
        return dto != null ? JsonVO.success(dto) : JsonVO.fail(null);
    }

    @Override
    @ApiOperation("修改下架信息")
    @PutMapping("modify")
    public JsonVO<String> modifyUnpublish(@Validated @RequestBody UnpublishDTO dto) {
        // 参数校验
        if (dto == null || dto.getOrderId() == null || dto.getGoodsId() == null) {
            return JsonVO.fail("参数不完整");
        }

        // 调用服务层方法
        boolean result = wmToUnpublishService.modifyUnpublish(dto);

        // 返回结果
        return result ? JsonVO.success("修改成功") : JsonVO.fail("修改失败");
    }

    @PostMapping("batch-update-down-goods")
    @ApiOperation("批量修改下架商品信息")
    @Override
    public JsonVO<String> batchUpdateDownGoods(
            @Validated @RequestBody List<DownGoodsDTO> downGoodsDTOList) {
        //对传入的商品信息进行校验
        //修改下架商品信息
        if(wmToDownGoodsService.batchUpdateDownGoods(downGoodsDTOList)!=0){
            //返回成功信息
            return JsonVO.success(null);
        }else {
            //返回失败信息
            return JsonVO.fail(null);
        }
    }

    @PostMapping("down-goods")
    @ApiOperation("下架商品 (支持批量下架）")
    @Override
    public JsonVO<String> downGoods(
            @Min(value = 1, message = "ID最小值为1")
            @RequestBody List<String> ids) {
        //对传入的id进行进行校验
        //下架商品
        if(wmToDownGoodsService.downGoods(ids)!=0){
            //返回成功信息
            return JsonVO.success(null);
        }else {
            //返回失败信息
            return JsonVO.fail(null);
        }
    }

    @GetMapping("delete-down-goods")
    @ApiOperation("删除下架任务")
    @Override
    public JsonVO<String> deleteDownGoods(
            @Min(value = 1, message = "ID最小值为1")
            @RequestParam String id) {
        //对传入的id进行进行校验
        //删除下架任务
        if(wmToDownGoodsService.removeDownGoods(id)!=0){
            //返回成功信息
            return JsonVO.success(null);
        }else {
            //返回失败信息
            return JsonVO.fail(null);
        }
    }

    @GetMapping(value = "export-down-goods-data",produces = "application/octet-stream")
    @ApiOperation("导出下架数据")
    public ResponseEntity<byte[]> exportDownGoodsData(@RequestParam List<String> ids) throws Exception {
        //TODO实现导出
        ResponseEntity<byte[]> responseEntity = wmToDownGoodsService.exportDownGoods(ids);
        return responseEntity;

    }
}

