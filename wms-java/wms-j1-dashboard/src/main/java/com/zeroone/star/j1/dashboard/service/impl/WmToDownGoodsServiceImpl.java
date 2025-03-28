package com.zeroone.star.j1.dashboard.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.j1.dashboard.entity.WmToDownGoods;
import com.zeroone.star.j1.dashboard.mapper.WmToDownGoodsMapper;
import com.zeroone.star.j1.dashboard.service.IWmToDownGoodsService;
import com.zeroone.star.project.constant.j1.dashboard.GoodsRedisKeyConstant;
import com.zeroone.star.project.vo.j1.dashboard.GoodsDownInRecentVO;
import com.zeroone.star.project.vo.j1.dashboard.GoodsToDownVO;
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
public class WmToDownGoodsServiceImpl extends ServiceImpl<WmToDownGoodsMapper, WmToDownGoods> implements IWmToDownGoodsService {

    @Resource(name = "dayGoodsDownRedisTemplate")
    private RedisTemplate<String, List<GoodsDownInRecentVO>> dayDownRedisTemplate;
    @Resource
    private WmToDownGoodsMapper wmToDownGoodsMapper;
    @Override
    public List<GoodsDownInRecentVO> listGoodsDownNumberInRecentDays(int count) {
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
        List<GoodsDownInRecentVO> goods = dayDownRedisTemplate.opsForValue().get(GoodsRedisKeyConstant.GOODS_DOWN_IN_RECENT_DAYS);
        if (goods == null){
            List<GoodsDownInRecentVO> goodsList = wmToDownGoodsMapper.selectGoodsDownNumberInRecentDays(startDate, endDate);
            if (goodsList == null){
                throw new RuntimeException("查询失败");
            }
            int keyTTL = ThreadLocalRandom.current().nextInt(1, 11);
            if (goodsList.size() == 0){
                dayDownRedisTemplate.opsForValue().set(GoodsRedisKeyConstant.GOODS_DOWN_IN_RECENT_DAYS, goodsList, 60 * 2 + keyTTL , TimeUnit.SECONDS);
                return goodsList;
            }
            dayDownRedisTemplate.opsForValue().set(GoodsRedisKeyConstant.GOODS_DOWN_IN_RECENT_DAYS, goodsList, 60 * 12 + keyTTL, TimeUnit.MINUTES);
            return goodsList;
        }

        return goods;
    }

    @Resource(name = "totalGoodsDownRedisTemplate")
    private RedisTemplate<String, List<GoodsToDownVO>> totalDownRedisTemplate;
    @Override
    public List<GoodsToDownVO> listTotalGoodsDownNumber(int count) {
        if (count > 30){
            throw new RuntimeException("请求参数过大");
        }
        if (count < 1){
            throw new RuntimeException("请求参数过小");
        }
        List<GoodsToDownVO> goods = totalDownRedisTemplate.opsForValue().get(GoodsRedisKeyConstant.TOTAL_GOODS_DOWN);
        if (goods == null){
            List<GoodsToDownVO> goodsList = wmToDownGoodsMapper.selectTotalGoodsDownNumber(count);
            if (goodsList == null){
                throw new RuntimeException("查询失败");
            }
            int keyTTL = ThreadLocalRandom.current().nextInt(1, 11);
            totalDownRedisTemplate.opsForValue().set(GoodsRedisKeyConstant.TOTAL_GOODS_DOWN, goodsList, 60 * 2 + keyTTL,TimeUnit.SECONDS);
            return goodsList;
        }
        return goods;
    }
}
