package com.zeroone.star.outgoodsmanage.controller;

import com.baomidou.mybatisplus.core.conditions.query.QueryWrapper;
import com.zeroone.star.outgoodsmanage.config.MatrixToImageWriter;
import com.zeroone.star.outgoodsmanage.entity.WmOmNoticeH;
import com.zeroone.star.outgoodsmanage.service.IWmOmNoticeHService;
import com.zeroone.star.outgoodsmanage.service.IWmOmNoticeIService;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.alibaba.excel.EasyExcel;
import com.alibaba.excel.ExcelWriter;
import com.alibaba.excel.support.ExcelTypeEnum;
import com.alibaba.excel.write.metadata.WriteSheet;
import com.alibaba.excel.write.metadata.style.WriteCellStyle;
import com.alibaba.excel.write.metadata.style.WriteFont;
import com.alibaba.excel.write.style.HorizontalCellStyleStrategy;
import com.google.zxing.BarcodeFormat;
import com.google.zxing.EncodeHintType;
import com.google.zxing.MultiFormatWriter;
import com.google.zxing.common.BitMatrix;
import com.google.zxing.oned.Code128Writer;
import com.zeroone.star.outgoodsmanage.entity.MdCus;
import com.zeroone.star.outgoodsmanage.service.IMdCusService;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j7.outmanage.*;
import com.zeroone.star.project.j7.outmanage.OutGoodsNoticeApis;
import com.zeroone.star.project.j7.outmanage.WmOmNoticeHApis;
import com.zeroone.star.project.query.j7.outbound.WonQuery;
import com.zeroone.star.project.query.j7.outnotice.OutGoodNoticeQuery;
import com.zeroone.star.project.vo.JsonVO;
import com.zeroone.star.project.vo.ResultStatus;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Value;
import org.apache.poi.ss.usermodel.*;
import org.apache.poi.ss.util.CellRangeAddress;
import org.apache.poi.xssf.streaming.SXSSFWorkbook;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;
import javax.annotation.Resource;
import javax.validation.constraints.NotNull;
import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;


/**
 * @Author: ayuan
 * @CreateTime: 2025-02-22
 * @Description:
 */

@RestController
@RequestMapping("/out-goods-manager/")
@Api(tags = "出库通知单管理相关接口")
@Slf4j
public class OutManageController implements WmOmNoticeHApis, OutGoodsNoticeApis {

    @Resource
    private IWmOmNoticeHService iWmOmNoticeHService;
    @Resource
    IMdCusService iMdCusService;
    @Resource
    IWmOmNoticeIService iWmOmNoticeIService;

    @Resource
    private FastDfsClientComponent dfs;

    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;

    /**
     * 获取出货通知单列表
     * @param outGoodNoticeQuery 条件查询对象
     * @return JsonVO<PageDTO<OutNoticeListDTO>>
     * @author cuofan
     */
    @Override
    @ApiOperation("获取出货通知单列表（条件+分页）")
    @GetMapping("query-out-notice-list")
    public JsonVO<PageDTO<OutNoticeListDTO>> getGoodsNoticeList(@NotNull OutGoodNoticeQuery outGoodNoticeQuery) {
        PageDTO<OutNoticeListDTO> date = iWmOmNoticeHService.getNoticeList( outGoodNoticeQuery);
        return JsonVO.success(date);
    }


    @Override
    @ApiOperation("获取出货通知单详细信息")
    @GetMapping("query-out-notice-item")
    public JsonVO<OutNoticeItemDTO> getGoodsItem(String omNoticeId) {
        OutNoticeItemDTO noticeItem = iWmOmNoticeIService.getNoticeItem(omNoticeId);
        if(noticeItem == null) {
            JsonVO<OutNoticeItemDTO> fail = JsonVO.fail(null);
            fail.setMessage("omNoticeId不存在");
            return fail;
        }else {
            return JsonVO.success(noticeItem);
        }
    }

