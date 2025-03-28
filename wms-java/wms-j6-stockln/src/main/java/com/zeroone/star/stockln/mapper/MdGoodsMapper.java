package com.zeroone.star.stockln.mapper;

import com.zeroone.star.stockln.entity.MdGoods;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.springframework.stereotype.Repository;

/**
 * <p>
 * 商品信息 Mapper 接口
 * </p>
 *
 * @author Backa
 * @since 2025-03-18
 */
@Repository
@Mapper
public interface MdGoodsMapper extends BaseMapper<MdGoods> {

}
