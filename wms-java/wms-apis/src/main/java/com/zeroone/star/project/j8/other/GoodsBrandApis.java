package com.zeroone.star.project.j8.other;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.other.goodsbrand.GoodsBrandDTO;
import com.zeroone.star.project.query.j8.other.goodsbrand.GoodsBrandQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j8.other.goodsbrand.GoodsBrandAddReqVO;
import com.zeroone.star.project.vo.j8.other.goodsbrand.GoodsBrandNameVO;
import com.zeroone.star.project.vo.j8.other.goodsbrand.GoodsBrandUpdateOprationRespVO;
import com.zeroone.star.project.vo.j8.other.goodsbrand.GoodsBrandVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.multipart.MultipartFile;

import java.io.IOException;
import java.util.List;

/**
 * @ClassName: GoodsBrandApis
 * @Package: com.zeroone.star.project.j8.other.goodsbrand
 * @Description: 商品品牌接口api
 * @Author: zk
 * @Create: 2025/2/26 - 上午9:30
 */
public interface GoodsBrandApis {

    /**
     * 获取商品品牌列表(条件加分页)
     * @param query 查询条件
     * @return 商品品牌列表
     */
    JsonVO<PageDTO<GoodsBrandVO>> queryGoodsBrand(GoodsBrandQuery query);

    /**
     * 录入商品皮牌
     * @return
     */
    JsonVO<String> addGoodsBrand(GoodsBrandAddReqVO goodsBrandAddReqVO);

    /**
     * 修改商品品牌按钮操作
     * @return
     */
    JsonVO<GoodsBrandUpdateOprationRespVO> modifyGoodsBrand(String id);

    /**
     * 删除商品品牌(支持批量删除)
     * @param ids 商品品牌id，每一个id使用 , 分割
     * @return
     */
    JsonVO<String> removeGoodsBandByIds(List<String> ids);


    /**
     * 导出商品品牌
     * @param query 查询条件
     * @return
     */
    ResponseEntity<byte[]> exportGoodsBrand(GoodsBrandQuery query) throws IOException;


    /**
     * 导入商品品牌
     * @param file 文件对象
     * @return
     */
    JsonVO<String> importGoodsBrand(MultipartFile file);
}
