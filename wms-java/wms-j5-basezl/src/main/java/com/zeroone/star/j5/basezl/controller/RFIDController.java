package com.zeroone.star.j5.basezl.controller;

import cn.hutool.core.date.DateTime;
import com.zeroone.star.j5.basezl.entity.rfid.RfidBuseExcelDO;
import com.zeroone.star.j5.basezl.service.RFIDService;
import com.zeroone.star.project.components.easyexcel.EasyExcelComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsClientComponent;
import com.zeroone.star.project.components.fastdfs.FastDfsFileInfo;
import com.zeroone.star.project.dto.PageDTO;
import com.zeroone.star.project.dto.j5.basezl.rfid.RFIDAddDTO;
import com.zeroone.star.project.dto.j5.basezl.rfid.RFIDDetailDTO;
import com.zeroone.star.project.dto.j5.basezl.rfid.RFIDListDTO;
import com.zeroone.star.project.dto.j5.basezl.rfid.RFIDModifyDTO;

import com.zeroone.star.project.j5.basezl.RFIDApis;
import com.zeroone.star.project.query.j5.basezl.rfid.RFIDQuery;
import com.zeroone.star.project.vo.JsonVO;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import lombok.SneakyThrows;
import lombok.extern.slf4j.Slf4j;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.annotation.Resource;
import java.io.ByteArrayOutputStream;
import java.util.List;

/**
 * 功能：RFIDController类
 * 作者：叶子
 * 日期：2025/2/22 18:07
 */
//负责接收请求、‌验证输入、‌调用Service层处理业务逻辑，‌并将结果返回给前端
@Slf4j
@RestController
@RequestMapping("/rfid")
@Api(tags = "RFID接口实现")
public class RFIDController implements RFIDApis {
    @Resource
    FastDfsClientComponent dfs;

    @Value("${fastdfs.nginx-servers}")
    private String fileServerUrl;

    @Autowired
    private RFIDService rfidService;
    @GetMapping("query-all")
    @ApiOperation("RFID列表查询接口")
    public JsonVO<PageDTO<RFIDListDTO>> queryRFIDAll(RFIDQuery rfidQuery) {
        return JsonVO.success(rfidService.queryRFIDAll(rfidQuery));
    }


    @GetMapping("query-one")
    @ApiOperation("RFID详情查询接口")
    public JsonVO<RFIDDetailDTO> queryRFIDDetail(String rfid) {
        return JsonVO.success(rfidService.queryRFIDDetail(rfid));
    }


    @PostMapping("add-rfid")
    @ApiOperation("RFID新增信息接口")
    public JsonVO<String> addRfid(@RequestBody RFIDAddDTO rfidAddDTO) {
        return JsonVO.success(rfidService.addRfid(rfidAddDTO));
    }


    @PutMapping("modify-rfid")
    @ApiOperation("修改RFID信息")
    public JsonVO<String> modifyRfid(@RequestBody RFIDModifyDTO rfidModifyDTO) {

        return JsonVO.success(rfidService.modifyRfid(rfidModifyDTO));
    }

    @DeleteMapping("delete-rfid")
    @ApiOperation("批量删除RFID")
    public JsonVO<String> deleteRfid(@RequestParam List<Long> rfidList) {
        rfidService.deleteRfid(rfidList);
        return JsonVO.success(null);
    }

    @SneakyThrows
        @ApiOperation(value = "导入RFID")
        @PostMapping("upload")
        public JsonVO<String> uploadFile(MultipartFile file) {
            String filename = file.getOriginalFilename();
            assert filename != null;
            String suffix = filename.substring(filename.lastIndexOf(".") + 1);
            FastDfsFileInfo fastDfsFileInfo = dfs.uploadFile(file.getBytes(), suffix);
            if (fastDfsFileInfo != null) {
                return JsonVO.success(dfs.fetchUrl(fastDfsFileInfo, fileServerUrl, true));
            }
            return JsonVO.fail(null);
        }
    

    @Resource
    EasyExcelComponent excel;

    @SneakyThrows
    @ApiOperation(value = "导出报表")
    @GetMapping(value = "export", produces = "application/octet-stream")
    public ResponseEntity<byte[]> expoExcel(@RequestParam(required = false)  Long id) {

        List<RfidBuseExcelDO> list;
        if(id == null){
            list = rfidService.selectAll();
        }else {
            list = rfidService.selectById(id);
        }
        // 导出到输出流
        ByteArrayOutputStream out = new ByteArrayOutputStream();
        excel.export("Rfid", out, RfidBuseExcelDO.class, list);
        // 响应文件数据
        String filename = "rep-" + DateTime.now().toString("yyyyMMddHHmmssS") + ".xlsx";
        HttpHeaders headers = new HttpHeaders();
        headers.setContentDispositionFormData("attachment", filename);
        headers.setContentType(MediaType.APPLICATION_OCTET_STREAM);
        ResponseEntity<byte[]> result = new ResponseEntity<>(out.toByteArray(), headers, HttpStatus.CREATED);
        out.close();
        return result;
    }
}
