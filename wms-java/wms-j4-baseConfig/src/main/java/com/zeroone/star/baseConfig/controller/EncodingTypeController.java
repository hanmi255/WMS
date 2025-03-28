package com.zeroone.star.baseConfig.controller;

import cn.hutool.core.date.DateTime;
import com.alibaba.excel.EasyExcel;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.zeroone.star.baseConfig.entity.EncodingType;
import com.zeroone.star.baseConfig.mapper.EncodingTypeMapper;
import com.zeroone.star.baseConfig.service.EncodingTypeService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.easyexcel.ExcelReadListener;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.encodingType.EncodingTypeBaseDTO;
import com.zeroone.star.project.dto.j4.encodingType.EncodingTypeListDTO;
import com.zeroone.star.project.j4.baseConfig.EncodingTypeApis;
import com.zeroone.star.project.query.j4.encodingType.EncodingTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.encodingType.EncodingTypeVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import lombok.SneakyThrows;
import org.apache.poi.hssf.usermodel.HSSFWorkbook;
import org.apache.poi.ss.usermodel.Cell;
import org.apache.poi.ss.usermodel.Row;
import org.apache.poi.ss.usermodel.Sheet;
import org.apache.poi.ss.usermodel.Workbook;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
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
import java.util.stream.Collectors;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author bwb
 * @since 2025-02-22
 */
@RestController
@RequestMapping("/baseconfig")
@Api(tags = "编码类型")
public class EncodingTypeController implements EncodingTypeApis {
    @Autowired
    private EncodingTypeService baSnroTypeService;
    @Autowired
    private EncodingTypeMapper baSnroTypeMapper;
    @Resource
    EasyExcelComponent excel;
    @ApiOperation(
            value = "删除编码类型(支持批量删除)",
            notes = "根据ID列表删除编码类型",
            consumes = "application/json"
    )
    @DeleteMapping("/delete-encodingtype")
    @Override
    public JsonVO<String> deleteByIds(@ApiParam(value = "ID列表(示例值: id1,id2,id3)",
            required = true, example = "[\"id1\", \"id2\", \"id3\"]") @RequestBody List<String> ids) {
        baSnroTypeMapper.deleteBatchIds(ids);
        return JsonVO.success("删除成功");
    }




    @SneakyThrows
    @ApiOperation(value = "导出编码类型")
    @GetMapping(value = "/export-encodingtype",produces = "application/octet-stream")
    @Override
    public ResponseEntity<byte[]> exportexcel(EncodingTypeQuery query) {
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        List<EncodingType> data = new ArrayList<>();

        // 获取原始数据
        if(query==null){
            data = baSnroTypeService.list();
        }
        else {
            if(query.getSnroTypeCode()!=null){
                LambdaQueryWrapper<EncodingType> queryWrapper=new LambdaQueryWrapper<>();
                queryWrapper.eq(EncodingType::getSnroTypeCode,query.getSnroTypeCode());
                data = baSnroTypeService.list(queryWrapper);
            }else if(query.getSnroTypeName()!=null){
                LambdaQueryWrapper<EncodingType> queryWrapper=new LambdaQueryWrapper<>();
                queryWrapper.eq(EncodingType::getSnroTypeName,query.getSnroTypeName());
                data = baSnroTypeService.list(queryWrapper);
            }

        }
        // 将 BaSnroType 转换为 EncodingTypeVO
        List<EncodingTypeVO> transformedData = data.stream()
                .map(item -> {
                    EncodingTypeVO vo = new EncodingTypeVO();
                    BeanUtils.copyProperties(item, vo); // 复制属性
                    return vo;
                })
                .collect(Collectors.toList());
        excel.export("user", out, EncodingTypeVO.class, transformedData);
        String filename = "rep-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        HttpHeaders headers = new HttpHeaders();
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(), headers, HttpStatus.CREATED);
        out.close();
        return result;

    }


    @SneakyThrows
    @Override
    @ApiOperation(value = "导入编码类型")
    @PostMapping(value = "/import-encodingtype")
    public ResponseEntity<String> importExcel(@RequestParam("file") MultipartFile file) {
        try {
            // 检查文件是否为空
            if (file.isEmpty()) {
                return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("上传的文件为空！");
            }

            // 获取文件后缀名并判断文件类型
            String fileName = file.getOriginalFilename();
            if (!fileName.toLowerCase().endsWith(".xls") && !fileName.toLowerCase().endsWith(".xlsx")) {
                return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("仅支持 .xls 或 .xlsx 格式的文件！");
            }

            // 获取文件输入流
            InputStream inputStream = file.getInputStream();

            // 根据文件类型选择解析方式
            List<EncodingTypeVO> importedData;
            if (fileName.toLowerCase().endsWith(".xlsx")) {
                // 解析 .xlsx 文件
                importedData = parseExcelFromInputStream(inputStream, EncodingTypeVO.class);
            } else {
                // 解析 .xls 文件
                importedData = parseHSSFWorkbook(inputStream, EncodingTypeVO.class);
            }

            // 处理导入的数据（例如保存到数据库）
            baSnroTypeService.saveBatch(importedData);

            return ResponseEntity.ok("Excel 导入成功！");
        } catch (IOException e) {
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body("文件读取失败：" + e.getMessage());
        } catch (Exception e) {
            e.printStackTrace();
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body("Excel 导入失败：" + e.getMessage());
        }
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



    @Resource
    private EncodingTypeService encodingTypeService;

    @GetMapping("query-encodingtype")
    @ApiOperation(value = "获取编码类型列表（条件+分页）")
    @Override
    public JsonVO<PageDTO<EncodingTypeListDTO>> queryAllEncodingType(EncodingTypeQuery query) {
        return JsonVO.success(encodingTypeService.listAllEncodingType(query));
    }

    @PostMapping("add-encodingtype")
    @ApiOperation(value = "录入编码类型")
    @Override
    public JsonVO<String> addEncodingType(@Validated @RequestBody EncodingTypeBaseDTO dto) {
        if(encodingTypeService.saveEncodingType(dto).equals("success")){
            return JsonVO.success("录入成功");
        }
        return JsonVO.fail("录入失败");
    }

    @PutMapping("modify-encodingtype")
    @ApiOperation(value = "修改编码类型")
    @Override
    public JsonVO<String> modifyEncodingType(@Validated @RequestBody EncodingTypeListDTO dto) {
        if(encodingTypeService.updateEncodingType(dto).equals("success")){
            return JsonVO.success("修改成功");
        }
        return JsonVO.fail("修改失败");
    }



    /**
     * 获取编码类型名称列表
     * @return
     */
    @GetMapping("/getnamelist")
    @Override
    @ApiOperation(value = "获取编码类型名称列表")
    public JsonVO<List<com.zeroone.star.project.dto.j4.encodingType.EncodingTypeNameListDTO>> encodingTypeNameList(@ApiParam(value = "编码类型名称" ,required=false,example = "ASCII") String query) {
        return JsonVO.success(encodingTypeService.encodingTypeNameList(query).getData());
    }
}