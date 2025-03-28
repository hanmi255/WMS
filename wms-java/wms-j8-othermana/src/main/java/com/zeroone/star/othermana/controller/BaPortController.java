package com.zeroone.star.othermana.controller;


import com.alibaba.excel.EasyExcel;
import com.zeroone.star.othermana.service.IBaPortService;
import com.zeroone.star.othermana.entity.BaPort;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.other.port.PortAddDTO;
import com.zeroone.star.project.dto.j8.other.port.PortBaseDTO;
import com.zeroone.star.project.dto.j8.other.port.PortModifyDTO;
import com.zeroone.star.project.j8.other.PortApis;
import com.zeroone.star.project.query.j8.other.port.PortQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;
import javax.annotation.Resource;
import javax.servlet.ServletOutputStream;
import javax.servlet.http.HttpServletResponse;
import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;
import java.util.List;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author yjq
 * @since 2025-02-26
 */
@RestController
@RequestMapping("othermana")
@Api(tags = "港口管理")
public class BaPortController implements PortApis {

    @Resource
    IBaPortService iBaPortService;

    @PostMapping("/port/queryPort")
    @ApiOperation(value = "分页查询港口信息")
    @Override
    public JsonVO<PageDTO<PortBaseDTO>> queryAll(@RequestBody PortQuery query) {
        return JsonVO.success(iBaPortService.listPort(query));
    }

    @PostMapping ("/port/addPort")
    @ApiOperation(value = "新增港口信息")
    @Override
    public JsonVO<String> addPort(@RequestBody PortAddDTO dto) {
        return iBaPortService.addPort(dto);
    }

    @PostMapping ("/port/removePort")
    @ApiOperation(value = "移除港口信息")
    @Override
    public JsonVO<String> removePort(@RequestParam String id) {
        return iBaPortService.removePort(id);
    }

    @PostMapping ("/port/modifyPort")
    @ApiOperation(value = "修改港口信息")
    @Override
    public JsonVO<String> modifyPort(@RequestBody PortModifyDTO dto) {
        return iBaPortService.updatePort(dto);
    }

    @PostMapping("/port/uploadPort")
    @ApiOperation(value = "导入港口信息")
    @Override
    public JsonVO<String> importPort(@RequestParam("file") MultipartFile file) {
        return iBaPortService.importPort(file);
    }


    @SneakyThrows
    @GetMapping("/port/exportPort")
    @ApiOperation(value = "导出港口信息")
    @Override
    public void exportPort(HttpServletResponse response) {
        // 获取数据
        List<BaPort> dataList = iBaPortService.exportPort();
        // 设置HTTP响应头
        response.setContentType("application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
        response.setCharacterEncoding("utf-8");
        String fileName = URLEncoder.encode("港口信息.xlsx", StandardCharsets.UTF_8.toString());
        response.setHeader("Content-disposition", "attachment;filename*=UTF-8''" + fileName);
        // 使用EasyExcel写入数据到响应输出流
        try (ServletOutputStream out = response.getOutputStream()) {
            EasyExcel.write(out, BaPort.class)
                    .inMemory(Boolean.TRUE)  // 开启内存处理模式
                    .sheet("港口信息")
                    .doWrite(dataList);
        }
    }
}

