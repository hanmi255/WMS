package com.zeroone.star.daycheck.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.daycheck.Listener.TemperatureListener;
import com.zeroone.star.daycheck.entity.Temperature;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.daycheck.tem.TemperatureDTO;
import com.zeroone.star.project.dto.j3.daycheck.tem.TemperatureUpdateDTO;
import com.zeroone.star.project.query.j3.daycheck.tem.TemperaturePageQuery;
import com.zeroone.star.project.vo.j3.daycheck.tem.TemperatureVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

public interface ITemperatureService extends IService<Temperature> {
    void saveTemp(TemperatureDTO temperatureDTO);

    void deleteTemps(List<String> ids);

    void updateTemp(TemperatureUpdateDTO temperatureUpdateDTO);

    TemperatureVO temperatureById(String id);

    PageDTO<TemperatureVO> pageQueryAll(TemperaturePageQuery temperaturePageQuery);

    ResponseEntity<byte[]> exportTemperature();

    List<Temperature> importTemperature(MultipartFile file, Class head, TemperatureListener listener);
}
