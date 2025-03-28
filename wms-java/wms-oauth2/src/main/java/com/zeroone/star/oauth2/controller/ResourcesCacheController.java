package com.zeroone.star.oauth2.controller;

import com.zeroone.star.oauth2.service.impl.oauth2.ResourcesServiceImpl;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;

/**
 * <p>
 * 描述：资源缓存操作接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author 阿伟学长
 * @version 1.0.0
 */
@RequestMapping("/open/resources/cache")
@RestController
public class ResourcesCacheController {
    @Resource
    ResourcesServiceImpl resourcesService;

    @PutMapping("reload")
    public JsonVO<String> reloadCache() {
        resourcesService.loadData(true);
        return JsonVO.success("重新加载完成");
    }
}
