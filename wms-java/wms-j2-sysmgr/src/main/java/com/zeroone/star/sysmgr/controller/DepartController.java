package com.zeroone.star.sysmgr.controller;

import com.zeroone.star.project.components.user.UserDTO;
import com.zeroone.star.project.components.user.UserHolder;
import com.zeroone.star.project.dto.j2.sysmgr.DepartBaseDTO;
import com.zeroone.star.project.j2.sysmgr.DepartApis;
import com.zeroone.star.project.dto.j2.sysmgr.DepartTreeBaseDTO;
import com.zeroone.star.project.dto.j2.sysmgr.DepartTreeListDTO;
import com.zeroone.star.project.query.j2.sysmgr.DepartTreeQuery;
import com.zeroone.star.project.query.j2.sysmgr.OrgExportQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.sysmgr.mapper.DepartMapper;
import com.zeroone.star.sysmgr.service.DepartADMService;
import com.zeroone.star.sysmgr.service.DepartService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import io.swagger.annotations.ApiParam;
import lombok.SneakyThrows;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.IOException;
import java.util.List;


/**
 * <p>
 * 描述：组织相关接口
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @author TWTW
 * @version 1.0.0
 */
@RestController
@RequestMapping("/sysmgr")
@Api(tags = "组织基础数据")
public class DepartController implements DepartApis {

    @Autowired
    private DepartMapper departMapper;
    @Autowired
    private DepartService departService;
    @Autowired
    private UserHolder userHolder; //获取当前用户信息
    @GetMapping("/get-organization-tree")
    @ApiOperation(value = "获取组织名称树")
    @Override
    public JsonVO<List<DepartTreeBaseDTO>> queryTree() {
        return departService.queryTree();
    }

    @PostMapping("/get-organization-list")
    @ApiOperation(value = "获取组织列表")
    @Override
    public JsonVO<List<DepartTreeListDTO>> queryList(@RequestBody(required = false) DepartTreeQuery query) {
        if (query == null) {
            query = new DepartTreeQuery();
            // 可以根据业务需求设置默认值
            query.setParentDepartId(null);
        }
        return departService.queryList(query);
    }

    @PostMapping("/export-selected-organization")
    @ApiOperation(value = "导出选择组织")
    @Override
    public JsonVO<String> exportSelected(@RequestBody OrgExportQuery query) throws Exception {
        // 通过 UserHolder 获取当前用户信息
        UserDTO currentUser = userHolder.getCurrentUser();
        if (currentUser == null) {
            throw new RuntimeException("用户未登录");
        }
        // 设置操作人名称（username）
        query.setOperatorName(currentUser.getUsername());
        // 检查 departIds 是否为 null
        if (query.getDepartIds() == null) {
            throw new RuntimeException("部门 ID 列表不能为空");
        }
        return departService.exportSelected(query);
    }

    @GetMapping("/export-all-organization")
    @ApiOperation(value = "导出全部组织")
    @Override
    public JsonVO<String> exportAll() throws Exception {
        // 通过 UserHolder 获取当前用户信息
        UserDTO currentUser = userHolder.getCurrentUser();
        if (currentUser == null) {
            throw new RuntimeException("用户未登录");
        }
        // 直接使用用户名（username）
        String operatorName = currentUser.getUsername();
        return departService.exportAll(operatorName);
    }
    @PostMapping("/import-organization")
    @ApiOperation("导入组织")
    public JsonVO<String> importOrgData(@RequestParam("file") MultipartFile file) {
        if (file == null || file.isEmpty()) {
            return JsonVO.fail("上传文件为空");
        }
        try {
            return departService.importOrganization(file);
        } catch (Exception e) {
            e.printStackTrace();
            return JsonVO.fail("导入失败：" + e.getMessage());
        }
    }


    @Resource
    DepartADMService departADMService;

    @GetMapping("query-by-id")
    @ApiOperation("根据id查询组织机构信息")
    @Override
    public JsonVO<DepartBaseDTO> queryOrgById(@RequestParam("id") String id) {
        DepartBaseDTO result = departADMService.getDepartDetailById(id);
        if (result == null) {
            return JsonVO.fail(null);
        }
        return JsonVO.success(result);
    }

    @PostMapping("add-depart")
    @ApiOperation("录入组织机构")
    @Override
    public JsonVO<String> addOrg(@RequestBody DepartBaseDTO dto) {
        DepartBaseDTO result = departADMService.getDepartDetailById(dto.getId());
        if (result != null) {
            return JsonVO.fail("组织机构已存在");
        }
        return departADMService.addDepart(dto) ? JsonVO.success("录入成功") : JsonVO.fail("录入失败");
    }

    @PostMapping("delete-depart")
    @ApiOperation("删除组织机构")
    @Override
    public JsonVO<String> removeOrg(@RequestBody @ApiParam("组织机构id") String id) {
        DepartBaseDTO detail = departADMService.getDepartDetailById(id);
        if (detail == null) {
            return JsonVO.fail("该组织机构不存在");
        }
        if (detail.getDepartOrder().toString().equals("1")) {
            return JsonVO.fail("该组织机构存在成员，不能删除");
        }
        return departADMService.deleteDepart(id) ? JsonVO.success("删除成功") : JsonVO.fail("该组织不存在");
    }

    @SneakyThrows
    @PostMapping("modify-depart-order")
    @ApiOperation("修改组织机构成员是否存在")
    @Override
    public JsonVO<String> modifyDepartOrder(
            @RequestBody String departOrder) {
        DepartBaseDTO result = departADMService.getDepartDetailById(userHolder.getCurrentUser().getId());
        if (departOrder == "0" || departOrder == "1") {
            result.setDepartOrder(departOrder);
        } else {
            return JsonVO.fail("departOrder设置错误");
        }
        if (departADMService.updateDepart(result)) {
            return JsonVO.success("修改成功");
        }
        return JsonVO.fail("修改失败");

    }


    @PostMapping("modify-depart")
    @Override
    @ApiOperation("修改组织机构数据")
    public JsonVO<String> modifyOrg(@RequestBody DepartBaseDTO dto) {
        return departADMService.updateDepart(dto) ? JsonVO.success("修改成功") : JsonVO.fail("修改失败");
    }
}
