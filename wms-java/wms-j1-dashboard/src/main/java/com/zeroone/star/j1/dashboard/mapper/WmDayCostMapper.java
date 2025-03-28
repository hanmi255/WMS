package com.zeroone.star.j1.dashboard.mapper;

import com.zeroone.star.j1.dashboard.entity.WmDayCost;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.vo.j1.dashboard.WmDayCostInRecentVO;
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
 * @since 2025-03-04
 */
@Mapper
public interface WmDayCostMapper extends BaseMapper<WmDayCost> {

    @Select("SELECT DATE(cost_data) AS cost_data, " +
            "SUM(CAST(day_cost_yj AS UNSIGNED)) AS day_cost_yj " +
            "FROM wm_day_cost " +
            "WHERE cost_data >= #{startDate} and cost_data < #{endDate} " +
            "GROUP BY DATE(cost_data) " +
            "ORDER BY DATE(cost_data) ASC")
    List<WmDayCostInRecentVO> selectOneDayTotalCost(LocalDate startDate, LocalDate endDate);
}
