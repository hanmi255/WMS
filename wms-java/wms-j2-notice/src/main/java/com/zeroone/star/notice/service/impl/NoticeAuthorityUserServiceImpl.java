package com.zeroone.star.notice.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.notice.entity.NoticeAuthorityUser;
import com.zeroone.star.notice.mapper.NoticeAuthorityUserMapper;
import com.zeroone.star.notice.service.INoticeAuthorityUserService;
import org.springframework.stereotype.Service;

@Service
public class NoticeAuthorityUserServiceImpl extends ServiceImpl<NoticeAuthorityUserMapper, NoticeAuthorityUser> implements INoticeAuthorityUserService {
}
