package com.zeroone.star.outgoodsmanage.channel;
import cn.hutool.json.JSONUtil;
import org.springframework.stereotype.Component;

import javax.websocket.*;
import javax.websocket.server.ServerEndpoint;
import java.io.IOException;
import java.util.concurrent.ConcurrentHashMap;

/**
 * @description websocket服务器,导出excel文件到dfs服务器,并给前端返回地址
 * @function 与前端建立websocket连接
 */
@Component
@ServerEndpoint("/exportExcel")
public class ChatServer {
    /**
     * 保存连接对象
     */
    private static final ConcurrentHashMap<String, Session> SESSION_POOL = new ConcurrentHashMap<>();

    @OnOpen
    public void onOpen(Session session) throws IOException {
        System.out.println("websocke连接建立");
        //判断客户端对象是否存在
        if (SESSION_POOL.containsKey(session.getQueryString())) {
            CloseReason reason = new CloseReason(CloseReason.CloseCodes.CANNOT_ACCEPT, "ID冲突，连接拒绝");
            session.getUserProperties().put("reason", reason);
            session.close();
            return;
        }
        //将客户端记录到Map中
        SESSION_POOL.put(session.getQueryString(), session);
        System.out.println("客户端（" + session.getQueryString() + "）：开启连接");
    }

    @OnMessage
    public String onMessage(String text, Session session) throws IOException {
        //解析消息 => ID::消息内容
        String[] msgArr = text.split("::", 2);
        //群发消息 ID=all表示群发
        if ("all".equalsIgnoreCase(msgArr[0])) {
            for (Session one : SESSION_POOL.values()) {
                //排除自己
                if (session == one) {
                    continue;
                }
                //发送消息
                one.getBasicRemote().sendText(msgArr[1]);
            }
        }
        //指定发送
        else {
            Session target = SESSION_POOL.get(msgArr[0]);
            if (target != null) {
                target.getBasicRemote().sendText(msgArr[1]);
            }
        }
        return session.getQueryString() + ":消息发送成功";
    }

    @OnClose
    public void onClose(Session session) {
        //处理拒绝连接session关闭对象
        Object obj = session.getUserProperties().get("reason");
        if (obj instanceof CloseReason) {
            CloseReason reason = (CloseReason) obj;
            if (reason.getCloseCode() == CloseReason.CloseCodes.CANNOT_ACCEPT) {
                System.out.println("拒绝客户端（" + session.getQueryString() + "）：关闭连接");
                return;
            }
        }
        //将session对象从map中移除
        SESSION_POOL.remove(session.getQueryString());
        System.out.println("客户端（" + session.getQueryString() + "）：关闭连接");
    }

    @OnError
    public void onError(Session session, Throwable throwable) {
        System.out.println("客户端（" + session.getQueryString() + "）错误信息：" + throwable.getMessage());
    }

    public void sendMessage(String id, Object message) {
        //群发消息 ID=all表示群发
        if ("all".equalsIgnoreCase(id)) {
            for (Session one : SESSION_POOL.values()) {
                //发送消息
                try {
                    one.getBasicRemote().sendText(JSONUtil.toJsonStr(message));
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        //指定发送
        else {
            Session target = SESSION_POOL.get(id);
            if (target != null) {
                try {
                    target.getBasicRemote().sendText(JSONUtil.toJsonStr(message));
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
