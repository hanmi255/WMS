package com.zeroone.star.baseConfig.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.baseConfig.entity.SystemParameter;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface SystemParameterMapper extends BaseMapper<SystemParameter> {
        void removeAll(List<String> ids);
}
