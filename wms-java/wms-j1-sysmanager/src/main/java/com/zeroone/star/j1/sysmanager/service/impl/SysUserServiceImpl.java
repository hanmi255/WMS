package com.zeroone.star.j1.sysmanager.service.impl;

import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.zeroone.star.j1.sysmanager.entity.*;
import com.zeroone.star.j1.sysmanager.mapper.*;
import com.zeroone.star.j1.sysmanager.service.ISysUserService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.j1.sysmanager.usermanager.UserExportDTO;
import com.zeroone.star.project.dto.j1.sysmanager.usermanager.ResetPasswordDTO;
import org.springframework.beans.BeanUtils;
import org.springframework.context.annotation.ComponentScan;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletResponse;
import java.io.File;
import java.io.OutputStream;
import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;
import java.util.UUID;

/**
 * <p>
 * 描述：系统用户服务实现类
 * </p>
 * @author j1-小马
 * @version 1.0.0
 */
@Service
@ComponentScan("com/zeroone/star/project/components/easyexcel")
public class SysUserServiceImpl implements ISysUserService {

    @Resource
    private TSBaseUserMapper baseUserMapper;

    @Resource
    private TSUserMapper tsUserMapper;

    @Resource
    private TSUserOrgMapper tsUserOrgMapper;

    @Resource
    private EasyExcelComponent excelComponent;

    @Resource
    private TSRoleUserMapper roleUserMapper;

    @Resource
    private TSRoleMapper roleMapper;

    @Resource
    private TSDepartMapper departMapper;

    private final BCryptPasswordEncoder passwordEncoder = new BCryptPasswordEncoder();

    @Override
    @Transactional(rollbackFor = Exception.class)
    public void resetPassword(ResetPasswordDTO dto) {
        // 1. 验证用户是否存在
        TSBaseUser user = baseUserMapper.selectById(dto.getUserId());
        if (user == null) {
            throw new RuntimeException("用户不存在");
        }
    }

    @Override
    @Transactional(rollbackFor = Exception.class)
    public void deleteUser(String userId, boolean isPhysicalDelete) {
        // 1. 验证用户是否存在
        TSBaseUser baseUser = baseUserMapper.selectById(userId);
        if (baseUser == null) {
            throw new RuntimeException("用户不存在");
        }

        // 2. 检查是否为逻辑删除（delete_flag=1表示已删除）
        if (!isPhysicalDelete && baseUser.getDeleteFlag() != null && baseUser.getDeleteFlag() == 1) {
            throw new RuntimeException("用户已被删除");
        }

        // 3. 删除关联数据
        // 3.1 删除用户-组织关系
        tsUserOrgMapper.delete(
            new LambdaQueryWrapper<TSUserOrg>()
                .eq(TSUserOrg::getUserId, userId)
        );

        // 3.2 删除用户-角色关系
        roleUserMapper.delete(
            new LambdaQueryWrapper<TSRoleUser>()
                .eq(TSRoleUser::getUserid, userId)
        );

        // 3.3 删除用户扩展信息
        tsUserMapper.deleteById(userId);

        // 4. 根据删除类型处理基本用户信息
        if (isPhysicalDelete) {
            // 物理删除：直接从数据库中删除记录
            baseUserMapper.deleteById(userId);
        } else {
            // 逻辑删除：更新删除标志
            baseUser.setDeleteFlag(1);
            baseUserMapper.updateById(baseUser);
        }
    }

