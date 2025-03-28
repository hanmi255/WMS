package com.zeroone.star.project.j6.stockln;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.stockln.BatchModifyBinDTO;
import com.zeroone.star.project.dto.j6.stockln.InboundQmIDTO;
import com.zeroone.star.project.dto.j6.stockln.ModifyShelvesDTO;
import com.zeroone.star.project.dto.j6.stockln.ToShelvesDTO;
import com.zeroone.star.project.query.j6.stockln.ToShelvesQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.stockln.InboundQmIVO;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.multipart.MultipartFile;

import javax.validation.Valid;

/**
 * 收货登记
 */
public interface GoodsReceiveApis {

    /**
     * 分页查询待上架的货物
     *
     * @return
     */
    JsonVO<PageDTO<InboundQmIDTO>> pageToSheleves(ToShelvesQuery toShelvesQuery);

    /**
     * 获取待上架货物详细信息
     *
     * @param
     * @return
     */

    JsonVO<String> addItem(@RequestBody @Valid ToShelvesDTO dto);

    JsonVO<String> removeItem(@PathVariable String id);

    JsonVO<String> modifyItem(@RequestBody ModifyShelvesDTO dto);

    JsonVO<InboundQmIDTO> getShelevesByid(@PathVariable String id);

    JsonVO<String> batchModifyBin(@RequestBody BatchModifyBinDTO dto);

    // 导入报表接口
    public JsonVO<InboundQmIVO> importItems(MultipartFile file);


    public JsonVO<String> exportAllItems();
}
