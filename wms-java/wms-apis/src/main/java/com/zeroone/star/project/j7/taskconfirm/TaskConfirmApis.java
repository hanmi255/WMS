package com.zeroone.star.project.j7.taskconfirm;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.taskconfirm.BatchConfirmationDTO;
import com.zeroone.star.project.dto.j7.taskconfirm.BatchSetRecipientsDTO;
import com.zeroone.star.project.dto.j7.taskconfirm.ModifyTaskDTO;
import com.zeroone.star.project.dto.j7.taskconfirm.OutboundTaskDTO;
import com.zeroone.star.project.query.j7.taskconfirm.OutboundTaskQuery;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 描述：任务确认接口
 * </p>
 *
 * @author LLy
 * @since 2025/2/23
 */
public interface TaskConfirmApis {

    /**
     * 分页获取出库任务列表
     * @param  outboundTaskQuery 查询条件
     * @return 响应数据结果
     */
    JsonVO<PageDTO<OutboundTaskDTO>> queryAll(OutboundTaskQuery outboundTaskQuery);

    /**
     * 修改任务
     *
     * @param modfiyTaskDTO 修改任务参数
     * @return 修改任务结果
     */
    JsonVO<ModifyTaskDTO> modifyTask(ModifyTaskDTO modfiyTaskDTO);

    /**
     * 批量设置接收人
     * @param ids 传入id
     * @param receiverName 接收人姓名
     * @return 批量设置接收人结果
     */
    JsonVO<Integer> batchSetRecipients(List<String> ids, String receiverName);

    /**
     * 批量确认任务
     * @param ids 传入id
     * @return 批量确认结果
     */
    JsonVO<Integer> batchConfirmation(List<String> ids);
}
