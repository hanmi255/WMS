package com.zeroone.star.outgoodsmanage.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.outgoodsmanage.entity.WmToUnpublish;
import com.zeroone.star.outgoodsmanage.mapper.WmToUnpublishMapper;
import com.zeroone.star.outgoodsmanage.service.IWmToUnpublishService;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.downgoods.UnpublishDTO;
import com.zeroone.star.project.query.j7.downgoods.UnpublishQuery;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.time.LocalDateTime;
import java.util.List;

/**
 * <p>
 * 商品下架 服务实现类
 * </p>
 *
 * @author King
 * @since 2025-03-06
 */
@Service
public class WmToUnpublishServiceImpl extends ServiceImpl<WmToUnpublishMapper, WmToUnpublish> implements IWmToUnpublishService {

    private static final Logger log = LoggerFactory.getLogger(WmToUnpublishServiceImpl.class);

    @Override
    public PageDTO<UnpublishDTO> queryUnpublishList(UnpublishQuery query) {
        // 构建分页对象
        Page<UnpublishDTO> page = new Page<>(query.getPageIndex(), query.getPageSize());
        
        // 执行分页查询
        Page<UnpublishDTO> resultPage = baseMapper.selectUnpublishList(page, query);
        
        // 转换为PageDTO
        return PageDTO.create(resultPage);
    }

    @Override
    public UnpublishDTO getUnpublishById(String id) {
        // 参数校验
        if (id == null || id.isEmpty()) {
            return null;
        }
        
        // 查询详情
        return baseMapper.getUnpublishById(id);
    }

    @Override
    @Transactional(rollbackFor = Exception.class)
    public boolean modifyUnpublish(UnpublishDTO dto) {
        // 参数校验
        if (dto == null || dto.getId() == null || dto.getId().isEmpty()) {
            log.error("参数校验失败：id不能为空");
            return false;
        }
        
        log.info("开始修改下架信息：id={}", dto.getId());
        
        // 根据ID查询下架记录
        WmToUnpublish unpublish = getById(dto.getId());
        
        if (unpublish == null) {
            log.error("未找到对应的下架记录：id={}", dto.getId());
            return false;
        }
        
        try {
            // 更新下架信息
            unpublish.setUpdateDate(LocalDateTime.now());
            unpublish.setUpdateBy(dto.getUpdateBy());
            if (dto.getGoodsQua() != null) {
                unpublish.setGoodsQua(dto.getGoodsQua());
            }
            if (dto.getGoodsUnit() != null) {
                unpublish.setGoodsUnit(dto.getGoodsUnit());
            }
            if (dto.getBaseGoodscount() != null) {
                unpublish.setBaseGoodscount(dto.getBaseGoodscount());
            }
            if (dto.getBaseUnit() != null) {
                unpublish.setBaseUnit(dto.getBaseUnit());
            }
            if (dto.getOmBeiZhu() != null) {
                unpublish.setOmBeiZhu(dto.getOmBeiZhu());
            }
            
            // 保存更新
            boolean result = updateById(unpublish);
            log.info("修改下架信息{}：id={}", result ? "成功" : "失败", unpublish.getId());
            return result;
        } catch (Exception e) {
            log.error("修改下架信息异常：", e);
            throw e;
        }
    }
}
