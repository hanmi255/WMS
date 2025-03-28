package com.zeroone.star.project.j6.stockln;

import com.zeroone.star.project.dto.j6.stockln.AcceptRequestDTO;
import com.zeroone.star.project.vo.JsonVO;

/**
 * 描述：验收操作的API接口
 * 提供处理验收相关操作的方法
 */
public interface AcceptApis {

    /**
     * 提交验收数据
     * 该接口用于接收前端提交的验收数据
     * @param id 待验收货物的ID
     * @param requestDTO 包含待验收货物的详细信息及用户填写的字段
     * @return 验收操作是否成功的状态信息
     */
    JsonVO<String> acceptItem(String id, AcceptRequestDTO requestDTO);
}
