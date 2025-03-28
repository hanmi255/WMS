package com.zeroone.star.project.j1.sysmanager.menumanage;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.sysmanager.menumanager.*;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiImplicitParams;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;

import java.util.List;
/**
 * <p>
 * 描述：菜单管理
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author j1-图团
 * @version 1.0.0
 */
public interface MenuManageApis {

    /**
     * 修改资源
     */
    JsonVO<String> modify(MenuEditDTO dto);

    /**
     * 删除资源
     */
    JsonVO<String> remove(String id);

    /**
     * 获取资源名称树
     */
    JsonVO<List<MenuManagementBaseDTO>> queryMenuList(String id);

    /**
     * 获取菜单名称树
     */
    JsonVO<List<MenuTreeDTO>> getMenuTree();

    /**
     * 获取菜单列表
     */
    JsonVO<List<MenuEntryDTO>> getMenuList(String menuId);

    /**
     * 获取菜单详细信息
     */
    JsonVO<MenuDetailDTO> getMenuDetail(String menuId);

    /**
     * 录入菜单
     */
    JsonVO<String> addMenu(@RequestBody MenuCreateDTO menuCreateDTO) throws Exception;
}