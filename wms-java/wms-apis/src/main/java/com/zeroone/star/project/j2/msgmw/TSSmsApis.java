package com.zeroone.star.project.j2.msgmw;


import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.msgmw.MessageDTO;
import com.zeroone.star.project.dto.j2.msgmw.MessageListDTO;
import com.zeroone.star.project.dto.j2.msgmw.MessageModifyDTO;
import com.zeroone.star.project.query.j2.msgmw.MessageQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.bind.annotation.RequestBody;

public interface TSSmsApis {
    /**
     * 获取消息列表（带条件分页）
     *
     * @param query 查询条件
     * @return 消息列表
     */

    JsonVO<PageDTO<MessageListDTO>> queryAll(@RequestBody MessageQuery query);
    /**
     * 根据id查询消息
     *
     * @param id 消息id
     * @return 消息数据传输对象
     */
    JsonVO<MessageDTO> queryById(String id);
    /**
     * 更新消息
     *
     * @param messageDTO 消息数据传输对象
     */

    JsonVO<String> updateMessage(@RequestBody MessageModifyDTO messageDTO);
}
