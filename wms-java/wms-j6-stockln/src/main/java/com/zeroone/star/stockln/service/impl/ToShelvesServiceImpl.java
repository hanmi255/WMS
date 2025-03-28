package com.zeroone.star.stockln.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j6.stockln.InboundQmIDTO;
import com.zeroone.star.project.dto.j6.stockln.ModifyShelvesDTO;
import com.zeroone.star.project.dto.j6.stockln.ToShelvesDTO;
import com.zeroone.star.project.query.j6.stockln.ToShelvesQuery;
import com.zeroone.star.stockln.entity.ToShelves;
import com.zeroone.star.stockln.mapper.ToShelvesMapper;
import com.zeroone.star.stockln.service.IToShelvesService;
import org.mapstruct.Mapper;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.List;

@Mapper(componentModel = "spring")
interface MsItemMapper {
    InboundQmIDTO ToShelvesToInboundQmIDTO(ToShelves toShelves);
}

@Service
public class ToShelvesServiceImpl extends ServiceImpl<ToShelvesMapper, ToShelves> implements IToShelvesService {
    @Resource
    MsItemMapper itemMapper;
    @Resource
    ToShelvesMapper toShelvesMapper;


    @Override
    public PageDTO<InboundQmIDTO> listall(ToShelvesQuery toShelvesQuery) {
        // 分页对象
        Page<ToShelves> page = new Page<>(toShelvesQuery.getPageIndex(), toShelvesQuery.getPageSize());

        // 查询对象
        QueryWrapper<ToShelves> wrapper = new QueryWrapper<>();

        // 只在字段不为空时才添加查询条件
        if (toShelvesQuery.getImNoticeId() != null && !toShelvesQuery.getImNoticeId().isEmpty()) {
            wrapper.like("im_notice_id", toShelvesQuery.getImNoticeId());
        }
        if (toShelvesQuery.getCusCode() != null && !toShelvesQuery.getCusCode().isEmpty()) {
            wrapper.or().like("cus_code", toShelvesQuery.getCusCode());
        }
        if (toShelvesQuery.getGoodsId() != null && !toShelvesQuery.getGoodsId().isEmpty()) {
            wrapper.or().like("goods_id", toShelvesQuery.getGoodsId());
        }
        if (toShelvesQuery.getGoodsName() != null && !toShelvesQuery.getGoodsName().isEmpty()) {
            wrapper.or().like("goods_name", toShelvesQuery.getGoodsName());
        }
        if (toShelvesQuery.getTinId() != null && !toShelvesQuery.getTinId().isEmpty()) {
            wrapper.or().like("tin_id", toShelvesQuery.getTinId());
        }
        if (toShelvesQuery.getBinId() != null && !toShelvesQuery.getBinId().isEmpty()) {
            wrapper.or().like("bin_id", toShelvesQuery.getBinId());
        }
        if (toShelvesQuery.getCusName() != null && !toShelvesQuery.getCusName().isEmpty()) {
            wrapper.or().like("cus_name", toShelvesQuery.getCusName());
        }
        if (toShelvesQuery.getBinSta() != null && !toShelvesQuery.getBinSta().isEmpty()) {
            wrapper.or().like("bin_sta", toShelvesQuery.getBinSta());
        }

        // 如果没有任何查询条件，则直接查询所有记录
        if (wrapper.isEmptyOfWhere()) {
            return PageDTO.create(baseMapper.selectPage(page, new QueryWrapper<ToShelves>()), itemMapper::ToShelvesToInboundQmIDTO);
        }

        // 执行分页查询
        Page<ToShelves> ps = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(ps, itemMapper::ToShelvesToInboundQmIDTO);
    }

    //
//    @Override
//    public void insertItem(InboundQmIDTO dto) {
//        ToShelves mdItem = BeanUtil.copyProperties(dto, ToShelves.class);
//        //TODO 需要添加创造人，新建时间等属性
//        this.save(mdItem);
//    }
    @Override
    //   @Transactional
    public void insertItem(ToShelvesDTO dto) {
        // 将 DTO 对象转换为 ToShelves 实体类
        ToShelves toShelves = new ToShelves();

        // 2. 手动赋值（确保 DTO 和实体类字段匹配）
        toShelves.setImNoticeId(dto.getImNoticeId());
        toShelves.setGoodsId(dto.getGoodsId());
        toShelves.setCusCode(dto.getCusCode());
        toShelves.setBinId(dto.getBinId());
        toShelves.setImQuat(dto.getImQuat());
        toShelves.setProData(dto.getProData());
        toShelves.setGoodsBatch(dto.getGoodsBatch());
        toShelves.setRecDeg(dto.getRecDeg());
        toShelves.setItemText(dto.getItemText());
        toShelves.setTinId(dto.getTinId());
        toShelves.setBaseInGoodscount(dto.getBaseInGoodscount());

        // 3. 设置创建时间和更新时间
        LocalDateTime now = java.time.LocalDateTime.now();
        toShelves.setCreateDate(now);
        toShelves.setUpdateDate(now);
        System.out.println("创建的 toShelves 数据：" + toShelves);

        // 4. 保存到数据库
        this.save(toShelves);
    }


    @Override
    public boolean deleteById(String id) {
        int result = toShelvesMapper.deleteById(id);
        return result > 0;
    }

    @Override
    public InboundQmIDTO myGetById(String id) {
        ToShelves entity = this.getById(id);
        InboundQmIDTO productDTO = BeanUtil.copyProperties(entity, InboundQmIDTO.class);
        return productDTO;
    }

    @Override
    public boolean modifyShelvesInfo(ModifyShelvesDTO dto) {
        // 根据 id 查询记录
        ToShelves existingItem = toShelvesMapper.selectById(dto.getId());

        // 如果记录存在，则更新相关字段
        if (existingItem != null) {
            // 只更新用户可以修改的字段
            existingItem.setTinId(dto.getTinId());
            existingItem.setBinId(dto.getBinId());
            existingItem.setQmOkQuat(dto.getQmOkQuat());
            existingItem.setTinTj(dto.getTinTj());
            existingItem.setTinZhl(dto.getTinZhl());
            existingItem.setProData(dto.getProData());
            existingItem.setGoodsBatch(dto.getGoodsBatch());
            existingItem.setRecDeg(dto.getRecDeg());
            existingItem.setItemText(dto.getItemText());
            existingItem.setBaseInGoodscount(dto.getBaseInGoodscount());
            existingItem.setBaseOutGoodscount(dto.getBaseOutGoodscount());

            // 执行更新操作，使用主键 id 来更新记录
            return toShelvesMapper.updateById(existingItem) > 0; // 如果更新成功，返回 true
        } else {
            return false; // 如果没有找到记录，返回 false
        }
    }

    @Override
    public boolean batchModifyBin(List<String> ids, String binId) {
        // 使用 UpdateWrapper 构建批量更新条件
        UpdateWrapper<ToShelves> updateWrapper = new UpdateWrapper<>();
        updateWrapper.in("id", ids); // 设置需要更新的记录的 id 列表
        updateWrapper.set("bin_id", binId); // 设置新的储位值

        // 执行批量更新操作
        int rowsUpdated = toShelvesMapper.update(null, updateWrapper);

        // 如果更新的行数大于 0，说明更新成功
        return rowsUpdated > 0;
    }

//    /**
//     * 根据id查询待上架货物详细信息
//     * @param id
//     * @return
//     */
//    public ToShelves getInfo(String id){
//        return toShelvesMapper.selectById(id);
//    }
}
