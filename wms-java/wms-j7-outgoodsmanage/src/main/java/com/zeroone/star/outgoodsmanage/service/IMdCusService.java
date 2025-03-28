package com.zeroone.star.outgoodsmanage.service;

import com.zeroone.star.project.query.j7.outbound.WonQuery;
import com.zeroone.star.outgoodsmanage.entity.MdCus;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.outgoodsmanage.entity.WmOmNoticeH;

/**
 * <p>
 *  服务类
 * </p>
 *
 * @author qiuye
 * @since 2025-02-23
 */
public interface IMdCusService extends IService<MdCus> {
    MdCus queryByOmId(WonQuery query);
}
