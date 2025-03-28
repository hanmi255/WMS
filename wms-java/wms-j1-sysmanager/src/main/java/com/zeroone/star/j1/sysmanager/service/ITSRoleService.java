package com.zeroone.star.j1.sysmanager.service;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.zeroone.star.j1.sysmanager.entity.TSRole;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleDeleteDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleEditDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleListDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleManagementBaseDTO;
import com.zeroone.star.project.query.j1.sysmanager.rolemanager.RoleManagementQuery;
import org.springframework.web.multipart.MultipartFile;

import java.util.List;

/**
 * @author lgl
 * 2025年03月02日 16:54
 */
public interface ITSRoleService {
    PageDTO<RoleListDTO> getRoleNameList(RoleManagementQuery query);

    PageDTO<RoleListDTO> getRoleList(RoleManagementQuery query);

    void addTSRole(RoleEditDTO roleEditDTO);

    void updateTSRole(RoleEditDTO roleEditDTO);

    void removeRole(RoleDeleteDTO roleDeleteDTO);

    List<TSRole> selectRoleList(RoleManagementQuery query);

    void importRole(MultipartFile file);
}
