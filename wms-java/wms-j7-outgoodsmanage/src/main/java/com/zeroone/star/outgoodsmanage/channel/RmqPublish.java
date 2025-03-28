package com.zeroone.star.outgoodsmanage.channel;//package com.zeroone.star.outgoodsmanage.component;


import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.messaging.support.MessageBuilder;
import org.springframework.stereotype.Component;


/**
 * <p>
 * 描述：消息发布组件
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Component
@EnableBinding({MySource.class})
public class RmqPublish {


  private final MySource mySource;

    public RmqPublish(MySource mySource) {
        this.mySource = mySource;
    }


    public void publish(String message) {
        mySource.customOutput().send(MessageBuilder.withPayload(message).build());
    }
}
