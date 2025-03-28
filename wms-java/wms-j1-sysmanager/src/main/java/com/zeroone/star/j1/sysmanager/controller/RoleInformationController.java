package com.zeroone.star.j1.sysmanager.controller;

import com.alibaba.excel.EasyExcel;
import com.alibaba.excel.metadata.Font;
import com.alibaba.excel.write.merge.LoopMergeStrategy;
import com.alibaba.excel.write.metadata.style.WriteCellStyle;
import com.alibaba.excel.write.metadata.style.WriteFont;
import com.alibaba.excel.write.style.HorizontalCellStyleStrategy;
import com.alibaba.excel.write.style.column.LongestMatchColumnWidthStyleStrategy;
import com.alibaba.excel.write.style.row.SimpleRowHeightStyleStrategy;
import com.baomidou.mybatisplus.core.conditions.query.LambdaQueryWrapper;
import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.j1.sysmanager.entity.TSBaseUser;
import com.zeroone.star.j1.sysmanager.entity.TSRole;
import com.zeroone.star.j1.sysmanager.service.ITSRoleService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleDeleteDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleEditDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleExportDTO;
import com.zeroone.star.project.dto.j1.sysmanager.rolemanager.RoleListDTO;
import com.zeroone.star.project.j1.sysmanager.rolemanage.RoleInformationApis;
import com.zeroone.star.project.query.j1.sysmanager.rolemanager.RoleManagementQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.apache.commons.lang.RandomStringUtils;
import org.apache.poi.ss.usermodel.HorizontalAlignment;
import org.apache.poi.ss.usermodel.IndexedColors;
import org.apache.poi.ss.usermodel.VerticalAlignment;
import org.springframework.beans.BeanUtils;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.IOException;
import java.net.URLEncoder;
import java.nio.charset.StandardCharsets;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

import static cn.hutool.poi.excel.style.StyleUtil.createHeadCellStyle;

/**
 * <p>
 * 描述：角色信息
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author j1-图团
 * @version 1.0.0
 */
@RestController
@RequestMapping("/role")
@Api(tags = "角色管理 -> 角色信息")
@Validated
public class RoleInformationController implements RoleInformationApis {
    @Resource
    private ITSRoleService tsRoleService;
    @Resource
    private EasyExcelComponent excel;
    @Resource
    private UserHolder userHolder;
    //获取角色名称列表（条件+分页）
    @ApiOperation("获取角色名称列表（条件+分页）")
    @GetMapping("/query-rolename")
    @Override
    public JsonVO<PageDTO<RoleListDTO>> queryRoleNameList(RoleManagementQuery query){
        // 获取角色名称列表（条件+分页）
       PageDTO<RoleListDTO> roleNameList = tsRoleService.getRoleNameList(query);
       return JsonVO.success(roleNameList);
    }
    //获取角色列表（条件+分页）
    @ApiOperation("获取角色列表（条件+分页）")
    @GetMapping("/query-role")
    @Override
    public JsonVO<PageDTO<RoleListDTO>> queryRoleList(RoleManagementQuery query){
        // 获取角色列表（条件+分页）
       PageDTO<RoleListDTO> roleList = tsRoleService.getRoleList(query);
       return JsonVO.success(roleList);
    }

    //录入角色
    @PostMapping("/add-role")
    @ApiOperation("录入角色")
    @Override
    public JsonVO addTSRole(@RequestBody RoleEditDTO roleEditDTO){
        //录入角色
        tsRoleService.addTSRole(roleEditDTO);
        return JsonVO.success(ResultStatus.SUCCESS);
    }

    //修改角色
    @PostMapping("/update-role")
    @ApiOperation("修改角色")
    @Override
    public JsonVO updateTSRole(@RequestBody RoleEditDTO roleEditDTO){
        // 修改角色
        tsRoleService.updateTSRole(roleEditDTO);
        return JsonVO.success(ResultStatus.SUCCESS);
    }

    @GetMapping("/remove-role")
    @ApiOperation("删除角色")
    @Override
    public JsonVO removeRole(RoleDeleteDTO roleDeleteDTO) {
        //删除角色
        tsRoleService.removeRole(roleDeleteDTO);
        return JsonVO.success(null);
    }

    @PostMapping("/import-role")
    @ApiOperation("导入角色")
    @Override
    public JsonVO importRole(MultipartFile file) {
        tsRoleService.importRole(file);
        PageDTO<RoleListDTO> roleList = tsRoleService.getRoleList(null);
        return JsonVO.success(roleList);
    }

    @GetMapping("export-role")
    @ApiOperation("导出角色")
    @SneakyThrows
    @Override
    public ResponseEntity<byte[]> exportRole(RoleManagementQuery query) {
        List<TSRole> roleList = tsRoleService.selectRoleList(query);
        if (roleList.isEmpty()) {
            return ResponseEntity.status(HttpStatus.BAD_REQUEST).body(null);
        }

        // 创建字节流
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        //属性拷贝
        List<RoleExportDTO> exportDTO = new ArrayList<>();
        for (TSRole tsRole:roleList){
            RoleExportDTO dto = new RoleExportDTO();
            BeanUtils.copyProperties(tsRole,dto);
            exportDTO.add(dto);
        }


       // 使用 EasyExcel 进行导出
        EasyExcel.write(out, RoleExportDTO.class)
                .sheet("角色数据")
                .doWrite(exportDTO);

        out.flush();

        // 生成文件名（防止中文乱码）
        String filename = URLEncoder.encode("角色表.xlsx", StandardCharsets.UTF_8.toString());

        // 设置响应头
        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.parseMediaType("application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"));
        headers.setContentDispositionFormData("attachment", filename);

        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(), headers, HttpStatus.CREATED);

        out.close();
        return result;
    }
}