    @SneakyThrows
    @Override
    @ApiOperation(value = "上传出库通知单附件",notes = "数据库附件格式: group:storageId")
    @PostMapping("add-upload-fu-jan/")
    public JsonVO<FileInfoDTO> uploadFuJan(@RequestParam("upFile") MultipartFile upFile, @RequestParam("omNoticeId")String omNoticeId) {
        String fileName = upFile.getOriginalFilename();
        QueryWrapper<WmOmNoticeH> wrapper = new QueryWrapper<>();
        WmOmNoticeH one = iWmOmNoticeHService.getOne(wrapper.eq("om_notice_id", omNoticeId));
        if (fileName == null) {
            return JsonVO.create(null,ResultStatus.PARAMS_INVALID);
        }
        if (one == null) {
            JsonVO<FileInfoDTO> fail = JsonVO.fail(null);
            fail.setMessage("出库通知单不存在！");
            return fail;
        }
        //获取文件扩展名
        String extName = fileName.substring(fileName.lastIndexOf(".") + 1);
        //上传文件，并获取文件资源信息。
        FastDfsFileInfo fileInfo = dfs.uploadFile(upFile.getBytes(), extName);
        if (fileInfo != null){
            //拼接附件资源信息
            String fuJian = fileInfo.getGroup() + ":" + fileInfo.getStorageId();
            //上传附件信息
            iWmOmNoticeHService.saveFujian(omNoticeId,fuJian);
            FileInfoDTO fileInfoDTO = new FileInfoDTO();
            fileInfoDTO.setFileName(fileName);
            fileInfoDTO.setGroup(fileInfo.getGroup());
            fileInfoDTO.setStoredId(fileInfo.getStorageId());
            return JsonVO.success(fileInfoDTO);
        }
        else {
            JsonVO<FileInfoDTO> fail = JsonVO.fail(null);
            fail.setMessage("文件上传服务器失败！");
            return fail;
        }
    }

    @Override
    @PostMapping("add-out-goods-notice")
    @ApiOperation(value = "录入出库通知单")
    public JsonVO<ResultStatus> addOutGoodsNotice(@RequestBody OutGoodsNoticeFormDTO outGoodsNoticeFormDTO) {
        if (iWmOmNoticeIService.saveOutGoodsNotice(outGoodsNoticeFormDTO)!=0) {
            return JsonVO.success(ResultStatus.SUCCESS);
        }
        return JsonVO.fail(ResultStatus.FAIL);
    }

    @Override
    @GetMapping(value = "query-picking-list",produces = "application/octet-stream")
    @ApiOperation(value = "打印拣货单")
    public ResponseEntity<byte[]> queryPickingList(@RequestParam String id) {


        ResponseEntity<byte[]> responseEntity = iWmOmNoticeHService.queryPickingList(id);
        return responseEntity;
    }

    @Override
    @GetMapping(value = "query-out-goods-list",produces = "application/octet-stream")
    @ApiOperation(value = "打印出库单")
    public ResponseEntity<byte[]> queryOutGoodsList(@RequestParam String id) {

        //TODO 打印出库单
        log.info("打印出库单: {}",id);
        ResponseEntity<byte[]> responseEntity = iWmOmNoticeHService.queryOutGoodsList(id);
        return responseEntity;
    }

