package com.zeroone.star.project.j6.stockln;

import com.zeroone.star.project.query.j6.stockln.InNoticeQuery;
import com.zeroone.star.project.query.j6.stockln.ToAcceptQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j6.stockln.InNoticePageVO;
import com.zeroone.star.project.vo.j6.stockln.ToAcceptDetailVO;
import com.zeroone.star.project.vo.j6.stockln.ToAcceptPageVO;

/**
 * <p>
 * 描述：待验收货物相关接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 *
 * @version 1.0.0
 */
public interface InNoticeApis {

    /**
     * 获取入库通知明细列表，支持条件查询和分页查询
     *
     * @param query 查询条件（包括到货通知单、商品编码等）
     * @param page  页码
     * @param size  每页数量
     * @return 返回分页的待验收货物列表
     */
    JsonVO<InNoticePageVO> getInNoticeItems(InNoticeQuery query, int page, int size);

}
