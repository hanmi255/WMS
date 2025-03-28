package com.zeroone.star.outgoodsmanage.mapper;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.j7.ycoutbound.YcOutBoundDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

/**
 * @Author: Lin
 * @Description: TODO
 * @Version: v1.0.0
 * @Date: 2025/3/1 下午 6:47
 **/
@Mapper
public interface YcOutBoundMapper extends BaseMapper<YcOutBoundDTO> {
    Page<YcOutBoundDTO> selectYcOutBoundDTO(Page<YcOutBoundDTO> page, @Param("ew") QueryWrapper<YcOutBoundDTO> wrapper);

    Long getPageSize();
}