    @Override
    @ApiOperation("导出出货通知excel表")
    @GetMapping(value = "export-h", produces = "application/octet-stream")
    public ResponseEntity<byte[]> queryWonh(WonQuery query) throws IOException {
        WmOmNoticeH wmOmNoticeH = iWmOmNoticeHService.queryByOmId(query);
        MdCus mdCus = iMdCusService.queryByOmId(query);
        List<WonhGoodsDTO> wonhGoodsDTOS = iWmOmNoticeIService.queryByOmId(query);

        // 1. 创建Code128编码器
        Code128Writer barcodeWriter = new Code128Writer();
        List<byte[]> barcode=new ArrayList<>();
        for (int i = 0; i < wonhGoodsDTOS.size(); i++) {
            wonhGoodsDTOS.get(i).setId(String.valueOf(i+1));
            BitMatrix bitMatrix = barcodeWriter.encode(
                    wonhGoodsDTOS.get(i).getGoodsId(),
                    BarcodeFormat.CODE_128,
                    183,
                    67
            );
            // 3. 将位矩阵转换为BufferedImage对象
            BufferedImage bufferedImage = MatrixToImageWriter.toBufferedImage(bitMatrix);

            // 4. 将图像写入字节输出流（PNG格式）
            ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
            ImageIO.write(bufferedImage, "png", outputStream);

            barcode.add(i,outputStream.toByteArray());
        }
        // 2. 创建内存中的Excel模板（使用POI生成复杂表头）
        ByteArrayOutputStream templateOutputStream = new ByteArrayOutputStream();
        try (Workbook workbook = new XSSFWorkbook()) {
            Sheet sheet = workbook.createSheet("出货通知");
            //合并单元格
            sheet.addMergedRegion(new CellRangeAddress(1, 1, 0, 8));
            sheet.addMergedRegion(new CellRangeAddress(2, 2, 0, 8));
            sheet.addMergedRegion(new CellRangeAddress(3, 3, 0, 4));
            sheet.addMergedRegion(new CellRangeAddress(3, 3, 5, 8));
            sheet.addMergedRegion(new CellRangeAddress(4, 4, 0, 4));
            sheet.addMergedRegion(new CellRangeAddress(4, 4, 5, 8));
            sheet.addMergedRegion(new CellRangeAddress(5, 5, 0, 4));
            sheet.addMergedRegion(new CellRangeAddress(5, 5, 5, 8));
            //设置列宽
            sheet.setColumnWidth(0, (int) (4.36*256));
            sheet.setColumnWidth(1, (int) (9.36 * 256));
            sheet.setColumnWidth(2, (int) (7.18 * 256));
            sheet.setColumnWidth(8, (int) (25.33 * 256));

            //设置头居中样式
            CellStyle cellStyle = workbook.createCellStyle();
            cellStyle.setAlignment(HorizontalAlignment.CENTER);
            cellStyle.setVerticalAlignment(VerticalAlignment.CENTER);
            //设置头字体
            Font font = workbook.createFont();
            font.setFontName("Arial");
            font.setFontHeightInPoints((short) 16);
            font.setBold(true);
            cellStyle.setFont(font);
            //设置正文样式
            CellStyle body= workbook.createCellStyle();
            body.setVerticalAlignment(VerticalAlignment.BOTTOM);
            //设置正文字体
            Font fontBody = workbook.createFont();
            fontBody.setFontName("Arial");
            fontBody.setFontHeightInPoints((short) 10);
            body.setFont(fontBody);
            BitMatrix bitMatrix = barcodeWriter.encode(
                    wmOmNoticeH.getOmNoticeId(),
                    BarcodeFormat.CODE_128,
                    180,
                    45
            );
            // 3. 将位矩阵转换为BufferedImage对象
            BufferedImage bufferedImage = MatrixToImageWriter.toBufferedImage(bitMatrix);
            // 4. 将图像写入字节输出流（PNG格式）
            ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
            ImageIO.write(bufferedImage, "png", outputStream);
            byte[] byteBareCode = outputStream.toByteArray();
            // 4. 设置图像插入位置（锚点）
            CreationHelper helper = workbook.getCreationHelper();
            ClientAnchor anchor = helper.createClientAnchor();
            anchor.setCol1(8);  // 起始列
            anchor.setRow1(1);  // 起始行
            // 5. 将图像添加到工作簿并获取索引
            int pictureIdx = workbook.addPicture(
                    byteBareCode,
                    Workbook.PICTURE_TYPE_PNG  // 指定图像格式
            );
            // 6. 在指定位置插入图像
            Drawing<?> drawing = sheet.createDrawingPatriarch();  // 获取绘图容器
            Picture pict = drawing.createPicture(anchor, pictureIdx);  // 绑定锚点和图像
            pict.resize();
            //(1,0)
            Row headRow=sheet.createRow(1);
            headRow.setHeightInPoints(35);
            Cell head = headRow.createCell(0);
            head.setCellValue("仓储管理系统出货通知");
            head.setCellStyle(cellStyle);
            //(2,0)
            Row noticeNumberRow=sheet.createRow(2);
            Cell noticeNumberCell = noticeNumberRow.createCell(0);
            noticeNumberCell.setCellValue("通知单号: "+wmOmNoticeH.getOmNoticeId());
            noticeNumberCell.setCellStyle(body);
            //(3,0)
            Row customerRow=sheet.createRow(3);
            Cell customerCell = customerRow.createCell(0);
            customerCell.setCellValue("客户: "+wmOmNoticeH.getCusCode()+"-"+mdCus.getZhongWenQch());
            customerCell.setCellStyle(body);
            //(3,5)
            Cell plannedTimeCell = customerRow.createCell(5);
            plannedTimeCell.setCellValue("计划出货时间: "+wmOmNoticeH.getDelvData());
            plannedTimeCell.setCellStyle(body);
            //(4,0)
            Row driverRow=sheet.createRow(4);
            Cell driverCell = driverRow.createCell(0);
            driverCell.setCellValue("司机: "+wmOmNoticeH.getReMember()+" 司机电话: "+wmOmNoticeH.getReMobile());
            driverCell.setCellStyle(body);
            //(4,5)
            Cell wagonNumCell = driverRow.createCell(5);
            wagonNumCell.setCellValue("车号: "+wmOmNoticeH.getReCarno()+" 备注: "+wmOmNoticeH.getOmBeizhu());
            wagonNumCell.setCellStyle(body);
            //(5,0)
            Row receiverRow=sheet.createRow(5);
            Cell receiverCell = receiverRow.createCell(0);
            receiverCell.setCellValue("收货人: "+wmOmNoticeH.getDelvMember()+" 电话: "+wmOmNoticeH.getDelvMobile());
            receiverCell.setCellStyle(body);
            //(5,5)
            Cell receiveAddressCell = receiverRow.createCell(5);
            receiveAddressCell.setCellValue("收货地址: "+wmOmNoticeH.getDelvAddr() );
            receiveAddressCell.setCellStyle(body);
            //写入
            workbook.write(templateOutputStream);
        }
        // 2. 使用EasyExcel写入动态数据到模板
        ByteArrayOutputStream easyExcelOutputStream = new ByteArrayOutputStream();
        try (InputStream templateInputStream = new ByteArrayInputStream(templateOutputStream.toByteArray())) {
            // 创建统一边框样式
            WriteCellStyle contentWriteCellStyle = new WriteCellStyle();
            // 设置所有边框为单线
            contentWriteCellStyle.setBorderLeft(BorderStyle.THIN);
            contentWriteCellStyle.setBorderRight(BorderStyle.THIN);
            contentWriteCellStyle.setBorderTop(BorderStyle.THIN);
            contentWriteCellStyle.setBorderBottom(BorderStyle.THIN);
            // 去除灰色背景（设置为无填充）
            contentWriteCellStyle.setFillPatternType(FillPatternType.NO_FILL);
            // 创建通用字体样式（不加粗）
            WriteFont unifiedFont = new WriteFont();
            unifiedFont.setBold(false);  // 关键：去除加粗
            unifiedFont.setFontName("Arial");
            unifiedFont.setFontHeightInPoints((short) 10);
            contentWriteCellStyle.setWriteFont(unifiedFont);
            // 创建样式策略（表头和内容共用同一样式）
            HorizontalCellStyleStrategy styleStrategy = new HorizontalCellStyleStrategy(
                    contentWriteCellStyle, // 表头样式
                    contentWriteCellStyle // 内容样式
            );
            ExcelWriter excelWriter = EasyExcel.write(easyExcelOutputStream)
                    .withTemplate(templateInputStream)
                    .excelType(ExcelTypeEnum.XLSX)
                    .registerWriteHandler(styleStrategy)
                    .build();
            WriteSheet writeSheet = EasyExcel.writerSheet("出货通知")
                    .relativeHeadRowIndex(0)
                    .head(WonhGoodsDTO.class)
                    .build();
            excelWriter.write(wonhGoodsDTOS, writeSheet);
            excelWriter.finish();
        }

        // 3. 后处理：插入备注行到动态数据之后
        ByteArrayOutputStream finalOutputStream = new ByteArrayOutputStream();
        try (InputStream processedInputStream = new ByteArrayInputStream(easyExcelOutputStream.toByteArray());
             Workbook workbook = new XSSFWorkbook(processedInputStream)) {
            Sheet sheet = workbook.getSheet("出货通知");
            int dataStartRow = 7;
            int dataRowCount = wonhGoodsDTOS.size();
            int lastDataRow = dataStartRow + dataRowCount;
            // 创建备注行
            Row attentionRow = sheet.createRow(lastDataRow + 1);
            Cell attentionCell = attentionRow.createCell(0);
            attentionCell.setCellValue("注:烦请按时到厂内 谢谢！");
            //条码
            for (int i = 0; i < wonhGoodsDTOS.size(); i++) {
                //行高
                sheet.getRow(7+i).setHeightInPoints(50);
                // 4. 设置图像插入位置（锚点）
                CreationHelper helper = workbook.getCreationHelper();
                ClientAnchor anchor = helper.createClientAnchor();
                anchor.setCol1(8);  // 起始列
                anchor.setRow1(7+i);  // 起始行
                // 5. 将图像添加到工作簿并获取索引
                int pictureIdx = workbook.addPicture(
                        barcode.get(i),
                        Workbook.PICTURE_TYPE_PNG  // 指定图像格式
                );
                // 6. 在指定位置插入图像
                Drawing<?> drawing = sheet.createDrawingPatriarch();  // 获取绘图容器
                Picture pict = drawing.createPicture(anchor, pictureIdx);  // 绑定锚点和图像
                pict.resize();  // 自动调整图像大小以适配锚点区域
            }
            // 设置备注行样式
            CellStyle body = workbook.createCellStyle();
            body.setVerticalAlignment(VerticalAlignment.BOTTOM);
            Font fontBody = workbook.createFont();
            fontBody.setFontName("Arial");
            fontBody.setFontHeightInPoints((short) 10);
            body.setFont(fontBody);
            attentionCell.setCellStyle(body);

            // 保存修改后的Excel
            workbook.write(finalOutputStream);
        }
        // 响应文件数据
        String filename = query.getOmNoticeId() + ".xlsx";
        HttpHeaders headers = new HttpHeaders();
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.parseMediaType("application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"));
        ResponseEntity<byte[]> result = new ResponseEntity<>(finalOutputStream.toByteArray(), headers, HttpStatus.CREATED);
        finalOutputStream.close();
        return result;
    }

    @SneakyThrows
    @Override
    @ApiOperation("导出出库单excel表")
    @GetMapping(value = "export-i", produces = "application/octet-stream")
    public ResponseEntity<byte[]> queryWoni(WonQuery query) throws IOException{
        WmOmNoticeH wmOmNoticeH = iWmOmNoticeHService.queryByOmId(query);
        MdCus mdCus = iMdCusService.queryByOmId(query);
        List<WoniGoodsDTO> woniGoodsDTOS = iWmOmNoticeIService.queryByOmIdToI(query);
        for (int i = 0; i < woniGoodsDTOS.size(); i++) {
            woniGoodsDTOS.get(i).setId(String.valueOf(i+1));
        }
        int length=woniGoodsDTOS.size()-1;
        // 2. 创建内存中的Excel模板（使用POI生成复杂表头）
        ByteArrayOutputStream templateOutputStream = new ByteArrayOutputStream();
        try (Workbook workbook = new SXSSFWorkbook(100)) {
            Sheet sheet = workbook.createSheet("出库单");
            //合并单元格
            sheet.addMergedRegion(new CellRangeAddress(1, 1, 0, 8));
            sheet.addMergedRegion(new CellRangeAddress(2, 2, 0, 9));
            sheet.addMergedRegion(new CellRangeAddress(3, 3, 0, 9));
            sheet.addMergedRegion(new CellRangeAddress(4, 4, 0, 2));
            sheet.addMergedRegion(new CellRangeAddress(4, 4, 3, 9));
            sheet.addMergedRegion(new CellRangeAddress(5, 5, 0, 2));
            sheet.addMergedRegion(new CellRangeAddress(5, 5, 3, 9));
            sheet.addMergedRegion(new CellRangeAddress(6, 6, 0, 2));
            sheet.addMergedRegion(new CellRangeAddress(6, 6, 3, 9));
            sheet.addMergedRegion(new CellRangeAddress(7, 7, 0, 4));
            sheet.addMergedRegion(new CellRangeAddress(7, 7, 5, 9));
            sheet.addMergedRegion(new CellRangeAddress(length+10, length+10, 0, 4));
            sheet.addMergedRegion(new CellRangeAddress(length+11, length+11, 0, 9));
            sheet.addMergedRegion(new CellRangeAddress(length+12, length+12, 0, 9));
            sheet.addMergedRegion(new CellRangeAddress(0, 19, 10, 10));
            //设置列宽
            sheet.setColumnWidth(0, (int) (4.36*256));
            sheet.setColumnWidth(1, (int) (14.36*256));
            sheet.setColumnWidth(2, (int) (24.36 * 256));
            sheet.setColumnWidth(3, (int) (10.36 * 256));
            sheet.setColumnWidth(4, (int) (4.36 * 256));
            sheet.setColumnWidth(5, (int) (4.36 * 256));
            sheet.setColumnWidth(6, (int) (6.36 * 256));
            sheet.setColumnWidth(7, (int) (6.36 * 256));
            sheet.setColumnWidth(8, (int) (8.36 * 256));
            sheet.setColumnWidth(9, (int) (6.36 * 256));
            sheet.setColumnWidth(10, (int) (2.36 * 256));
            //设置头居中样式
            CellStyle cellStyle = workbook.createCellStyle();
            cellStyle.setAlignment(HorizontalAlignment.CENTER);
            cellStyle.setVerticalAlignment(VerticalAlignment.CENTER);
            //设置头字体
            Font font = workbook.createFont();
            font.setFontName("Arial");
            font.setFontHeightInPoints((short) 16);
            font.setBold(true);
            cellStyle.setFont(font);
            //设置正文样式
            CellStyle body= workbook.createCellStyle();
            body.setVerticalAlignment(VerticalAlignment.BOTTOM);
            CellStyle center=workbook.createCellStyle();
            center.setAlignment(HorizontalAlignment.CENTER);
            CellStyle right=workbook.createCellStyle();
            right.setAlignment(HorizontalAlignment.RIGHT);
            //设置正文字体
            Font fontBody = workbook.createFont();
            fontBody.setFontName("Arial");
            fontBody.setFontHeightInPoints((short) 10);
            body.setFont(fontBody);
            center.setFont(fontBody);
            right.setFont(fontBody);
            //二维码生成
            Map<EncodeHintType, Object> hints = new HashMap<>();
            hints.put(EncodeHintType.CHARACTER_SET, "UTF-8");
            hints.put(EncodeHintType.MARGIN, 1); // 设置边距
            // 生成BitMatrix
            BitMatrix bitMatrix = new MultiFormatWriter().encode(
                    wmOmNoticeH.getOmNoticeId(),
                    BarcodeFormat.QR_CODE,
                    100,
                    100,
                    hints
            );
            // 转换为BufferedImage
            BufferedImage bufferedImage = MatrixToImageWriter.toBufferedImage(bitMatrix);
            // 写入字节流
            ByteArrayOutputStream outputStream = new ByteArrayOutputStream();
            ImageIO.write(bufferedImage, "png", outputStream);
            byte[] qrCodeBytes=outputStream.toByteArray();
            // 创建绘图工具
            CreationHelper helper = workbook.getCreationHelper();
            Drawing<?> drawing = sheet.createDrawingPatriarch();
            // 设置图片插入位置
            ClientAnchor anchor = helper.createClientAnchor();
            anchor.setCol1(8); // 起始列（A列）
            anchor.setRow1(1); // 起始行（第1行）
            // 插入图片
            int pictureIdx = workbook.addPicture(qrCodeBytes, Workbook.PICTURE_TYPE_PNG);
            Picture picture = drawing.createPicture(anchor, pictureIdx);
            picture.resize(); // 自动缩放图片到单元格
            //(1,0)
            Row headRow=sheet.createRow(1);
            Cell head = headRow.createCell(0);
            head.setCellValue("仓储管理系统出库单");
            head.setCellStyle(cellStyle);
            //(2,0)
            Row companyAddRow=sheet.createRow(2);
            Cell companyAddCell = companyAddRow.createCell(0);
            companyAddCell.setCellValue("公司地址: 厂内");
            companyAddCell.setCellStyle(center);
            //(3,0)
            Row phoneRow=sheet.createRow(3);
            Cell phoneCell = phoneRow.createCell(0);
            phoneCell.setCellValue("电话: 详询客服");
            phoneCell.setCellStyle(center);
            //(4,0)
            Row outDateRow=sheet.createRow(4);
            Cell outDateCell = outDateRow.createCell(0);
            outDateCell.setCellValue("出库日期: "+wmOmNoticeH.getDelvData().format(DateTimeFormatter.ofPattern("yyyy-MM-dd")));
            outDateCell.setCellStyle(body);
            //(4,3)
            Cell outBoudCell = outDateRow.createCell(3);
            outBoudCell.setCellValue("出库单号: "+wmOmNoticeH.getOmNoticeId());
            outBoudCell.setCellStyle(body);
            //(5,0)
            Row cunNumRow=sheet.createRow(5);
            Cell cunNumCell = cunNumRow.createCell(0);
            cunNumCell.setCellValue("客户单号: "+wmOmNoticeH.getOcusCode());
            cunNumCell.setCellStyle(body);
            //(5,3)
            Cell wagonNumCell = cunNumRow.createCell(3);
            wagonNumCell.setCellValue("车号: "+wmOmNoticeH.getReCarno());
            wagonNumCell.setCellStyle(body);
            //(6,0)
            Row cunNameRow=sheet.createRow(6);
            Cell cusNameCell = cunNameRow.createCell(0);
            cusNameCell.setCellValue("客户名称: "+wmOmNoticeH.getCusCode()+"-"+mdCus.getZhongWenQch());
            cusNameCell.setCellStyle(body);
            //(6,3)
            Cell receiverCell = cunNameRow.createCell(3);
            receiverCell.setCellValue("收货人: "+wmOmNoticeH.getDelvMember()+" 电话: "+wmOmNoticeH.getDelvMobile());
            receiverCell.setCellStyle(body);
            //(7,0)
            Row receiveAddRow=sheet.createRow(7);
            Cell receiveAddCell = receiveAddRow.createCell(0);
            receiveAddCell.setCellValue("收货地址: "+wmOmNoticeH.getDelvAddr());
            receiveAddCell.setCellStyle(body);
            //(7,5)
            Cell printDateCell = receiveAddRow.createCell(5);
            printDateCell.setCellValue("打印时间: "+ LocalDateTime.now().format(DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"))+" 第1页  ");
            printDateCell.setCellStyle(right);
            //写入
            workbook.write(templateOutputStream);
        }
        // 2. 使用EasyExcel写入动态数据到模板
        ByteArrayOutputStream easyExcelOutputStream = new ByteArrayOutputStream();
        try (InputStream templateInputStream = new ByteArrayInputStream(templateOutputStream.toByteArray())) {
            // 创建统一边框样式
            WriteCellStyle contentWriteCellStyle = new WriteCellStyle();
            // 设置所有边框为单线
            contentWriteCellStyle.setBorderLeft(BorderStyle.THIN);
            contentWriteCellStyle.setBorderRight(BorderStyle.THIN);
            contentWriteCellStyle.setBorderTop(BorderStyle.THIN);
            contentWriteCellStyle.setBorderBottom(BorderStyle.THIN);
            // 去除灰色背景（设置为无填充）
            contentWriteCellStyle.setFillPatternType(FillPatternType.NO_FILL);
            // 创建通用字体样式（不加粗）
            WriteFont unifiedFont = new WriteFont();
            unifiedFont.setBold(false);  // 关键：去除加粗
            unifiedFont.setFontName("Arial");
            unifiedFont.setFontHeightInPoints((short) 10);
            contentWriteCellStyle.setWriteFont(unifiedFont);
            // 创建样式策略（表头和内容共用同一样式）
            HorizontalCellStyleStrategy styleStrategy = new HorizontalCellStyleStrategy(
                    contentWriteCellStyle, // 表头样式
                    contentWriteCellStyle // 内容样式
            );
            ExcelWriter excelWriter = EasyExcel.write(easyExcelOutputStream)
                    .withTemplate(templateInputStream)
                    .excelType(ExcelTypeEnum.XLSX)
                    .registerWriteHandler(styleStrategy)
                    .build();
            WriteSheet writeSheet = EasyExcel.writerSheet("出库单")
                    .relativeHeadRowIndex(0)
                    .head(WoniGoodsDTO.class)
                    .build();
            excelWriter.write(woniGoodsDTOS, writeSheet);
            excelWriter.finish();
        }
        // 3. 后处理：插入到动态数据之后
        ByteArrayOutputStream finalOutputStream = new ByteArrayOutputStream();
        try (InputStream processedInputStream = new ByteArrayInputStream(easyExcelOutputStream.toByteArray());
             Workbook workbook = new XSSFWorkbook(processedInputStream)) {
            Sheet sheet = workbook.getSheet("出库单");
            int dataStartRow = 9;
            int dataRowCount = woniGoodsDTOS.size();
            int lastDataRow = dataStartRow + dataRowCount;
            //计算
            int startRow = 9;
            int startNum = 5;
            int startSplittingNum = 6;
            int startGrossWeight = 7;
            double sum5 = 0;
            double sum6 = 0;
            double sum7 = 0;
            for (int rowNum = startRow; rowNum < woniGoodsDTOS.size()+9; rowNum++) {
                Row row = sheet.getRow(rowNum);
                if (row != null) {
                    Cell cell5 = row.getCell(startNum);
                    Cell cell6 = row.getCell(startSplittingNum);
                    Cell cell7 = row.getCell(startGrossWeight);
                    if (cell5 != null && !cell6.getStringCellValue().isEmpty() && cell5.getCellType() == CellType.STRING ) {
                        sum5 += Double.parseDouble(cell5.getStringCellValue());
                    }
                    if (cell6 != null && !cell6.getStringCellValue().isEmpty() && cell6.getCellType() == CellType.STRING) {
                        sum6 += Double.parseDouble(cell6.getStringCellValue());
                    }
                    if (cell7 != null && !cell7.getStringCellValue().isEmpty() && cell7.getCellType() == CellType.STRING) {
                        sum7 += Double.parseDouble(cell7.getStringCellValue());
                    }
                }
            }
            // 设置行样式
            CellStyle body = workbook.createCellStyle();
            body.setVerticalAlignment(VerticalAlignment.BOTTOM);
            Font fontBody = workbook.createFont();
            fontBody.setFontName("Arial");
            fontBody.setFontHeightInPoints((short) 10);
            body.setFont(fontBody);
            //竖向
            CellStyle vertical = workbook.createCellStyle();
            vertical.setRotation((short) 255);
            Font fontVertical = workbook.createFont();
            fontVertical.setFontName("Arial");
            fontVertical.setFontHeightInPoints((short) 8);
            vertical.setFont(fontVertical);
            //(n,0)
            Row amoutRow = sheet.createRow(lastDataRow);
            Cell amoutCell = amoutRow.createCell(0);
            amoutCell.setCellValue("合计:");
            amoutCell.setCellStyle(body);
            //(n,5)
            Cell amoutCell5 = amoutRow.createCell(5);
            amoutCell5.setCellValue(sum5);
            amoutCell5.setCellStyle(body);
            //(n,6)
            Cell amoutCell6 = amoutRow.createCell(6);
            amoutCell6.setCellValue(sum6);
            amoutCell6.setCellStyle(body);
            //(n,7)
            Cell amoutCell7 = amoutRow.createCell(7);
            amoutCell7.setCellValue(sum7);
            amoutCell7.setCellStyle(body);
            //(n+1,0)
            Row verify1Row=sheet.createRow(lastDataRow+1);
            Cell verify1Cell = verify1Row.createCell(0);
            verify1Cell.setCellValue("  发货人员: " +
                    "                              " +
                    "配送司机:" +
                    "                              " +
                    "收货人员:");
            verify1Cell.setCellStyle(body);
            //(n+2,0)
            Row verify2Row=sheet.createRow(lastDataRow+2);
            Cell verify2Cell = verify2Row.createCell(0);
            verify2Cell.setCellValue("  发货时间: " +
                    "                              " +
                    "收货时间:" +
                    "                              " +
                    "收货单位盖章:");
            verify2Cell.setCellStyle(body);
            //(0,10)
            Row row0=sheet.createRow(0);
            Cell verticalCell = row0.createCell(10);
            verticalCell.setCellValue("① 财务联  ② 客户联  ③司机联  ④回单联");
            verticalCell.setCellStyle(vertical);
            // 保存修改后的Excel
            workbook.write(finalOutputStream);
        }
        // 响应文件数据
        String filename = query.getOmNoticeId() + ".xlsx";
        HttpHeaders headers = new HttpHeaders();
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.parseMediaType("application/vnd.openxmlformats-officedocument.spreadsheetml.sheet"));
        ResponseEntity<byte[]> result = new ResponseEntity<>(finalOutputStream.toByteArray(), headers, HttpStatus.CREATED);
        finalOutputStream.close();
        return result;
    }

    @Override
    @ApiOperation("修改出货通知表")
    @PutMapping("modify-query")
    public JsonVO<String> modifyWonh(WonhDTO modify) {
        return JsonVO.success(iWmOmNoticeHService.updateById(modify));
    }

    @PostMapping("remove")
    @ApiOperation(value = "根据id删除出库通知单")
    @Override
    public JsonVO<Long> removeNoticeH(Long id) {
        if(id == null) {
            log.error("id不能为空");
            return JsonVO.fail(null);
        }
        Long isdelete = iWmOmNoticeHService.removeNoticeH(id);
        return JsonVO.success(isdelete);
    }
}
