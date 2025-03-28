package com.zeroone.star.outgoodsmanage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.outgoodsmanage.entity.LoadCheckDO;
import com.zeroone.star.project.dto.j7.zccheck.CheckDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

@Mapper
public interface LoadCheckMapper extends BaseMapper<LoadCheckDO> {
    int updateBatchCheck(@Param("checkDTOs") List<CheckDTO> CheckDTOList);
}
