package com.zeroone.star.outgoodsmanage.controller;


import com.zeroone.star.outgoodsmanage.service.IWmOmNoticeIService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.outbound.WmOmNoticeIDTO;
import com.zeroone.star.project.j7.outbound.WmOmNoticeIApis;
import com.zeroone.star.project.query.j7.outbound.WmOmNoticeIQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 出库通知项 前端控制器
 * </p>
 *
 * @author lenyan
 * @since 2025-02-21
 */
@RestController
@RequestMapping("/outbound/item/")
@Api(tags = "出库通知项接口")
public class OutBoundController implements WmOmNoticeIApis {

    @Resource
    private IWmOmNoticeIService iWmOmNoticeIService;

    @GetMapping("queryall")
    @ApiOperation(value = "获取出库通知项列表（条件+分页）")
    @Override
    public JsonVO<PageDTO<WmOmNoticeIDTO>> queryAllWmOmNoticeI(WmOmNoticeIQuery query) {
        PageDTO<WmOmNoticeIDTO> pageDTO = iWmOmNoticeIService.queryAllWmOmNoticeI(query);
        return JsonVO.success(pageDTO);
    }

    @PostMapping("modify")
    @ApiOperation(value = "修改出库通知项（支持批量修改）")
    @Override
    public JsonVO<String> modifyWmOmNoticeI(@RequestBody List<WmOmNoticeIDTO> modifyList) {
        if (modifyList == null || modifyList.isEmpty()) {
            return JsonVO.fail("修改列表不能为空");
        }
        iWmOmNoticeIService.modifyWmOmNoticeI(modifyList);
        return JsonVO.success("修改成功");
    }
}

