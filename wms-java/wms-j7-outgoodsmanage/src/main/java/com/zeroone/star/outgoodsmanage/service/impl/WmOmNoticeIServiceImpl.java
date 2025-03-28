package com.zeroone.star.outgoodsmanage.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.outgoodsmanage.entity.TransportOrderDetailDO;
import com.zeroone.star.outgoodsmanage.entity.WmOmNoticeH;
import com.zeroone.star.outgoodsmanage.entity.WmOmNoticeI;
import com.zeroone.star.outgoodsmanage.mapper.TransportOrderMapper;
import com.zeroone.star.outgoodsmanage.mapper.WmOmNoticeHMapper;
import com.zeroone.star.outgoodsmanage.mapper.WmOmNoticeIMapper;
import com.zeroone.star.outgoodsmanage.service.IWmOmNoticeIService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.outbound.WmOmNoticeIDTO;

import com.zeroone.star.project.dto.j7.outmanage.OutGoodDetailDTO;
import com.zeroone.star.project.dto.j7.outmanage.OutNoticeItemDTO;
import com.zeroone.star.project.dto.j7.outmanage.TransportOrderDetailDTO;
import com.zeroone.star.project.query.j7.outbound.WmOmNoticeIQuery;

import com.zeroone.star.project.dto.j7.outmanage.WonhGoodsDTO;
import com.zeroone.star.project.dto.j7.outmanage.WoniGoodsDTO;
import com.zeroone.star.project.query.j7.outbound.WmOmNoticeIQuery;
import com.zeroone.star.project.query.j7.outbound.WonQuery;
import com.zeroone.star.project.dto.j7.outmanage.OutGoodsNoticeFormDTO;

import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;

@Mapper(componentModel = "spring")
interface  MsWoniMapper{
    List<WonhGoodsDTO> WoniToWonhGoodsDTO(List<WmOmNoticeI> wmOmNoticei);
    List<WoniGoodsDTO> WoniToWoniGoodsDTO(List<WmOmNoticeI> wmOmNoticei);
}
/**
 * <p>
 * 出库通知项 服务实现类
 * </p>
 *
 * @author lenyan
 * @author 做了错饭
 * @since 2025-02-21
 */
@Mapper(componentModel = "spring")
interface MsOutGoodsIMapper{

    /**
     * 将DO转换为DTO
     * @param wmOmNoticeH
     * @return
     */
    OutNoticeItemDTO wmOmNoticeHToOutNoticeItemDTO(WmOmNoticeH wmOmNoticeH);

    /**
     * 将WmOmNoticeI转换为OutGoodDetailDTO
     * @param wmOmNoticeIList
     * @return
     */
    List<OutGoodDetailDTO> wmOmNoticeIListToOutGoodDetailDTOList(List<WmOmNoticeI> wmOmNoticeIList);

    List<TransportOrderDetailDTO> transportDOListTotransportDtolist(List<TransportOrderDetailDO> transportOrderDetailDOList);
}



@Service
public class WmOmNoticeIServiceImpl extends ServiceImpl<WmOmNoticeIMapper, WmOmNoticeI> implements IWmOmNoticeIService {
    @Resource
    MsWoniMapper msWoniMapper;
    @Resource
    private WmOmNoticeIMapper wmOmNoticeIMapper;

    @Resource
    private WmOmNoticeHMapper wmOmNoticeHMapper;

    @Resource
    private MsOutGoodsIMapper msOutGoodsIMapper;

    //录入出库通知单
    @Override
    public int saveOutGoodsNotice(OutGoodsNoticeFormDTO outGoodsNoticeFormDTO) {
        return wmOmNoticeIMapper.insertOutGoodsNotice(outGoodsNoticeFormDTO);
    }

