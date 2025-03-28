package com.zeroone.star.project.j5.basezl;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.basezl.goods.GoodsAddDTO;
import com.zeroone.star.project.dto.j5.basezl.goods.GoodsDetailDTO;
import com.zeroone.star.project.dto.j5.basezl.goods.GoodsListDTO;
import com.zeroone.star.project.dto.j5.basezl.goods.GoodsModifyDTO;
import com.zeroone.star.project.query.j5.basezl.goods.GoodsQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.servlet.ModelAndView;

import javax.servlet.http.HttpServletRequest;
import java.util.List;

/**
 * 商品管理接口
 */
public interface GoodsApis {

    /**
     * 获取商品列表
     *
     * @param query 查询条件
     * @return 响应数据结果
     */
    JsonVO<PageDTO<GoodsListDTO>> queryAll(GoodsQuery query);

    /**
     * 获取商品详细信息
     *
     * @param shp_bian_ma 商品编号
     * @return 响应数据结果
     */
    JsonVO<GoodsDetailDTO> queryOne(String shp_bian_ma);

    /**
     * 录入商品信息
     *
     * @param goodsAddDTO 商品信息
     * @return 响应数据结果
     */
    JsonVO<String> addGoods(GoodsAddDTO goodsAddDTO);

    /**
     * 修改商品信息
     *
     * @param goodsModifyDTO 商品信息
     * @return 响应数据结果
     */
    JsonVO<String> updateGoods(GoodsModifyDTO goodsModifyDTO);

    /**
     * 批量删除商品信息
     *
     * @param shpBianMas 需要删除商品的商品编码集合
     * @return 响应数据结果
     */
    JsonVO<String> deleteGoods(List<String> shpBianMas);

    /**
     * 导入商品
     *
     * @param file 导入文件
     * @return 响应数据结果
     */
    JsonVO<String> uploadGoods(MultipartFile file);

    /**
     * 导出商品
     *
     * @param shpBianMas 需要导出商品的商品编码集合
     * @return
     */
    ResponseEntity<byte[]> exportGoods(List<String> shpBianMas);

    /**
     * 打印标签
     * @param shpBianMa 商品编码
     * @return
     */
    ResponseEntity<byte[]> printGoodsTiaoMa(String shpBianMa);
}
