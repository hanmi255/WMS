package com.zeroone.star.message.channel;

import org.springframework.cloud.stream.annotation.Input;
import org.springframework.messaging.SubscribableChannel;

/**
 * @Author: dashuai
 * @Description: 实时消息的通道
 */
public interface RealtimeMessageChannel {
    String REALTIME_MSG_INPUT = "realtime-msg-input";
    @Input(REALTIME_MSG_INPUT)
    SubscribableChannel realtimeMsgInput();
}
