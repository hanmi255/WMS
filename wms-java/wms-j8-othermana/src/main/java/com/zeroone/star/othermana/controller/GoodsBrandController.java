package com.zeroone.star.othermana.controller;

import cn.hutool.core.date.DateTime;
import com.alibaba.excel.EasyExcel;
import com.zeroone.star.othermana.entity.GoodsBrandListener;
import com.zeroone.star.othermana.service.BaGoodsBrandService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.j8.other.GoodsBrandApis;
import com.zeroone.star.project.query.j8.other.goodsbrand.GoodsBrandQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.other.goodsbrand.GoodsBrandAddReqVO;
import com.zeroone.star.project.vo.j8.other.goodsbrand.GoodsBrandUpdateOprationRespVO;
import com.zeroone.star.project.vo.j8.other.goodsbrand.GoodsBrandVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.util.List;

/**
 * @ClassName: GoodsBrandController
 * @Package: com.zeroone.star.goodsbrand.controller
 * @Description: 商品品牌
 * @Author: zk
 * @Create: 2025/2/26 - 上午10:02
 */
@RestController
@RequestMapping("othermana")
@Api(tags = "商品品牌")
public class GoodsBrandController implements GoodsBrandApis {

    @Autowired
    private BaGoodsBrandService baGoodsBrandService;

    @Resource
    EasyExcelComponent easyExcelComponent;


    @GetMapping("/goodsbrand/query-goodsbrand")
    @ApiOperation(value = "查询商品品牌列表接口")
    @Override
    public JsonVO<PageDTO<GoodsBrandVO>> queryGoodsBrand(@ModelAttribute GoodsBrandQuery query) {
        PageDTO<GoodsBrandVO> pageDTO = baGoodsBrandService.queryGoodsBrandPage(query);
        return JsonVO.success(pageDTO);
    }

    @PostMapping("/goodsbrand/add-goodsbrand")
    @ApiOperation(value = "录入商品品牌")
    @Override
    public JsonVO<String> addGoodsBrand(GoodsBrandAddReqVO goodsBrandAddReqVO) {
        boolean b = baGoodsBrandService.addGoodsBrand(goodsBrandAddReqVO);
        if (b){
            return JsonVO.success("录入成功");
        }
        return JsonVO.fail("失败");
    }

    @GetMapping ("/goodsbrand/modifybutton")
    @ApiOperation(value = "修改商品品牌按钮")
    @Override
    public JsonVO<GoodsBrandUpdateOprationRespVO> modifyGoodsBrand(String id) {
        return JsonVO.success(baGoodsBrandService.oprationGetById(id));
    }

    @DeleteMapping("/goodsbrand/remove-goodsbrand-by-ids")
    @ApiOperation(value = "删除商品品牌")
    @Override
    public JsonVO<String> removeGoodsBandByIds(@RequestBody List<String> ids) {
        baGoodsBrandService.removeByIds(ids);
        return JsonVO.success("删除成功");
    }

    @SneakyThrows
    @PostMapping(value = "/goodsbrand/export-goodsbrand", produces = "application/octet-stream")
    @ApiOperation(value = "导出商品品牌")
    @Override
    public ResponseEntity<byte[]> exportGoodsBrand(@RequestBody GoodsBrandQuery query){
        PageDTO<GoodsBrandVO> goodsBrandVOPageDTO = baGoodsBrandService.queryGoodsBrandPage(query);
        ByteArrayOutputStream os = new ByteArrayOutputStream();
        easyExcelComponent.export("商品品牌",os,GoodsBrandVO.class,goodsBrandVOPageDTO.getRows());
        String fileName ="excel-"+ DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        headers.setContentDispositionFormData("attachment", fileName);
        ResponseEntity<byte[]> responseEntity = new ResponseEntity<>(os.toByteArray(), headers, HttpStatus.CREATED);
        os.close();
        return responseEntity;
    }

    @SneakyThrows
    @PostMapping("/goodsbrand/import-goodsbrand")
    @ApiOperation(value = "导入商品品牌")
    @Override
    public JsonVO<String> importGoodsBrand(MultipartFile file) {
        boolean b = false;
        GoodsBrandListener goodsBrandListener = new GoodsBrandListener();
        EasyExcel.read(file.getInputStream(),GoodsBrandVO.class,goodsBrandListener).sheet().doRead();
        b = baGoodsBrandService.saveAll(goodsBrandListener.getList());
        if (b){
            return JsonVO.success("导入成功");
        }
        return JsonVO.fail("导入失败");
    }
}
