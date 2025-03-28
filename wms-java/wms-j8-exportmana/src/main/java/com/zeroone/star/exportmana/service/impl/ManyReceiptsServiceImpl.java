package com.zeroone.star.exportmana.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.exportmana.entity.ManyReceipts;
import com.zeroone.star.exportmana.mapper.ManyReceiptsMapper;
import com.zeroone.star.exportmana.service.ManyReceiptsService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.manyreceipts.ManyRecepitsDTO;
import com.zeroone.star.project.query.j8.shipmentmana.manyreceipts.ManyReceiptsQuery;
import org.mapstruct.Mapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * @author 陈尚益
 * @description 针对表【wm_om_notice_h(出库通知抬头)】的数据库操作Service实现
 * @createDate 2025-03-01 10:38:33
 */

@Mapper(componentModel = "spring")
interface MsManyReceiptsMapper {
    ManyRecepitsDTO manyReceiptsToManyRecepitsDTO(ManyReceipts manyReceipts);

    ManyReceipts manyRecepitsDTOToManyReceipts(ManyRecepitsDTO manyRecepitsDTO);

}


@Service
public class ManyReceiptsServiceImpl extends ServiceImpl<ManyReceiptsMapper, ManyReceipts>
        implements ManyReceiptsService {

    @Autowired
    private MsManyReceiptsMapper msManyReceiptsMapper;

    @Override
    public PageDTO<ManyRecepitsDTO> queryManyReceiptsList(ManyReceiptsQuery manyReceiptsQuery) {
        Page<ManyReceipts> page = new Page<>(manyReceiptsQuery.getPageIndex(), manyReceiptsQuery.getPageSize());
        QueryWrapper<ManyReceipts> queryWrapper = new QueryWrapper<>();
        if (manyReceiptsQuery != null) {
            //动态添加客户订单号查询条件
            if (manyReceiptsQuery.getCoustomerOrederNo() != null && !manyReceiptsQuery.getCoustomerOrederNo().equals("")) {
                queryWrapper.like("im_cus_code", manyReceiptsQuery.getCoustomerOrederNo());
            }
            //动态添加备注查询条件
            if (manyReceiptsQuery.getRemark() != null && !manyReceiptsQuery.getCoustomerOrederNo().equals("")) {
                queryWrapper.like("om_beizhu", manyReceiptsQuery.getRemark());
            }
            //动态添加出货单号查询条件
            if (manyReceiptsQuery.getDeliveryNo() != null && !manyReceiptsQuery.getCoustomerOrederNo().equals("")) {
                queryWrapper.like("om_notice_id", manyReceiptsQuery.getDeliveryNo());
            }
            //动态添加客户代码查询条件
            if (manyReceiptsQuery.getCustomer() != null && !manyReceiptsQuery.getCoustomerOrederNo().equals("")) {
                queryWrapper.eq("cus_code", manyReceiptsQuery.getCustomer());
            }
            //动态添加回单日期最小查询条件
            if (manyReceiptsQuery.getReceiptStartTime() != null && !manyReceiptsQuery.getCoustomerOrederNo().equals("")) {
                queryWrapper.ge("delv_date", manyReceiptsQuery.getReceiptStartTime());
            }
            //动态添加回单日期最大查询条件
            if (manyReceiptsQuery.getReceiptEndTime() != null && !manyReceiptsQuery.getCoustomerOrederNo().equals("")) {
                queryWrapper.le("delv_date", manyReceiptsQuery.getReceiptEndTime());
            }
            //动态添加收货人姓名查询条件
            if (manyReceiptsQuery.getConsignee() != null && !manyReceiptsQuery.getCoustomerOrederNo().equals("")) {
                queryWrapper.like("delv_menber", manyReceiptsQuery.getConsignee());
            }
            //动态添加收货人手机号查询条件
            if (manyReceiptsQuery.getConsigneePhone() != null && !manyReceiptsQuery.getCoustomerOrederNo().equals("")) {
                queryWrapper.like("delv_mobile", manyReceiptsQuery.getConsigneePhone());
            }
            //动态添加承运人姓名查询条件
            if (manyReceiptsQuery.getCarrier() != null && !manyReceiptsQuery.getCoustomerOrederNo().equals("")) {
                queryWrapper.like("re_menber", manyReceiptsQuery.getCarrier());
            }
            //动态添加承运人手机号查询条件
            if (manyReceiptsQuery.getCarrierPhone() != null && !manyReceiptsQuery.getCoustomerOrederNo().equals("")) {
                queryWrapper.like("re_mobile", manyReceiptsQuery.getCarrierPhone());
            }
            //动态添加添加承运人车牌号查询条件
            if (manyReceiptsQuery.getCarrierCarNumber() != null && !manyReceiptsQuery.getCoustomerOrederNo().equals("")) {
                queryWrapper.like("re_carno", manyReceiptsQuery.getCarrierCarNumber());
            }
            //动态添加发货月台查询条件
            if (manyReceiptsQuery.getPlatNo() != null && !manyReceiptsQuery.getCoustomerOrederNo().equals("")) {
                queryWrapper.eq("om_plat_no", manyReceiptsQuery.getPlatNo());
            }
            //动态添加回单状态查询条件
            if (manyReceiptsQuery.getReceiptStatus() != null && !manyReceiptsQuery.getCoustomerOrederNo().equals("")) {
                queryWrapper.eq("om_sta", manyReceiptsQuery.getReceiptStatus());
            }
        }
        Page<ManyReceipts> manyReceiptsPage = baseMapper.selectPage(page, queryWrapper);
        return PageDTO.create(manyReceiptsPage, msManyReceiptsMapper::manyReceiptsToManyRecepitsDTO);
    }

    @Override
    public int updateListManyReceipts(List<ManyRecepitsDTO> manyReceiptsDTOList) {
        int count = 0;
        for (ManyRecepitsDTO manyReceiptsDTO : manyReceiptsDTOList) {
            ManyReceipts manyReceipts = msManyReceiptsMapper.manyRecepitsDTOToManyReceipts(manyReceiptsDTO);
            int i = baseMapper.updateById(manyReceipts);
            if (i > 0) {
                count++;
            }
        }
        return count;
    }
}




