package com.zeroone.star.j1.dashboard.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.j1.dashboard.entity.WmToUpGoods;
import com.zeroone.star.j1.dashboard.mapper.WmToUpGoodsMapper;
import com.zeroone.star.j1.dashboard.service.IWmToUpGoodsService;
import com.zeroone.star.project.constant.j1.dashboard.GoodsRedisKeyConstant;
import com.zeroone.star.project.vo.j1.dashboard.GoodsToUpVO;
import com.zeroone.star.project.vo.j1.dashboard.GoodsUpInRecentVO;
import lombok.extern.slf4j.Slf4j;
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
 * @since 2025-02-27
 */
@Service
@Slf4j
public class WmToUpGoodsServiceImpl extends ServiceImpl<WmToUpGoodsMapper, WmToUpGoods> implements IWmToUpGoodsService {

    @Resource(name = "dayGoodsRedisTemplate")
    private RedisTemplate<String, List<GoodsUpInRecentVO>> dayRedisTempLate;
    @Resource
    private WmToUpGoodsMapper wmToUpGoodsMapper;
    @Override
    public List<GoodsUpInRecentVO> listGoodsToUpNumberInRecentDays(int count) {
        if (count > 30){
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
        List<GoodsUpInRecentVO> goods = dayRedisTempLate.opsForValue().get(GoodsRedisKeyConstant.GOODS_UP_IN_RECENT_DAYS);
        if (goods == null){
            List<GoodsUpInRecentVO> goodsList = wmToUpGoodsMapper.selectGoodsToUpNumberInRecentDays(startDate, endDate);
            if (goodsList == null){
                throw new RuntimeException("查询失败");
            }
            int keyTTL = ThreadLocalRandom.current().nextInt(1, 11);
            if (goodsList.size() == 0){
                dayRedisTempLate.opsForValue().set(GoodsRedisKeyConstant.GOODS_UP_IN_RECENT_DAYS, goodsList, 60 * 2 + keyTTL,TimeUnit.SECONDS);
                return goodsList;
            }
            dayRedisTempLate.opsForValue().set(GoodsRedisKeyConstant.GOODS_UP_IN_RECENT_DAYS, goodsList, 60 * 2 + keyTTL,TimeUnit.MINUTES);
            return goodsList;
        }
        return goods;
    }

    @Resource(name = "totalGoodsUpRedisTemplate")
    private RedisTemplate<String, List<GoodsToUpVO>> totalUpRedisTemplate;
    @Override
    public List<GoodsToUpVO> listTotalGoodsUpNumber(int count) {
        if (count > 30){
            throw new RuntimeException("请求参数过大");
        }
        if (count < 1){
            throw new RuntimeException("请求参数过小");
        }
        List<GoodsToUpVO> goods = totalUpRedisTemplate.opsForValue().get(GoodsRedisKeyConstant.TOTAL_GOODS_UP);
        if (goods == null){
            List<GoodsToUpVO> goodsList = wmToUpGoodsMapper.selectTotalGoodsUpNumber(count);
            if (goodsList == null){
                throw new RuntimeException("查询失败");
            }
            int keyTTL = ThreadLocalRandom.current().nextInt(1, 11);
            totalUpRedisTemplate.opsForValue().set(GoodsRedisKeyConstant.TOTAL_GOODS_UP, goodsList, 60 * 2 + keyTTL,TimeUnit.SECONDS);
            return goodsList;
        }
        return goods;
    }
}
