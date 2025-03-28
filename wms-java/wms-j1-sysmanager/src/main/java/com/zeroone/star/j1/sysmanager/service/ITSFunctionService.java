package com.zeroone.star.j1.sysmanager.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.zeroone.star.j1.sysmanager.entity.TSFunction;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.sysmanager.menumanager.*;
import com.zeroone.star.project.vo.JsonVO;

import java.util.List;

/**
 * <p>
 * 菜单管理 服务类
 * </p>
 *
 * @author jd
 * @since 2025-02-25
 */
public interface ITSFunctionService extends IService<TSFunction> {

    /**
     * 编辑菜单
     * @param menuEditDTO 菜单更新数据
     * @return 响应数据结果
     */
    Integer update(MenuEditDTO menuEditDTO);


    /**
     * 删除菜单
     * @param id 菜单id
     * @return 响应数据结果
     */
    Integer remove(String id);

    /**
     * 查询菜单列表
     * @return 响应数据结果
     */
    List<MenuManagementBaseDTO> listChild(String id);

    /**
     * 录入菜单
     */
    JsonVO<String> addMenu(MenuCreateDTO menuCreateDTO) throws Exception;

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
}
