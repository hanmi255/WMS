package com.zeroone.star.outgoodsmanage.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.outgoodsmanage.entity.WmOmQmI;
import com.zeroone.star.project.dto.j7.taskconfirm.BatchConfirmationDTO;
import com.zeroone.star.project.dto.j7.taskconfirm.BatchSetRecipientsDTO;
import com.zeroone.star.project.dto.j7.taskconfirm.ModifyTaskDTO;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 描述：任务确认mapper接口
 * </p>
 *
 * @author LLy
 * @since 2025/3/1
 */
@Mapper
public interface TaskConfirMapper extends BaseMapper<WmOmQmI> {
    // 修改任务
    int modifyTask(ModifyTaskDTO modifyTaskDTO);
    // 批量设置接收人
    int batchSetReceiver(BatchSetRecipientsDTO batchSetRecipientsDTO);
    // 批量确认任务
    int batchConfirmTask(BatchConfirmationDTO batchConfirmationDTO);
}
