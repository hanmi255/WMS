package com.zeroone.star.stockln.service.impl;

import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.j6.stockln.AcceptDTO;
import com.zeroone.star.project.dto.j6.stockln.ToListUpdateDTO;
import com.zeroone.star.stockln.mapper.AcceptMapper;
import com.zeroone.star.stockln.service.ToListService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 描述：待上架货物相关服务实现类
 * </p>
 *
 * @author []
 * @version 1.0.0
 */
@Service
public class ToListServiceImpl extends ServiceImpl<AcceptMapper, AcceptDTO> implements ToListService {

    @Autowired
    private AcceptMapper acceptMapper; // ✅ 替换 ToListMapper 为 AcceptMapper

    /**
     * 修改待上架货物信息
     * @param updateDTO 需要修改的信息
     * @return 是否修改成功
     */
    @Override
    public boolean updateToList(ToListUpdateDTO updateDTO) {
        // 创建更新条件
        UpdateWrapper<AcceptDTO> updateWrapper = new UpdateWrapper<>();
        updateWrapper.eq("id", updateDTO.getId()); // 以 ID 作为条件

        // 创建更新对象
        AcceptDTO acceptDTO = new AcceptDTO();
        acceptDTO.setTinId(updateDTO.getTinId());  // 托盘
        acceptDTO.setBinId(updateDTO.getBinId());  // 储位
        acceptDTO.setQmOkQuat(updateDTO.getQmOkQuat());  // 收货数量
        acceptDTO.setTinTj(updateDTO.getTinTj());  // 体积
        acceptDTO.setTinZhl(updateDTO.getTinZhl());  // 重量
        acceptDTO.setProData(updateDTO.getProData());  // 生产日期
        acceptDTO.setGoodsBatch(updateDTO.getGoodsBatch());  // 批次
        acceptDTO.setRecDeg(updateDTO.getRecDeg());  // 收货温度
        acceptDTO.setItemText(updateDTO.getItemText());  // 备注
        acceptDTO.setBaseInGoodscount(updateDTO.getBaseInGoodscount());  // 入重量
        acceptDTO.setBaseOutGoodscount(updateDTO.getBaseOutGoodscount());  // 出重量

        // 执行更新
        return acceptMapper.update(acceptDTO, updateWrapper) > 0;
    }
}
