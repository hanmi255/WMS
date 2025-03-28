package com.zeroone.star.ws.controller;

import com.zeroone.star.project.constant.MessageTags;
import com.zeroone.star.project.dto.j2.message.WsRqMsgDto;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.ws.service.WebSocketService;
import lombok.extern.slf4j.Slf4j;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * @Author: dashuai
 * @Description: 提供websocket服务
 */
@RestController
@RequestMapping("/api/ws")
@Slf4j
public class WebSocketController {
    @Resource
    private WebSocketService webSocketService;

    @PostMapping("/push")
    public JsonVO pushMessage(@RequestBody WsRqMsgDto wsRqMsgDto) {
        try {
            switch (wsRqMsgDto.getMessageType()) {
                case MessageTags.LOGIN:
                    log.info("接收到登录消息: {}", wsRqMsgDto.toString());
                    webSocketService.sendLoginMessage(wsRqMsgDto.getTarget());
                    break;
                case MessageTags.ANNOUNCEMENT:
                    log.info("接收到公告消息: {}", wsRqMsgDto.toString());
                    webSocketService.sendAnnouncementMessage(wsRqMsgDto.getContent());
                    break;
                case MessageTags.MESSAGE_NOTICE:
                    log.info("接收到消息通知: {}", wsRqMsgDto.toString());
                    webSocketService.sendMessageNotice(wsRqMsgDto.getTarget(), wsRqMsgDto.getContent());
                    break;
                case MessageTags.LOGOUT:
                    log.info("接收到登出消息: {}", wsRqMsgDto.toString());
                    webSocketService.sendLogoutMessage(wsRqMsgDto.getTarget());
                    break;
                default:
                    return JsonVO.fail("未知消息类型");
            }
            return JsonVO.success("消息推送成功");
        } catch (Exception e) {
            return JsonVO.fail("推送失败: " + e.getMessage());
        }
    }
}
