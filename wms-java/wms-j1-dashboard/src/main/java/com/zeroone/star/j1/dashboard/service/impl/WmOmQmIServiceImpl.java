package com.zeroone.star.j1.dashboard.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.j1.dashboard.entity.WmOmQmI;
import com.zeroone.star.j1.dashboard.mapper.WmOmQmIMapper;
import com.zeroone.star.j1.dashboard.service.IWmOmQmIService;
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
 *  拣货相关服务实现类
 * </p>
 *
 * @author j1-yunyu
 * @since 2025-02-27
 */
@Service
public class WmOmQmIServiceImpl extends ServiceImpl<WmOmQmIMapper, WmOmQmI> implements IWmOmQmIService {

    @Resource(name = "pendGoodsRedisTemplate")
    private RedisTemplate<String,String> redisTemplate;
    @Override
    public GoodsPendingVO getPickGoodNumber() {
        String goodsNumber = redisTemplate.opsForValue().get(GoodsRedisKeyConstant.GOODS_AWAITING_PICKING);
        GoodsPendingVO goodsPendingVO = new GoodsPendingVO();
        goodsPendingVO.setGoodsStatus("待拣货");
        goodsPendingVO.setGoodsNumber(goodsNumber);
        if (goodsNumber == null){
            QueryWrapper<WmOmQmI> queryWrapper = new QueryWrapper<>();
            queryWrapper.select("qm_ok_quat").eq("bin_sta","I");
            List< WmOmQmI> wmOmQmIList = baseMapper.selectList(queryWrapper);
            if (wmOmQmIList== null){
                throw new RuntimeException("待拣货的货物数量查询失败");
            }
            // 随机生成key的过期时间
            int keyTTL = ThreadLocalRandom.current().nextInt(1, 11);
            if (wmOmQmIList.size() == 0){
                goodsPendingVO.setGoodsNumber("0");
                //生成1~10分钟的随机数作为过期时间
                redisTemplate.opsForValue().set(GoodsRedisKeyConstant.GOODS_AWAITING_PICKING,"0", 60L * keyTTL, TimeUnit.SECONDS);
                return goodsPendingVO;
            }
            String safeTotal = String.valueOf( //将获取的每个货物件转换为浮点型后求和，再以String返回
                    wmOmQmIList.stream()
                            .map( WmOmQmI::getQmOkQuat)
                            .filter(Objects::nonNull) // 过滤null和特殊字符
                            .mapToDouble(Double::parseDouble)
                            .sum()
            );
            redisTemplate.opsForValue().set(GoodsRedisKeyConstant.GOODS_AWAITING_PICKING,safeTotal, 60L * keyTTL, TimeUnit.SECONDS);
            goodsPendingVO.setGoodsNumber(safeTotal);
            return goodsPendingVO;
        }

        return goodsPendingVO;
    }

    @Override
    public GoodsPendingVO getCurrentPickGoodNumber() {
        String goodsNumber = redisTemplate.opsForValue().get(GoodsRedisKeyConstant.GOODS_PICKING_IN_PROGRESS);
        GoodsPendingVO goodsPendingVO = new GoodsPendingVO();
        goodsPendingVO.setGoodsStatus("拣货中");
        goodsPendingVO.setGoodsNumber(goodsNumber);
        if (goodsNumber == null){
            QueryWrapper<WmOmQmI> queryWrapper = new QueryWrapper<>();
            queryWrapper.select("qm_ok_quat").eq("bin_sta","N");
            List< WmOmQmI> wmOmQmIList = baseMapper.selectList(queryWrapper);
            if (wmOmQmIList== null){
                throw new RuntimeException("拣货中的货物数量查询失败");
            }
            // 随机生成key的过期时间
            int keyTTL = ThreadLocalRandom.current().nextInt(1, 11);
            if (wmOmQmIList.size() == 0){
                goodsPendingVO.setGoodsNumber("0");
                redisTemplate.opsForValue().set(GoodsRedisKeyConstant.GOODS_PICKING_IN_PROGRESS,"0", 60L * keyTTL, TimeUnit.SECONDS);
                return goodsPendingVO;
            }
            String safeTotal = String.valueOf( //将获取的每个货物件转换为浮点型后求和，再以String返回
                    wmOmQmIList.stream()
                            .map( WmOmQmI::getQmOkQuat)
                            .filter(Objects::nonNull) // 过滤null和特殊字符
                            .mapToDouble(Double::parseDouble)
                            .sum()
            );
            redisTemplate.opsForValue().set(GoodsRedisKeyConstant.GOODS_PICKING_IN_PROGRESS,safeTotal, 60L * keyTTL, TimeUnit.SECONDS);
            goodsPendingVO.setGoodsNumber(safeTotal);
            return goodsPendingVO;
        }

        return goodsPendingVO;
    }
}
