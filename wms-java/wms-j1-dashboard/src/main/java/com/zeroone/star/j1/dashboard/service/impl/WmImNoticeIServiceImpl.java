package com.zeroone.star.j1.dashboard.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.j1.dashboard.entity.WmImNoticeI;
import com.zeroone.star.j1.dashboard.mapper.WmImNoticeIMapper;
import com.zeroone.star.j1.dashboard.service.IWmImNoticeIService;
import com.zeroone.star.project.constant.j1.dashboard.GoodsRedisKeyConstant;
import com.zeroone.star.project.vo.j1.dashboard.GoodsPendingVO;
import lombok.SneakyThrows;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.Objects;
import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.TimeUnit;

/**
 * <p>
 *  待收货服务实现类
 * </p>
 *
 * @author j1-yunyu
 * @since 2025-02-27
 */
@Service
public class WmImNoticeIServiceImpl extends ServiceImpl<WmImNoticeIMapper, WmImNoticeI> implements IWmImNoticeIService {

    @Resource(name = "pendGoodsRedisTemplate")
    private RedisTemplate<String,String> redisTemplate;
    @SneakyThrows
    @Override
    public GoodsPendingVO getReceiptGoodNumber() {
        //TODO 如何获取当前用户信息 编写工具类根据用户唯一标识生成对应key
        //TODO 编写缓存工具类获取缓存数据，避免缓存击穿，避免缓存穿透，避免缓存雪崩等问题
        String goodsNumber = redisTemplate.opsForValue().get(GoodsRedisKeyConstant.GOODS_AWAITING_RECEIPT);
        GoodsPendingVO goodsPendingVO = new GoodsPendingVO();
        goodsPendingVO.setGoodsStatus("待收货");
        goodsPendingVO.setGoodsNumber(goodsNumber);
        if (goodsNumber == null){
            QueryWrapper<WmImNoticeI> queryWrapper = new QueryWrapper<>();
            queryWrapper.select("goods_count").eq("bin_pre","N");
            List<WmImNoticeI> wmImNoticeIS = baseMapper.selectList(queryWrapper);
            if (wmImNoticeIS == null){
                throw new Exception("待收货数量查询失败");
            }
            // 随机生成key的过期时间
            int keyTTL = ThreadLocalRandom.current().nextInt(1, 11);
            if (wmImNoticeIS.size() == 0){
                goodsPendingVO.setGoodsNumber("0");
                redisTemplate.opsForValue().set(GoodsRedisKeyConstant.GOODS_AWAITING_RECEIPT,"0", 60L * keyTTL, TimeUnit.SECONDS);
                return goodsPendingVO;
            }
            String safeTotal = String.valueOf( //将获取的每个货物件转换为浮点型后求和，再以String返回
                    wmImNoticeIS.stream()
                            .map(WmImNoticeI::getGoodsCount)
                            .filter(Objects::nonNull) // 过滤null和特殊字符
                            .mapToDouble(Double::parseDouble)
                            .sum()
            );
            redisTemplate.opsForValue().set(GoodsRedisKeyConstant.GOODS_AWAITING_RECEIPT,safeTotal, 60L * keyTTL, TimeUnit.SECONDS);
            goodsPendingVO.setGoodsNumber(safeTotal);
            return goodsPendingVO;
        }

        return goodsPendingVO;
    }


}
