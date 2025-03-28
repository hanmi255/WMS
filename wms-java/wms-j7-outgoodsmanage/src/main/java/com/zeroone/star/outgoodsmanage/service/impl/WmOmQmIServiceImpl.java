package com.zeroone.star.outgoodsmanage.service.impl;

import cn.hutool.core.util.StrUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.outgoodsmanage.entity.WmOmQmI;
import com.zeroone.star.outgoodsmanage.mapper.WmOmQmIMapper;
import com.zeroone.star.outgoodsmanage.service.IWmOmQmIService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.taskconfirm.OutboundTaskDTO;
import com.zeroone.star.project.dto.j7.taskconfirm.WaveGenDTO;
import com.zeroone.star.project.query.j7.taskconfirm.OutboundTaskQuery;
import lombok.SneakyThrows;
import org.mapstruct.Mapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;


/**
 * <p>
 * 出库任务 服务实现类
 * </p>
 *
 * @author Longlive
 * @since 2025-02-21
 */
@Service
public class WmOmQmIServiceImpl extends ServiceImpl<WmOmQmIMapper, WmOmQmI> implements IWmOmQmIService {
    @Autowired
    WmOmQmIMapper wmOmQmIMapper;
    @Autowired
    EasyExcelComponent easyExcelComponent;
    @Autowired
    MsOutboundTaskMapper msOutboundTaskMapper;

    @Autowired
    UserHolder userHolder;
    /**
     * 描述:这里没有插入用户信息和更新信息,用户信息需要验证,时间的插入可以用切面注解
     *
     * @param ids
     */
    @Override
    @SneakyThrows
    public void genWave(WaveGenDTO ids) {
        //通过当前时间生成波次ID
        String waveId;
        LocalDateTime now = LocalDateTime.now();
        DateTimeFormatter formater = DateTimeFormatter.ofPattern("yyyyMMddHHmmss");
        DateTimeFormatter formater1=DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
        String format = now.format(formater);
        String updateTime=now.format(formater1);
        waveId = "BC" + format;
        //获取id集合
        String[] split = ids.getIds().split(",");
        List<String> list = new ArrayList<>();
        for (String s : split) {
            list.add(s);
        }
        //获取当前用户
        UserDTO currentUser = userHolder.getCurrentUser();
        if(null!=currentUser) {
            String username = currentUser.getUsername();
//        String username="caiwu001";
            String realname = wmOmQmIMapper.getRealName(username);
            wmOmQmIMapper.waveGen(list, waveId,realname,username,updateTime);
        }
    }

    @Override
    public void delMission(WaveGenDTO ids) {
        //获取id集合
        String[] split = ids.getIds().split(",");
        List<String> list = new ArrayList<>();
        for (String s : split) {
            list.add(s);
        }
        wmOmQmIMapper.delMission(list);

    }

    @Override
    public List<WmOmQmI> getData() {
        List<WmOmQmI> wmOmQmIS = wmOmQmIMapper.expoAll();
        return wmOmQmIS;

    }
    /**
     * 分页+条件查询
     * @param outboundTaskQuery 查询条件
     * @return PageDTO<OutboundTaskDTO> 查询结果
     */
    @Override
    public PageDTO<OutboundTaskDTO> queryAll(OutboundTaskQuery outboundTaskQuery) {
        //获取分页对象
        Page<WmOmQmI> page =
                new Page<>(outboundTaskQuery.getPageIndex(), outboundTaskQuery.getPageSize());

        //查询条件
        QueryWrapper<WmOmQmI> wrapper = new QueryWrapper<>();
        if(StrUtil.isNotBlank(outboundTaskQuery.getOmNoticeId())){
            wrapper.like("om_notice_id",outboundTaskQuery.getOmNoticeId());
        }
        if(StrUtil.isNotBlank(outboundTaskQuery.getGoodsId())){
            wrapper.like("goods_id",outboundTaskQuery.getGoodsId());
        }
        if(StrUtil.isNotBlank(outboundTaskQuery.getGoodsName())){
            wrapper.like("goods_name", outboundTaskQuery.getGoodsName());
        }
        if(StrUtil.isNotBlank(outboundTaskQuery.getImCusCode())){
            wrapper.like("i_cus_code", outboundTaskQuery.getImCusCode());
        }
        if(StrUtil.isNotBlank(outboundTaskQuery.getOmBeiZhu())){
            wrapper.like("om_bei_zhu", outboundTaskQuery.getOmBeiZhu());
        }
        if(StrUtil.isNotBlank(outboundTaskQuery.getTinId())){
            wrapper.like("tin_id", outboundTaskQuery.getTinId());
        }
        if(StrUtil.isNotBlank(outboundTaskQuery.getBinId())){
            wrapper.like("bin_id", outboundTaskQuery.getBinId());
        }
        if(StrUtil.isNotBlank(outboundTaskQuery.getCusCode())){
            wrapper.like("cus_code", outboundTaskQuery.getCusCode());
        }
        if(StrUtil.isNotBlank(outboundTaskQuery.getAssignTo())){
            wrapper.like("assign_to", outboundTaskQuery.getAssignTo());
        }
        if(StrUtil.isNotBlank(outboundTaskQuery.getWaveId())){
            wrapper.like("wave_id", outboundTaskQuery.getWaveId());
        }
        //执行查询
        Page<WmOmQmI> wmOmQmIPage = baseMapper.selectPage(page, wrapper);
        //将查询结果转换为DTO
        return PageDTO.create(wmOmQmIPage, msOutboundTaskMapper::WmOmQmIToOutboundTaskDTO);
    }
}

/**
 * <p>
 *  描述：转换 任务确认Entity -> 任务确认DTO
 * </p>
 *
 * @author keyuan
 * @since 2025-02-28
 */
@Mapper(componentModel = "spring")
interface MsOutboundTaskMapper {

    /**
     * 将WmOmQmI转换为OutboundTaskDTO
     * @param outboundTask 源对象
     * @return 转换后的对象
     */
    OutboundTaskDTO WmOmQmIToOutboundTaskDTO(WmOmQmI outboundTask);
}