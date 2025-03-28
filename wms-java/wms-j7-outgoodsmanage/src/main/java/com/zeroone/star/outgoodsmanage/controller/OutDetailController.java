package com.zeroone.star.outgoodsmanage.controller;


import com.zeroone.star.outgoodsmanage.service.IWmOmNoticeHService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.outdetail.OutDetailDTO;
import com.zeroone.star.project.dto.j7.outdetail.OutDetailExcelDTO;
import com.zeroone.star.project.j7.outdetail.OutDetailApis;
import com.zeroone.star.project.query.j7.outdetail.OutDetailExcelQuery;
import com.zeroone.star.project.query.j7.outdetail.OutDetailQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.http.ResponseEntity;
import org.springframework.validation.annotation.Validated;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import javax.annotation.Resource;
import java.util.List;

/**
 * <p>
 * 描述：出库明细接口实现
 * </p>
 *
 * @author chen
 * @since 2025/2/22 17:02
 */

@RestController
@RequestMapping("/out-detail/")
@Api(tags = "出库明细接口实现")
@Validated
public class OutDetailController implements OutDetailApis {

    @Resource
    IWmOmNoticeHService hService;

    @Resource
    EasyExcelComponent excel;

    @GetMapping("query-all")
    @ApiOperation("获取出库明细列表（条件+分页）")
    @Override
    public JsonVO<PageDTO<OutDetailDTO>> queryAll(@Validated OutDetailQuery detailQuery) {

        PageDTO<OutDetailDTO> pageDTO = hService.listAll(detailQuery);
        return JsonVO.success(pageDTO);
    }

    @GetMapping(value = "export-excel",produces = "application/octet-stream")
    @ApiOperation("导出数据")
    @Override
    public ResponseEntity<byte[]> exportExcel() {
        ResponseEntity<byte[]> responseEntity= hService.selectExcel();
        return responseEntity;
    }
}
