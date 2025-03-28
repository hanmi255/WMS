package com.zeroone.star.baseConfig.controller;

import cn.hutool.core.date.DateTime;
import com.alibaba.excel.EasyExcel;
import com.zeroone.star.baseConfig.entity.BaMeasurementUnit;
import com.zeroone.star.baseConfig.service.BaMeasurementUnitService;
import com.zeroone.star.baseConfig.service.MeasurementUnitService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.easyexcel.ExcelReadListener;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.measurementUnit.MeasurementUnitDTO;
import com.zeroone.star.project.j4.baseConfig.MeasurementUnitApis;
import com.zeroone.star.project.query.j4.measurementUnit.MeasurementListQuery;
import com.zeroone.star.project.query.j4.measurementUnit.MeasurementNameListQuery;
import com.zeroone.star.project.query.j4.measurementUnit.MeasurementUnitQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.measurementUnit.MeasurementUnitVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.Workbook;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * @author adi
 * #Description  计量单位控制层
 * #Date: 2025/2/23 22:25
 */
@RestController
@RequestMapping("measurementunit")
@Api(tags = "计量单位")
@Slf4j
public class MeasurementUnitController implements MeasurementUnitApis {


    @Resource
    MeasurementUnitService measurementUnitService;

    @GetMapping("/getunitlist")
    @Override
    @ApiOperation(value = "获取单位列表（条件+分页）")
    @ApiParam(
            name = "query",
            value = "查询条件：包含单位代码、单位名称、英文名称和分页参数"
    )
    public JsonVO<PageDTO<MeasurementUnitVO>> queryMeasurementUnitList(MeasurementListQuery query) {
        return measurementUnitService.queryMeasurementUnitList(query);
    }


    @GetMapping("/getnamelist")
    @Override
    @ApiOperation(value = "获取单位名称列表")
    @ApiParam(
            name = "query",
            value = "查询条件：计量单位名称"
    )
    public JsonVO<List<String>> queryMeasurementUnitNameList(MeasurementNameListQuery query) {
        log.info("查询计量单位名称列表，参数：{}", query);
        List<String> result = measurementUnitService.queryMeasurementUnitNameList(query);
        log.info("查询结果：{}", result);
        return JsonVO.success(result);
    }

    @Resource
    BaMeasurementUnitService bameasurementUnitService;

    @SneakyThrows
    @PostMapping("insertunit")
    @ApiOperation(value = "录入单位")
    @Override
    public JsonVO<MeasurementUnitVO> insertUnit(@RequestBody MeasurementUnitDTO measurementUnitDTO) {

        return bameasurementUnitService.insertUnit(measurementUnitDTO);
    }


    @PutMapping("updateunit")
    @ApiOperation(value = "修改单位")
    @Override
    public JsonVO<MeasurementUnitVO> updateUnit(@RequestBody MeasurementUnitDTO measurementUnitDTO) {
        return bameasurementUnitService.updateUnit(measurementUnitDTO);
    }


    @DeleteMapping("deleteunit")
    @ApiOperation(value = "删除单位(支持批量删除)")
    @Override
    public JsonVO<String> deleteUnit(@RequestBody List<MeasurementUnitDTO> measurementUnitListDTO) {
        return bameasurementUnitService.deleteUnit(measurementUnitListDTO);
    }




    @Resource
    EasyExcelComponent excel;

    @SneakyThrows
    @PostMapping("import")
    @ApiOperation(value = "导入单位")
    @Override
    public ResponseEntity<String> importMeasurementUnit(MultipartFile file) {
        // 检查文件是否为空
        if (file.isEmpty()){
            return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("上传文件为空");
        }

        // 获取文件后缀名并判断文件类型
        String fileName = file.getOriginalFilename();
        if (!fileName.toLowerCase().endsWith(".xls") && !fileName.toLowerCase().endsWith(".xlsx")){
            return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("仅支持 .xls 或 .xlsx 格式的文件！");
        }

        // 获取文件输入流
        InputStream inputStream = file.getInputStream();

        // 根据文件类型选择解析方式
        List<BaMeasurementUnit> importedData;
        if (fileName.toLowerCase().endsWith(".xlsx")) {
            // 解析 .xlsx 文件
            importedData = parseExcelFromInputStream(inputStream, BaMeasurementUnit.class);
        } else {
            // 解析 .xls 文件
            importedData = parseHSSFWorkbook(inputStream, BaMeasurementUnit.class);
        }

        // 将解析的数据导入数据库
        bameasurementUnitService.saveBatch(importedData);

        return ResponseEntity.ok("Excel 导入成功！");
    }

