package com.zeroone.star.project.j7.adpick;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.adpick.*;
import com.zeroone.star.project.query.j7.adpick.AdPickQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j7.adPick.AdPickDeatilVO;
import com.zeroone.star.project.vo.j7.adPick.AdPickVO;
import org.springframework.http.ResponseEntity;
import com.zeroone.star.project.query.j7.adpick.AnDanPickQuery;

import java.util.List;

/**
 * <p>
 * 描述：按单拣货接口
 * </p>
 *
 * @author 阿晨
 * @since 2025/2/22 12:47
 */
public interface AnDanPickApis {
    /**
     * 修改拣货单
     * @param adPickModifyDTO
     * @return
     */
    JsonVO<String> modify(AdPickModifyDTO adPickModifyDTO);

    /**
     * 批量修改拣货单
     * @param adPickModifyBaseDTOs
     * @return
     */
    JsonVO<String> modifyList(List<AdPickModifyBaseDTO> adPickModifyBaseDTOs);

    /**
     * 导出拣货excel数据表
     * @param queries 查询条件
     * @return 响应数据结果
     */
    ResponseEntity<byte[]> exportExcel(List<AdPickQuery> queries);


    /**
     * 获取拣货明细列表
     * @param adPickPageDTO 查询条件（多个查询）
     * @return 响应数据结果
     */
    JsonVO<PageDTO<AdPickVO>> queryAllAnDanPickApis(AdPickPageDTO adPickPageDTO);

    /**
     * 获取拣货详细信息（单个查询）
     * @param id -查询条件
     * @return
     */
    JsonVO<AdPickDeatilVO> queryOneAnDanPickApis(String id);
}
