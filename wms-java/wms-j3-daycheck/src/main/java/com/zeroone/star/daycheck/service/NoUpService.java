package com.zeroone.star.daycheck.service;

import com.zeroone.star.daycheck.entity.NoUpGoods;
import com.zeroone.star.project.dto.j3.daycheck.Arr.NoUpGoodsDTO;
import com.zeroone.star.project.query.j3.daycheck.Arr.NoUpGoodsQuery;

import java.util.List;

public interface NoUpService {
    List<NoUpGoodsDTO> getNoUpGoodsPage(NoUpGoodsQuery condition);

    List<NoUpGoods> getDate();
}
