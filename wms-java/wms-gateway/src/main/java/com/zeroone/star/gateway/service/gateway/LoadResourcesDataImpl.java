package com.zeroone.star.gateway.service.gateway;

import cn.hutool.core.convert.Convert;
import com.zeroone.cloud.starter.gateway.service.LoadResourcesData;
import com.zeroone.star.project.constant.RedisConstant;
import org.springframework.data.redis.core.RedisTemplate;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 描述：加载资源数据接口实现，一般是从Redis缓存中获取资源数据
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@Service
public class LoadResourcesDataImpl implements LoadResourcesData {
    @Resource
    private RedisTemplate<String, Object> redisTemplate;

    @Override
    public List<String> loadRolesByUrlPath(String url) {
        Object obj = redisTemplate.opsForHash().get(RedisConstant.RESOURCE_ROLES_MAP, url);
        if (obj == null) {
            return null;
        }
        return Convert.toList(String.class, obj);
    }
}
