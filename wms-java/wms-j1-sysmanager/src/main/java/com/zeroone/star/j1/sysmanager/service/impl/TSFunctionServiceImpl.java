package com.zeroone.star.j1.sysmanager.service.impl;

import cn.hutool.core.bean.BeanUtil;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.j1.sysmanager.entity.TSFunction;
import com.zeroone.star.j1.sysmanager.entity.TSRoleFunction;
import com.zeroone.star.j1.sysmanager.mapper.TSFunctionMapper;
import com.zeroone.star.j1.sysmanager.service.ITSFunctionService;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.sysmanager.menumanager.*;
//import org.springframework.data.redis.core.RedisTemplate;
import io.swagger.models.auth.In;
import com.zeroone.star.project.utils.tree.TreeNode;
import com.zeroone.star.project.utils.tree.TreeNodeMapper;
import com.zeroone.star.project.utils.tree.TreeUtils;
import com.zeroone.star.project.vo.JsonVO;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.BeanUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import javax.annotation.Resource;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


/**
 * <p>
 * 菜单管理 服务实现类
 * </p>
 *
 * @author jd
 * @since 2025-02-25
 */
@Service
public class TSFunctionServiceImpl extends ServiceImpl<TSFunctionMapper, TSFunction> implements ITSFunctionService {

//   @Resource
//   private RedisTemplate redisTemplate;

    @Resource
    TSFunctionMapper tsFunctionMapper;
    @Autowired
    private UserHolder userHolder;

    /**
     * 更新资源
     * @param menuEditDTO 菜单更新数据
     */
    @Override
    public Integer update(MenuEditDTO menuEditDTO) {
        //判断对象是否为空
        if(menuEditDTO == null){
            return null;
        }
        //构建更新对象
        TSFunction ts = TSFunction.builder()
                .functionname(menuEditDTO.getMenuName())
                .functiontype(menuEditDTO.getMenuType())
                .functionorder(menuEditDTO.getMenuSort())
                .functionurl(menuEditDTO.getMenuUrl())
                .functionlevel(menuEditDTO.getMenuLevels())
                .iconid(menuEditDTO.getMenuIcon())
                .deskIconid(menuEditDTO.getDesktopIcons())
                .functionIconStyle(menuEditDTO.getMenuIconStyle())
                .id(menuEditDTO.getMenuId())
                .parentfunctionid(menuEditDTO.getParentMenuId())
                .build();

        int result = tsFunctionMapper.update(ts);//更新数据结果

        //判断是否为父菜单
        //如果是父菜单，父菜单id为null
        if(menuEditDTO.getMenuLevels() == 0){
            tsFunctionMapper.updateParentId(menuEditDTO.getMenuId());
        }

        return result;
    }


    /**
     * 删除资源
     * @param id 菜单id
     */
    @Override
    public Integer remove(String id) {


        //判断是否有数据关联
        //对数据进行更新

        List<TSRoleFunction> tsRoleFunctions = tsFunctionMapper.selectList(id);
        if(tsRoleFunctions != null ){
            for (TSRoleFunction tsRoleFunction : tsRoleFunctions) {
                tsRoleFunction.setFunctionid(null);
                updateRoleFunction(tsRoleFunction);
            }
        }
        //删除数据
        return baseMapper.deleteById(id);

    }

    /**
     * 更新角色菜单
     * @param tsRoleFunction 角色数据
     * @return 响应数据结果
     */
    public Integer updateRoleFunction(TSRoleFunction tsRoleFunction) {
        return tsFunctionMapper.updateRoleFunction(tsRoleFunction);
    }

    /**
     * 查询资源列表树
     */
    @Override
    public List<MenuManagementBaseDTO> listChild(String id) {

        //查询子菜单
        List<TSFunction> childs = tsFunctionMapper.selectChild(id);

        //转换为dto
        List<MenuManagementBaseDTO> result=new ArrayList<>();

        for (TSFunction child : childs) {
            toMenuManagementBaseDTO(child);
            result.add(toMenuManagementBaseDTO(child));
        }
        return result;
    }

