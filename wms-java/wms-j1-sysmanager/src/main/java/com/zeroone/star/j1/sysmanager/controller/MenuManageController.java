package com.zeroone.star.j1.sysmanager.controller;

import com.zeroone.star.j1.sysmanager.service.impl.TSFunctionServiceImpl;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.sysmanager.menumanager.*;
import com.zeroone.star.project.j1.sysmanager.menumanage.MenuManageApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiImplicitParam;
import io.swagger.annotations.ApiImplicitParams;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 菜单管理控制器
 * </p>
 * @author j1-图团
 * @since 2025-02-21
 */
@RestController
@RequestMapping("/menu")
@Api(tags = "菜单管理")
@Validated
public class MenuManageController implements MenuManageApis {
    @Resource
    TSFunctionServiceImpl service;

    @ApiOperation(value = "修改资源")
    @PutMapping("/modify")
    @Override
    public JsonVO<String> modify(@RequestBody MenuEditDTO dto) {
        return JsonVO.success(String.valueOf(service.update(dto)));
    }

    @ApiOperation(value = "删除资源")
    @DeleteMapping("/remove/{id}")
    @Override
    public JsonVO<String> remove(@PathVariable(value = "id") String id) {
        //判断id是否为空
        if(id == null){
            return JsonVO.fail("id不能为空");
        }
        Integer result = service.remove(id);
        if(result == 0){
            return JsonVO.fail("没有该id对应的数据");
        }

        return JsonVO.success(String.valueOf(service.remove(id)));

    }

    @ApiOperation(value = "获取资源名称树")
    @GetMapping("/query-menu-list/{id}")
    @Override
    public JsonVO<List<MenuManagementBaseDTO>> queryMenuList(@PathVariable String id) {
        return JsonVO.success(service.listChild(id));
    }

    /**
     * 获取菜单名称树
     */
    @ApiOperation(value = "获取菜单名称树")
    @GetMapping ("query-menu-tree")
    @Override
    public JsonVO<List<MenuTreeDTO>> getMenuTree() {
        return service.getMenuTree();
    }

    /**
     * 获取菜单列表
     */
    @ApiOperation(value = "获取菜单列表")
    @GetMapping({"get-menu-list/{menuId}", "get-menu-list"})
    @Override
    public JsonVO<List<MenuEntryDTO>> getMenuList(@PathVariable(required = false) String menuId) {

        return service.getMenuList(menuId);
    }

    /**
     * 获取菜单详细信息
     */
    @GetMapping("menu/{menuId}")
    @ApiOperation(value = "获取菜单详细信息", notes = "根据菜单ID获取菜单的详细信息")
    @ApiImplicitParams({
            @ApiImplicitParam(name = "menuId", value = "菜单ID", required = true, dataType = "String", paramType = "path", example = "001")
    })
    @Override
    public JsonVO<MenuDetailDTO> getMenuDetail(@PathVariable String menuId) {
        return service.getMenuDetail(menuId);
    }

    /**
     * 录入菜单
     * @param menuCreateDTO 菜单数据
     * @return 录入结果
     */
    @ApiOperation(value = "录入菜单")
    @PostMapping("addmenu")
    @Override
    public JsonVO<String> addMenu(@RequestBody MenuCreateDTO menuCreateDTO) throws Exception {

        return JsonVO.success(String.valueOf(service.addMenu(menuCreateDTO)));
    }
}
