package com.zeroone.star.notice.service;

import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.notice.entity.Notice;
import com.zeroone.star.notice.entity.NoticeReadUser;
import com.zeroone.star.project.dto.j2.notice.NoticeStatusUpdateDTO;
import com.zeroone.star.project.dto.j2.notice.NoticeTitleDTO;

import java.util.List;

/**
 * <p>
 * 公告 服务类
 * </p>
 *
 * @author 恒
 */
public interface INoticeReadUserService extends IService<NoticeReadUser> {

    /**
     * 获取未读 公告标题
     * @param userId
     * @return
     */
    List<NoticeTitleDTO> queryUnreadNoticeTitles(String userId);

    /**
     * 修改公告状态(标记已读/删除)
     * @param noticeId
     * @param userId
     * @return
     */
    List<NoticeReadUser> updateNoticeStatus(String noticeId, String userId);
}
