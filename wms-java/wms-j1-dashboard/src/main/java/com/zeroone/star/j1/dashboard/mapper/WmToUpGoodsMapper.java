package com.zeroone.star.j1.dashboard.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.j1.dashboard.entity.WmToUpGoods;
import com.zeroone.star.project.vo.j1.dashboard.GoodsToUpVO;
import com.zeroone.star.project.vo.j1.dashboard.GoodsUpInRecentVO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Select;

import java.time.LocalDate;
import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author j1-yunyu
 * @since 2025-02-27
 */
@Mapper
public interface WmToUpGoodsMapper extends BaseMapper<WmToUpGoods> {

    /**
     * 查询几天内每天上架商品的数量，默认返回7天
     * @return 日期和数量的map集合
     */
    @Select("SELECT DATE(create_date) AS create_date_day, " +
            "SUM(CAST(goods_qua AS UNSIGNED)) AS total_goods_up_qua " +
            "FROM wm_to_up_goods " +
            "WHERE create_date >= #{startDate} and create_date < #{endDate} " +
            "GROUP BY DATE(create_date) " +
            "ORDER BY DATE(create_date) ASC")
    List<GoodsUpInRecentVO> selectGoodsToUpNumberInRecentDays(LocalDate startDate , LocalDate endDate);
    @Select("SELECT SUM(goods_qua) AS total_goods_qua, goods_name, goods_unit " +
            "FROM wm_to_up_goods " +
            "GROUP BY goods_name " +
            "ORDER BY total_goods_qua DESC " +
            "LIMIT #{count}")
    List<GoodsToUpVO> selectTotalGoodsUpNumber(int count);
}
