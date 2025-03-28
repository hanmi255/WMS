package com.zeroone.star.project.j1.sysmanager.rolemanage;

import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleFunctionAssignmentDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleFunctionDTO;
import com.zeroone.star.project.vo.JsonVO;
/**
 * <p>
 * 描述：角色资源
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author j1-图团
 * @version 1.0.0
 */
public interface RoleResourcesApis {
    /**
     * 获取资源名称树
     * 匿名的好友
     * @param langType 语言类型，用于指定返回资源名称的语言。
     * @return 包含资源名称树的 JsonVO 对象。
     */
    JsonVO<RoleFunctionAssignmentDTO> getRoleAllFunction(String langType);

    /**
     * 获取角色分配资源
     * 匿名的好友
     * @param roleCode
     * @return 角色分配资源
     */
    JsonVO<RoleFunctionAssignmentDTO> getRoleFunction(String roleCode, String langType);

    /**
     * 设置角色分配资源
     * 匿名的好友
     * @param roleFunctionAssignmentDTO
     * @return 角色分配资源
     */
    JsonVO<String> setRoleFunction(RoleFunctionAssignmentDTO roleFunctionAssignmentDTO);

}
