package com.zeroone.star.project.j6.stockln;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.stockln.WvStockDTO;
import com.zeroone.star.project.query.j6.stockln.WvStockQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface StockQueryApis {
    JsonVO<PageDTO<WvStockDTO>> queryAllStock(WvStockQuery condition);
}
