package com.zeroone.star.daycheck.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.daycheck.entity.NoUpGoods;
import com.zeroone.star.project.query.j3.daycheck.Arr.NoUpGoodsQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

@Mapper
public interface NoUpMapper extends BaseMapper {
    Page<NoUpGoods> getNoUpGoodsPage(Page<NoUpGoods> page, @Param("query") NoUpGoodsQuery condition);
}
