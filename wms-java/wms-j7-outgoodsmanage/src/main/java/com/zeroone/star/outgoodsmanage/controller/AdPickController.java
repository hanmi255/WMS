package com.zeroone.star.outgoodsmanage.controller;

import com.alibaba.excel.EasyExcel;
import com.alibaba.excel.ExcelWriter;
import com.alibaba.excel.write.metadata.WriteSheet;
import com.alibaba.excel.write.metadata.style.WriteCellStyle;
import com.alibaba.excel.write.style.HorizontalCellStyleStrategy;
import com.zeroone.star.outgoodsmanage.service.IWmToDownGoodsService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.adpick.*;
import com.zeroone.star.project.dto.j7.ycoutbound.YcOutBoundDTO;
import com.zeroone.star.project.j7.adpick.AnDanPickApis;
import com.zeroone.star.project.query.j7.adpick.AdPickQuery;
import com.zeroone.star.project.query.j7.ycoutbound.YcOutBoundQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.j7.adPick.AdPickDeatilVO;
import com.zeroone.star.project.vo.j7.adPick.AdPickVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import org.apache.poi.ss.usermodel.*;
import org.apache.poi.ss.util.CellRangeAddress;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpHeaders;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.InputStream;
import java.net.URLEncoder;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.util.List;

/**
 * @author 阿晨
 * @since 2025 2-25
 */
@RestController
@RequestMapping("/adpick/")
@Api(tags = "按单拣货接口实现")
public class AdPickController implements AnDanPickApis {
    @Autowired
    private IWmToDownGoodsService wmToDownGoodsService;


    @GetMapping("query-all")
    @ApiOperation("获取拣货明细列表（条件+分页）")
    @Override
    public JsonVO<PageDTO<AdPickVO>> queryAllAnDanPickApis(AdPickPageDTO adPickPageDTO) {
        return wmToDownGoodsService.selectPage(adPickPageDTO);
    }


    @GetMapping("query-one")
    @ApiOperation("获取拣货详细信息（单个查询）")
    @Override
    public JsonVO<AdPickDeatilVO> queryOneAnDanPickApis(String id) {
        return wmToDownGoodsService.setectOneDeatil(id);
    }

    @PostMapping("modify")
    @ApiOperation("修改拣货")
    @Override
    public JsonVO<String> modify(@RequestBody AdPickModifyDTO adPickModifyDTO) {
        if(adPickModifyDTO == null || adPickModifyDTO.getGoodsName() == null || adPickModifyDTO.getImCusCode() == null) {
            return JsonVO.fail("客户订单号不能为空 or 商品名称不能为空");
        }
        // 调用服务层方法
        return wmToDownGoodsService.modifyAdPick(adPickModifyDTO)
                ? JsonVO.success("修改拣货成功") : JsonVO.fail("修改拣货失败");
    }

    @PostMapping("modify-list")
    @ApiOperation("批量修改拣货")
    @Override
    public JsonVO<String> modifyList(@RequestBody List<AdPickModifyBaseDTO> adPickModifyBaseDTOs) {
        return wmToDownGoodsService.modifyAdPickList(adPickModifyBaseDTOs)
                ? JsonVO.success("批量修改拣货成功") : JsonVO.fail("批量修改拣货失败");
    }

