package com.zeroone.star.baseConfig.controller;

import com.alibaba.excel.EasyExcel;
import com.zeroone.star.baseConfig.mapper.ExcelAutomaticEncodingMapper;
import com.zeroone.star.project.components.easyexcel.ExcelReadListener;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.automaticEncoding.AutomaticEncodingDTO;
import com.zeroone.star.project.dto.j4.automaticEncoding.DeleteEncodingDTO;
import com.zeroone.star.project.j4.baseConfig.AutomaticEncodingApis;
import com.zeroone.star.project.query.j4.automaticEncoding.AutomaticEncodingQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.automaticEncoding.DeleteEncodingVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.Workbook;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.Field;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * <p>
 *  前端控制器
 * </p>
 *  自动编码表 前端控制器
 * @author lzm
 * @since 2025-02-22
 */
@RestController
@RequestMapping("/baseConfig/automaticEncoding")
@Api(tags = "自动编码")
public class AutomaticEncodingController implements AutomaticEncodingApis {
    @Resource
    com.zeroone.star.baseConfig.service.AutomaticEncodingService automaticEncodingService;

    @GetMapping("/queryAll")
    @ApiOperation(value = "获取编码列表（条件+分页）")
    public JsonVO<PageDTO<AutomaticEncodingDTO>> queryAll(@Validated AutomaticEncodingQuery condition) {
        return JsonVO.success(automaticEncodingService.queryAll(condition));
    }


    @PutMapping("/update")
    @ApiOperation(value = "修改编码")
    @Override
    public JsonVO<AutomaticEncodingDTO> update(AutomaticEncodingDTO dto) {
        return JsonVO.success(automaticEncodingService.doSaveOrUpdate(dto));
    }

    @PostMapping("/save")
    @ApiOperation(value = "录入编码")
    public JsonVO<AutomaticEncodingDTO> save(AutomaticEncodingDTO dto) {
        return JsonVO.success(automaticEncodingService.doSaveOrUpdate(dto));
    }



    @Resource
    com.zeroone.star.baseConfig.service.AutomaticEncodingService service;
    @Override
    @ApiOperation("删除编码(支持批量删除)")
    @DeleteMapping("/delete")
    public JsonVO<List<DeleteEncodingVO>> deleteEncoding(@RequestBody DeleteEncodingDTO dto) {
        // 调用 Service 层方法
        return automaticEncodingService.deleteEncoding(dto);
    }
    @ApiOperation("导出编码")
    @GetMapping(value = "/export")
    public ResponseEntity<byte[]> exportExcel(
            @RequestParam String create_name,
            @RequestParam String endDate,
            @RequestParam String[] ids,
            @RequestParam String startDate,
            @RequestParam String exportDTO) {

        // 调用 Service 层方法
        return automaticEncodingService.exportExcel(create_name, endDate, ids, startDate, exportDTO);
    }

    /**
     * 完成自动编码 Excel 导入
     * @param file 上传的 Excel 文件
     * @return 导入结果
     */
    @PostMapping("/import")
    @ApiOperation(value = "导入编码")
    public ResponseEntity<String> importExcel(@RequestBody MultipartFile file) {
        // 检查文件是否为空
        if (file.isEmpty()) {
            return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("上传文件为空");
        }

        // 获取文件后缀名并判断文件类型
        String fileName = file.getOriginalFilename();
        if (!fileName.toLowerCase().endsWith(".xls") && !fileName.toLowerCase().endsWith(".xlsx")) {
            return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("仅支持 .xls 或 .xlsx 格式的文件！");
        }

        // 获取文件输入流
        InputStream inputStream = null;
        try {
            inputStream = file.getInputStream();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

        // 根据文件类型选择解析方式
        List<ExcelAutomaticEncodingMapper> importedData;
        if (fileName.toLowerCase().endsWith(".xlsx")) {
            // 解析 .xlsx 文件
            try {
                importedData = parseExcelFromInputStream(inputStream, ExcelAutomaticEncodingMapper.class);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        } else {
            // 解析 .xls 文件
            try {
                importedData = parseHSSFWorkbook(inputStream, ExcelAutomaticEncodingMapper.class);
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        // 将解析的数据导入数据库
        automaticEncodingService.saveBatch(importedData);

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

            // 假设 ExcelAutomaticEncoding 类有字段 field1 和 field2
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
}

