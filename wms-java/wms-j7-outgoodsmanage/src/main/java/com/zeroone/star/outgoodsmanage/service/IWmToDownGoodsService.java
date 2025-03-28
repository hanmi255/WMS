package com.zeroone.star.outgoodsmanage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.outgoodsmanage.entity.WmToDownGoods;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.adpick.AdPickExportDTO;
import com.zeroone.star.project.dto.j7.adpick.AdPickModifyBaseDTO;
import com.zeroone.star.project.dto.j7.adpick.AdPickModifyDTO;
import com.zeroone.star.project.dto.j7.adpick.AdPickPageDTO;
import com.zeroone.star.project.dto.j7.downgoods.DownGoodsDTO;
import com.zeroone.star.project.dto.j7.zccheck.CheckListDTO;
import com.zeroone.star.project.query.j7.adpick.AdPickQuery;
import com.zeroone.star.project.query.j7.zccheck.ZcCheckQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j7.adPick.AdPickDeatilVO;
import com.zeroone.star.project.vo.j7.adPick.AdPickVO;
import org.springframework.http.ResponseEntity;

import java.util.List;

/**
 * <p>
 * 商品下架 服务类
 * </p>
 *
 * @author rocklin
 * @since 2025-02-23
 */
public interface IWmToDownGoodsService extends IService<WmToDownGoods> {
        // 批量修改下架商品信息
        int batchUpdateDownGoods(List<DownGoodsDTO> downGoodsDTOList);
        // 下架商品
        int downGoods(List<String> ids);
        // 删除下架任务
        int removeDownGoods(String id);

        //导出下架数据
        ResponseEntity<byte[]> exportDownGoods(List<String> ids) throws Exception;


        JsonVO<PageDTO<AdPickVO>> selectPage(AdPickPageDTO adPickPageDTO);

        JsonVO<AdPickDeatilVO> setectOneDeatil(String id);

        PageDTO<CheckListDTO> queryAll(ZcCheckQuery query);
        boolean modifyAdPick(AdPickModifyDTO adPickModifyDTO);
        boolean modifyAdPickList(List<AdPickModifyBaseDTO> dtos);
        List<AdPickExportDTO> queryExportData(List<AdPickQuery> queries);
}
