package com.zeroone.star.notice.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.notice.entity.Notice;
import com.zeroone.star.notice.entity.NoticeReadUser;
import com.zeroone.star.notice.mapper.NoticeReadUserMapper;
import com.zeroone.star.notice.service.INoticeReadUserService;
import com.zeroone.star.notice.service.INoticeService;
import com.zeroone.star.project.dto.j2.notice.NoticeTitleDTO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 公告 服务类
 * </p>
 *
 * @author 恒
 */
@Service
public class NoticeReadUserServiceImpl extends ServiceImpl<NoticeReadUserMapper, NoticeReadUser> implements INoticeReadUserService {

    @Autowired
    private INoticeService noticeService;

    /**
     * 获取未读公告标题
     * @return NoticeTitleDTO
     * @author heng
     * @date 2025/2/27
     */
    @Override
    public List<NoticeTitleDTO> queryUnreadNoticeTitles(String userId) {
        LambdaQueryWrapper<NoticeReadUser> lqw=new LambdaQueryWrapper();
        //根据用户id,和是否阅读,2个条件去查询,公告id即 noticeId
        lqw.eq(NoticeReadUser::getUserId,userId)
            .eq(NoticeReadUser::getIsRead,0); //未读的公告
        //得到的公告id列表
        List<NoticeReadUser> noticeReadUsers = this.list(lqw);

        if (noticeReadUsers==null || noticeReadUsers.isEmpty()) return null;

        //获得未读的notice编号 列表
        List<String> NoticeIds = noticeReadUsers.stream().map(NoticeReadUser::getNoticeId).
                collect(Collectors.toList());
        //根据确定的公告编号,查询符合要求的公告
        LambdaQueryWrapper<Notice> lqw2=new LambdaQueryWrapper<>();
        lqw2.in(Notice::getId,NoticeIds).eq(Notice::getNoticeType,"2");
        //获得相应的公告详情
        List<Notice> notices = noticeService.list(lqw2);

        //使用stream流将notice列表,封装到NoticeDetailVO返回给前端
        List<NoticeTitleDTO> noticeTitleDTOList = notices.stream().map(
                notice -> {
                    NoticeTitleDTO noticeTitleDTO = new NoticeTitleDTO();
                    noticeTitleDTO.setNoticeTitle(notice.getNoticeTitle());
                    noticeTitleDTO.setNoticeId(notice.getId());
                    return noticeTitleDTO;
                }
        ).collect(Collectors.toList());

        return noticeTitleDTOList;
    }

    /**
     * 修改公告状态
     * @return NoticeTitleDTO
     * @author heng
     * @date 2025/2/27
     */
    @Override
    public List<NoticeReadUser> updateNoticeStatus(String noticeId, String userId) {
        LambdaQueryWrapper<NoticeReadUser> lqw=new LambdaQueryWrapper<>();
        //根据公告id和用户id搜索出唯一的对象
        lqw.eq(NoticeReadUser::getUserId,userId).eq(NoticeReadUser::getNoticeId,noticeId);
        List<NoticeReadUser> list = this.list(lqw);
        return list;
    }
}
