package com.zeroone.star.stockln.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.stockln.ImportNoticeListDTO;
import com.zeroone.star.project.query.j6.stockln.ImportNoticeQuery;
import com.zeroone.star.stockln.entity.WmImNoticeH;
import com.zeroone.star.stockln.mapper.WmImNoticeHMapper;
import com.zeroone.star.stockln.service.IWmImNoticeHService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;


@Mapper(componentModel = "spring")
interface MsWmImNoticeHMapper{
    ImportNoticeListDTO WmImNoticeHToWmImNoticeHDTO(WmImNoticeH wmImNoticeH);
}


/**
 * <p>
 * 预约进货通知抬头 服务实现类
 * </p>
 *
 * @author juhao
 * @since 2025-03-06
 */
@Service
public class WmImNoticeHServiceImpl extends ServiceImpl<WmImNoticeHMapper, WmImNoticeH> implements IWmImNoticeHService {

    @Resource
    MsWmImNoticeHMapper msWmImNoticeHMapper;

    @Override
    public PageDTO<ImportNoticeListDTO> listAll(ImportNoticeQuery query) {

        Page<ImportNoticeListDTO> page = new Page<>(query.getPageIndex(), query.getPageSize());
        QueryWrapper<WmImNoticeH> wrapper = new QueryWrapper<>();
        if (query.getNoticeId() != null)
            wrapper.like("notice_id", query.getNoticeId());
        if (query.getCusCode() != null)
            wrapper.eq("cus_code", query.getCusCode());
        if (query.getImCusCode() != null)
            wrapper.like("im_cus_code", query.getImCusCode());
        if (query.getSupCode() != null)
            wrapper.like("sup_code", query.getSupCode());
        if (query.getSupName() != null)
            wrapper.like("sup_name", query.getSupName());
        if (query.getOrderTypeCode()!= null)
            wrapper.eq("order_type_code", query.getOrderTypeCode());
        if (query.getImSta() != null)
            wrapper.like("im_sta", query.getImSta());
        if (query.getImCarDri() != null)
            wrapper.like("im_car_dri", query.getImCarDri());
        if (query.getImCarNo() != null)
            wrapper.like("im_car_no",query.getImCarNo());
        if (query.getImDataBegin() != null && query.getImDataEnd() != null)
            wrapper.between("create_date", query.getImDataBegin(), query.getImDataEnd());

//        Page<WmImNoticeH> ps = baseMapper.selectPage(page, wrapper);
//        List<ImportNoticeListDTO> list_ =  baseMapper.searchAll(page, wrapper);
         page = baseMapper.searchAll(page, wrapper);

        return PageDTO.create(page, (s)->s);
    }


}
