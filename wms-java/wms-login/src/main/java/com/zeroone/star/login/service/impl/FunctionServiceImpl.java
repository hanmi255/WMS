package com.zeroone.star.login.service.impl;

import cn.hutool.core.collection.CollectionUtil;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.login.entity.TSFunction;
import com.zeroone.star.login.mapper.TSFunctionMapper;
import com.zeroone.star.login.service.ITSFunctionService;
import com.zeroone.star.project.utils.tree.TreeNode;
import com.zeroone.star.project.utils.tree.TreeNodeMapper;
import com.zeroone.star.project.utils.tree.TreeUtils;
import com.zeroone.star.project.vo.login.FunctionTreeVO;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * 描述：定义一个function数据到functionTreeNode的属性映射配器
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author nefertari
 * @version 1.0.0
 */
@Service
class functionTreeNodMapper implements TreeNodeMapper<FunctionTreeVO> {

    @Autowired
    TSFunctionMapper TSFunctionMapper;

    @Override
    public TreeNode objectMapper(FunctionTreeVO function) {
        FunctionTreeVO treeNode = new FunctionTreeVO();
        // 首先设置TreeNode计算层数使用属性
        treeNode.setTnId(function.getId());
        if (function.getParentfunctionid() == null) {
            treeNode.setTnPid(null);
        } else {
            treeNode.setTnPid(function.getParentfunctionid());
        }
        // 设置扩展属性
        treeNode.setId(function.getId());
        treeNode.setIconName(function.getIconName());
        treeNode.setDeskIconName(function.getDeskIconName());
        treeNode.setFunctionname(function.getFunctionname());
        treeNode.setFunctionurl(function.getFunctionurl());
        treeNode.setParentfunctionid(function.getParentfunctionid());
        return treeNode;
    }
}

/**
 * <p>
 * 菜单管理 服务实现类
 * </p>
 *
 * @author nefertari
 * @since 2025-02-25
 */

@Service
public class FunctionServiceImpl extends ServiceImpl<TSFunctionMapper, TSFunction> implements ITSFunctionService {

    @Autowired
    TSFunctionMapper TSFunctionMapper;

    /**
     * 获取所有菜单的url
     * @return
     */

    public List<FunctionTreeVO> listFunctionByRoleName(List<String> roleNames) {
        //1 定义一个存储数据库查询菜单数据的容器
        List<FunctionTreeVO> functions = new ArrayList<>();
        //2 遍历获取角色获取所有的菜单列表
        roleNames.forEach(roleName -> {
            //通过角色名获取菜单列表
            List<FunctionTreeVO> functionTreeVOS = TSFunctionMapper.selectFunctionsByRoleName(roleName);
            if (CollectionUtil.isNotEmpty(functionTreeVOS)) {
                functions.addAll(functionTreeVOS);
            }
        });
        //3 转换树形结构并返回
        return TreeUtils.listToTree(functions,new functionTreeNodMapper());
    }
}
