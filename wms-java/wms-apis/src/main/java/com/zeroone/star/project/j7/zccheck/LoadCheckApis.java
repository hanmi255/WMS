package com.zeroone.star.project.j7.zccheck;


import com.zeroone.star.project.dto.j7.zccheck.BatchCheckDTO;
import com.zeroone.star.project.dto.j7.zccheck.CheckDTO;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 描述：装车复核相关接口
 * </p>
 *
 * @author chen
 * @since 2025/2/25 14:47
 */


public interface LoadCheckApis {


    /**
     * 批量复核
     * @param batchCheckDTO 批量复核条件
     * @return 批量复核结果
     */
    JsonVO<List<CheckDTO>> checkModify(List<CheckDTO> batchCheckDTO);
}
