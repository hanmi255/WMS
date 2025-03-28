package com.zeroone.star.ws.service.ServiceImpl;

import com.zeroone.star.ws.handler.WebSocketHandler;
import com.zeroone.star.ws.service.WebSocketService;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
 * @Author: dashuai
 * @Description: websocket服务实现类
 */
@Service
public class WebSocketServiceImpl implements WebSocketService {

    @Resource
    private WebSocketHandler webSocketHandler;
    /**
     * @description: 发送登录消息
     **/
    @Override
    public void sendLoginMessage(String clientId) {
        String message = "成功登录";
        webSocketHandler.sendToClient(clientId, message);
    }

    /**
     * @description: 发送公告消息
     **/
    @Override
    public void sendAnnouncementMessage(String content) {
        webSocketHandler.sendToAllClients(content);
    }

    /**
     * @description: 发送消息提醒
     **/
    @Override
    public void sendMessageNotice(String clientId, String content) {
        webSocketHandler.sendToClient(clientId, content);
    }

    /**
     * @description: 发送登出消息
     **/
    @Override
    public void sendLogoutMessage(String clientId) {
        String message = "成功登出";
        webSocketHandler.sendToClient(clientId, message);
    }
}