    /**
     * 录入菜单
     */
    @Override
    public JsonVO<String> addMenu(MenuCreateDTO menuCreateDTO) throws Exception {
        //检验字段-菜单名称和菜单顺序为必须项
        if(menuCreateDTO.getMenuName()==null){
            return JsonVO.fail("菜单名称不能为空");
        }
        //要求暂时不关注菜单顺序
//        if(menuCreateDTO.getMenuSort()==null){
//            return JsonVO.fail("菜单顺序不能为空");
//        }
//        获取当前登录人的信息
        com.zeroone.star.project.components.user.UserDTO currentUser = userHolder.getCurrentUser();
        if(currentUser.getId()==null){
            return JsonVO.fail("当前用户信息获取失败");
        }
        //构建菜单实体
        TSFunction ts = TSFunction.builder()
                .functionname(menuCreateDTO.getMenuName())
                .functiontype(menuCreateDTO.getMenuType())
                .functionlevel(menuCreateDTO.getMenuLevels())
                .parentfunctionid(menuCreateDTO.getParentFunctionId())
                .functionurl(menuCreateDTO.getMenuUrl())
                .iconid(menuCreateDTO.getMenuIcon())
                .createBy(currentUser.getId())
                .createName(currentUser.getUsername())
                .createDate(LocalDateTime.now())
                .build();
        //插入数据库
        tsFunctionMapper.insertMenu(ts);
        return JsonVO.success("菜单录入成功");
    }

    /**
     * 获取菜单名称树
     */
    @Override
    public JsonVO<List<MenuTreeDTO>> getMenuTree() {
     //   查询所有菜单
          List<TSFunction> allMenus = tsFunctionMapper.getAllMenus();
         if(allMenus == null || allMenus.isEmpty()){
             return JsonVO.fail(null);
         }
         Map<String,MenuTreeDTO> menuTreeDTOMap=new HashMap<>();
         for(TSFunction tsFunction:allMenus){
             MenuTreeDTO menuTreeDTO=new MenuTreeDTO();
             menuTreeDTO.setMenuId(tsFunction.getId());
             menuTreeDTO.setMenuName(tsFunction.getFunctionname());
             menuTreeDTO.setParentId(tsFunction.getParentfunctionid());
             menuTreeDTOMap.put(tsFunction.getId(),menuTreeDTO);
         }
         //构建树形结构
        List<MenuTreeDTO> rootMenu=new ArrayList<>();
         for(MenuTreeDTO menuTreeDTO:menuTreeDTOMap.values()){
             //找到父菜单
             if(menuTreeDTO.getParentId()==null||menuTreeDTO.getParentId().isEmpty()){
                 rootMenu.add(menuTreeDTO);
             }else{
                 // 根据父菜单ID找到父菜单
                 MenuTreeDTO parentMenu=menuTreeDTOMap.get(menuTreeDTO.getParentId());
                 if(parentMenu!=null){
                     parentMenu.addChild(menuTreeDTO);
                 }
             }
         }
        return JsonVO.success(rootMenu);
    }
    /**
     * 获取菜单列表
     */
    @Override
    public JsonVO<List<MenuEntryDTO>> getMenuList(String menuId) {
        List<TSFunction> menuList;
        //没有携带id获取一级数据
        if(menuId==null||menuId.isEmpty()){
           menuList= tsFunctionMapper.getFirstMenus();
        }else{
            //携带id获取子级数据
            menuList= tsFunctionMapper.getAllMenusHavaparent(menuId);
        }
        if(menuList==null||menuList.isEmpty()){
            return JsonVO.fail(null);
        }
        //转换为dto
        List<MenuEntryDTO> result=new ArrayList<>();
        for(TSFunction tsFunction:menuList){
            MenuEntryDTO dto=toMenuEntryDTO(tsFunction);
            if(tsFunctionMapper.selectisParent(dto.getMenuId())==null||tsFunctionMapper.selectisParent(dto.getMenuId()).isEmpty()){
                dto.setIsParentNode(0);
            }else {
                dto.setIsParentNode(1);
            }
            result.add(dto);
        }
        return JsonVO.success(result);
    }

//    public boolean isParent(String menuId) {
//        Boolean result = tsFunctionMapper.selectisParent(menuId);
//        return result != null && result;
//    }

