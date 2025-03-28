package com.zeroone.star.stockln.controller;

import com.zeroone.star.project.j6.stockln.ToAcceptApis;
import com.zeroone.star.project.query.j6.stockln.ToAcceptQuery;
import com.zeroone.star.project.vo.j6.stockln.ToAcceptDetailVO;
import com.zeroone.star.project.vo.j6.stockln.ToAcceptPageVO;
import com.zeroone.star.project.vo.JsonVO;

import com.zeroone.star.stockln.service.ToAcceptService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

/**
 * <p>
 * 描述：待验收货物相关控制器
 * </p>
 * <p>版权：&copy;01星球</p>
 * <p>地址：01星球总部</p>
 * @version 1.0.0
 */
@RestController
@RequestMapping("/stock/bulk_receipt/toaccept")
@Api(tags = "批量验收")
public class ToAcceptController implements ToAcceptApis {

    @Autowired
    private ToAcceptService toAcceptService; // 注入服务层

    /**
     * 获取待验收货物列表，支持条件查询和分页查询
     * @param query 查询条件（包括到货通知单、商品编码等）
     * @param page 页码
     * @param size 每页数量
     * @return 返回分页的待验收货物列表
     */
    @Override
    @GetMapping("/items")
    @ApiOperation(value = "获取待验收货物列表", notes = "支持分页和条件查询")
    public JsonVO<ToAcceptPageVO> getAcceptanceItems(
            ToAcceptQuery query,
            @RequestParam(defaultValue = "1") int page,
            @RequestParam(defaultValue = "10") int size) {

        // 调用服务层进行分页查询
        ToAcceptPageVO result = toAcceptService.getAcceptanceItems(query, page, size);

        return JsonVO.success(result);
    }

    /**
     * 根据ID查询单个待验收货物
     * @param id 货物ID
     * @return 返回待验收货物的详细信息
     */
    @Override
    @GetMapping("/items/{id}")
    @ApiOperation(value = "获取待上架货物信息", notes = "按 ID 查询待验收货物详细信息")
    public JsonVO<ToAcceptDetailVO> getAcceptanceItemById(@PathVariable String id) {

        // 调用服务层根据ID查询货物信息
        ToAcceptDetailVO itemDetail = toAcceptService.getAcceptanceItemById(id);

        // 如果没有找到数据，返回404
        if (itemDetail == null) {
            return JsonVO.fail(null);
        }

        return JsonVO.success(itemDetail);
    }
}
