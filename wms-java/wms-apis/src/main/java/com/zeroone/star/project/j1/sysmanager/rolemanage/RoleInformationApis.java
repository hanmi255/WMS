package com.zeroone.star.project.j1.sysmanager.rolemanage;

import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleDeleteDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleEditDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleListDTO;
import com.zeroone.star.project.query.j1.sysmanager.rolemanager.RoleManagementQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.multipart.MultipartFile;

/**
 * <p>
 * 描述：角色信息
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author j1-图团
 * @version 1.0.0
 */
public interface RoleInformationApis {
    /**
     * 获取角色名称列表（条件+分页）
     */
    JsonVO<PageDTO<RoleListDTO>> queryRoleNameList(RoleManagementQuery query);

    /**
     * 获取角色列表（条件+分页）
     */
    JsonVO<PageDTO<RoleListDTO>> queryRoleList(RoleManagementQuery query);

    /**
     * 录入角色
     */
    JsonVO addTSRole(RoleEditDTO roleEditDTO);

    /**
     * 修改角色
     */
    JsonVO updateTSRole(RoleEditDTO roleEditDTO);

    /**
     * 删除角色
     */
    JsonVO removeRole(RoleDeleteDTO roleDeleteDTO);

    /**
     * 导入角色
     */
    JsonVO importRole(MultipartFile file);

    /**
     * 导出角色
     */
    ResponseEntity<byte[]> exportRole(RoleManagementQuery query);

}

