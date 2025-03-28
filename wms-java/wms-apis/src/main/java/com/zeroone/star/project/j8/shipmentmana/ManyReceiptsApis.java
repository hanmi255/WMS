package com.zeroone.star.project.j8.shipmentmana;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.manyreceipts.ManyRecepitsDTO;
import com.zeroone.star.project.query.j8.shipmentmana.manyreceipts.ManyReceiptsQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * 批量回单接口
 * @author csy
 * @date 2021/12/13 14:53
 */
public interface ManyReceiptsApis {
    JsonVO<PageDTO<ManyRecepitsDTO>> queryManyReceiptsList(ManyReceiptsQuery manyReceiptsQuery);
    JsonVO<String> putManyReceipts(List<ManyRecepitsDTO> manyReceiptsDTOList);
}
