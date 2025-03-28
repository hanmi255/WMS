package com.zeroone.star.message.controller;

import cn.hutool.core.bean.BeanUtil;
import com.zeroone.star.project.components.mail.MailComponent;
import com.zeroone.star.project.components.mail.MailMessage;
import com.zeroone.star.project.dto.mail.MailDTO;
import com.zeroone.star.project.j2.message.SendMailApis;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.mail.MailVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 * 发送邮件服务
 * </p>
 *
 * @author Maple
 */
@RestController
@RequestMapping("/message")
@Api(tags = "发送邮件服务")
public class SendMailController implements SendMailApis {

    @Resource
    private MailComponent mail;

    @PostMapping("/send-mail")
    @ApiOperation(value = "发送邮件信息")
    @Override
    public JsonVO<MailVO> sendMail(@RequestBody MailDTO mailDTO) {
        MailMessage mm = new MailMessage();
        BeanUtil.copyProperties(mailDTO,mm);
        MailMessage mailMessage = mail.sendMail(mm);
        MailVO mailVO = new MailVO();
        BeanUtil.copyProperties(mailMessage,mailVO);
        if ("ok".equals(mailMessage.getStatus())){
            return JsonVO.success(mailVO);
        }
        return JsonVO.fail(mailVO);
    }
}
