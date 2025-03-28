package com.zeroone.star.baseConfig.controller;

import cn.hutool.core.date.DateTime;
import com.alibaba.excel.EasyExcel;
import com.zeroone.star.baseConfig.entity.SystemParameter;
import com.zeroone.star.baseConfig.mapper.SystemParameterMapper;
import com.zeroone.star.baseConfig.service.SystemParameterService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.easyexcel.ExcelReadListener;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.systemParameter.SPAddDTO;
import com.zeroone.star.project.dto.j4.systemParameter.SPListDTO;
import com.zeroone.star.project.dto.j4.systemParameter.SPModifyDTO;
import com.zeroone.star.project.j4.baseConfig.SystemParameterApis;
import com.zeroone.star.project.query.j4.systemParameter.SPPageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j4.systemParameter.SystemParameterVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
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
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.Field;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.stream.Collectors;


/**
 * @ClassName SystemParameterController
 * @Description 系统参数接口实现
 * @Author 阿强
 * @Date2025/2/23 14:39
 * @Version 1.0
 **/


@RestController
@RequestMapping("/systemparameter/")
@Api(tags = "系统参数")
@Slf4j
//@Validated  // 开启方法级别的参数校验
public class SystemParameterController implements SystemParameterApis {


    @Resource
    private SystemParameterService systemParameterService;

    @Resource
    private UserHolder userHolder;

    @GetMapping("query-all")
    @ApiOperation(value = "获取参数列表（条件+分页）")
    @Override
    public JsonVO<PageDTO<SPListDTO>> queryAll(SPPageQuery query) {
        return JsonVO.success(systemParameterService.listAll(query));
    }

    @PostMapping("add")
    @ApiOperation(value = "录入参数")
    @Override
    public JsonVO<String> addSP(@RequestBody SPAddDTO spAddDTO) {
        try{
            log.info(spAddDTO.toString());
            SystemParameter systemParameter = new SystemParameter();
            BeanUtils.copyProperties(spAddDTO, systemParameter);
            // 设置当前时间到 creat_time 字段
            systemParameter.setCreateDate(LocalDateTime.now());
            UserDTO user = userHolder.getCurrentUser();
            if(user != null){
                // 设置当前创建人 creat_name 字段
                systemParameter.setCreateName(userHolder.getCurrentUser().getUsername());
                // 设置当前创建人 creat_by 字段
                systemParameter.setCreateBy(userHolder.getCurrentUser().getRealname());
                // 设置所属公司 companyCode 字段
                systemParameter.setSysCompanyCode(userHolder.getCurrentUser().getCompanyCode());
                // 设置所属部门 orgCode 字段
                systemParameter.setSysConfOrg(userHolder.getCurrentUser().getOrgCode());
            }

            systemParameterService.save(systemParameter);
            return JsonVO.success("录入成功");
        } catch (Exception e) {
            return JsonVO.fail(e.getMessage());
        }
    }
    @PostMapping("modify")
    @ApiOperation(value = "修改参数")
    @Override
    public JsonVO<String> modifySP(@RequestBody SPModifyDTO spModifyDTO) {
        try{
            SystemParameter systemParameter = new SystemParameter();
            BeanUtils.copyProperties(spModifyDTO, systemParameter);
            // 设置当前时间到 update_time 字段
            systemParameter.setUpdateDate(LocalDateTime.now());
            // 设置当前创建人 update_name 字段
            UserDTO user = userHolder.getCurrentUser();
            if(user != null){
                systemParameter.setUpdateName(userHolder.getCurrentUser().getUsername());
            }
            systemParameterService.updateById(systemParameter);
            return JsonVO.success("修改成功");
        } catch (Exception e) {
            return JsonVO.fail(e.getMessage());
        }
    }


    @Autowired
    private SystemParameterMapper systemParameterMapper;
    @Resource
    EasyExcelComponent excel;
    @ApiOperation(value = "删除参数（支持批量删除）")
    @DeleteMapping("/delete-SystemParameter")
    @Override
    public JsonVO<String> deleteByIds(@RequestBody List<String> ids) {
        //通过调用BaseMapper中的deleteBatchIds方法，传入要删除的ID列表，实现批量删除操作。
        systemParameterMapper.deleteBatchIds(ids);
        return JsonVO.success("删除成功");
    }

