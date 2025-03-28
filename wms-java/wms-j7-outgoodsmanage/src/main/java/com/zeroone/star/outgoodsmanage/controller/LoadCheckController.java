package com.zeroone.star.outgoodsmanage.controller;


import com.zeroone.star.outgoodsmanage.entity.WmOmNoticeH;
import com.zeroone.star.outgoodsmanage.service.IWmOmNoticeHService;
import com.zeroone.star.outgoodsmanage.service.IWmToDownGoodsService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.zccheck.*;
import com.zeroone.star.outgoodsmanage.service.ILoadCheckService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.zccheck.BatchCheckDTO;
import com.zeroone.star.project.j7.zccheck.CheckApis;
import com.zeroone.star.project.j7.zccheck.LoadCheckApis;
import com.zeroone.star.project.j7.zccheck.LoadingReviewApis;
import com.zeroone.star.project.query.j7.zccheck.ZcCheckQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import java.util.List;
import java.util.stream.Collectors;

/**
 * <p>
 * 描述：装车复核接口实现
 * </p>
 *
 * @author chen
 * @since 2025/2/25 17:15
 */
@RestController
@RequestMapping("/zc-check/")
@Api(tags = "装车复核接口实现")
public class LoadCheckController implements LoadCheckApis, LoadingReviewApis, CheckApis {

    @Resource
    private IWmOmNoticeHService wmOmNoticeHService;

    @Resource
    ILoadCheckService iService;

    @Autowired
    IWmToDownGoodsService wmToDownGoodsService;

    @GetMapping("query-all")
    @ApiOperation("获取复核列表（条件+分页）")
    @Override
    public JsonVO<PageDTO<CheckListDTO>> queryAll(ZcCheckQuery zcCheckQuery) {
        return JsonVO.success(wmToDownGoodsService.queryAll(zcCheckQuery));
    }

    @PostMapping("batch-check")
    @ApiOperation("批量复核")
    @Override
    public JsonVO<List<CheckDTO>> checkModify(@RequestBody List<CheckDTO> batchCheckDTO) {
        List<CheckDTO> batchCheckDTOList = iService.updateBatchCheck(batchCheckDTO);
        if (batchCheckDTOList != null)
            return JsonVO.success(batchCheckDTOList);
        else return JsonVO.fail(batchCheckDTOList);
    }

    @Override
    @ApiOperation("一键复核")
    @PostMapping("modify-review-by-list")
    public JsonVO<String> oneClickReview(@RequestBody OneClickReviewDTO oneClickReviewDTO) {
        List<String> reviewIds = oneClickReviewDTO.getOmNoticeIds();
        List<WmOmNoticeH> list = reviewIds.stream().map(e -> {
            WmOmNoticeH wmOmNoticeH = new WmOmNoticeH();
            wmOmNoticeH.setOmNoticeId(e);
            wmOmNoticeH.setOmSta("复核完成");
            return wmOmNoticeH;
        }).collect(Collectors.toList());
        wmOmNoticeHService.updateBatchById(list);
        return JsonVO.success("一键复核成功！");
    }


}
