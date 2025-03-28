package com.zeroone.star.stockln.service;

import com.zeroone.star.project.dto.j6.stockln.AcceptRequestDTO;
import com.zeroone.star.project.dto.j6.stockln.AcceptDTO;
import com.baomidou.mybatisplus.extension.service.IService;

public interface AcceptService extends IService<AcceptDTO> {
    /**
     * 处理验收操作
     * @param requestDTO 包含验收操作所需的字段
     * @return 是否成功
     */
    boolean processAcceptance(AcceptRequestDTO requestDTO);
}
