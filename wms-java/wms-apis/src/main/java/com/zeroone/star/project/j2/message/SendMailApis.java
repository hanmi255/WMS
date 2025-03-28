package com.zeroone.star.project.j2.message;

import com.zeroone.star.project.dto.mail.MailDTO;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.mail.MailVO;

public interface SendMailApis {
    /**
     * 发送邮件
     *
     * @param mailDTO 邮件内容
     * @return 发送结果
     */
    JsonVO<MailVO> sendMail(MailDTO mailDTO);
}