    @Override
    public void exportUsers(HttpServletResponse response) {
        try (OutputStream outputStream = response.getOutputStream()) {
            // 1. 获取所有用户基本信息
            List<TSBaseUser> baseUsers = baseUserMapper.selectList(null);
            if (baseUsers.isEmpty()) {
                response.setContentType("text/plain");
                response.setCharacterEncoding("UTF-8");
                outputStream.write("没有用户数据可导出".getBytes(StandardCharsets.UTF_8));
                return;
            }

            // 2. 转换数据
            List<UserExportDTO> exportList = new ArrayList<>();
            for (TSBaseUser baseUser : baseUsers) {
                UserExportDTO dto = new UserExportDTO();
                
                // 2.1 设置用户名和真实姓名
                dto.setUsername(baseUser.getUsername());
                dto.setRealName(baseUser.getRealname());
                
                // 2.2 获取用户扩展信息
                TSUser tsUser = tsUserMapper.selectById(baseUser.getId());
                if (tsUser != null) {
                    dto.setMobile(tsUser.getMobilePhone());
                    dto.setOfficePhone(tsUser.getOfficePhone());
                    dto.setEmail(tsUser.getEmail());
                }
                
                // 2.3 获取用户角色信息
                List<TSRoleUser> roleUsers = roleUserMapper.selectList(
                    new LambdaQueryWrapper<TSRoleUser>()
                        .eq(TSRoleUser::getUserid, baseUser.getId())
                );
                if (!roleUsers.isEmpty()) {
                    List<String> roleCodes = new ArrayList<>();
                    for (TSRoleUser roleUser : roleUsers) {
                        TSRole role = roleMapper.selectById(roleUser.getRoleid());
                        if (role != null) {
                            roleCodes.add(role.getRolecode());
                        }
                    }
                    dto.setRoleCodes(String.join(",", roleCodes));
                }
                
                // 2.4 获取用户组织机构信息
                List<TSUserOrg> userOrgs = tsUserOrgMapper.selectList(
                    new LambdaQueryWrapper<TSUserOrg>()
                        .eq(TSUserOrg::getUserId, baseUser.getId())
                );
                if (!userOrgs.isEmpty()) {
                    List<String> orgCodes = new ArrayList<>();
                    for (TSUserOrg userOrg : userOrgs) {
                        // 根据组织机构ID获取组织机构编码
                        TSDepart depart = departMapper.selectById(userOrg.getOrgId());
                        if (depart != null) {
                            orgCodes.add(depart.getOrgCode());
                        }
                    }
                    dto.setOrgCodes(String.join(",", orgCodes));
                }
                
                exportList.add(dto);
            }

            // 3. 设置响应头
            response.setContentType("application/vnd.openxmlformats-officedocument.spreadsheetml.sheet");
            response.setCharacterEncoding("UTF-8");
            String fileName = URLEncoder.encode("用户数据.xlsx", "UTF-8");
            response.setHeader("Content-Disposition", "attachment;filename=" + fileName);

            // 4. 导出数据
            excelComponent.export("用户数据", outputStream, UserExportDTO.class, exportList);
        } catch (Exception e) {
            throw new RuntimeException("导出用户数据失败: " + e.getMessage());
        }
    }

