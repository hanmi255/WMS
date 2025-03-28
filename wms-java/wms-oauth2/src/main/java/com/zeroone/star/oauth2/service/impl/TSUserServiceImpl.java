package com.zeroone.star.oauth2.service.impl;

import com.zeroone.star.oauth2.entity.TSUser;
import com.zeroone.star.oauth2.mapper.TSUserMapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.oauth2.service.ITSUserService;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 系统用户扩展 服务实现类
 * </p>
 *
 * @author nefertari
 * @since 2025-02-25
 */
@Service
public class TSUserServiceImpl extends ServiceImpl<TSUserMapper, TSUser> implements ITSUserService {

}
