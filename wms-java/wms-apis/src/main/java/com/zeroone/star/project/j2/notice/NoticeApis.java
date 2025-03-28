package com.zeroone.star.project.j2.notice;

import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.notice.NoticeContentDTO;
import com.zeroone.star.project.dto.j2.notice.NoticeDetailDTO;
import com.zeroone.star.project.dto.j2.notice.NoticeTitleDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.dto.j2.notice.*;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.notice.NoticeDetailVO;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestParam;

import java.util.List;

public interface NoticeApis {

    /**
     * 获取消息标题列表
     * @return 消息的标题列表（返回10条）
     * @author lessismore
     * @date 2025/2/26
     */
    public JsonVO<PageDTO<NoticeTitleDTO>> ListNoticeTitle(PageQuery pageQuery);

    /**
     * 获取"未读"公告标题列表
     * @return 公告标题列表  10条
     * @author heng
     */
    @ApiOperation(value = "获取未读公告标题列表")
    JsonVO<List<NoticeTitleDTO>> queryUnreadNotices();

    /**
     * 分页获取公告列表
     * @return 消息标题+消息时间+消息内容+是否阅读
     * @author heng
     */
    @ApiOperation(value = "分页获取公告列表")
    JsonVO<PageDTO<NoticeListDTO>> queryNoticePage(@RequestParam("currentPage")int currentPage,
                                                   @RequestParam("pageSize")int pageSize);
    /**
     * 根据公告id获取公告详情
     * @return 消息标题+消息时间+消息内容
     * @author heng
     */
    @ApiOperation(value = "根据id获取公告")
    JsonVO<NoticeDetailVO> queryNoticeById(@PathVariable("noticeId") String noticed);

    /**
     * 根据指定公告id
     * @return 成功或失败
     * @author heng
     */
    @ApiOperation(value = "修改公告状态")
    JsonVO<String> updateNoticeStatus(@RequestParam("userId") String userId);

    /**
     * 获取当日创建的所有消息，(分页查询，每页10条)
     * @return NoticeContentDTO 获取消息列表
     * @author lessismore
     * @date 2025/2/26
     */
    public JsonVO<PageDTO<NoticeContentDTO>> ListNoticePage(PageQuery pageQuery);


    /**
     * 获取消息详情(根据id)查询消息
     * @param noticeId (消息的id)
     * @return NoticeDetailDTO 消息对象
     * @author lessismore
     * @date 2025/2/23
     */
    public JsonVO<NoticeDetailDTO> queryNoticeDetailsById(@PathVariable("noticeId") Integer noticeId);
}
