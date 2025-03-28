package com.zeroone.star.notice.service;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.notice.entity.Notice;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.notice.NoticeContentDTO;
import com.zeroone.star.project.dto.j2.notice.NoticeDetailDTO;
import com.zeroone.star.project.dto.j2.notice.NoticeTitleDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.vo.j2.notice.NoticeDetailVO;

/**
 * <p>
 * 公告 服务类
 * </p>
 *
 * @author 恒
 */
public interface INoticeService extends IService<Notice> {

    /**
     * 获取消息标题列表(今天的10条)
     * @return 消息的标题列表
     * @author lessismore
     * @date 2025/2/23
     */
    PageDTO<NoticeTitleDTO> listNoticeTitle(PageQuery pageQuery);

    /**
     * 获取当日创建的所有消息，(分页查询，每页10条)
     * @return NoticeContentDTO 获取消息列表
     * @author lessismore
     * @date 2025/2/23
     */
    PageDTO<NoticeContentDTO> listNoticePage(PageQuery pageQuery);

    /**
     * 获取消息详情(根据id)查询消息
     * @param noticeId (消息的id)
     * @return NoticeDetailDTO 消息对象
     * @author lessismore
     * @date 2025/2/26
     */
    NoticeDetailDTO queryNoticeDetailsById(Integer noticeId);



    /**
     * 获取未读公告标题列表
     * @param userId
     * @return
     */
    //List<NoticeTitleVO> getUnreadTitles(Long userId);

    /**
     * 分页获取公告详情
     * @param userId 用户id
     * @param currentPage 当前页
     * @param pageSize 页大小
     * @return
     */
    Page getNoticePage(String userId,int currentPage,int pageSize);

    /**
     * 根据id获取公告详情
     * @param noticeId 公告id
     * @param userId  用户id
     * @return
     */
    NoticeDetailVO queryNoticeById(String noticeId,String userId);
}
