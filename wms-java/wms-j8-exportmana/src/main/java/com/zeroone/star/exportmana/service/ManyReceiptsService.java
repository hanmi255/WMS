package com.zeroone.star.exportmana.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.exportmana.entity.ManyReceipts;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.manyreceipts.ManyRecepitsDTO;
import com.zeroone.star.project.query.j8.shipmentmana.manyreceipts.ManyReceiptsQuery;

import java.util.List;

/**
* @author 陈尚益
* @description 针对表【wm_om_notice_h(出库通知抬头)】的数据库操作Service
* @createDate 2025-03-01 10:38:33
*/
public interface ManyReceiptsService extends IService<ManyReceipts> {

    PageDTO<ManyRecepitsDTO> queryManyReceiptsList(ManyReceiptsQuery manyReceiptsQuery);


    int updateListManyReceipts(List<ManyRecepitsDTO> manyReceiptsDTOList);
}
