package com.zeroone.star.othermana.controller;

import com.zeroone.star.othermana.service.impl.BaContSpecServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.other.contspec.SpecificationAddDTO;
import com.zeroone.star.project.dto.j8.other.contspec.SpecificationBaseDTO;
import com.zeroone.star.project.dto.j8.other.contspec.SpecificationDeleteDTO;
import com.zeroone.star.project.dto.j8.other.contspec.SpecificationModifyDTO;
import com.zeroone.star.project.j8.other.SpecificationApis;
import com.zeroone.star.project.query.j8.other.contspec.SpecificationQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import javax.validation.Valid;
import javax.validation.constraints.NotBlank;
import java.util.List;

/**
 * <p>
 * 描述：客户管理接口实现
 * </p>
 * <p>地址：01星球总部</p>
 * @author xban
 * @version 1.0.0
 */
@RestController
@RequestMapping("othermana")
@Api(tags = "箱规管理")
public class SpecificationController implements SpecificationApis {

    @Resource
    private BaContSpecServiceImpl service;

    @GetMapping("/specification/list")
    @ApiOperation(value = "查询箱规列表接口")
    @Override
    public JsonVO<PageDTO<SpecificationBaseDTO>> querySpecificationList(@Valid SpecificationQuery query) {
        return JsonVO.success(service.listAll(query));
    }

    @GetMapping("/specification/get-by-id")
    @ApiOperation(value = "查询箱规详情接口")
    @Override
    public JsonVO<SpecificationBaseDTO> querySpecificationDetails(@NotBlank @RequestParam("id") String  id) {
        return JsonVO.success(service.getById(id));
    }

    @PostMapping("/specification/add")
    @ApiOperation(value = "新增箱规接口")
    @Override
    public JsonVO<String> addSpecification(@Valid @RequestBody SpecificationAddDTO dto) {
        int result = service.addSpecification(dto);
        if (result > 0) {
            return JsonVO.success("新增箱规成功");
        } else {
            return JsonVO.fail("新增箱规失败");
        }
    }

    @PutMapping("/specification/modify")
    @ApiOperation(value = "修改箱规接口")
    @Override
    public JsonVO<String> putSpecification(@Valid @RequestBody SpecificationModifyDTO dto) {
        int result = service.putSpecification(dto);
        if (result > 0) {
            return JsonVO.success("修改箱规成功");
        } else {
            return JsonVO.fail("修改箱规失败");
        }
    }



    @DeleteMapping("/specification/remove-batch")
    @ApiOperation(value = "批量删除箱规接口")
    @Override
    public JsonVO<String> deleteSpecifications(@RequestBody @Valid List<SpecificationDeleteDTO> dtos) {
        int count = service.deleteSpecifications(dtos);
        if (count > 0) {
            return JsonVO.success("批量删除箱规成功，共删除 " + count + " 条记录");
        } else {
            return JsonVO.fail("批量删除箱规失败");
        }
    }

    @PostMapping("/specification/import")
    @ApiOperation(value = "导入excel接口")
    @Override
    public JsonVO<String> importSpecificationFromExcel(MultipartFile file) {
        int res = service.importExcel(file);
        if (res > 0){
            return JsonVO.success("导入成功，导入"+res+"条数据");
        }
        return JsonVO.fail("导入失败");
    }

    @GetMapping(value = "/specification/export",produces = "application/octet-stream")
    @ApiOperation("导出excel接口")
    @Override
    public ResponseEntity<byte[]> exportSpecificationToExcel() {
        return service.exportExcel();
    }


}
