package com.zeroone.star.outgoodsmanage.channel;//package com.zeroone.star.outgoodsmanage.component;

import com.zeroone.star.outgoodsmanage.entity.WmOmQmI;
import com.zeroone.star.outgoodsmanage.service.impl.WmOmQmIServiceImpl;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.vo.JsonVO;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.cloud.stream.annotation.EnableBinding;
import org.springframework.cloud.stream.annotation.StreamListener;
import org.springframework.cloud.stream.messaging.Sink;
import org.springframework.stereotype.Component;

import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.List;

@Slf4j
@Component
@EnableBinding({MySink.class})
public class RmqListen {
    @Autowired
    ChatServer chatServer;
    @Autowired
    WmOmQmIServiceImpl wmOmQmIService;
    @Autowired
    EasyExcelComponent easyExcelComponent;
    @Autowired
    FastDfsClientComponent dfs;
    @Value("${fastdfs.nginx-servers}")
    private String serverurl;
    /**
     * <描述>
     *  监听频道MySink的EXCEL_INPUT属性对应的主题,消费消息;
     *  将对应数据存储到FastDFS服务器,获得文件地址
     *  通过websocket与前端连接,将文件地址广播给所有连接对象
     * </描述>
     * @Author LongLive
     * @param message
     */

    @StreamListener(MySink.EXCEL_INPUT)
    public void listen(String message) throws Exception {
        log.info("接收到消息：{}", message);
        System.out.println("收到消息");
        //获取文件流
        List<WmOmQmI> data = wmOmQmIService.getData();
        ByteArrayOutputStream out =new ByteArrayOutputStream();
        easyExcelComponent.export("mission",out,WmOmQmI.class,data);
        //将文件发送到dfs服务器,回送文件url
        FastDfsFileInfo xlsx = dfs.uploadFile(out.toByteArray(), "xlsx");
        out.close();
        String url=dfs.fetchUrl(xlsx,serverurl,true);
        chatServer.sendMessage("all",url);
        System.out.println("文件路径已经返回");

    }
}
