package com.zeroone.star.stockln.service.impl;

import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j6.stockln.BatchUpdateBinDTO;
import com.zeroone.star.project.dto.j6.stockln.BatchUpdateProductionDateDTO;
import com.zeroone.star.project.dto.j6.stockln.BatchUpdateShelfDTO;
import com.zeroone.star.stockln.entity.WmSttInGoods;
import com.zeroone.star.stockln.mapper.WmSttInGoodsMapper;
import com.zeroone.star.stockln.service.IWmSttInGoodsService;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;

/**
 * <p>
 * 盘点指令 服务实现类
 * </p>
 *
 * @author ting
 * @since 2025-03-06
 */
@Service
public class WmSttInGoodsServiceImpl extends ServiceImpl<WmSttInGoodsMapper, WmSttInGoods> implements IWmSttInGoodsService {
    @Resource
    private UserHolder userHolder;
    // 获取当前用户信息
    private UserDTO getCurrentUserInfo() {
        try {
            UserDTO user = userHolder.getCurrentUser();
            if (user == null) {
                throw new IllegalStateException("未获取到当前用户信息，请检查登录状态");
            }
            return user;
        } catch (Exception e) {
            throw new IllegalStateException("用户信息解析失败：" + e.getMessage());
        }
    }
    @Transactional
    public int batchUpdateBinIds(BatchUpdateBinDTO dto) {
        UserDTO currentUser=getCurrentUserInfo();
        // 构造更新条件
        UpdateWrapper<WmSttInGoods> updateWrapper = new UpdateWrapper<>();
        // WHERE id IN (...)
        updateWrapper.in("id", dto.getIds());
        // 要更新的字段值
        WmSttInGoods entity = new WmSttInGoods();
        entity.setBinId(dto.getNewBinId());
        entity.setUpdateDate(LocalDateTime.now());
        entity.setUpdateName(currentUser.getRealname());
        entity.setUpdateBy(currentUser.getUsername());
        entity.setSysCompanyCode(currentUser.getCompanyCode());
        entity.setSysOrgCode(currentUser.getOrgCode());
        boolean success = this.update(entity, updateWrapper);
        return success ? dto.getIds().size() : 0;
    }

    @Transactional
    public int batchUpdateProductionDate(BatchUpdateProductionDateDTO dto) {
        UserDTO currentUser=getCurrentUserInfo();
        // 构造更新条件
        UpdateWrapper<WmSttInGoods> updateWrapper = new UpdateWrapper<>();
        // WHERE id IN (...)
        updateWrapper.in("id", dto.getIds());
        // 要更新的字段值
        WmSttInGoods entity = new WmSttInGoods();
        entity.setGoodsProData(dto.getNewProductionDate());
        entity.setUpdateName(currentUser.getRealname());
        entity.setUpdateBy(currentUser.getUsername());
        entity.setUpdateDate(LocalDateTime.now());
        entity.setSysCompanyCode(currentUser.getCompanyCode());
        entity.setSysOrgCode(currentUser.getOrgCode());
        boolean success = this.update(entity, updateWrapper);
        return success ? dto.getIds().size() : 0;
    }

    @Override
    public int batchUpdateShelf(BatchUpdateShelfDTO dto) {
        UserDTO currentUser=getCurrentUserInfo();
        // 构造更新条件
        UpdateWrapper<WmSttInGoods> updateWrapper = new UpdateWrapper<>();
        // WHERE id IN (...)
        updateWrapper.in("id", dto.getIds());
        // 要更新的字段值
        WmSttInGoods entity = new WmSttInGoods();
        entity.setSttSta("已上架");
        entity.setUpdateName(currentUser.getRealname());
        entity.setUpdateBy(currentUser.getUsername());
        entity.setUpdateDate(LocalDateTime.now());
        entity.setSysCompanyCode(currentUser.getCompanyCode());
        entity.setSysOrgCode(currentUser.getOrgCode());
        boolean success = this.update(entity, updateWrapper);
        return success ? dto.getIds().size() : 0;
    }
}

