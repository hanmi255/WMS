package com.zeroone.star.outgoodsmanage.channel;//package com.zeroone.star.outgoodsmanage.component;

import org.springframework.cloud.stream.annotation.Input;
import org.springframework.cloud.stream.messaging.Sink;
import org.springframework.messaging.SubscribableChannel;

public interface MySink extends Sink {
    //    注意属性名和注解要对上,这里message是topic的值,消费的topic与生产的topic要相同
    String EXCEL_INPUT = "taskexport";
    @Input(EXCEL_INPUT)
    SubscribableChannel input();
}
