package com.zeroone.star.j1.dashboard.config.task;

import com.zeroone.star.j1.dashboard.service.IWmDayCostService;
import com.zeroone.star.j1.dashboard.service.IWmToDownGoodsService;
import com.zeroone.star.j1.dashboard.service.IWmToUpGoodsService;
import com.zeroone.star.project.constant.j1.dashboard.GoodsRedisKeyConstant;
import com.zeroone.star.project.vo.j1.dashboard.*;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.redisson.api.RLock;
import org.redisson.api.RedissonClient;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;
import java.util.List;
import java.util.concurrent.TimeUnit;

/**
 * <p>
 * 描述：定时执行刷新缓存中的首页近七天商品数量，前六位商品数量 ，近日费用合计
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author j1-yunyu
 * @version 1.0.0
 */
@Component
@Slf4j
public class ScheduledTasks {

       @Resource
       private IWmToUpGoodsService wmToUpGoodsService;
       @Resource
       private IWmToDownGoodsService wmToDownGoodsService;
       @Resource
       private IWmDayCostService wmDayCostService;

       @Resource
       private RedissonClient redissonClient;

       @Resource
       private RedisTemplate<String,Object> redisTemplate;
       /**
        * 每天00.00执行执行任务
        */
       @SneakyThrows
       @Scheduled(cron = "0 1 0 * * ?")
       public void fetchDashboardData() {
           RLock lock = redissonClient.getLock("fetchGoodsDownNumbersLock");
           try {
               if (lock.tryLock(60, 60, TimeUnit.SECONDS)) {
                   redisTemplate.delete(GoodsRedisKeyConstant.GOODS_UP_IN_RECENT_DAYS);
                   redisTemplate.delete(GoodsRedisKeyConstant.GOODS_DOWN_IN_RECENT_DAYS);
                   redisTemplate.delete(GoodsRedisKeyConstant.TOTAL_GOODS_UP);
                   redisTemplate.delete(GoodsRedisKeyConstant.TOTAL_GOODS_DOWN);
                   redisTemplate.delete(GoodsRedisKeyConstant.ONE_DAY_TOTAL_COST);
                   // 获取七天前上架商品的数量
                   List<GoodsUpInRecentVO> goodsUpInRecentVOList = wmToUpGoodsService.listGoodsToUpNumberInRecentDays(7);
                   log.info("GoodsUpInRecentVO元素数量为：{}", goodsUpInRecentVOList.size());
                   List<GoodsToUpVO> goodsToUpVOS = wmToUpGoodsService.listTotalGoodsUpNumber(6);
                   log.info("GoodsToUpVO元素数量为：{}", goodsToUpVOS.size());
                   List<GoodsDownInRecentVO> goodsDownInRecentVOS = wmToDownGoodsService.listGoodsDownNumberInRecentDays(7);
                   log.info("GoodsDownInRecentVO元素数量为：{}", goodsDownInRecentVOS.size());
                   List<GoodsToDownVO> goodsToDownVOList = wmToDownGoodsService.listTotalGoodsDownNumber(6);
                   log.info("GoodsToDownVO元素数量为：{}", goodsToDownVOList.size());
                   List<WmDayCostInRecentVO> wmDayCostInRecentVOList = wmDayCostService.listOneDayTotalCost(7);
                   log.info("WmDayCostInRecentVO元素数量为：{}", wmDayCostInRecentVOList.size());

               }
           } finally {
               if (lock.isHeldByCurrentThread()) {
                   lock.unlock();
               }
           }
       }
   }
   