package com.zeroone.star.othermana.controller;

import com.zeroone.star.othermana.service.BaContTypeService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.other.baconttype.BaContTypeDTO;
import com.zeroone.star.project.j8.other.BaContTypeApis;
import com.zeroone.star.project.query.j8.other.baconttype.BaContTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.j8.other.baconttype.BaContTypeVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

//箱型管理接口实现
@RestController
@RequestMapping("contshape")
@Api(tags = "箱型管理接口实现")
public class ContTypeController implements BaContTypeApis {

    //controller-->service-->dao-->mapper(ContShapeMapper.xml)
    @Autowired
    private BaContTypeService baContTypeService;

    @GetMapping("queryAll")
    @ApiOperation(value = "箱型列表查询接口")
    @Override
    public JsonVO<PageDTO<BaContTypeVO>> query(@ModelAttribute BaContTypeQuery dto) {
        PageDTO<BaContTypeVO> pageDTO = baContTypeService.pageQuery(dto);
        return JsonVO.success(pageDTO);
    }

    @GetMapping("query/{id}")
    @ApiOperation(value = "查看箱型详情接口")
    @Override
    public JsonVO<BaContTypeVO> queryBaContType(@Validated @PathVariable String id) {
        return baContTypeService.queryBaContType(id);
    }

    @PostMapping("add")
    @ApiOperation(value = "新增箱型接口")
    @Override
    public JsonVO<ResultStatus> addBaContType(@Validated @RequestBody BaContTypeDTO dto) {
        baContTypeService.addBaContType(dto);
        return JsonVO.success(ResultStatus.SUCCESS);
    }

    @PutMapping("modify")
    @ApiOperation(value = "修改箱型接口")
    @Override
    public JsonVO<ResultStatus> modifyBaContType(@Validated @RequestBody BaContTypeDTO dto) {
        baContTypeService.updateById(dto);
        return JsonVO.success(ResultStatus.SUCCESS);
    }

    @DeleteMapping("delete")
    @ApiOperation(value = "删除箱型接口")
    @Override
    public JsonVO<ResultStatus> removeCont_shape(@Validated @RequestParam List<String> ids) {

        baContTypeService.removeBaContType(ids);
        return JsonVO.success(ResultStatus.SUCCESS);
    }
    //
    @ApiOperation("导出报表")
    @GetMapping(value = "export", produces = "application/octet-stream")
    @Override
    public ResponseEntity<byte[]> exportExcel() {
        return baContTypeService.exportExcel();

    }


    @ApiOperation("导入报表")
    @PostMapping(value = "import")
    @Override
    public JsonVO<ResultStatus> importExcel(@RequestParam("file") MultipartFile file) {
        try {
            baContTypeService.importExcel(file);
            return JsonVO.success(ResultStatus.SUCCESS);
        } catch (Exception e) {
            return JsonVO.success(ResultStatus.FAIL);
        }
    }
}