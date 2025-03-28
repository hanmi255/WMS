package com.zeroone.star.daycheck.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.daycheck.entity.Temperature;
import com.zeroone.star.project.dto.j3.daycheck.tem.TemperatureDTO;
import com.zeroone.star.project.vo.j3.daycheck.tem.TemperatureVO;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import java.util.List;

@Mapper
public interface TemperatureMapper extends BaseMapper<Temperature> {

    void saveTemp(Temperature temperature);

    void deleteTemps(List<String> ids);

    void updateTemp(Temperature temperature);

    @Select("select * from zo_wms.wm_wendu where id = #{id}")
    Temperature TemperatureById(String id);

    Page<TemperatureVO> pageQueryAll();

    @Select("SELECT * FROM zo_wms.wm_wendu")
    List<Temperature> selectAll();

    void saveBatch(@Param("list") List<Temperature> list);

}
