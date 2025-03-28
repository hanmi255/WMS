package com.zeroone.star.j1.dashboard.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.j1.dashboard.entity.WmInQmI;
import com.zeroone.star.j1.dashboard.mapper.WmInQmIMapper;
import com.zeroone.star.j1.dashboard.service.IWmInQmIService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.constant.j1.dashboard.GoodsRedisKeyConstant;
import com.zeroone.star.project.vo.j1.dashboard.GoodsPendingVO;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.Objects;
import java.util.concurrent.ThreadLocalRandom;
import java.util.concurrent.TimeUnit;

/**
 * <p>
 *  待上架货物服务实现类
 * </p>
 *
 * @author j1-yunyu
 * @since 2025-02-27
 */
@Service
public class WmInQmIServiceImpl extends ServiceImpl<WmInQmIMapper, WmInQmI> implements IWmInQmIService {

    @Resource(name = "pendGoodsRedisTemplate")
    private RedisTemplate<String,String> redisTemplate;

    @Override
    public GoodsPendingVO getToUpGoodNumber() {
        String goodsNumber = redisTemplate.opsForValue().get(GoodsRedisKeyConstant.GOODS_AWAITING_UP);
        GoodsPendingVO goodsPendingVO = new GoodsPendingVO();
        goodsPendingVO.setGoodsStatus("待上架");
        goodsPendingVO.setGoodsNumber(goodsNumber);
        if (goodsNumber == null){
            QueryWrapper<WmInQmI> queryWrapper = new QueryWrapper<>();
            queryWrapper.select("qm_ok_quat").eq("bin_sta","N");
            List<WmInQmI> wmInQmIList = baseMapper.selectList(queryWrapper);
            if (wmInQmIList== null){
                throw new RuntimeException("待上架货物数量查询失败");
            }
            // 随机生成key的过期时间
            int keyTTL = ThreadLocalRandom.current().nextInt(1, 11);
            if (wmInQmIList.size() == 0){
                goodsPendingVO.setGoodsNumber("0");
                redisTemplate.opsForValue().set(GoodsRedisKeyConstant.GOODS_AWAITING_UP,"0", 60L * keyTTL, TimeUnit.SECONDS);
                return goodsPendingVO;
            }
            String safeTotal = String.valueOf( //将获取的每个货物件转换为浮点型后求和，再以String返回
                    wmInQmIList.stream()
                            .map(WmInQmI::getQmOkQuat)
                            .filter(Objects::nonNull) // 过滤null和特殊字符
                            .mapToDouble(Double::parseDouble)
                            .sum()
            );
            redisTemplate.opsForValue().set(GoodsRedisKeyConstant.GOODS_AWAITING_UP,safeTotal, 60L * keyTTL, TimeUnit.SECONDS);
            goodsPendingVO.setGoodsNumber(safeTotal);
            return goodsPendingVO;
        }

        return goodsPendingVO;
    }

}
