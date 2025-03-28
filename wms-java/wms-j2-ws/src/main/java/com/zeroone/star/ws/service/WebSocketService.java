package com.zeroone.star.ws.service;

import org.springframework.stereotype.Service;

/**
 * @Author: dashuai
 * @Description: websocket服务层
 */
public interface WebSocketService {

    public void sendLoginMessage(String clientId);

    public void sendAnnouncementMessage(String content) ;

    public void sendMessageNotice(String clientId, String content);

    public void sendLogoutMessage(String clientId);
}
