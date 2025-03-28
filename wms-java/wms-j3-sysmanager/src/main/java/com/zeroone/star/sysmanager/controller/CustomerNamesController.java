package com.zeroone.star.sysmanager.controller;

import com.zeroone.star.project.j3.sysmg.CustomerNamesApis;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;
import java.util.List;

/**
 * 客户名称列表查询接口实现
 */
@RestController
@RequestMapping("sysmanager/customer-names")
@Api(tags = "客户名称列表查询接口实现")
public class CustomerNamesController implements CustomerNamesApis {

    /**
     * 查询客户名称列表
     * @return
     */
    @GetMapping()
    @ApiOperation(value = "查询客户名称列表接口")
    @Override
    public JsonVO<List<String>> queryCustomerNames() {
        return null;
    }
}
