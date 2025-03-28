package com.zeroone.star.notice.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.notice.entity.Notice;
import com.zeroone.star.notice.entity.NoticeAuthorityUser;
import com.zeroone.star.notice.entity.NoticeReadUser;
import com.zeroone.star.notice.mapper.NoticeMapper;
import com.zeroone.star.notice.service.INoticeAuthorityUserService;
import com.zeroone.star.notice.service.INoticeReadUserService;
import com.zeroone.star.notice.service.INoticeService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j2.notice.NoticeContentDTO;
import com.zeroone.star.project.dto.j2.notice.NoticeDetailDTO;
import com.zeroone.star.project.dto.j2.notice.NoticeTitleDTO;
import com.zeroone.star.project.query.PageQuery;
import com.zeroone.star.project.vo.j2.notice.NoticeDetailVO;
import org.springframework.beans.BeanUtils;
import com.zeroone.star.project.dto.j2.notice.NoticeListDTO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import javax.annotation.Resource;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.LocalTime;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 公告 服务实现类
 * </p>
 *
 * @author 恒
 */
@Service
public class NoticeServiceImpl extends ServiceImpl<NoticeMapper, Notice> implements INoticeService {
    @Autowired
    private NoticeMapper noticeMapper;

    @Resource
    private INoticeAuthorityUserService noticeAuthorityUserService;

    @Autowired
    private INoticeReadUserService noticeReadUserService;

    /**
     * 获取消息标题列表(今天的10条)
     * @return 消息的标题列表
     * @author lessismore
     * @date 2025/2/26
     */
    @Override
    public PageDTO<NoticeTitleDTO> listNoticeTitle(PageQuery pageQuery) {
        // 分页查询
        // 1 创建分页对象，指定当前页和每页大小
        Page<Notice> page = new Page<>(pageQuery.getPageIndex(), pageQuery.getPageSize());
        // 2 构造分页查询条件
        // 2.1 获取今天的开始时间和结束时间
        LocalDateTime startOfDay = LocalDate.now().atStartOfDay(); // 今天的 00:00:00
        LocalDateTime endOfDay = LocalDateTime.of(LocalDate.now(), LocalTime.MAX); // 今天的 23:59:59.999
        // 2.2 查询条件1：当天的消息
        QueryWrapper<Notice> queryWrapper = new QueryWrapper<>();
        queryWrapper.ge("create_time", startOfDay); // create_time >= 今天的开始时间
        queryWrapper.le("create_time", endOfDay);   // create_time <= 今天的结束时间
        // 2.3 查询条件2：消息类型为1（通知）
        queryWrapper.eq("notice_type",1);
        // 2.4 查询条件3：只显示阅读期限大于当前时间的
        queryWrapper.ge("notice_term",LocalDateTime.now());

        // 3. 查询
        IPage<Notice> result = noticeMapper.selectPage(page, queryWrapper);

        // 4. 将查询结果中的Notice转化为NoticeContentDTO,用于返回给前端
        List<NoticeTitleDTO> pageList=page.getRecords().stream()
                .map(notice -> {
                    NoticeTitleDTO dto = new NoticeTitleDTO();
                    BeanUtils.copyProperties(notice, dto);
                    return dto;
                })
                .collect(Collectors.toList());

        // 手动创建新的 Page<NoticeDTO>
        Page<NoticeTitleDTO> dPage = new Page<>(pageQuery.getPageIndex(), pageQuery.getPageSize(), result.getTotal());
        dPage.setRecords(pageList);

        // PageDTO提供的create方法能够将page对象转化为PageDTO对象
        return PageDTO.create(dPage);
    }



    /**
     * 获取当日创建的所有消息，(分页查询，每页10条)
     * @return NoticeContentDTO 获取消息列表
     * @author lessismore
     * @date 2025/2/26
     */
    @Override
    public PageDTO<NoticeContentDTO> listNoticePage(PageQuery pageQuery) {
        // 分页查询
        // 1 创建分页对象，指定当前页和每页大小
        Page<Notice> page = new Page<>(pageQuery.getPageIndex(), pageQuery.getPageSize());
        // 2 构造分页查询条件
        // 2.1 获取今天的开始时间和结束时间
        LocalDateTime startOfDay = LocalDate.now().atStartOfDay(); // 今天的 00:00:00
        LocalDateTime endOfDay = LocalDateTime.of(LocalDate.now(), LocalTime.MAX); // 今天的 23:59:59.999
        // 2.2 查询条件1：当天的消息
        QueryWrapper<Notice> queryWrapper = new QueryWrapper<>();
        queryWrapper.ge("create_time", startOfDay); // create_time >= 今天的开始时间
        queryWrapper.le("create_time", endOfDay);   // create_time <= 今天的结束时间
        // 2.3 查询条件2：消息类型为1（通知）
        queryWrapper.eq("notice_type",1);
        // 2.4 查询条件3：只显示阅读期限大于当前时间的
        queryWrapper.ge("notice_term",LocalDateTime.now());

        // 3. 查询
        IPage<Notice> result = noticeMapper.selectPage(page, queryWrapper);

        // 4. 将查询结果中的Notice转化为NoticeContentDTO,用于返回给前端
        List<NoticeContentDTO> pageList=page.getRecords().stream()
                .map(notice -> {
                    NoticeContentDTO dto = new NoticeContentDTO();
                    BeanUtils.copyProperties(notice, dto);
                    return dto;
                })
                .collect(Collectors.toList());

        // 手动创建新的 Page<NoticeDTO>
        Page<NoticeContentDTO> dPage = new Page<>(pageQuery.getPageIndex(), pageQuery.getPageSize(), result.getTotal());
        dPage.setRecords(pageList);

        // PageDTO提供的create方法能够将page对象转化为PageDTO对象
        return PageDTO.create(dPage);
    }


