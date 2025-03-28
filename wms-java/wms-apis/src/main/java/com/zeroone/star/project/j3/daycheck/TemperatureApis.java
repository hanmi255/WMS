package com.zeroone.star.project.j3.daycheck.tem;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.daycheck.tem.TemperatureDTO;
import com.zeroone.star.project.dto.j3.daycheck.tem.TemperatureUpdateDTO;
import com.zeroone.star.project.query.j3.daycheck.tem.TemperaturePageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j3.daycheck.tem.TemperatureVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * 温度维护接口
 */
public interface TemperatureApis {
    /**
     * 查询温度信息列表
     * @param temperaturePageQuery 查询条件
     * @return 响应数据结果
     */
    JsonVO<PageDTO<TemperatureVO>>  pageQueryAll(TemperaturePageQuery temperaturePageQuery);

    /**
     * 新增温度信息
     * @param temperatureDTO 温度信息
     * @return 响应数据结果
     */
    JsonVO<String> addTemperature(TemperatureDTO temperatureDTO);


    /**
     * 修改温度信息
     * @param temperatureUpdateDTO 温度信息
     * @return 响应数据结果
     */
    JsonVO<String> updateTemperature(TemperatureUpdateDTO temperatureUpdateDTO);

    /**
     * 根据id查看温度信息
     * @param id 温度id
     * @return 响应数据结果
     */
    JsonVO<TemperatureVO> temperatureById(String id);

    /**
     * 批量删除
     * @param ids 温度id集合
     * @return 响应数据结果
     */
    JsonVO<String> deleteTemperature(List<String> ids);

    /**
     * 导出数据
     *
     * @return 响应数据结果
     */
    ResponseEntity<byte[]> exportTemperature();

    /**
     * 导出数据
     * @return 响应数据结果
     */
    JsonVO<String> importTemperature(MultipartFile file);
}
