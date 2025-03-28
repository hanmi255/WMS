package com.zeroone.star.outgoodsmanage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.outgoodsmanage.entity.OutDetailDO;
import com.zeroone.star.outgoodsmanage.entity.WmOmNoticeH;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.outmanage.OutNoticeListDTO;
import com.zeroone.star.project.query.j7.outnotice.OutGoodNoticeQuery;

import com.zeroone.star.outgoodsmanage.entity.OutDetailExcelDO;
import com.zeroone.star.outgoodsmanage.entity.WmOmNoticeH;
import com.zeroone.star.project.dto.j7.outdetail.OutDetailDTO;
import com.zeroone.star.project.query.j7.outdetail.OutDetailExcelQuery;
import com.zeroone.star.project.query.j7.outdetail.OutDetailQuery;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

import com.zeroone.star.project.dto.j7.outmanage.WonhDTO;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Update;


/**
 * <p>
 * 出库通知抬头 Mapper 接口
 * </p>
 *
 * @author lenyan
 * @author 做了错饭
 * @since 2025-02-21
 */
@Mapper
public interface WmOmNoticeHMapper extends BaseMapper<WmOmNoticeH> {



    /**
     * 描述：查询出库通知列表
     * @param query
     * @return List<OutNoticeListDTO>
     */
    Page<WmOmNoticeH> selectNoticeList(@Param("page") Page<WmOmNoticeH> page, @Param("query") OutGoodNoticeQuery query);

    void saveFujian(@Param("omNoticeId") String omNoticeId,@Param("fuJian") String fuJian);


    @Update("UPDATE wm_om_notice_h " +
            "SET cus_code = #{cusCode}," +
            " delv_data = #{delvData}, " +
            " order_type_code = #{orderTypeCode}, " +
            " im_cus_code = #{imCusCode}, " +
            " ocus_code = #{ocusCode}, " +
            " ocus_name = #{ocusName}, " +
            " delv_member = #{delvMember}, " +
            " delv_mobile = #{delvMobile}, " +
            " delv_addr = #{delvAddr}, " +
            " re_member = #{reMember}, " +
            " re_carno = #{reCarno}, " +
            " delv_method = #{delvMethod}, " +
            " om_plat_no = #{omPlatNo}, " +
            " om_beizhu = #{omBeizhu}, " +
            " store_code = #{storeCode}, " +
            " fu_jian = #{fuJian} " +
            "WHERE om_notice_id = #{omNoticeId}")
    boolean updateWmOmNoticeH(WonhDTO modify);

    /**
     * 获取出库明细列表分页查询
     * @return
     */
    List<OutDetailDO> getOrderDetailsByPage(@Param("query") OutDetailQuery query,
                                            @Param("pageSize") Integer pageSize,
                                            @Param("offset") Integer offset);

    /**
     * 获取出库明细列表计数查询
     * @return
     */
    int getOrderDetailsCount( @Param("query") OutDetailQuery query);

    /**
     * 查询出库明细excel数据
     * @return
     */
    List<OutDetailExcelDO> selectAll();

    WmOmNoticeH selectByNoticeId(String omNoticeId);


}
