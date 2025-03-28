package com.zeroone.star.sysmgr.controller;


import com.zeroone.star.project.j2.sysmgr.OrgUserApis;
import com.zeroone.star.project.query.j2.sysmgr.AddUserQuery;
import com.zeroone.star.project.query.j2.sysmgr.DeleteUserQuery;
import com.zeroone.star.project.query.j2.sysmgr.ListUserQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import com.zeroone.star.project.vo.j2.sysmgr.ListUserVO;
import com.zeroone.star.sysmgr.service.ITSUserOrgService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;

/**
 * <p>
 *  前端控制器
 * </p>
 *
 * @author henry
 * @since 2025-02-21
 */
@RestController
@RequestMapping("/sysmgr/t-suser-org")
@Api(tags = "组织机构")
@Validated
public class TSUserOrgController implements OrgUserApis {


    @Resource
    private ITSUserOrgService itsUserOrgService;

    @GetMapping("/listUser")
    @Override
    @ApiOperation(value = "获取组织成员(条件+分页)")
    public JsonVO<ListUserVO> listUser(@Validated ListUserQuery userQuery) {
        ListUserVO listUserVO = itsUserOrgService.listUser(userQuery);
        return JsonVO.success(listUserVO);
    }

    @PostMapping("/deleteUser")
    @Override
    @ApiOperation(value = "删除组织成员")
    public JsonVO<Object> deleteUser(@Validated @RequestBody DeleteUserQuery userQuery) {
        int i = itsUserOrgService.deleteUser(userQuery);
        if (i <= 0){
            return JsonVO.create(null, ResultStatus.FAIL);
        }
        return JsonVO.success(null);
    }

    @PostMapping("/addUser")
    @Override
    @ApiOperation(value = "添加组织成员")
    public JsonVO<Object> addUser(@Validated @RequestBody AddUserQuery userQuery) {
        boolean b = itsUserOrgService.addUser(userQuery);
        if (!b){
            return JsonVO.create(null, ResultStatus.FAIL);
        }
        return JsonVO.success(null);
    }

}

