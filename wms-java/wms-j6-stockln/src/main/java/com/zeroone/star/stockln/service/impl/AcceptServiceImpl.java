package com.zeroone.star.stockln.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j6.stockln.AcceptRequestDTO;
import com.zeroone.star.project.dto.j6.stockln.ToAcceptDTO;
import com.zeroone.star.stockln.mapper.AcceptMapper;
import com.zeroone.star.stockln.mapper.ToAcceptMapper;
import com.zeroone.star.stockln.service.AcceptService;
import com.zeroone.star.project.dto.j6.stockln.AcceptDTO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class AcceptServiceImpl extends ServiceImpl<AcceptMapper, AcceptDTO> implements AcceptService {

    @Autowired
    private AcceptMapper acceptMapper;  // 注入验收记录的 Mapper

    @Autowired
    private ToAcceptMapper toAcceptMapper;  // 注入待验收货物的 Mapper

    @Override
    public boolean processAcceptance(AcceptRequestDTO requestDTO) {
        try {
            // 1. 创建验收记录
            AcceptDTO acceptDTO = new AcceptDTO();
            acceptDTO.setImNoticeId(requestDTO.getImNoticeId());
            acceptDTO.setGoodsId(requestDTO.getGoodsId());
            acceptDTO.setCusCode(requestDTO.getCusCode());
            acceptDTO.setBinId(requestDTO.getBinId());
            acceptDTO.setQmOkQuat(requestDTO.getImQuat());
            acceptDTO.setGoodsBatch(requestDTO.getGoodsBatch());
            acceptDTO.setRecDeg(requestDTO.getRecDeg());
            acceptDTO.setItemText(requestDTO.getItemText());
            acceptDTO.setTinId(requestDTO.getTinId());
            acceptDTO.setTinZhl(requestDTO.getTinZhl());
            acceptDTO.setCreateDate(java.time.LocalDateTime.now());

            // 使用 MyBatis-Plus 的 save() 方法保存
            save(acceptDTO);

            // 2. 更新待验收货物的数量
            ToAcceptDTO toAcceptDTO = toAcceptMapper.selectById(requestDTO.getId());
            if (toAcceptDTO != null) {
                int newGoodsWqmCount = toAcceptDTO.getGoodsWqmCount() - Integer.parseInt(requestDTO.getImQuat());
                int newGoodsQmCount = toAcceptDTO.getGoodsQmCount() + Integer.parseInt(requestDTO.getImQuat());

                // 更新数据库中的数量
                toAcceptDTO.setGoodsWqmCount(newGoodsWqmCount);
                toAcceptDTO.setGoodsQmCount(newGoodsQmCount);

                // 更新待验收货物的状态
                toAcceptMapper.updateById(toAcceptDTO);
            }

            return true;
        } catch (Exception e) {
            // 处理失败的情况
            e.printStackTrace();
            return false;
        }
    }
}
