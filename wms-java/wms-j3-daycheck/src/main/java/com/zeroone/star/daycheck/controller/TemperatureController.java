package com.zeroone.star.daycheck.controller;

import cn.hutool.core.date.DateTime;
import com.zeroone.star.daycheck.Listener.TemperatureListener;
import com.zeroone.star.daycheck.entity.Temperature;
import com.zeroone.star.daycheck.service.ITemperatureService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.daycheck.tem.TemperatureDTO;
import com.zeroone.star.project.dto.j3.daycheck.tem.TemperatureUpdateDTO;
import com.zeroone.star.project.j3.daycheck.tem.TemperatureApis;
import com.zeroone.star.project.query.j3.daycheck.tem.TemperaturePageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.daycheck.tem.TemperatureVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
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
 * 温度维护接口实现
 */
@RestController
@RequestMapping("/daycheck/temperature/")
@Api(tags = "温度维护接口实现")
@Slf4j
public class TemperatureController implements TemperatureApis {

    @Autowired
    private ITemperatureService temperatureService;

    @Resource
    EasyExcelComponent excel;

    @GetMapping("query")
    @ApiOperation(value = "温度列表查询接口")
    public JsonVO<PageDTO<TemperatureVO>> pageQueryAll(TemperaturePageQuery query) {
        log.info("分页查询数据：{}", query);

        PageDTO<TemperatureVO> pageResult = temperatureService.pageQueryAll(query);

        return JsonVO.success(pageResult);
    }

    /**
     * 录入温度
     * @param temperatureDTO 温度信息
     * @return
     */
    @PostMapping("add")
    @ApiOperation(value = "录入温度接口")
    public JsonVO<String> addTemperature(@RequestBody TemperatureDTO temperatureDTO) {
        log.info("开始录入温度数据：{}", temperatureDTO);

        temperatureService.saveTemp(temperatureDTO);

        return JsonVO.success("录入温度成功");
    }

    /**
     * 修改温度
     * @param temperatureUpdateDTO 温度信息
     * @return
     */
    @PutMapping("update")
    @ApiOperation(value = "修改温度接口")
    public JsonVO<String> updateTemperature(@RequestBody TemperatureUpdateDTO temperatureUpdateDTO) {
        log.info("开始修改温度数据：{}", temperatureUpdateDTO);

        temperatureService.updateTemp(temperatureUpdateDTO);

        return JsonVO.success("修改温度成功");
    }

    /**
     * 根据id查询数据
     * @param id 温度id
     * @return
     */
    @GetMapping("id")
    @ApiOperation(value = "根据id查询数据接口")
    public JsonVO<TemperatureVO> temperatureById(String id) {
        log.info("开始查询温度数据：{}", id);

        TemperatureVO temperatureVO = temperatureService.temperatureById(id);

        return JsonVO.success(temperatureVO);
    }

    /**
     * 删除温度
     * @param ids
     * @return
     */
    @DeleteMapping("delete")
    @ApiOperation(value = "删除温度接口")
    public JsonVO<String> deleteTemperature(@RequestParam List<String> ids) {
        log.info("开始删除温度数据：{}", ids);

        temperatureService.deleteTemps(ids);

        return JsonVO.success("删除温度成功");
    }

    @SneakyThrows
    @GetMapping(value = "export",produces = "application/octet-stream")
    @ApiOperation(value = "导出温度数据")
    public ResponseEntity<byte[]> exportTemperature() {
        //解析Excel文件
        List<Temperature> data = temperatureService.list();
        //导出到输出流
        ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
        excel.export("temperature", outputStream, Temperature.class, data);
        //响应文件数据
        String fileName = "rep-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        HttpHeaders headers = new HttpHeaders();
        headers.setContentDispositionFormData("attachment", fileName);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(outputStream.toByteArray(), headers, HttpStatus.CREATED);
        outputStream.close();
        return result;
    }
    @SneakyThrows
    @PostMapping("import")
    @ApiOperation(value = "导入温度数据")
    @ResponseBody
    public JsonVO<String> importTemperature(MultipartFile file) {

        List<Temperature> list = temperatureService.importTemperature(file,Temperature.class,new TemperatureListener());
        return JsonVO.success("导入成功");
    }

}
