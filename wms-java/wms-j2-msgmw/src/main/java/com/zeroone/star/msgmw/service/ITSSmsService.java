package com.zeroone.star.msgmw.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.msgmw.entity.TSSms;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.msgmw.MessageDTO;
import com.zeroone.star.project.dto.j2.msgmw.MessageListDTO;
import com.zeroone.star.project.dto.j2.msgmw.MessageModifyDTO;
import com.zeroone.star.project.query.j2.msgmw.MessageQuery;

/**
 * @author Henry
 */
public interface ITSSmsService extends IService<TSSms> {
    PageDTO<MessageListDTO> listMsg(MessageQuery query);

    MessageDTO getMsgById(String id);

    int updateMsg(MessageModifyDTO messageDTO);
}
