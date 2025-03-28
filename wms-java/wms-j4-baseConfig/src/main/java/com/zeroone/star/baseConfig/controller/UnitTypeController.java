package com.zeroone.star.baseConfig.controller;

import cn.hutool.core.date.DateTime;
import com.zeroone.star.baseConfig.entity.UnitType;
import com.zeroone.star.baseConfig.service.BaUnitTypeService;
import com.zeroone.star.baseConfig.service.UnitTypeService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.unitType.UnitTypeAddDTO;
import com.zeroone.star.project.dto.j4.unitType.UnitTypeListDTO;
import com.zeroone.star.project.dto.j4.unitType.UnitTypeModifyDTO;
import com.zeroone.star.project.j4.baseConfig.UnitTypeApis;
import com.zeroone.star.project.query.j4.unitType.UnitTypeListQuery;
import com.zeroone.star.project.query.j4.unitType.UnitTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.*;
import lombok.RequiredArgsConstructor;
import lombok.SneakyThrows;
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
 * <p>
 * 计量单位类型 前端控制器
 * </p>
 *
 * @author Dorain
 * @since 2025-02-22
 */
@RestController
@RequestMapping("/baseconfig")
@Api(tags = "单位类型")
@RequiredArgsConstructor
public class UnitTypeController implements UnitTypeApis {
    @Resource
    private final UnitTypeService unitTypeService;

    @ApiOperation("录入单位类型")
    @PostMapping("/addunittype")
    @ApiImplicitParams({
            @ApiImplicitParam(
                    name = "unitTypeCode",
                    value = "单位类型代码",
                    required = true,
                    paramType = "form",
                    example = "10006"
            ),
            @ApiImplicitParam(
                    name = "unitTypeName",
                    value = "单位类型名称",
                    required = true,
                    paramType = "form",
                    example = "件"
            )
    })
    @Override
    public JsonVO AddUnitType(UnitTypeAddDTO dto) {

        return  unitTypeService.addUnitType(dto);
    }

    @ApiOperation("修改单位类型")
    @PutMapping("/modifyunittype")
    @Override
    @ApiImplicitParams({
            @ApiImplicitParam(
                    name = "id",
                    value = "单位类型ID",
                    required = true,
                    paramType = "form",
                    example = "2c9efaca9516b1c201953137c0c700d7"
            ),
            @ApiImplicitParam(
                    name = "unitTypeCode",
                    value = "单位类型代码",
                    required = true,
                    paramType = "form",
                    example = "10002"
            ),
            @ApiImplicitParam(
                    name = "unitTypeName",
                    value = "单位类型名称",
                    required = true,
                    paramType = "form",
                    example = "件"
            )
    })
    public JsonVO<String> updateUnitType(
            @ApiParam(name = "dto",
                    value = "单位类型修改数据",
                    required = true)
            @ModelAttribute UnitTypeModifyDTO dto) {

        return  unitTypeService.updateUnitType(dto);
    }


    @DeleteMapping("/deletebatchunittype")
    @ApiOperation(value = "删除单位类型(支持批量删除)")
    @Override
    public JsonVO<String> deleteBatchUnitType(
            @RequestParam("ids")
            @ApiParam(value = "ID列表(示例值: id1,id2,id3)", required = true, example = "id1,id2,id3")
            List<String> ids) {
        return unitTypeService.deleteBatchUnitType(ids);
    }

    @Resource
    EasyExcelComponent excel;  // EasyExcel封装组件

    @SneakyThrows
    @ApiOperation("导出单位类型")
    @GetMapping(value = "/exportunittype", produces = "application/octet-stream")
    @Override
    public ResponseEntity<byte[]> exportUnitType(UnitTypeQuery query) {
        // 查询单位类型数据
        List<UnitType> data = unitTypeService.queryUnitTypes(query);

        // 导出到输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("unitType", out, UnitType.class, data);
        // 响应文件数据
        String filename = "rep-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        HttpHeaders headers = new HttpHeaders();
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(), headers, HttpStatus.CREATED);
        out.close();
        return result;
    }



    /**
     * 完成单位类型excel导入
     * @param file
     * @return
     */
    @PostMapping("/import")
    @Override
    @ApiOperation(value = "导入单位类型")
    public JsonVO<String> importExcel(@RequestBody MultipartFile file) {
        // 检查文件是否为空
        if (file.isEmpty()) {
            // 文件为空，返回错误页面或提示信息
            return JsonVO.fail("文件内容为空，请重新上传");
        }
        try {
            // 调用服务进行Excel数据解析和处理
            unitTypeService.importParameterType(file);
            return JsonVO.success("文件导入成功");
        } catch (Exception e) {
            // 解析失败，返回错误页面或提示信息
            return JsonVO.fail("文件解析失败，请检查文件格式和内容");
        }
    }


    @Resource
    BaUnitTypeService baunitTypeService;

    @GetMapping("getunittypenamelist")
    @ApiOperation(value = "获取单位类型名称列表")
    @Override
    public JsonVO<List<String>> getUnitTypeNameList() {
        return baunitTypeService.getUnitTypeNameList();
    }

    @GetMapping("getunittypelist")
    @ApiOperation(value = "获取单位类型列表（条件+分页）")
    @Override
    public JsonVO<PageDTO<UnitTypeListDTO>> getUnitTypeList(UnitTypeListQuery unitTypeListQuery) {
        return baunitTypeService.getUnitTypeList(unitTypeListQuery);
    }
}
