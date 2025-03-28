package com.zeroone.star.outgoodsmanage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.outgoodsmanage.entity.WmOmQmI;
import com.zeroone.star.project.dto.j7.taskconfirm.BatchConfirmationDTO;
import com.zeroone.star.project.dto.j7.taskconfirm.BatchSetRecipientsDTO;
import com.zeroone.star.project.dto.j7.taskconfirm.ModifyTaskDTO;

import java.util.List;

/**
 * <p>
 * 描述：任务确认Service
 * </p>
 *
 * @author zjx
 * @since 2025/3/2
 */
public interface TaskConfirmService extends IService<WmOmQmI> {

    // 修改任务
    int modifyTask(ModifyTaskDTO modifyTaskDTO);

    /**
     * 设置批量接收人
     * @param ids 传入id
     * @param receiverName 接收人姓名
     * @return 1 为成功 -1 为失败
     */
    int batchSetReceiver( List<String> ids,String receiverName);

    /**
     * 批量确认
     * @param ids 传入id
     * @return 1为成功 -1 为失败
     */
    int batchConfirmTask(List<String> ids);
}
