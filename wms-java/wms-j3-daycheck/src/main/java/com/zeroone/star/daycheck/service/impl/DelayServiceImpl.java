package com.zeroone.star.daycheck.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.daycheck.entity.Delay;
import com.zeroone.star.daycheck.mapper.DelayMapper;
import com.zeroone.star.daycheck.service.DelayService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j3.daycheck.delay.WaringAllDTO;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.List;


@Service
public class DelayServiceImpl extends ServiceImpl<DelayMapper, Delay> implements DelayService {

    @Override
    public PageDTO<WaringAllDTO> selectAll(Integer pageIndex, Integer pageSize) {
        LocalDateTime now = LocalDateTime.now();

        Page<Delay> page = new Page<>(pageIndex,pageSize);

        QueryWrapper<Delay> queryWrapper = new QueryWrapper<>();

        queryWrapper.lt("im_data",now);

        Page <Delay> delayPage = baseMapper.selectPage(page,queryWrapper);


        PageDTO<WaringAllDTO> delayPageDTO = PageDTO.create(delayPage, WaringAllDTO.class);

        return delayPageDTO;
    }

    @Override
    public List<Delay> selectExcel() {
        LocalDateTime now = LocalDateTime.now();

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        String nowStr = now.format(formatter);
        System.out.println(nowStr);
        QueryWrapper<Delay> queryWrapper = new QueryWrapper<>();

        queryWrapper.lt("im_data", nowStr);

        List<Delay> delays = baseMapper.selectList(queryWrapper);

        delays.forEach(System.out::println);

        return delays;
    }
}
