package com.zeroone.star.othermana.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.project.dto.j8.other.goodsbrand.GoodsBrandDTO;
import com.zeroone.star.project.vo.j8.other.goodsbrand.GoodsBrandVO;
import org.apache.ibatis.annotations.Mapper;

/**
* @author 陈尚益
* @description 针对表【ba_goods_brand(品牌信息)】的数据库操作Mapper
* @createDate 2025-03-08 11:38:45
* @Entity com.zeroone.star.goodsbrand.entity.BaGoodsBrand
*/
@Mapper
public interface BaGoodsBrandMapper extends BaseMapper<GoodsBrandVO> {

    boolean addGoodsBrand(GoodsBrandDTO goodsBrandDTO);
}




