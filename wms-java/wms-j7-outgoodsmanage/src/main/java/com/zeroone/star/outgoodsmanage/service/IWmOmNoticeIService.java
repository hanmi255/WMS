package com.zeroone.star.outgoodsmanage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.outgoodsmanage.entity.WmOmNoticeI;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.outbound.WmOmNoticeIDTO;
import com.zeroone.star.project.dto.j7.outmanage.OutGoodsNoticeFormDTO;
import com.zeroone.star.project.dto.j7.outmanage.OutNoticeItemDTO;
import com.zeroone.star.project.dto.j7.outmanage.WonhGoodsDTO;
import com.zeroone.star.project.dto.j7.outmanage.WoniGoodsDTO;

import com.zeroone.star.project.query.j7.outbound.WmOmNoticeIQuery;
import com.zeroone.star.project.query.j7.outbound.WonQuery;

import java.util.List;
/**
 * <p>
 * 出库通知项 服务类
 * </p>
 *
 * @author lenyan
 * @since 2025-02-21
 */
public interface IWmOmNoticeIService extends IService<WmOmNoticeI> {

    PageDTO<WmOmNoticeIDTO> queryAllWmOmNoticeI(WmOmNoticeIQuery query);

    void modifyWmOmNoticeI(List<WmOmNoticeIDTO> modifyList);

    //录入出库通知项
    int saveOutGoodsNotice(OutGoodsNoticeFormDTO outGoodsNoticeFormDTO);
    OutNoticeItemDTO getNoticeItem(String omNoticeId);

    List<WonhGoodsDTO> queryByOmId(WonQuery query);

    List<WoniGoodsDTO> queryByOmIdToI(WonQuery query);
}