    /**
     * 获取消息详情(根据id)查询消息
     * @param noticeId (消息的id)
     * @return NoticeDetailDTO 消息对象
     * @author lessismore
     * @date 2025/2/26
     */
    @Override
    public NoticeDetailDTO queryNoticeDetailsById(Integer noticeId) {
        // 根据id查询数据库
        Notice notice = query().eq("id", noticeId).one();
        // 未查询到目标通知
        if (notice == null) {
            return null;
        }
        // 使用NoticeDetailDTO接收返回给前端的数据
        return BeanUtil.copyProperties(notice, NoticeDetailDTO.class);
    }

    /**
     * 获取公告分页
     * @return Page
     * @author heng
     * @date 2025/2/27
     */
    @Override
    public Page getNoticePage(String userId,int currentPage,int pageSize) {
        //构造 用户权限查询器
        LambdaQueryWrapper<NoticeReadUser> lqw1=new LambdaQueryWrapper();
        lqw1.eq(NoticeReadUser::getUserId,userId).eq(NoticeReadUser::getDelFlag,0)
                .select(NoticeReadUser::getNoticeId);
        //根据查询条件获取 表(有公告id和用户id) 即以此获取----用户id可以查看的公告id列表
        List<NoticeReadUser> list = noticeReadUserService.list(lqw1);

        if (list.isEmpty()) return null;

        //得到 用户可以查看的公告id 列表
        List<String> noticeIds = new ArrayList<>();
        for (NoticeReadUser noticeReadUser : list) {
            noticeIds.add(noticeReadUser.getNoticeId());
        }
        //构建Notice的查询器
        LambdaQueryWrapper<Notice> lqw2=new LambdaQueryWrapper<>();
        //条件: 可以查看的和没过期的 公告列表
        lqw2.in(Notice::getId,noticeIds).eq(Notice::getNoticeType,"2")
                .ge(Notice::getNoticeTerm, new Date()); //未过期判断
        //创建分页
        Page<Notice> pageRequest=new Page<>(currentPage,pageSize);
        Page<Notice> noticePage = noticeMapper.selectPage(pageRequest, lqw2);

        //对分页的notice列表进行遍历
        List<NoticeListDTO> noticeListDTOList = noticePage.getRecords().stream()
                .map(notice -> {
                    LambdaQueryWrapper<NoticeReadUser> lqw3=new LambdaQueryWrapper<>();

                    NoticeListDTO noticeListDTO = new NoticeListDTO();
                    noticeListDTO.setNoticeTitle(notice.getNoticeTitle());
                    noticeListDTO.setNoticeContent(notice.getNoticeContent());
                    noticeListDTO.setNoticeTime(notice.getCreateTime());
                    noticeListDTO.setNoticeId(notice.getId());

                    lqw3.eq(NoticeReadUser::getNoticeId,notice.getId())
                            .eq(NoticeReadUser::getUserId,userId);

                    List<NoticeReadUser> list1 = noticeReadUserService.list(lqw3);
                    noticeListDTO.setIsRead(list1.get(0).getIsRead());

                    return noticeListDTO;
                }).collect(Collectors.toList());


        Page<NoticeListDTO> dtoPage=new Page<>(currentPage,pageSize,noticePage.getTotal());
        dtoPage.setRecords(noticeListDTOList);
        return dtoPage;
    }

    /**
     * 获取公告详情
     * @return NoticeDetailVO
     * @author heng
     * @date 2025/2/27
     */
    @Override
    public NoticeDetailVO queryNoticeById(String noticeId,String userId) {
        //查看用户是否能查看此公告
        LambdaQueryWrapper<NoticeReadUser> lqw=new LambdaQueryWrapper<>();
        lqw.eq(NoticeReadUser::getUserId,userId).eq(NoticeReadUser::getNoticeId,noticeId);
        List<NoticeReadUser> list = noticeReadUserService.list(lqw);
        if (list==null || list.isEmpty()){
            return null;
        }
        //查询公告详情
        LambdaQueryWrapper<Notice> lqw2=new LambdaQueryWrapper<>();
        lqw2.eq(Notice::getNoticeType,"2");
        List<Notice> notices = this.list(lqw2);
        if (notices==null || notices.isEmpty()) return null;
        //将公告信息封装到新VO中,并上传
        NoticeDetailVO noticeDetailVO = BeanUtil.toBean(notices.get(0), NoticeDetailVO.class);
        return noticeDetailVO;
    }


}
