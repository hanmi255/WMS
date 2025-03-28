package com.zeroone.star.message.listener;

import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONException;
import com.alibaba.fastjson.JSONObject;
import com.zeroone.star.message.channel.RealtimeMessageChannel;
import com.zeroone.star.message.feiginClient.WebSocketFeignClient;
import com.zeroone.star.project.dto.j2.message.WsRqMsgDto;
import com.zeroone.star.project.vo.JsonVO;
import lombok.extern.slf4j.Slf4j;
import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.cloud.stream.annotation.StreamListener;
import org.springframework.stereotype.Component;

import javax.annotation.PostConstruct;
import javax.annotation.Resource;

/**
 * @Author: dashuai
 * @Description: 监听mq中实时消息的监听者
 */
@Component
@Slf4j
@EnableBinding(RealtimeMessageChannel.class)
public class RealtimeMessageListener {
    @Resource
    private WebSocketFeignClient wsFeignClient;

    @PostConstruct
    public void init() {
        log.info("消费者已订阅 Topic: {}", RealtimeMessageChannel.REALTIME_MSG_INPUT);
    }

    @StreamListener(RealtimeMessageChannel.REALTIME_MSG_INPUT)
    public void handlerMessage(String message) {
        JSONObject jsonObject = null;
        try {
            jsonObject = JSON.parseObject(message);
        } catch (JSONException e) {
            log.error("消息格式错误，请检查消息格式是否正确", e);
        }
        //获取类型
        String type = jsonObject.getString("messageType");
        //获取目标用户
        String targetUser = jsonObject.getString("target");
        //获取消息内容
        String content = jsonObject.getString("content");

        // 构建 Feign 请求
        WsRqMsgDto request = new WsRqMsgDto();
        request.setTarget(targetUser);
        request.setMessageType(type);
        request.setContent(content);

        log.info("接收来自rocketmq的消息：{}", message);

        // 调用方法发送请求
        JsonVO response = wsFeignClient.pushMessage(request);
        log.info("调用消息服务返回结果：{}", response);
    }
}