    /**
     * 获取菜单详细信息
     */
    @Override
    public JsonVO<MenuDetailDTO> getMenuDetail(String menuId) {
        //检验id是否为空
        if(menuId==null||menuId.isEmpty()){
            return JsonVO.fail(null);
        }
        //查询菜单详细信息
        TSFunction tsFunction=tsFunctionMapper.getMenuById(menuId);
        if(tsFunction==null){
            return JsonVO.fail(null);
        }
        //获取父菜单名称；
        String parentName=tsFunctionMapper.selectParentName(tsFunction.getParentfunctionid());
        //转换为dto
          MenuDetailDTO dto=new MenuDetailDTO();
          dto.setMenuId(tsFunction.getId());
          dto.setMenuName(tsFunction.getFunctionname());
          dto.setMenuType(tsFunction.getFunctiontype());
          dto.setMenuLevels(tsFunction.getFunctionlevel());
          dto.setMenuUrl(tsFunction.getFunctionurl());
          dto.setMenuIcon(tsFunction.getIconid());
          dto.setMenuIconStyle(tsFunction.getFunctionIconStyle());//获取不显示
          dto.setMenuSort(tsFunction.getFunctionorder());
          dto.setParentId(tsFunction.getParentfunctionid());
          dto.setParentName(parentName);
          dto.setCreatedBy(tsFunction.getCreateBy());
          dto.setUpdatedBy(tsFunction.getUpdateBy());
          dto.setDesktopIcons(tsFunction.getDeskIconid());
          dto.setCreateTime(tsFunction.getCreateDate());
          dto.setUpdateTime(tsFunction.getUpdateDate());
        return JsonVO.success(dto);
    }

    private MenuManagementBaseDTO toMenuManagementBaseDTO(TSFunction tsFunction) {
        if(tsFunction == null) return null;

        MenuManagementBaseDTO dto = new MenuManagementBaseDTO();
        dto.setMenuId(tsFunction.getId());
        dto.setMenuName(tsFunction.getFunctionname());
        dto.setMenuType(tsFunction.getFunctiontype());
        dto.setMenuLevels(tsFunction.getFunctionlevel());
        dto.setMenuUrl(tsFunction.getFunctionurl());
        dto.setMenuIcon(tsFunction.getIconid());
        dto.setDesktopIcons(tsFunction.getDeskIconid());
        dto.setMenuSort(tsFunction.getFunctionorder());
        dto.setMenuIconStyle(tsFunction.getFunctionIconStyle());


        return dto;
    }
    private MenuEntryDTO toMenuEntryDTO(TSFunction tsFunction) {
        if(tsFunction == null) return null;
        MenuEntryDTO dto = new MenuEntryDTO();
        dto.setMenuId(tsFunction.getId());
        dto.setMenuName(tsFunction.getFunctionname());
        dto.setMenuType(tsFunction.getFunctiontype());
        dto.setMenuLevels(tsFunction.getFunctionlevel());
        dto.setMenuUrl(tsFunction.getFunctionurl());
        dto.setMenuIcon(tsFunction.getIconid());
        dto.setDesktopIcons(tsFunction.getDeskIconid());
        dto.setMenuSort(tsFunction.getFunctionorder());
        dto.setMenuIconStyle(tsFunction.getFunctionIconStyle());
        return  dto;
    }

}
