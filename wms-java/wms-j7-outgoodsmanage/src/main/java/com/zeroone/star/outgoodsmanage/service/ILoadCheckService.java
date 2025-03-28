package com.zeroone.star.outgoodsmanage.service;


import com.zeroone.star.project.dto.j7.zccheck.BatchCheckDTO;
import com.zeroone.star.project.dto.j7.zccheck.CheckDTO;

import java.util.List;

/**
 * <p>
 * 描述：
 * </p>
 *
 * @author chen
 * @since 2025/3/4 19:25
 */


public interface ILoadCheckService {
    List<CheckDTO> updateBatchCheck(List<CheckDTO> batchCheckDTO);
}
