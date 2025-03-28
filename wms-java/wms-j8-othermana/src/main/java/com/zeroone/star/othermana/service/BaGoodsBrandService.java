package com.zeroone.star.othermana.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.query.j8.other.goodsbrand.GoodsBrandQuery;
import com.zeroone.star.project.vo.j8.other.goodsbrand.GoodsBrandAddReqVO;
import com.zeroone.star.project.vo.j8.other.goodsbrand.GoodsBrandUpdateOprationRespVO;
import com.zeroone.star.project.vo.j8.other.goodsbrand.GoodsBrandVO;

import java.util.List;

/**
* @author 陈尚益
* @description 针对表【ba_goods_brand(品牌信息)】的数据库操作Service
* @createDate 2025-03-08 11:38:45
*/
public interface BaGoodsBrandService extends IService<GoodsBrandVO> {

    PageDTO<GoodsBrandVO> queryGoodsBrandPage(GoodsBrandQuery query);

    boolean addGoodsBrand(GoodsBrandAddReqVO goodsBrandAddReqVO);

    GoodsBrandUpdateOprationRespVO oprationGetById(String id);

    boolean saveAll(List<GoodsBrandVO> list);
}
