package com.zeroone.star.outgoodsmanage.mapper;

import com.zeroone.star.project.dto.j7.outmanage.OutGoodsNoticeFormDTO;
import com.zeroone.star.project.dto.j7.outmanage.WoniGoodsDTO;
import com.zeroone.star.project.query.j7.outbound.WonQuery;
import com.zeroone.star.outgoodsmanage.entity.WmOmNoticeI;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import java.util.List;

/**
 * <p>
 *  Mapper 接口
 * </p>
 *
 * @author qiuye
 * @since 2025-02-22
 */
@Mapper
public interface WmOmNoticeIMapper extends BaseMapper<WmOmNoticeI> {
    @Select("SELECT goods_id,goods_name,goods_qua,goods_unit,goods_pro_data,barcode " +
            "FROM wm_om_notice_i " +
            "WHERE om_notice_id =#{omNoticeId}")
    List<WmOmNoticeI> queryByOmNoticeId(String omNoticeId);
    @Select("SELECT " +
            "    ni.goods_id," +
            "    md.shp_ming_cheng," +
            "    qm.pro_data," +
            "    ni.goods_qua," +
            "    md.chl_shl," +
            "    md.zhl_kgm," +
            "    pio.goods_now " +
            "FROM " +
            "    `wm_om_notice_i` ni " +
            "LEFT JOIN " +
            "    `md_goods` md " +
            "ON " +
            "    ni.goods_id = md.shp_bian_ma " +
            "LEFT JOIN " +
            "    `wm_om_qm_i` qm " +
            "ON " +
            "    ni.goods_id = qm.goods_id AND qm.om_notice_id = ni.om_notice_id " +
            "LEFT JOIN " +
            "    `rp_period_in_out` pio " +
            "ON " +
            "    ni.goods_id = pio.goods_id " +
            "WHERE " +
            "    ni.om_notice_id = #{omNoticeId};")
    List<WoniGoodsDTO> queryByOmNoticeIdToI(String omNoticeId);

    //录入出库通知单
    int insertOutGoodsNotice(OutGoodsNoticeFormDTO outGoodsNoticeFormDTO);
}
