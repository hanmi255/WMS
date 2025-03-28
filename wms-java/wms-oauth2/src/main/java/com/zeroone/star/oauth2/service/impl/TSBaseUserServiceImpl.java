package com.zeroone.star.oauth2.service.impl;

import com.zeroone.star.oauth2.entity.TSBaseUser;
import com.zeroone.star.oauth2.mapper.TSBaseUserMapper;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.oauth2.service.ITSBaseUserService;
import org.springframework.stereotype.Service;

/**
 * <p>
 * 系统用户 服务实现类
 * </p>
 *
 * @author nefertari
 * @since 2025-02-25
 */
@Service
public class TSBaseUserServiceImpl extends ServiceImpl<TSBaseUserMapper, TSBaseUser> implements ITSBaseUserService {

}