    @Override
    @Transactional(rollbackFor = Exception.class)
    public String importUsers(MultipartFile file) {
        try {
            // 1. 将MultipartFile转换为临时文件
            File tempFile = File.createTempFile("temp", file.getOriginalFilename());
            file.transferTo(tempFile);

            // 2. 读取Excel数据
            List<UserExportDTO> importList = excelComponent.parseExcel(tempFile.getPath(), UserExportDTO.class);
            if (importList == null || importList.isEmpty()) {
                return "导入的Excel文件中没有数据";
            }

            // 3. 验证数据
            validateImportData(importList);

            // 4. 保存数据
            int successCount = 0;
            int failCount = 0;
            StringBuilder failMsg = new StringBuilder();

            for (UserExportDTO dto : importList) {
                try {
                    // 4.1 检查用户是否已存在
                    LambdaQueryWrapper<TSBaseUser> wrapper = new LambdaQueryWrapper<>();
                    wrapper.eq(TSBaseUser::getUsername, dto.getUsername());
                    if (baseUserMapper.selectCount(wrapper) > 0) {
                        failCount++;
                        failMsg.append("用户名[").append(dto.getUsername()).append("]已存在; ");
                        continue;
                    }

                    // 4.2 创建基本用户信息
                    TSBaseUser baseUser = new TSBaseUser();
                    baseUser.setId(UUID.randomUUID().toString().replace("-", ""));
                    baseUser.setUsername(dto.getUsername());
                    baseUser.setRealname(dto.getRealName());
                    baseUser.setStatus(1); // 默认激活状态
                    baseUser.setPassword(passwordEncoder.encode("123456")); // 加密默认密码
                    baseUser.setDeleteFlag(0); // 设置删除标志为未删除
                    baseUserMapper.insert(baseUser);

                    // 4.3 创建用户扩展信息
                    TSUser tsUser = new TSUser();
                    tsUser.setId(baseUser.getId());
                    tsUser.setEmail(dto.getEmail());
                    tsUser.setMobilePhone(dto.getMobile());
                    tsUser.setOfficePhone(dto.getOfficePhone());
                    tsUser.setCreateDate(LocalDateTime.now());
                    tsUser.setCreateBy("admin");
                    tsUser.setCreateName("系统导入");
                    tsUserMapper.insert(tsUser);

                    // 4.4 处理角色关系
                    if (dto.getRoleCodes() != null && !dto.getRoleCodes().isEmpty()) {
                        String[] roleCodes = dto.getRoleCodes().split(",");
                        for (String roleCode : roleCodes) {
                            // 查找角色ID
                            LambdaQueryWrapper<TSRole> roleWrapper = new LambdaQueryWrapper<>();
                            roleWrapper.eq(TSRole::getRolecode, roleCode.trim());
                            TSRole role = roleMapper.selectOne(roleWrapper);
                            
                            if (role != null) {
                                // 创建用户角色关系
                                TSRoleUser roleUser = new TSRoleUser();
                                roleUser.setId(UUID.randomUUID().toString().replace("-", ""));
                                roleUser.setUserid(baseUser.getId());
                                roleUser.setRoleid(role.getId());
                                roleUserMapper.insert(roleUser);
                            } else {
                                failMsg.append("用户[").append(dto.getUsername())
                                    .append("]的角色编码[").append(roleCode).append("]不存在; ");
                            }
                        }
                    }

                    // 4.5 处理组织机构关系
                    if (dto.getOrgCodes() != null && !dto.getOrgCodes().isEmpty()) {
                        String[] orgCodes = dto.getOrgCodes().split(",");
                        for (String orgCode : orgCodes) {
                            // 查找组织机构ID
                            LambdaQueryWrapper<TSDepart> departWrapper = new LambdaQueryWrapper<>();
                            departWrapper.eq(TSDepart::getOrgCode, orgCode.trim());
                            TSDepart depart = departMapper.selectOne(departWrapper);
                            
                            if (depart != null) {
                                // 创建用户组织机构关系
                                TSUserOrg userOrg = new TSUserOrg();
                                userOrg.setId(UUID.randomUUID().toString().replace("-", ""));
                                userOrg.setUserId(baseUser.getId());
                                userOrg.setOrgId(depart.getId());
                                tsUserOrgMapper.insert(userOrg);
                            } else {
                                failMsg.append("用户[").append(dto.getUsername())
                                    .append("]的组织机构编码[").append(orgCode).append("]不存在; ");
                            }
                        }
                    }

                    successCount++;
                } catch (Exception e) {
                    failCount++;
                    failMsg.append("用户[").append(dto.getUsername())
                        .append("]导入失败: ").append(e.getMessage()).append("; ");
                }
            }

            // 5. 删除临时文件
            tempFile.delete();

            // 6. 返回导入结果
            if (failCount > 0) {
                return String.format("导入完成，成功导入%d条数据，失败%d条。\n失败原因：\n%s", 
                    successCount, failCount, failMsg.toString());
            } else {
                return String.format("成功导入%d条数据。", successCount);
            }
        } catch (Exception e) {
            throw new RuntimeException("导入用户数据失败: " + e.getMessage());
        }
    }

    /**
     * 验证密码是否符合要求
     */
    private boolean validatePassword(String password) {
        if (password.length() < 8) return false;
        boolean hasDigit = false;
        boolean hasLetter = false;
        for (char c : password.toCharArray()) {
            if (Character.isDigit(c)) hasDigit = true;
            if (Character.isLetter(c)) hasLetter = true;
        }
        return hasDigit && hasLetter;
    }

    /**
     * 验证导入的数据
     */
    private void validateImportData(List<UserExportDTO> importList) {
        for (UserExportDTO dto : importList) {
            // 1. 验证必填字段
            if (dto.getUsername() == null || dto.getUsername().trim().isEmpty()) {
                throw new RuntimeException("用户名不能为空");
            }


        }
    }
} 