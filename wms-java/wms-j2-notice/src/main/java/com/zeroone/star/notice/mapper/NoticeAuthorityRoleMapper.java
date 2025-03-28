package com.zeroone.star.notice.mapper;

import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import com.zeroone.star.notice.entity.Notice;
import com.zeroone.star.notice.entity.NoticeAuthorityRole;
import org.apache.ibatis.annotations.Mapper;

/**
 * <p>
 * 公告 授权角色  接口
 * </p>
 *
 * @author 恒
 */
@Mapper
public interface NoticeAuthorityRoleMapper extends BaseMapper<NoticeAuthorityRole> {
}
