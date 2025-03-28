package com.zeroone.star.outgoodsmanage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.outgoodsmanage.entity.OutDetailExcelDO;
import com.zeroone.star.outgoodsmanage.entity.WmOmNoticeH;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.outdetail.OutDetailDTO;
import com.zeroone.star.project.dto.j7.outmanage.OutNoticeItemDTO;
import com.zeroone.star.project.dto.j7.outmanage.OutNoticeListDTO;
import com.zeroone.star.project.dto.j7.outmanage.WonhDTO;
import com.zeroone.star.project.query.j7.outbound.WonQuery;
import com.zeroone.star.project.dto.j7.outdetail.OutDetailExcelDTO;
import com.zeroone.star.project.query.j7.outdetail.OutDetailExcelQuery;
import com.zeroone.star.project.query.j7.outdetail.OutDetailQuery;
import com.zeroone.star.project.query.j7.outnotice.OutGoodNoticeQuery;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.List;

import java.util.List;

/**
 * <p>
 * 出库通知抬头 服务类
 * </p>
 *
 * @author lenyan
 * @since 2025-02-21
 */
public interface IWmOmNoticeHService extends IService<WmOmNoticeH> {


    Long removeNoticeH(Long id);



    /**
     * 分页查询出库明细数据
     * @param query 查询条件
     * @return 查询结果
     */
    PageDTO<OutDetailDTO> listAll(OutDetailQuery query);


    PageDTO<OutNoticeListDTO> getNoticeList(OutGoodNoticeQuery query);

    void saveFujian(String omNoticeId,String fuJian);

    String updateById(WonhDTO modify);
    WmOmNoticeH queryByOmId(WonQuery query);
    /**
     * 查询出库明细报表数据
     * @return
     */
    ResponseEntity<byte[]> selectExcel();


    /**
     * 打印出库单
     * @param id
     * @return
     */
    ResponseEntity<byte[]> queryOutGoodsList(@RequestParam String id);


    /**
     * 打印拣货单
     * @param id
     * @return
     */
    ResponseEntity<byte[]> queryPickingList(@RequestParam String id);




}
