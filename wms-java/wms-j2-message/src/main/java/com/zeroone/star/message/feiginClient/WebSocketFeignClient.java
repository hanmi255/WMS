package com.zeroone.star.message.feiginClient;

import com.zeroone.star.project.dto.j2.message.WsRqMsgDto;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.stereotype.Component;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;

/**
 * @Author: dashuai
 * @Description: 声明式调用websocket服务的feign接口
 */
@Component
@FeignClient(
        name = "${ws.name}",
        url = "${ws.url}"
)
public interface WebSocketFeignClient {
    @PostMapping("/api/ws/push")
    JsonVO pushMessage(@RequestBody WsRqMsgDto wsRqMsgDto);
}
