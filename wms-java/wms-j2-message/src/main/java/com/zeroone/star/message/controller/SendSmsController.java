package com.zeroone.star.message.controller;

import com.zeroone.star.project.components.sms.aliyun.SmsComponent;
import com.zeroone.star.project.components.sms.aliyun.SmsResult;
import com.zeroone.star.project.j2.message.SendSmsApis;
import com.zeroone.star.project.query.j2.message.SendMsgQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.HashMap;

/**
 * <p>
 * 发送短信服务
 * </p>
 *
 * @author Maple
 */
@RestController
@RequestMapping("/message")
@Api(tags = "发送短信服务")
public class SendSmsController implements SendSmsApis {

    @Resource
    private SmsComponent sms;

    @PostMapping("/send-one-sms")
    @ApiOperation(value = "发送短信信息")
    @Override
    public JsonVO<String> sendSms(@RequestBody @Validated SendMsgQuery sendMsgQuery) {
        HashMap<String,String> params = new HashMap<>();
        params.put("message",sendMsgQuery.getMessage());
        SmsResult smsResult = sms.sendSms(sendMsgQuery.getPhone(), "阿里云测试短信", "SMS_154950909", params);
        String code = smsResult.getCode();
        if ("isv.AMOUNT_NOT_ENOUGH".equals(code)){
            return JsonVO.fail("账户余额不足");
        }
        else if (!"OK".equals(code)){
            return JsonVO.fail("发送短信失败，请稍后再试");
        }
        return JsonVO.success("发送短信成功");
    }
}
