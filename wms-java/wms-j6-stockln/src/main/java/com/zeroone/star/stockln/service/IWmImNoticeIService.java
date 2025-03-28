package com.zeroone.star.stockln.service;

import com.zeroone.star.project.dto.j6.stockln.ImportNoticeDetailHeadDTO;
import com.zeroone.star.stockln.entity.WmImNoticeI;
import com.baomidou.mybatisplus.extension.service.IService;

/**
 * <p>
 * 预约进货通知明细 服务类
 * </p>
 *
 * @author juhao
 * @since 2025-03-06
 */
public interface IWmImNoticeIService extends IService<WmImNoticeI> {

    ImportNoticeDetailHeadDTO getDetailsById(String imNoticeId);
}
