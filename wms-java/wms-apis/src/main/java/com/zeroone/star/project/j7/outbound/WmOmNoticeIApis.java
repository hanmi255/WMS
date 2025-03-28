package com.zeroone.star.project.j7.outbound;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.outbound.WmOmNoticeIDTO;
import com.zeroone.star.project.query.j7.outbound.WmOmNoticeIQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

public interface WmOmNoticeIApis {


    /**
     * 获取出库通知项列表（条件+分页）
     * @param query
     * @return
     */
    JsonVO<PageDTO<WmOmNoticeIDTO>> queryAllWmOmNoticeI(WmOmNoticeIQuery query);

    /**
     * 修改出库通知项（支持批量修改）
     * @param dto
     * @return
     */
    JsonVO<String> modifyWmOmNoticeI(List<WmOmNoticeIDTO> dto);
}
