package com.zeroone.star.j1.sysmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.baomidou.mybatisplus.core.conditions.update.UpdateWrapper;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import com.zeroone.star.j1.sysmanager.entity.TSBaseUser;
import com.zeroone.star.j1.sysmanager.entity.TSRole;
import com.zeroone.star.j1.sysmanager.mapper.TSRoleMapper;
import com.zeroone.star.j1.sysmanager.service.ITSRoleService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleDeleteDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleEditDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleListDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleManagementBaseDTO;
import com.zeroone.star.project.query.j1.sysmanager.rolemanager.RoleManagementQuery;
import com.zeroone.star.project.vo.JsonVO;
import org.apache.commons.lang.RandomStringUtils;
import org.mapstruct.Mapper;
import org.springframework.beans.BeanUtils;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.File;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

/**
 * @author lgl
 * @date 2025年03月02日 16:55
 */

@Mapper(componentModel = "spring")
interface MsSampleMapper {
    /**
     * 将Sample转换为SampleDTO
     * @param
     * @return 转换后的对象
     */
    RoleListDTO TSRoleToTSRoleDTO(TSRole tsRole);
}
@Service
public class TSRoleServiceImpl extends ServiceImpl<TSRoleMapper, TSRole> implements ITSRoleService {

    @Resource
    private UserHolder userHolder;

    @Resource
    private MsSampleMapper msMapper;

    @Resource
    private TSRoleMapper tsRoleMapper;
    @Resource
    private EasyExcelComponent excel;
    @Override
    public PageDTO<RoleListDTO> getRoleNameList(RoleManagementQuery query) {
        // 构建分页对象
        Page<TSRole> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<TSRole> wrapper = new QueryWrapper<>();
        if (query.getRolename()!=null) {
            wrapper.like("rolename", query.getRolename());
        }
        wrapper.select("ID","rolename");
        // 查询数据
        Page<TSRole> ps = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(ps, msMapper::TSRoleToTSRoleDTO);
    }

    @Override
    public PageDTO<RoleListDTO> getRoleList(RoleManagementQuery query) {
        // 构建分页对象
        Page<TSRole> page = new Page<>(query.getPageIndex(), query.getPageSize());
        // 构建查询条件
        QueryWrapper<TSRole> wrapper = new QueryWrapper<>();
        if (query.getRolename()!=null){
            wrapper.like("rolename", query.getRolename());
        }
        wrapper.select("ID","rolecode","rolename");
        // 查询数据
        Page<TSRole> ps = baseMapper.selectPage(page, wrapper);
        return PageDTO.create(ps, msMapper::TSRoleToTSRoleDTO);
    }

