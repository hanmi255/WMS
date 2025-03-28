package com.zeroone.star.daycheck.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.daycheck.entity.YichangDown;
import com.zeroone.star.project.query.j3.daycheck.Arr.YichangDownQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

@Mapper
public interface YichangDownMapper extends BaseMapper<YichangDown> {

    Page<YichangDown> getYichangDownPage(Page<YichangDown> page, @Param("query") YichangDownQuery condition);
}
