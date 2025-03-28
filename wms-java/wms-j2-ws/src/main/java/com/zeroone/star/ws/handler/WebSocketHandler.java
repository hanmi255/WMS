package com.zeroone.star.ws.handler;

import lombok.extern.slf4j.Slf4j;
import org.springframework.stereotype.Component;
import org.springframework.web.socket.CloseStatus;
import org.springframework.web.socket.TextMessage;
import org.springframework.web.socket.WebSocketSession;
import org.springframework.web.socket.handler.TextWebSocketHandler;

import java.io.IOException;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

@Component
@Slf4j
public class WebSocketHandler extends TextWebSocketHandler {
    private static final Map<String, WebSocketSession> clients = new ConcurrentHashMap<>();

    /**
     * @description: 刚开始建立连接时，将sessionId和session对象存入map中
     **/
    @Override
    public void afterConnectionEstablished(WebSocketSession session) {
        String clientId = session.getId();
        clients.put(clientId, session);
    }

    /**
     * @description: 关闭连接时，从map中移除sessionId和session对象
     **/
    @Override
    public void afterConnectionClosed(WebSocketSession session, CloseStatus status) {
        clients.remove(session.getId());
    }

    // 发送消息到指定客户端
    public void sendToClient(String clientId, String message) {
        WebSocketSession session = clients.get(clientId);
        if (session != null && session.isOpen()) {
            try {
                session.sendMessage(new TextMessage(message));
            } catch (IOException e) {
                log.error("消息发送失败，客户端ID: {}", clientId, e);
            }
        }
    }

    // 发送消息到所有客户端
    public void sendToAllClients(String message) {
        for (WebSocketSession session : clients.values()) {
            if (session.isOpen()) {
                try {
                    session.sendMessage(new TextMessage(message));
                } catch (IOException e) {
                    log.error("消息发送失败，客户端ID: {}", session.getId(), e);
                }
            }
        }
    }
}