    @SneakyThrows
    @ApiOperation(value = "导出参数")
    @GetMapping(value = "/export-SystemParameter", produces = "application/octet-stream")
    @Override
    public ResponseEntity<byte[]> exportexcel(SPPageQuery query) {
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        //导出到输入流
        List<SystemParameter> data = systemParameterService.list();
        //导出
        List<SystemParameterVO> transformedData = data.stream().map(item -> {
            SystemParameterVO vo = new SystemParameterVO();
            BeanUtils.copyProperties(item, vo);
            return vo;
        }).collect(Collectors.toList());
        excel.export("系统参数", out, SystemParameterVO.class, transformedData);
        String filename = "系统参数"+ DateTime.now().toString("yyyyMMddHHmmssS")+".xlsx";
        HttpHeaders headers = new HttpHeaders();
        headers.setContentDispositionFormData("attachment",filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(),headers, HttpStatus.CREATED);
        out.close();
        return result;
    }
    @Override
    @ApiOperation(value = "导入参数")
    @PostMapping(value = "/import-SystemParameter")
    public ResponseEntity<String> importExcel(@RequestParam("file") MultipartFile file) {
        try{
            if(file.isEmpty()){
                return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("上传文件为空！");
            }
            String fileName = file.getOriginalFilename();
            if (!fileName.toLowerCase().endsWith(".xlsx")&& !fileName.toLowerCase().endsWith(".xls")){
                return ResponseEntity.status(HttpStatus.BAD_REQUEST).body("仅支持 .xls 或 .xlsx 格式的文件");
            }
            InputStream inputStream = file.getInputStream();
            List<SystemParameterVO> importedData;
            if (fileName.toLowerCase().endsWith(".xlsx")){
                importedData = parseExcelFromInputStream(inputStream, SystemParameterVO.class);
            }else {
                importedData = parseHSSFWorkbook(inputStream, SystemParameterVO.class);
            }

            systemParameterService.saveBatch(importedData);

            return ResponseEntity.ok("Excel文件上传成功");
        }catch (IOException e){
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body("文件读取失败："+e.getMessage());
        }catch (Exception e){
            e.printStackTrace();
            return ResponseEntity.status(HttpStatus.INTERNAL_SERVER_ERROR).body("Excel 导入失败："+e.getMessage());
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
    public  <T> List<T> parseExcelFromInputStream(InputStream inputStream, Class<T> clazz) throws IOException {
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
    public  <T> List<T> parseHSSFWorkbook(InputStream inputStream, Class<T> clazz) throws IOException {
        // 使用 Apache POI 的 HSSFWorkbook 解析 .xls 文件
        // ...
        Workbook workbook = new HSSFWorkbook(inputStream);
        Sheet sheet = workbook.getSheetAt(0);
        List<T> datalist = new ArrayList<>();

        for (int i = 1; i <= sheet.getLastRowNum() ; i++) {
            Row row = sheet.getRow(i);
            if (row != null){
                T obj = convertRowToObject(row, clazz);
                datalist.add(obj);
            }
        }
        workbook.close();
        return datalist;
    }

    /**
     * 将 Excel 行数据转换为对象
     *
     * @param row   Excel 行
     * @param clazz 数据类型
     * @param <T>   泛型
     * @return 转换后的对象
     */
    public  <T> T convertRowToObject(Row row, Class<T> clazz) {
        try {
            T obj = clazz.getDeclaredConstructor().newInstance();
            // 根据 Excel 行数据填充对象属性
            Field[] fields = clazz.getDeclaredFields();

            for (int j = 0; j < fields.length; j++) {
                Field field = fields[j];
                field.setAccessible(true);

                Cell cell = row.getCell(j);
                if (cell != null){
                    if (field.getType().equals(String.class)){
                        field.set(obj, cell.getStringCellValue());
                    }
                    else if (field.getType() == Integer.TYPE || field.getType()== Integer.class){
                        field.set(obj, (int) cell.getNumericCellValue());
                    }
                    else if (field.getType() == Double.TYPE || field.getType() == Double.class){
                        field.set(obj, cell.getNumericCellValue());
                    }else if (field.getType() == Date.class){
                        field.set(obj, cell.getDateCellValue());
                    }
                }
            }
            return obj;
        }catch (Exception e){
            throw new RuntimeException("无法将 Excel 行数据转换为对象：" + e.getMessage(), e);
        }
    }

}
