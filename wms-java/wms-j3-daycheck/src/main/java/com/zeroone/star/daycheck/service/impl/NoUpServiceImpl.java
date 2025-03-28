package com.zeroone.star.daycheck.service.impl;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.daycheck.entity.NoUpGoods;
import com.zeroone.star.daycheck.mapper.NoUpMapper;
import com.zeroone.star.daycheck.service.NoUpService;
import com.zeroone.star.project.dto.j3.daycheck.Arr.NoUpGoodsDTO;
import com.zeroone.star.project.query.j3.daycheck.Arr.NoUpGoodsQuery;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.*;

/**
 * @author aaa
 * @version 1.0
 * @description TODO
 * @date 2025/2/27 10:30
 */
@Service
public class NoUpServiceImpl implements NoUpService {

    @Resource
    NoUpMapper noUpMapper;

    Map<String,List<NoUpGoods>> data ;

    @Override
    public List<NoUpGoodsDTO> getNoUpGoodsPage(NoUpGoodsQuery condition) {
        data = new HashMap<>();
        Page<NoUpGoods> page = new Page<>(condition.getPageIndex(), condition.getPageSize());
        Page<NoUpGoods> pages = noUpMapper.getNoUpGoodsPage(page, condition);
        ArrayList<NoUpGoodsDTO> result = new ArrayList<>();
        for(NoUpGoods noUpGoods : pages.getRecords()){
            NoUpGoodsDTO noUpGoodsDTO = new NoUpGoodsDTO();
            BeanUtils.copyProperties(noUpGoods,noUpGoodsDTO);
            noUpGoodsDTO.setKucunsta(noUpGoods.getBin_sta());
            result.add(noUpGoodsDTO);
        }
        data.put("a1",pages.getRecords());
        return result;
    }

    @Override
    public List<NoUpGoods> getDate() {
        return data.get("a1");
    }
}
