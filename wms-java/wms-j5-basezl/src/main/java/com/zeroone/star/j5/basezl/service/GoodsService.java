package com.zeroone.star.j5.basezl.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.j5.basezl.entity.good.MdGoods;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.basezl.goods.GoodsAddDTO;
import com.zeroone.star.project.dto.j5.basezl.goods.GoodsDetailDTO;
import com.zeroone.star.project.dto.j5.basezl.goods.GoodsListDTO;
import com.zeroone.star.project.dto.j5.basezl.goods.GoodsModifyDTO;
import com.zeroone.star.project.query.j5.basezl.goods.GoodsQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiParam;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * <p>
 * 商品信息 服务类
 * </p>
 *
 * @author heavydrink
 * @since 2025-02-27
 */
public interface GoodsService extends IService<MdGoods> {

    PageDTO<GoodsListDTO> queryAll(GoodsQuery query);

    GoodsDetailDTO queryOne(String shp_bian_ma);

    String addGoods(GoodsAddDTO goodsAddDTO);

    String updateGoods(GoodsModifyDTO goodsModifyDTO);

    String deleteGoods(List<String> shpBianMas);

    JsonVO<String> uploadGoods(MultipartFile file);

    ResponseEntity<byte[]> exportGoods(List<String> shpBianMas);

    ResponseEntity<byte[]> printGoodsTiaoMa(String shpBianMa);
}
