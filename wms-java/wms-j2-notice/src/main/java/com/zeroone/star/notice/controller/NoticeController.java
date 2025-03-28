package com.zeroone.star.notice.controller;

import com.zeroone.star.notice.service.INoticeReadUserService;
import com.zeroone.star.notice.service.INoticeService;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.zeroone.star.notice.entity.NoticeReadUser;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.notice.*;
import com.zeroone.star.project.j2.notice.NoticeApis;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j2.notice.NoticeDetailVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@RestController
@RequestMapping("/notice")
@Api(tags = "消息通知")
public class NoticeController implements NoticeApis {

    @Autowired
    private INoticeService noticeService;

    @Autowired
    private UserHolder userHolder;

    @Autowired
    private INoticeReadUserService noticeReadUserService;

    /**
     * 获取消息标题列表(今天的10条)
     * @return 消息的标题列表
     * @author lessismore
     * @date 2025/2/23
     */
    @PostMapping("/list-notice-title")
    @ApiOperation(value = "获取消息标题列表")
    public JsonVO<PageDTO<NoticeTitleDTO>> ListNoticeTitle(@RequestBody PageQuery pageQuery) {
        PageDTO<NoticeTitleDTO> pageDTO=noticeService.listNoticeTitle(pageQuery);
        return JsonVO.success(pageDTO);
    }

    /**
     * 获取当日创建的所有消息，(分页查询，每页10条)
     * @return NoticeContentDTO 获取消息列表
     * @author lessismore
     * @date 2025/2/23
     */
    @PostMapping("/list-notice-page")
    @ApiOperation(value = "获取消息列表(分页)")
    public JsonVO<PageDTO<NoticeContentDTO>> ListNoticePage(@RequestBody PageQuery pageQuery) {
        PageDTO<NoticeContentDTO> list=noticeService.listNoticePage(pageQuery);
        return JsonVO.success(list);
    }


    /**
     * 获取消息详情(根据id)查询消息
     * @param noticeId (消息的id)
     * @return NoticeDetailDTO 消息对象
     * @author lessismore
     * @date 2025/2/23
     */
    @GetMapping("query-notice-details-by-id/{noticeId}")
    @ApiOperation(value = "获取消息详情")
    public JsonVO<NoticeDetailDTO> queryNoticeDetailsById(@PathVariable("noticeId") Integer noticeId) {
        NoticeDetailDTO noticeDetailDTO=noticeService.queryNoticeDetailsById(noticeId);
        return JsonVO.success(noticeDetailDTO);
    }

    /**
     * 获取"未读"公告标题列表
     * @return 公告标题列表  10条
     * @author heng
     */
    @ApiOperation(value = "获取未读公告标题列表")
    @GetMapping("/query-Unread-notices")
    @Override
    public JsonVO<List<NoticeTitleDTO>> queryUnreadNotices(){
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            throw new RuntimeException("用户未登录");
        }

        List<NoticeTitleDTO> noticeTitleDTOList = noticeReadUserService.queryUnreadNoticeTitles(currentUser.getId());
        if (noticeTitleDTOList!=null) return JsonVO.success(noticeTitleDTOList);
        return JsonVO.fail(null);
    }

    /**
     * 分页获取公告列表
     * @return 消息标题+消息时间+消息内容+是否阅读+公告id
     * @author heng
     */
    @ApiOperation(value = "分页获取公告列表")
    @GetMapping("/list-notice-2-page")
    @Override
    public JsonVO<PageDTO<NoticeListDTO>> queryNoticePage(@RequestParam("currentPage")int currentPage,
                                                        @RequestParam("pageSize")int pageSize) {
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            throw new RuntimeException("用户未登录");
        }

        Page page = noticeService.getNoticePage(currentUser.getId(), currentPage, pageSize);
        PageDTO pageDTO = PageDTO.create(page);
        return JsonVO.success(pageDTO);
    }

    /**
     * 根据公告id获取公告详情
     * @return 消息标题+消息时间+消息内容
     * @author heng
     */
    @ApiOperation(value = "获取公告详情")
    @GetMapping("/query-notice-2-by-id/{noticeId}")
    @Override
    public JsonVO<NoticeDetailVO> queryNoticeById(@PathVariable("noticeId") String noticed) {
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            throw new RuntimeException("用户未登录");
        }
        List<String> roles = currentUser.getRoles();

        NoticeDetailVO noticeDetailVO = noticeService.queryNoticeById(noticed, currentUser.getId());
        return JsonVO.success(noticeDetailVO);
    }

    /**
     * 根据指定公告id
     * @return 成功或失败
     * @author heng
     */
    @ApiOperation(value = "修改公告状态")
    @PutMapping("/update-notice-status")
    @Override
    public JsonVO<String> updateNoticeStatus(@RequestParam("noticeId") String noticeId) {
        UserDTO currentUser = null;
        try {
            currentUser = userHolder.getCurrentUser();
        } catch (Exception e) {
            throw new RuntimeException("用户未登录");
        }
        List<NoticeReadUser> noticeReadUsers = noticeReadUserService.updateNoticeStatus(noticeId, currentUser.getId());
        if (noticeReadUsers!=null || !noticeReadUsers.isEmpty()){
            NoticeReadUser noticeReadUser = noticeReadUsers.get(0);
            //设置对象 对于公告 已阅读
            noticeReadUser.setIsRead(1);
            noticeReadUserService.updateById(noticeReadUser);
            return JsonVO.success("修改成功");
        }
        return  JsonVO.fail("修改失败");

    }


}