    @Override
    public PageDTO<WmOmNoticeIDTO> queryAllWmOmNoticeI(WmOmNoticeIQuery query) {
        Page<WmOmNoticeI> page = new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<WmOmNoticeI> queryWrapper = new QueryWrapper<WmOmNoticeI>();
        if (query.getOmNoticeId() != null) {
            queryWrapper.like("om_notice_id", query.getOmNoticeId());
        }
        if (query.getCusOrderId() != null) {
            queryWrapper.like("IM_CUS_CODE", query.getCusOrderId());
        }
        if (query.getGoodsText() != null) {
            queryWrapper.like("goods_text", query.getGoodsText());
        }
        if (query.getSku() != null) {
            queryWrapper.like("sku", query.getSku());
        }
        if (query.getBinId() != null) {
            queryWrapper.like("bin_id", query.getBinId());
        }

        Page<WmOmNoticeI> wmOmNoticeIPage = wmOmNoticeIMapper.selectPage(page, queryWrapper);
        List<WmOmNoticeI> records = wmOmNoticeIPage.getRecords();
        System.out.println(records);
            List<WmOmNoticeIDTO> wmOmNoticeIDTOList = wmOmNoticeIPage.getRecords().stream()
                .map(this::convertToDTO)
                .collect(Collectors.toList());
        return PageDTO.create(wmOmNoticeIPage, WmOmNoticeIDTO.class);
    }

    private WmOmNoticeIDTO convertToDTO(WmOmNoticeI wmOmNoticeI) {
        // 假设存在一个方法将 WmOmNoticeI 转换为 WmOmNoticeIDTO
        WmOmNoticeIDTO dto = new WmOmNoticeIDTO();
        BeanUtil.copyProperties(wmOmNoticeI, dto);
        return dto;
    }

    @Override
    public void modifyWmOmNoticeI(List<WmOmNoticeIDTO> modifyList) {
        for (WmOmNoticeIDTO wmOmNoticeIDTO : modifyList) {
            WmOmNoticeI wmOmNoticeI = new WmOmNoticeI();
            BeanUtil.copyProperties(wmOmNoticeIDTO, wmOmNoticeI);
            wmOmNoticeIMapper.updateById(wmOmNoticeI);
        }
    }


    @Resource
    private TransportOrderMapper transportOrderMapper;

    @Override
    public OutNoticeItemDTO getNoticeItem(String omNoticeId) {
        OutNoticeItemDTO outNoticeItemDTO;
        QueryWrapper<WmOmNoticeH> queryWrapperHead = new QueryWrapper<>();
        QueryWrapper<WmOmNoticeI> queryWrapperItem = new QueryWrapper<>();
        QueryWrapper<TransportOrderDetailDO> queryWrapperTransport = new QueryWrapper<>();

        queryWrapperHead.eq("om_notice_id", omNoticeId);
        queryWrapperItem.eq("om_notice_id", omNoticeId);
        queryWrapperTransport.eq("fadh", omNoticeId);

        //查询出货通知抬头
        WmOmNoticeH wmOmNoticeH = wmOmNoticeHMapper.selectOne(queryWrapperHead);
        if (wmOmNoticeH == null) {
            return null;
        }else{
            //查询出货通知明细
            List<WmOmNoticeI> wmOmNoticeIS = wmOmNoticeIMapper.selectList(queryWrapperItem);
            List<OutGoodDetailDTO> outGoodDetailDTOList = msOutGoodsIMapper.wmOmNoticeIListToOutGoodDetailDTOList(wmOmNoticeIS);
            //查询运输订单详情
            List<TransportOrderDetailDO> transportOrderDetailDTOS = transportOrderMapper.selectList(queryWrapperTransport);
            List<TransportOrderDetailDTO> transportOrderDetailDTOList = msOutGoodsIMapper.transportDOListTotransportDtolist(transportOrderDetailDTOS);

            //组装出货通知详情DTO
            outNoticeItemDTO = msOutGoodsIMapper.wmOmNoticeHToOutNoticeItemDTO(wmOmNoticeH);
            //组装出货商品明细DTO
            outNoticeItemDTO.setOutGoodDetailDTOList(outGoodDetailDTOList);
            //组装运输订单明细DTO
            outNoticeItemDTO.setTransportOrderDetailDTOList(transportOrderDetailDTOList);
            return outNoticeItemDTO;
        }
    }



    @Override
    public List<WonhGoodsDTO> queryByOmId(WonQuery query) {
        String omNoticeId = query.getOmNoticeId();
        return msWoniMapper.WoniToWonhGoodsDTO(wmOmNoticeIMapper.queryByOmNoticeId(omNoticeId));
    }
    @Override
    public List<WoniGoodsDTO> queryByOmIdToI(WonQuery query) {
        String omNoticeId = query.getOmNoticeId();
        return wmOmNoticeIMapper.queryByOmNoticeIdToI(omNoticeId);
    }
}
