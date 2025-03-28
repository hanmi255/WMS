package com.zeroone.star.outgoodsmanage.service.impl;

import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.outgoodsmanage.entity.WmOmQmI;
import com.zeroone.star.outgoodsmanage.mapper.TaskConfirMapper;
import com.zeroone.star.outgoodsmanage.service.TaskConfirmService;
import com.zeroone.star.project.dto.j7.taskconfirm.BatchConfirmationDTO;
import com.zeroone.star.project.dto.j7.taskconfirm.BatchSetRecipientsDTO;
import com.zeroone.star.project.dto.j7.taskconfirm.ModifyTaskDTO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.List;

/**
 * <p>
 * 描述：任务确认Service实现类
 * </p>
 *
 * @author zjx
 * @since 2025/3/2
 */
@Service
public class TaskConfirmServiceImpl extends ServiceImpl<TaskConfirMapper, WmOmQmI> implements TaskConfirmService {
    @Autowired
    TaskConfirMapper taskConfirMapper;

    // 修改任务
    @Override
    public int modifyTask(ModifyTaskDTO modifyTaskDTO){
        return taskConfirMapper.modifyTask(modifyTaskDTO);
    }

    /**
     * 批量设置接收人
     * @param ids 传入id
     * @param receiverName 接收人姓名
     * @return
     */
    @Override
    public int batchSetReceiver(List<String> ids, String receiverName) {

        UpdateWrapper<WmOmQmI> wrapper = new UpdateWrapper();
        wrapper.in("id", ids).set("assign_to", receiverName);
        int update = taskConfirMapper.update(null, wrapper);
        if (update >0){
            return 1;
        }
        return -1;
    }

    /**
     * 批量确认
     * @param ids 传入id
     * @return
     */
    @Override
    public int batchConfirmTask(List<String> ids) {

        UpdateWrapper<WmOmQmI> wrapper = new UpdateWrapper();
        wrapper.in("id", ids).set("bin_sta","Y");
        int update = taskConfirMapper.update(null, wrapper);
        if (update >0){
            return 1;
        }
        return -1;
    }

}
