package com.zeroone.star.outgoodsmanage.channel;//package com.zeroone.star.outgoodsmanage.component;

import org.springframework.cloud.stream.annotation.Output;
import org.springframework.cloud.stream.messaging.Source;
import org.springframework.context.annotation.Bean;
import org.springframework.messaging.MessageChannel;


public interface MySource extends Source {
//    注意属性名和注解要对上,这里message是topic的值
    String EXCEL_OUTPUT = "taskexport";
    @Output(EXCEL_OUTPUT)
    MessageChannel customOutput();
}
