package com.zeroone.star.msgmw.controller;

import com.zeroone.star.msgmw.service.ITSSmsService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.msgmw.MessageDTO;
import com.zeroone.star.project.dto.j2.msgmw.MessageListDTO;
import com.zeroone.star.project.dto.j2.msgmw.MessageModifyDTO;
import com.zeroone.star.project.j2.msgmw.TSSmsApis;
import com.zeroone.star.project.query.j2.msgmw.MessageQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.validation.constraints.NotNull;

/**
 * <p>
 * 消息中间件模块的消息中心实现
 * </p>
 *
 * @author Maple
 */
@RestController
@RequestMapping("/msgmw")
@Api(tags = "消息中间件模块的消息中心")
@Validated
public class TSSmsController implements TSSmsApis {

    @Resource
    private ITSSmsService itsSmsService;

    /**
     * 获取消息列表（带条件分页）
     *
     * @param query 查询条件
     * @return 消息列表
     */
    @GetMapping("/messages")
    @ApiOperation(value = "获取消息列表（带条件分页）")
    @Override
    public JsonVO<PageDTO<MessageListDTO>> queryAll(@RequestBody @Validated @NotNull MessageQuery query) {
        return JsonVO.success(itsSmsService.listMsg(query));
    }
    @GetMapping("/message/{id}")
    @ApiOperation(value = "获取单条消息")
    @Override
    public JsonVO<MessageDTO> queryById(@PathVariable String id) {
        return JsonVO.success(itsSmsService.getMsgById(id));
    }
    /**
     * 更新消息
     *
     * @param messageDTO 消息数据传输对象
     */
    @PutMapping("/messages/{id}")
    @ApiOperation(value = "修改消息")
    @Override
    public JsonVO<String> updateMessage(@RequestBody @NotNull MessageModifyDTO messageDTO) {
        int i = itsSmsService.updateMsg(messageDTO);
        if (i == 0){
            JsonVO.fail("修改消息失败");
        }
        return JsonVO.success("修改成功");
    }
}
