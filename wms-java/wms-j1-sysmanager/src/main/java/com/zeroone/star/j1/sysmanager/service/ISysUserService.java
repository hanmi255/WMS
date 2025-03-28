package com.zeroone.star.j1.sysmanager.service;

import com.zeroone.star.project.dto.j1.sysmanager.usermanager.ResetPasswordDTO;
import org.springframework.web.multipart.MultipartFile;
import javax.servlet.http.HttpServletResponse;

public interface ISysUserService {
    /**
     * 重置用户密码
     */
    void resetPassword(ResetPasswordDTO dto);
    
    /**
     * 删除用户
     * @param userId 用户ID
     * @param isPhysicalDelete 是否物理删除
     */
    void deleteUser(String userId, boolean isPhysicalDelete);
    
    /**
     * 导出用户数据
     */
    void exportUsers(HttpServletResponse response);
    
    /**
     * 导入用户数据
     */
    String importUsers(MultipartFile file);
} 
