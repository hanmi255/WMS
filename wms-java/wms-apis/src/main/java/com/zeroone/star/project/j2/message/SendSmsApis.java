package com.zeroone.star.project.j2.message;

import com.zeroone.star.project.query.j2.message.SendMsgQuery;
import com.zeroone.star.project.vo.JsonVO;

public interface SendSmsApis {
    /**
     * 发送短信消息
     *
     * @param sendMsgQuery 发送短信相关参数
     * @return 短信发送结果
     */

    JsonVO<String> sendSms(SendMsgQuery sendMsgQuery);
}
