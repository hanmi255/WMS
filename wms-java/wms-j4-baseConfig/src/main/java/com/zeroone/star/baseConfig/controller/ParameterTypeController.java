package com.zeroone.star.baseConfig.controller;

import cn.hutool.core.date.DateTime;
import com.zeroone.star.baseConfig.entity.BaParameterType;
import com.zeroone.star.baseConfig.mapper.BaParameterTypeMapper;
import com.zeroone.star.baseConfig.service.BaParameterTypeService;
import com.zeroone.star.baseConfig.service.ParameterTypeService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j4.parameter.*;
import com.zeroone.star.project.j4.baseConfig.ParameterTypeApis;
import com.zeroone.star.project.query.j4.parameter.ParameterTypeModifyQuery;
import com.zeroone.star.project.query.j4.parameter.ParameterTypeQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.beans.BeanUtils;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.util.Arrays;
import java.util.List;

/**
 * 参数类型接口实现
 * @author qiaozhi
 * @title 参数修改接口
 * @date 2025/2/22 21:26
 * @description TODO
 */
@RestController
@RequestMapping("ParameterType")
@Api(tags = "参数类型")
public class ParameterTypeController implements ParameterTypeApis {

    @Resource
    private BaParameterTypeService baParameterTypeService;

    @Resource
    BaParameterTypeMapper baParameterTypeMapper;


    @Resource
    EasyExcelComponent excel;

    @PostMapping("modifyOne")
    @ApiOperation(value = "修改参数类型")
    @Override
    public JsonVO<ParameterTypeModifyQuery> modifyOne(@RequestBody ParameterTypeModifyQuery query) {
        try {
            BaParameterType baParameterType = new BaParameterType();
            // 复制转换为entity
            BeanUtils.copyProperties(query, baParameterType);
            // 数据库修改
            baParameterTypeService.updateById(baParameterType);
            return JsonVO.success(query);
        }catch (Exception e){
            return JsonVO.create(null,9999,"参数错误");
        }
    }

    @DeleteMapping("deleteParameterType")
    @ApiOperation(value = "删除参数类型（支持批量删除）")
    @Override
    public JsonVO<String> deleteMore(String[] ids) {
        List<String> idList = Arrays.asList(ids);
        try {
            int deletedCount = baParameterTypeMapper.deleteBatchIds(idList);
            if (deletedCount > 0) {
                return JsonVO.success("删除成功");
            } else {
                return JsonVO.fail("未找到匹配的记录");
            }
        } catch (Exception e) {
            return JsonVO.fail("删除失败");
        }
    }

    @SneakyThrows
    @GetMapping(value = "getParameterType", produces = "application/octet-stream")
    @ApiOperation(value = "导出参数类型")
    @Override
    public ResponseEntity<byte[]> downloadParameterType(ParameterTypeFileDTO query) {
        // 查询数据库数据
        List<BaParameterType> data = baParameterTypeService.exportParameterType();
        // 导出到输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("BaParameterType", out, BaParameterType.class, data);
        // 响应文件数据
        String filename = "rep-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        // 构建响应头
        HttpHeaders headers = new HttpHeaders();
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(), headers, HttpStatus.CREATED);
        out.close();
        // 响应数据给客户端
        return result;
    }

    @PostMapping("addParameterType")
    @ApiOperation(value = "导入参数类型")
    @Override
    public JsonVO<String> uploadParameterType(@RequestParam MultipartFile file) {
        // 检查文件是否为空
        if (file.isEmpty()) {
            // 文件为空，返回错误页面或提示信息
            return JsonVO.fail("文件内容为空，请重新上传");
        }
        try {
            // 调用服务进行Excel数据解析和处理
            baParameterTypeService.importParameterType(file);
            return JsonVO.success("文件导入成功");
        } catch (Exception e) {
            // 解析失败，返回错误页面或提示信息
            return JsonVO.fail("文件解析失败，请检查文件格式和内容");
        }
    }


    @Resource
    ParameterTypeService parameterTypeService;

    @GetMapping("listName")
    @ApiOperation(value = "获取参数类型名称列表")
    @Override
    public JsonVO<List<ParameterTypeNameListDTO>> listParameterTypeName(String query) {
        return JsonVO.success(parameterTypeService.listParameterTypeName());
    }

    @GetMapping("all")
    @ApiOperation(value = "获取参数类型列表（条件+分页）")
    @Override
    public JsonVO<PageDTO<ParameterTypeListDTO>> queryAll(ParameterTypeQuery query) {
        return JsonVO.success(parameterTypeService.queryAll(query));
    }

    @PostMapping("add")
    @ApiOperation(value = "录入参数类型")
    @Override
    public JsonVO<String> addParameterType(@RequestBody ParameterTypeAddDTO dto) {
        return JsonVO.success(parameterTypeService.addParameterType(dto));
    }
}
