package com.zeroone.star.notice.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.notice.entity.NoticeReadUser;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 公告 已读用户 接口
 * </p>
 *
 * @author 恒
 */
@Mapper
public interface NoticeReadUserMapper extends BaseMapper<NoticeReadUser> {
}
