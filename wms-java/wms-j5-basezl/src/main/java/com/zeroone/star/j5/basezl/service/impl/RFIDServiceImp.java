package com.zeroone.star.j5.basezl.service.impl;

import cn.hutool.core.bean.BeanUtil;
import cn.hutool.core.util.StrUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.toolkit.support.SFunction;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.j5.basezl.entity.rfid.RfidBuseDO;
import com.zeroone.star.j5.basezl.entity.rfid.RfidBuseExcelDO;
import com.zeroone.star.j5.basezl.mapper.RFIDMapper;
import com.zeroone.star.j5.basezl.service.RFIDService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.basezl.rfid.RFIDAddDTO;
import com.zeroone.star.project.dto.j5.basezl.rfid.RFIDDetailDTO;
import com.zeroone.star.project.dto.j5.basezl.rfid.RFIDListDTO;
import com.zeroone.star.project.dto.j5.basezl.rfid.RFIDModifyDTO;
import com.zeroone.star.project.query.j5.basezl.rfid.RFIDQuery;
import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

import static cn.hutool.core.collection.ListUtil.page;

/**
 * @author meiqin liu(叶子）
 * @date 2025/2/27 15:07
 */
@Slf4j
@Service("rfidService")
public class RFIDServiceImp extends ServiceImpl<RFIDMapper, RfidBuseDO> implements RFIDService{

    @Resource
    private RFIDMapper rfidmapper;
    @Override
    public PageDTO<RFIDListDTO> queryRFIDAll(RFIDQuery rfidQuery) {
        LambdaQueryWrapper<RfidBuseDO> queryWrapper = new LambdaQueryWrapper<>();
        // 动态构建查询条件
        addEqualIfPresent(queryWrapper, RfidBuseDO::getRfidType, rfidQuery.getType());
        addEqualIfPresent(queryWrapper, RfidBuseDO::getRfidBuseno, rfidQuery.getBuseCode());
        addEqualIfPresent(queryWrapper, RfidBuseDO::getRfidBusecont, rfidQuery.getBuseContent());
        addEqualIfPresent(queryWrapper, RfidBuseDO::getRfidId1, rfidQuery.getRfid1());

        //构建分页对象
//        if (rfidQuery == null) {
//            throw new IllegalArgumentException("Query object cannot be null");
//        }

        Page<RfidBuseDO> page = new Page<>(rfidQuery.getPageIndex(), rfidQuery.getPageSize());

//        if (queryWrapper == null) {
//            throw new IllegalArgumentException("QueryWrapper cannot be null");
//        }

        //进行分页查询
        page(page, queryWrapper);
        return PageDTO.create(page, RFIDListDTO.class);
    }

     private <T> void addEqualIfPresent(LambdaQueryWrapper<T> wrapper, SFunction<T, ?> column, String value) {
        if (StrUtil.isNotBlank(value)) {
            wrapper.eq(column, value);
        }
    }


    @Override
    public RFIDDetailDTO queryRFIDDetail(String rfid) {
        LambdaQueryWrapper<RfidBuseDO> queryWrapper = new LambdaQueryWrapper<>();
        if(StrUtil.isBlank(rfid))
        {
            throw new IllegalArgumentException("查询对象不能为空");
        }
        queryWrapper.eq(RfidBuseDO::getRfidBuseno,rfid);
        return BeanUtil.copyProperties(baseMapper.selectOne(queryWrapper),RFIDDetailDTO.class);
    }

    @Override
    public String addRfid(RFIDAddDTO rfidAddDTO) {
//        String rfidBuseno = rfidAddDTO.getRfidBuseno();
//        if (StrUtil.isBlank(rfidBuseno)) {
//            throw new IllegalArgumentException("查询对象不能为空");
//        }
//        LambdaQueryWrapper<RfidBuseDO> queryWrapper = new LambdaQueryWrapper<>();
//        queryWrapper.eq(RfidBuseDO::getRfidBuseno, rfidBuseno);
//        if (baseMapper.selectOne(queryWrapper) != null) {
//            throw new IllegalArgumentException("对象已存在");
//        }
        RfidBuseDO rfidBuseDO = BeanUtil.copyProperties(rfidAddDTO, RfidBuseDO.class);
        if (baseMapper.insert(rfidBuseDO) > 0) {
            return "添加成功";
        }
        return "添加失败";
    }
        //在这里设置创建时间和修改时间的业务代码
//        Long id = 1L;
//        rfidmapper.insertRfid(id,rfidAddDTO);
//        return "ok";

    @Override
    public String modifyRfid(RFIDModifyDTO rfidModifyDTO) {
        if (rfidModifyDTO == null || StrUtil.isBlank(rfidModifyDTO.getRfidBuseno())) {
            throw new IllegalArgumentException("对象不存在");
        }

        // 创建查询条件
        LambdaQueryWrapper<RfidBuseDO> queryWrapper = new LambdaQueryWrapper<>();
        queryWrapper.eq(RfidBuseDO::getRfidBuseno, rfidModifyDTO.getRfidBuseno());

        // 复制属性到 RfidBuseDO 对象
        RfidBuseDO rfidBuseDO = BeanUtil.copyProperties(rfidModifyDTO, RfidBuseDO.class);

        // 执行更新操作
        if (baseMapper.update(rfidBuseDO, queryWrapper) > 0) {
            return "修改成功";
        }
        return "修改失败";
    }


    @Override
    public void deleteRfid(List<Long> rfidList) {
        for (Long id : rfidList) {
            rfidmapper.deleteByid(id);
        }

    }

    @Override
    public List<RfidBuseExcelDO> selectAll() {
        return rfidmapper.selectAll();
    }

    @Override
    public List<RfidBuseExcelDO> selectById(Long id) {
        return rfidmapper.selectByRfiId(id);
    }
}
