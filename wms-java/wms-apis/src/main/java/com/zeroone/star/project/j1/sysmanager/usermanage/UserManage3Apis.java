package com.zeroone.star.project.j1.sysmanager.usermanage;

import com.zeroone.star.project.dto.j1.sysmanager.usermanager.ResetPasswordDTO;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletResponse;
import javax.validation.Valid;

/**
 *  j1-小马 接口放置位置
 * @author 李云毅
 * @version 1.0.0
 * 2025/3/1
 */
public interface UserManage3Apis {


    /**
     * 重置用户密码
     * @param resetPasswordDTO 重置密码数据对象
     * @return 返回重置结果
     */
    @ApiOperation(value = "重置用户密码", notes = "重置指定用户的密码")
    JsonVO<String> resetUserPassword(@Valid @ApiParam(value = "重置密码数据", required = true) ResetPasswordDTO resetPasswordDTO);

    /**
     * 删除用户
     * @param userId 用户ID
     * @param isPhysicalDelete 是否物理删除，true表示物理删除，false表示逻辑删除
     * @return 返回删除结果
     */
    @ApiOperation(value = "删除用户", notes = "根据用户ID删除用户，支持物理删除和逻辑删除")
    JsonVO<String> deleteUser(@ApiParam(value = "用户ID") String userId, 
                             @ApiParam(value = "是否物理删除", defaultValue = "false") boolean isPhysicalDelete);

    /**
     * 导出用户数据
     * @param response HTTP响应对象,用于返回文件流
     */
    @ApiOperation(value = "导出用户", notes = "导出所有用户数据到Excel文件")
    void exportUsers(@ApiParam(value = "HTTP响应对象", hidden = true) HttpServletResponse response);

    /**
     * 导入用户数据
     * @param file Excel文件
     * @return 返回导入结果
     */
    @ApiOperation(value = "导入用户", notes = "从Excel文件导入用户数据")
    JsonVO<String> importUsers(@ApiParam(value = "Excel文件", required = true) MultipartFile file);
}
