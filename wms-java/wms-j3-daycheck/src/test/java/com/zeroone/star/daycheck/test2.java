package com.zeroone.star.daycheck;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.daycheck.entity.NoUpGoods;
import com.zeroone.star.daycheck.mapper.NoUpMapper;
import com.zeroone.star.daycheck.service.NoUpService;
import com.zeroone.star.project.query.j3.daycheck.Arr.NoUpGoodsQuery;
import jdk.nashorn.internal.ir.annotations.Reference;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

import javax.annotation.Resource;

/**
 * @author aaa
 * @version 1.0
 * @description TODO
 * @date 2025/2/25 15:37
 */
@SpringBootTest
public class test2 {

    @Resource
    NoUpMapper noUpMapper;

    @Resource
    NoUpService noUpService;

    @Test
    public void test(){
        NoUpGoodsQuery query = new NoUpGoodsQuery();
        query.setPageIndex(1);
        query.setPageSize(10);
        query.setShp_ming_cheng("蔗糖");
        Page<NoUpGoods> page = new Page<>(query.getPageIndex(), query.getPageSize());
        Page<NoUpGoods> noUpGoodsPage = noUpMapper.getNoUpGoodsPage(page, query);
        for(NoUpGoods noUpGoods : noUpGoodsPage.getRecords()){
            System.out.println(noUpGoods);
        }
    }

    @Test
    public void test2(){
        NoUpGoodsQuery query = new NoUpGoodsQuery();
        query.setShp_ming_cheng("蔗糖");
        noUpService.getNoUpGoodsPage(query);
    }
}