    @Override
    @SneakyThrows
    @PostMapping(value = "export-excel", produces = "application/octet-stream")
    @ApiOperation("导出按单拣货Excel")
    public ResponseEntity<byte[]> exportExcel(@RequestBody List<AdPickQuery> queries) {
        // 1. 根据查询条件获取数据
        List<AdPickExportDTO> dataList = wmToDownGoodsService.queryExportData(queries);
        // 2. 创建Excel
        ByteArrayOutputStream templateStream = new ByteArrayOutputStream();
        try (Workbook workbook = new XSSFWorkbook()) {
            Sheet sheet = workbook.createSheet("出库任务列表");
            // 2.1 合并单元格
            sheet.addMergedRegion(new CellRangeAddress(0, 0, 0, 19)); // 主标题
            sheet.addMergedRegion(new CellRangeAddress(1, 1, 0, 19)); // 导出信息
            // 2.2 列宽配置（单位：1/256字符宽度）
            int[] colWidths = {18, 20, 35, 12, 12, 22, 22, 15, 10, 15,
                    12, 15, 18, 18, 15, 12, 12, 18, 18, 35};
            for (int i = 0; i < colWidths.length; i++) {
                sheet.setColumnWidth(i, colWidths[i] * 256);
            }
            // 2.3 样式创建
            CellStyle titleStyle = createTitleStyle(workbook);
            CellStyle infoStyle = createInfoStyle(workbook);
            // 2.4 构建表头
            // 主标题行
            Row titleRow = sheet.createRow(0);
            Cell titleCell = titleRow.createCell(0);
            titleCell.setCellValue("出库任务明细表");
            titleCell.setCellStyle(titleStyle);
            // 导出信息行
            Row infoRow = sheet.createRow(1);
            Cell infoCell = infoRow.createCell(0);
            infoCell.setCellValue("导出时间: " + LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm")));
            infoCell.setCellStyle(infoStyle);
            workbook.write(templateStream);
        }
        // 3. EasyExcel数据填充
        ByteArrayOutputStream finalStream = new ByteArrayOutputStream();
        try (InputStream templateInput = new ByteArrayInputStream(templateStream.toByteArray())) {
            // 3.1 样式策略
            WriteCellStyle contentStyle = new WriteCellStyle();
            contentStyle.setBorderLeft(BorderStyle.THIN);
            contentStyle.setBorderRight(BorderStyle.THIN);
            contentStyle.setBorderTop(BorderStyle.THIN);
            contentStyle.setBorderBottom(BorderStyle.THIN);
            contentStyle.setVerticalAlignment(VerticalAlignment.CENTER);
            contentStyle.setWrapped(true); // 自动换行
            HorizontalCellStyleStrategy styleStrategy = new HorizontalCellStyleStrategy(null, contentStyle);
            // 3.3 写入数据
            ExcelWriter excelWriter = EasyExcel.write(finalStream)
                    .withTemplate(templateInput)
                    .registerWriteHandler(styleStrategy)
                    .build();
            WriteSheet writeSheet = EasyExcel.writerSheet()
                    .head(AdPickExportDTO.class)
                    .relativeHeadRowIndex(0)
                    .build();
            excelWriter.write(dataList, writeSheet);
            excelWriter.finish();
        }
        String fileName = URLEncoder.encode("出库任务列表.xlsx", "UTF-8");
        return ResponseEntity.ok()
                .header(HttpHeaders.CONTENT_DISPOSITION, "attachment; filename*=UTF-8''" + fileName)
                .contentType(MediaType.APPLICATION_OCTET_STREAM)
                .body(finalStream.toByteArray());
    }
    private CellStyle createTitleStyle(Workbook workbook) {
        CellStyle style = workbook.createCellStyle();
        style.setAlignment(HorizontalAlignment.CENTER);
        style.setVerticalAlignment(VerticalAlignment.CENTER);
        style.setFillForegroundColor(IndexedColors.GREY_25_PERCENT.getIndex());
        style.setFillPattern(FillPatternType.SOLID_FOREGROUND);
        Font font = workbook.createFont();
        font.setFontName("微软雅黑");
        font.setFontHeightInPoints((short) 18);
        font.setBold(true);
        style.setFont(font);
        return style;
    }
    private CellStyle createInfoStyle(Workbook workbook) {
        CellStyle style = workbook.createCellStyle();
        Font font = workbook.createFont();
        font.setColor(IndexedColors.DARK_BLUE.getIndex());
        font.setItalic(true);
        style.setFont(font);
        return style;
    }
}
