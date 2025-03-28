package com.zeroone.star.msgmw.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.msgmw.entity.TSSms;
import com.zeroone.star.msgmw.mapper.TSSmsMapper;
import com.zeroone.star.msgmw.service.ITSSmsService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.msgmw.MessageDTO;
import com.zeroone.star.project.dto.j2.msgmw.MessageListDTO;
import com.zeroone.star.project.dto.j2.msgmw.MessageModifyDTO;
import com.zeroone.star.project.query.j2.msgmw.MessageQuery;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Service;

/**
 * @author Henry
 */
@Service
@RequiredArgsConstructor
public class TSSmsServiceImpl extends ServiceImpl<TSSmsMapper, TSSms> implements ITSSmsService {

    private final TSSmsMapper mapper;

    @Override
    public PageDTO<MessageListDTO> listMsg(MessageQuery query) {
        LambdaQueryWrapper<TSSms> lambda = new LambdaQueryWrapper<>();
        lambda.eq(TSSms::getEsType,query.getEsType())
                .eq(TSSms::getEsStatus,query.getEsStatus())
                .like(TSSms::getEsTitle,query.getEsTitle());
        Page<TSSms> page = new Page<>(query.getPageIndex(),query.getPageSize());
        Page<TSSms> tsSmsPage = mapper.selectPage(page, lambda);
        return PageDTO.create(tsSmsPage,MessageListDTO.class);
    }

    @Override
    public MessageDTO getMsgById(String id) {
        TSSms tsSms = mapper.selectById(id);
        MessageDTO messageDTO = new MessageDTO();
        BeanUtil.copyProperties(tsSms,messageDTO);
        return messageDTO;
    }

    @Override
    public int updateMsg(MessageModifyDTO messageDTO) {
        TSSms tsSms = new TSSms();
        BeanUtil.copyProperties(messageDTO,tsSms);
        return  mapper.updateById(tsSms);
    }
}
