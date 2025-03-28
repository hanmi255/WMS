package com.zeroone.star.outgoodsmanage.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.outgoodsmanage.entity.WmOmQmI;
import com.zeroone.star.project.dto.j7.taskconfirm.OutboundTaskDTO;
import com.zeroone.star.project.dto.j7.taskconfirm.WaveGenDTO;
import com.zeroone.star.project.query.j7.taskconfirm.OutboundTaskQuery;
import com.zeroone.star.project.dto.PageDTO;

import java.util.List;

/**
 * <p>
 * 出库任务 服务类
 * </p>
 *
 * @author Longlive
 * @since 2025-02-21
 */
public interface IWmOmQmIService extends IService<WmOmQmI> {
       void genWave(WaveGenDTO ids);

       void delMission(WaveGenDTO ids);

       List<WmOmQmI> getData();
       PageDTO<OutboundTaskDTO> queryAll(OutboundTaskQuery outboundTaskQuery);
}
