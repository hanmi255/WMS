package com.zeroone.star.project.vo.j2.sysmgr;

import cn.hutool.json.JSONUtil;
import io.swagger.annotations.ApiModel;
import lombok.Data;
import lombok.Getter;
import lombok.Setter;
import lombok.ToString;
import org.springframework.beans.BeanUtils;

import java.util.Date;

/**
 * @Author: hjm
 * @Date: 2025/02/22/21:12
 * @Description:
 */
@ApiModel("公告显示对象")
@Getter
@Setter
@ToString
public class TSNoticeVO {
    /**
     * 通知标题
     */
    private String noticeTitle;

    /**
     * 通知公告内容
     */
    private String noticeContent;

    /**
     * 通知公告类型（1：通知，2:公告）
     */
    private String noticeType;


    /**
     * 通告授权级别（1:全员，2：角色，3：用户）
     */
    private String noticeLevel;


    /**
     * 阅读期限
     */
    private Date noticeTerm;



}
