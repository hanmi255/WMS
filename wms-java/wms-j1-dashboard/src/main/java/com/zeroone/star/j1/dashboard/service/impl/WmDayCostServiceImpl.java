package com.zeroone.star.j1.dashboard.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.j1.dashboard.entity.WmDayCost;
import com.zeroone.star.j1.dashboard.mapper.WmDayCostMapper;
import com.zeroone.star.j1.dashboard.service.IWmDayCostService;
import com.zeroone.star.project.constant.j1.dashboard.GoodsRedisKeyConstant;
import com.zeroone.star.project.vo.j1.dashboard.WmDayCostInRecentVO;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.time.LocalDate;
import java.time.ZoneId;
import java.time.temporal.ChronoUnit;
import java.util.List;
import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.TimeUnit;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author j1-yunyu
 * @since 2025-03-04
 */
@Service
public class WmDayCostServiceImpl extends ServiceImpl<WmDayCostMapper, WmDayCost> implements IWmDayCostService {

    @Resource(name = "dayCostRedisTemplate")
    private RedisTemplate<String,List<WmDayCostInRecentVO>> redisTemplate;
    @Resource
    private WmDayCostMapper wmDayCostMapper;
    @Override
    public List<WmDayCostInRecentVO> listOneDayTotalCost(int count) {
        if (count > 90){
            throw new RuntimeException("请求参数过大");
        }
        if (count < 1){
            throw new RuntimeException("请求参数过小");
        }
        LocalDate endDate = LocalDate.now(ZoneId.of("Asia/Shanghai"));
        //根据count来确定起始日期
        LocalDate startDate = endDate.minus(count, ChronoUnit.DAYS);
        if (startDate == null){
            throw new RuntimeException("起始日期获取失败");
        }
        List<WmDayCostInRecentVO> goods = redisTemplate.opsForValue().get(GoodsRedisKeyConstant.ONE_DAY_TOTAL_COST);
        if (goods == null){
            List<WmDayCostInRecentVO> goodsList = wmDayCostMapper.selectOneDayTotalCost(startDate, endDate);
            if (goodsList == null){
                throw new RuntimeException("查询失败");
            }
            if (goodsList.size() == 0){
                redisTemplate.opsForValue().set(GoodsRedisKeyConstant.ONE_DAY_TOTAL_COST, goodsList, 60 * 2, TimeUnit.SECONDS);
                return goodsList;
            }
            int keyTTL = ThreadLocalRandom.current().nextInt(1, 11);
            redisTemplate.opsForValue().set(GoodsRedisKeyConstant.ONE_DAY_TOTAL_COST, goodsList, 60 * 12 + keyTTL, TimeUnit.MINUTES);
            return goodsList;
        }

        return goods;
    }
}