    @Override
    public void addTSRole(RoleEditDTO roleEditDTO) {
        List<TSRole> tsRoles = baseMapper.selectList(null);
        for (TSRole t : tsRoles){
            if (t.getRolecode().equals(roleEditDTO.getRolecode())){
                throw new RuntimeException("用户编码已存在");
            }
        }
        TSRole role = new TSRole();
        BeanUtils.copyProperties(roleEditDTO,role);
        try {
            UserDTO currentUser = userHolder.getCurrentUser();
            TSBaseUser tsBaseUser = tsRoleMapper.selectBaseUserById(currentUser.getId());
            role.setId(RandomStringUtils.random(32,true,true).toString());
            role.setCreateDate(LocalDateTime.now());
            role.setUpdateDate(LocalDateTime.now());
            role.setCreateName(tsBaseUser.getRealname());
            role.setCreateBy(tsBaseUser.getUsername());
            role.setUpdateBy(tsBaseUser.getUsername());
            role.setUpdateName(tsBaseUser.getRealname());
            int insert = baseMapper.insert(role);
            if (insert==0){
                throw new RuntimeException("添加失败");
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

    }

    @Override
    public void updateTSRole(RoleEditDTO roleEditDTO) {
        TSRole temp = baseMapper.selectById(roleEditDTO.getId());
        if (temp==null){
            throw new RuntimeException("用户不存在");
        }
        List<TSRole> tsRoles = baseMapper.selectList(null);
        for (TSRole t : tsRoles){
            if (t.getRolecode().equals(roleEditDTO.getRolecode())){
                throw new RuntimeException("用户编码已经存在");
            }
        }
        TSRole tsRole = new TSRole();
        BeanUtils.copyProperties(roleEditDTO,tsRole);
        try {
            UserDTO currentUser = userHolder.getCurrentUser();
            TSBaseUser tsBaseUser = tsRoleMapper.selectBaseUserById(currentUser.getId());
            tsRole.setUpdateBy(tsBaseUser.getUsername());
            tsRole.setUpdateName(tsBaseUser.getRealname());
            tsRole.setUpdateDate(LocalDateTime.now());
            UpdateWrapper<TSRole> wrapper = new UpdateWrapper<>();
            //根据唯一标识进行修改
            wrapper.eq("ID",tsRole.getId());
            int update = baseMapper.update(tsRole, wrapper);
            if (update==0){
                throw new RuntimeException("修改失败");
            }
        } catch (Exception e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    @Transactional(rollbackFor = Exception.class)
    public void removeRole(RoleDeleteDTO roleDeleteDTO) {
        TSRole tsRole = baseMapper.selectById(roleDeleteDTO.getId());
        if (tsRole == null)throw new RuntimeException("用户不存在");
        tsRoleMapper.deleteRoleFunction(roleDeleteDTO.getId());
        tsRoleMapper.deleteRoleUser(roleDeleteDTO.getId());
        int i = baseMapper.deleteById(roleDeleteDTO.getId());
        if (i==0){
            throw new RuntimeException("删除失败");
        }
    }

    @Override
    public List<TSRole> selectRoleList(RoleManagementQuery query) {
        QueryWrapper<TSRole> wrapper = new QueryWrapper<>();
        if (query.getRolename()!=null){
            wrapper.like("rolename", query.getRolename());
        }
        wrapper.select("rolecode","rolename");
        List<TSRole> roleList = baseMapper.selectList(wrapper);
        return roleList;
    }

    @Override
    public void importRole(MultipartFile file) {
        File tempFile = null;
        try {
            // 1. 创建临时文件（避免文件名冲突）
            tempFile = File.createTempFile("import_", ".xlsx");
            file.transferTo(tempFile);

            // 2. 解析 Excel
            List<TSRole> roleList = excel.parseExcel(tempFile.getPath(), TSRole.class);
            if (roleList == null || roleList.isEmpty()) {
                return;
            }

            // 3. 获取当前用户信息（避免重复查询）
            UserDTO currentUser = userHolder.getCurrentUser();
            TSBaseUser tsBaseUser = tsRoleMapper.selectBaseUserById(currentUser.getId());
            if (tsBaseUser == null) {
                throw new RuntimeException("用户信息异常，无法导入角色");
            }

            // 4. 查询数据库中已有角色
            List<String> roleCodes = roleList.stream().map(TSRole::getRolecode).distinct().collect(Collectors.toList());
            if (roleCodes.isEmpty()) {
                return;
            }
            LambdaQueryWrapper<TSRole> wrapper = new LambdaQueryWrapper<>();
            wrapper.in(TSRole::getRolecode, roleCodes);
            Set<String> existingRoleCodes = baseMapper.selectList(wrapper)
                    .stream()
                    .map(TSRole::getRolecode)
                    .collect(Collectors.toSet());

            // 5. 过滤已有角色，并构造新角色列表
            for (TSRole role : roleList) {
                if (existingRoleCodes.contains(role.getRolecode())) {
                    continue; // 角色已存在，跳过
                }
                role.setId(RandomStringUtils.randomAlphanumeric(32)); // 生成唯一 ID
                role.setCreateDate(LocalDateTime.now());
                role.setUpdateDate(LocalDateTime.now());
                role.setCreateName(tsBaseUser.getRealname());
                role.setCreateBy(tsBaseUser.getUsername());
                role.setUpdateBy(tsBaseUser.getUsername());
                role.setUpdateName(tsBaseUser.getRealname());
                baseMapper.insert(role);
            }

        } catch (Exception e) {
            throw new RuntimeException("导入 Excel 失败: " + e.getMessage(), e);
        } finally {
            // 7. 删除临时文件，避免占用磁盘空间
            if (tempFile != null && tempFile.exists()) {
                tempFile.delete();
            }
        }
    }

}
