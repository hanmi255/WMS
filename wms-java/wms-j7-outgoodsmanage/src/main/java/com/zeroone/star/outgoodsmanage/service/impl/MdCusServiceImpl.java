package com.zeroone.star.outgoodsmanage.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.project.query.j7.outbound.WonQuery;
import com.zeroone.star.outgoodsmanage.entity.MdCus;
import com.zeroone.star.outgoodsmanage.entity.WmOmNoticeH;
import com.zeroone.star.outgoodsmanage.mapper.MdCusMapper;
import com.zeroone.star.outgoodsmanage.mapper.WmOmNoticeHMapper;
import com.zeroone.star.outgoodsmanage.mapper.WmOmNoticeIMapper;
import com.zeroone.star.outgoodsmanage.service.IMdCusService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * <p>
 *  服务实现类
 * </p>
 *
 * @author qiuye
 * @since 2025-02-23
 */
@Service
public class MdCusServiceImpl extends ServiceImpl<MdCusMapper, MdCus> implements IMdCusService {

    @Resource
    WmOmNoticeHServiceImpl wmOmNoticeHService;
    @Resource
    MdCusMapper mdCusMapper;
    @Override
    public MdCus queryByOmId(WonQuery query) {
        String cusCode = wmOmNoticeHService.queryByOmId(query).getCusCode();
        return mdCusMapper.queryByCode(cusCode);
    }

}
