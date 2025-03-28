package com.zeroone.star.stockln.service;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.stockln.ImportNoticeListDTO;
import com.zeroone.star.project.query.j6.stockln.ImportNoticeQuery;
import com.zeroone.star.stockln.entity.WmImNoticeH;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 * 预约进货通知抬头 服务类
 * </p>
 *
 * @author juhao
 * @since 2025-03-06
 */
public interface IWmImNoticeHService extends IService<WmImNoticeH> {

    PageDTO<ImportNoticeListDTO> listAll(ImportNoticeQuery query);
}
