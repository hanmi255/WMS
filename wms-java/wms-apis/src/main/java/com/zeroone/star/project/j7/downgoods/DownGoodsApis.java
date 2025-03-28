package com.zeroone.star.project.j7.downgoods;

import com.zeroone.star.project.dto.j7.downgoods.DownGoodsDTO;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;

import java.util.ArrayList;
import java.util.List;

/**
 * @ClassName DownGoodsApis
 * @Description 商品下架Api接口
 * @Author: rocklin
 * @Date 2025/2/23 21:54
 * @Version 1.0
 */
public interface DownGoodsApis {
    /**
     * 批量修改下架商品的信息
     *
     * @param downGoodsDTOList 商品下架数据传输对象
     * @return 修改结果
     */
    JsonVO<String> batchUpdateDownGoods(List<DownGoodsDTO> downGoodsDTOList);

    /**
     * 下架商品 (支持批量下架）
     *
     * @param ids 下架商品ID
     * @return 响应数据结果
     */
    JsonVO<String> downGoods(List<String> ids);

    /**
     * 删除下架任务
     *
     * @param id 下架任务ID
     * @return 响应数据结果
     */
    JsonVO<String> deleteDownGoods(String id);


    /**
     * 导出下架数据
     * @param ids
     * @return
     */
    public ResponseEntity<byte[]> exportDownGoodsData(List<String> ids) throws Exception;
}
