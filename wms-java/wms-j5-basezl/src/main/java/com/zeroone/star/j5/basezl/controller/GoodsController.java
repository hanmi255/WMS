package com.zeroone.star.j5.basezl.controller;

import com.zeroone.star.j5.basezl.service.GoodsService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.basezl.goods.GoodsAddDTO;
import com.zeroone.star.project.dto.j5.basezl.goods.GoodsDetailDTO;
import com.zeroone.star.project.dto.j5.basezl.goods.GoodsListDTO;
import com.zeroone.star.project.dto.j5.basezl.goods.GoodsModifyDTO;
import com.zeroone.star.project.j5.basezl.GoodsApis;
import com.zeroone.star.project.query.j5.basezl.goods.GoodsQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.util.List;

@Controller
@RequestMapping("/goods")
@Api(tags = "商品管理接口实现")
public class GoodsController implements GoodsApis {

    @Resource
    GoodsService service;

    @GetMapping("query-all")
    @ApiOperation(value = "获取商品列表(条件+分页)接口")
    @ResponseBody
    @Override
    public JsonVO<PageDTO<GoodsListDTO>> queryAll(GoodsQuery query) {
        return JsonVO.success(service.queryAll(query));
    }

    @GetMapping("query-one")
    @ApiOperation(value = "获取商品详细信息接口")
    @ResponseBody
    @Override
    public JsonVO<GoodsDetailDTO> queryOne(String shp_bian_ma) {
        return JsonVO.success(service.queryOne(shp_bian_ma));
    }

    @PostMapping("add-goods")
    @ApiOperation(value = "录入商品接口")
    @ResponseBody
    @Override
    public JsonVO<String> addGoods(@RequestBody GoodsAddDTO goodsAddDTO) {
        return JsonVO.success(service.addGoods(goodsAddDTO));
    }

    @PutMapping("update-goods")
    @ApiOperation(value = "修改商品接口")
    @ResponseBody
    @Override
    public JsonVO<String> updateGoods(@RequestBody GoodsModifyDTO goodsModifyDTO) {
        return JsonVO.success(service.updateGoods(goodsModifyDTO));
    }

    @DeleteMapping("delete-goods")
    @ApiOperation(value = "删除商品(支持批量删除)接口")
    @ResponseBody
    @Override
    public JsonVO<String> deleteGoods(@RequestBody List<String> shpBianMas) {
        return JsonVO.success(service.deleteGoods(shpBianMas));
    }


    @PostMapping("upload")
    @ApiOperation(value = "导入商品")
    @ResponseBody
    @Override
    public JsonVO<String> uploadGoods(@RequestBody MultipartFile file) {
        return service.uploadGoods(file);
    }


    @GetMapping(value = "download", produces = "application/octet-stream")
    @ApiOperation(value = "导出商品")
    @Override
    public ResponseEntity<byte[]> exportGoods(@RequestParam List<String> shpBianMas) {
        return service.exportGoods(shpBianMas);
    }

    @GetMapping(value = "print")
    @ApiOperation(value = "打印标签")
    @Override
    public ResponseEntity<byte[]> printGoodsTiaoMa(String shpBianMa) {
        return service.printGoodsTiaoMa(shpBianMa);
    }

}
