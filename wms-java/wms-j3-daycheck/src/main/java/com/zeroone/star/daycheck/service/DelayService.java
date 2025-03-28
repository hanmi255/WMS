package com.zeroone.star.daycheck.service;


import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.daycheck.entity.Delay;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.daycheck.delay.WaringAllDTO;

import java.util.List;

public interface DelayService extends IService<Delay> {

    PageDTO<WaringAllDTO> selectAll(Integer pageIndex, Integer pageSize);

    List<Delay> selectExcel();
}