    /**
     * 从输入流解析 Excel 文件（支持 .xlsx 格式）
     *
     * @param inputStream 输入流
     * @param clazz       数据类型
     * @param <T>         泛型
     * @return 解析后的数据集合
     */
    private <T> List<T> parseExcelFromInputStream(InputStream inputStream, Class<T> clazz) throws IOException {
        ExcelReadListener<T> listener = new ExcelReadListener<>();
        EasyExcel.read(inputStream, clazz, listener).sheet().doRead();
        return listener.getDataList();
    }

    /**
     * 解析 .xls 文件（使用 Apache POI 的 HSSFWorkbook）
     *
     * @param inputStream 输入流
     * @param clazz       数据类型
     * @param <T>         泛型
     * @return 解析后的数据集合
     */
    private <T> List<T> parseHSSFWorkbook(InputStream inputStream, Class<T> clazz) throws IOException {
        Workbook workbook = new HSSFWorkbook(inputStream);
        Sheet sheet = workbook.getSheetAt(0);
        List<T> dataList = new ArrayList<>();

        for (int i = 1; i <= sheet.getLastRowNum(); i++) { // 跳过表头
            Row row = sheet.getRow(i);
            if (row != null) {
                T obj = convertRowToObject(row, clazz); // 将行数据转换为对象
                dataList.add(obj);
            }
        }

        workbook.close();
        return dataList;
    }

    /**
     * 将 Excel 行数据转换为对象
     *
     * @param row   Excel 行
     * @param clazz 数据类型
     * @param <T>   泛型
     * @return 转换后的对象
     */
    private <T> T convertRowToObject(Row row, Class<T> clazz) {
        try {
            // 使用反射创建实例
            T obj = clazz.getDeclaredConstructor().newInstance();

            // 假设 EncodingTypeVO 类有字段 field1 和 field2
            Field[] fields = clazz.getDeclaredFields();
            for (int i = 0; i < fields.length; i++) {
                Field field = fields[i];
                field.setAccessible(true);

                Cell cell = row.getCell(i);
                if (cell != null) {
                    if (field.getType() == String.class) {
                        field.set(obj, cell.getStringCellValue());
                    } else if (field.getType() == Integer.TYPE || field.getType() == Integer.class) {
                        field.set(obj, (int) cell.getNumericCellValue());
                    } else if (field.getType() == Double.TYPE || field.getType() == Double.class) {
                        field.set(obj, cell.getNumericCellValue());
                    } else if (field.getType() == Date.class) {
                        field.set(obj, cell.getDateCellValue());
                    }
                }
            }

            return obj;
        } catch (Exception e) {
            throw new RuntimeException("无法将 Excel 行数据转换为对象：" + e.getMessage(), e);
        }
    }

    @SneakyThrows
    @GetMapping(value = "expo",produces = "application/octet-stream")
    @ApiOperation(value = "导出单位")
    @Override
    public ResponseEntity<byte[]> expoMeasurementUnit(MeasurementUnitQuery query) {
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        // 获取原始数据
        List<BaMeasurementUnit> data = bameasurementUnitService.list();

        // 生成报表
        excel.export("MeasurementUnit",out,BaMeasurementUnit.class,data);
        String filename = "MeasurementUnit-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        HttpHeaders headers = new HttpHeaders();
        headers.setContentDispositionFormData("attachment",filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(),headers,HttpStatus.CREATED);
        out.close();


        return result;
    }
}
